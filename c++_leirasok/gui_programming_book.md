lib.platform_clear.argtypes = [ctypes.c_void_p, ctypes.c_ubyte, 
                               ctypes.c_ubyte, ctypes.c_ubyte]
lib.platform_clear.restype = None

lib.platform_fill_rect.argtypes = [ctypes.c_void_p, ctypes.c_int, ctypes.c_int,
                                   ctypes.c_int, ctypes.c_int, ctypes.c_ubyte,
                                   ctypes.c_ubyte, ctypes.c_ubyte]
lib.platform_fill_rect.restype = None

lib.platform_draw_rect.argtypes = [ctypes.c_void_p, ctypes.c_int, ctypes.c_int,
                                   ctypes.c_int, ctypes.c_int, ctypes.c_ubyte,
                                   ctypes.c_ubyte, ctypes.c_ubyte]
lib.platform_draw_rect.restype = None

lib.platform_draw_text.argtypes = [ctypes.c_void_p, ctypes.c_int, ctypes.c_int,
                                   ctypes.c_char_p, ctypes.c_ubyte,
                                   ctypes.c_ubyte, ctypes.c_ubyte]
lib.platform_draw_text.restype = None

# Python osztályok
class Window:
    def __init__(self, title, x, y, width, height):
        self.handle = lib.platform_create_window(title.encode(), x, y, width, height)
        if not self.handle:
            raise RuntimeError("Failed to create window")
        self.running = False
    
    def __del__(self):
        if self.handle:
            lib.platform_destroy_window(self.handle)
    
    def show(self):
        lib.platform_show_window(self.handle)
    
    def poll_event(self):
        event = PlatformEvent()
        if lib.platform_poll_event(self.handle, ctypes.byref(event)):
            return event
        return None
    
    def begin_paint(self):
        return lib.platform_begin_paint(self.handle)
    
    def end_paint(self, ctx):
        lib.platform_end_paint(self.handle, ctx)
    
    def run(self, on_paint=None, on_event=None):
        self.running = True
        
        while self.running:
            event = self.poll_event()
            
            while event:
                if event.type == EventType.CLOSE:
                    self.running = False
                    break
                
                if event.type == EventType.PAINT:
                    ctx = self.begin_paint()
                    if on_paint:
                        on_paint(ctx)
                    self.end_paint(ctx)
                elif on_event:
                    on_event(event)
                
                event = self.poll_event()
    
    def close(self):
        self.running = False

class Button:
    def __init__(self, x, y, width, height, label):
        self.x = x
        self.y = y
        self.width = width
        self.height = height
        self.label = label
        self.hovered = False
        self.pressed = False
        self.on_click = None
    
    def contains(self, x, y):
        return (self.x <= x <= self.x + self.width and
                self.y <= y <= self.y + self.height)
    
    def handle_event(self, event):
        if event.type == EventType.MOUSE_MOVE:
            self.hovered = self.contains(event.x, event.y)
        
        elif event.type == EventType.MOUSE_DOWN:
            if self.contains(event.x, event.y):
                self.pressed = True
        
        elif event.type == EventType.MOUSE_UP:
            if self.pressed and self.contains(event.x, event.y):
                if self.on_click:
                    self.on_click()
            self.pressed = False
    
    def draw(self, ctx):
        if self.pressed:
            r, g, b = 204, 228, 247
        elif self.hovered:
            r, g, b = 229, 241, 251
        else:
            r, g, b = 225, 225, 225
        
        lib.platform_fill_rect(ctx, self.x, self.y, self.width, self.height, r, g, b)
        lib.platform_draw_rect(ctx, self.x, self.y, self.width, self.height, 120, 120, 120)
        lib.platform_draw_text(ctx, self.x + 10, self.y + 20, 
                              self.label.encode(), 0, 0, 0)
```

**Python használat példa:**

```python
# main.py

from gui import Window, Button, EventType, lib

def main():
    window = Window("Python GUI Példa", 100, 100, 400, 300)
    
    buttons = [
        Button(50, 50, 150, 40, "Python Gomb 1"),
        Button(50, 110, 150, 40, "Python Gomb 2"),
        Button(50, 170, 150, 40, "Kilépés")
    ]
    
    click_count = [0]  # Lista használata closure-höz
    
    def on_button1_click():
        click_count[0] += 1
        print(f"Gomb 1 kattintva! Összesen: {click_count[0]}")
    
    def on_button2_click():
        print("Gomb 2 kattintva!")
    
    def on_exit_click():
        print("Kilépés...")
        window.close()
    
    buttons[0].on_click = on_button1_click
    buttons[1].on_click = on_button2_click
    buttons[2].on_click = on_exit_click
    
    def on_paint(ctx):
        lib.platform_clear(ctx, 240, 240, 240)
        
        for btn in buttons:
            btn.draw(ctx)
        
        lib.platform_draw_text(ctx, 10, 10, b"Python GUI Library", 0, 0, 0)
    
    def on_event(event):
        for btn in buttons:
            btn.handle_event(event)
    
    window.show()
    window.run(on_paint, on_event)

if __name__ == "__main__":
    main()
```

### 10.3 Java Binding (JNA)

Java wrapper JNA (Java Native Access) használatával.

```java
// GUI.java

import com.sun.jna.*;
import com.sun.jna.ptr.PointerByReference;
import java.util.ArrayList;
import java.util.List;

public class GUI {
    
    // Native library interface
    public interface GUILibrary extends Library {
        GUILibrary INSTANCE = Native.load(
            Platform.isWindows() ? "gui" : "gui",
            GUILibrary.class
        );
        
        Pointer platform_create_window(String title, int x, int y, int w, int h);
        void platform_destroy_window(Pointer window);
        void platform_show_window(Pointer window);
        int platform_poll_event(Pointer window, PlatformEvent event);
        Pointer platform_begin_paint(Pointer window);
        void platform_end_paint(Pointer window, Pointer ctx);
        
        void platform_clear(Pointer ctx, byte r, byte g, byte b);
        void platform_fill_rect(Pointer ctx, int x, int y, int w, int h, 
                               byte r, byte g, byte b);
        void platform_draw_rect(Pointer ctx, int x, int y, int w, int h,
                               byte r, byte g, byte b);
        void platform_draw_text(Pointer ctx, int x, int y, String text,
                               byte r, byte g, byte b);
    }
    
    // Event types
    public enum EventType {
        NONE(0), CLOSE(1), PAINT(2), MOUSE_DOWN(3), MOUSE_UP(4),
        MOUSE_MOVE(5), KEY_DOWN(6), KEY_UP(7), RESIZE(8);
        
        private final int value;
        EventType(int value) { this.value = value; }
        public int getValue() { return value; }
        
        public static EventType fromInt(int value) {
            for (EventType type : values()) {
                if (type.value == value) return type;
            }
            return NONE;
        }
    }
    
    // PlatformEvent structure
    public static class PlatformEvent extends Structure {
        public int type;
        public int x;
        public int y;
        public int button;
        public int key;
        public int width;
        public int height;
        
        @Override
        protected List<String> getFieldOrder() {
            return java.util.Arrays.asList("type", "x", "y", "button", 
                                          "key", "width", "height");
        }
        
        public EventType getType() {
            return EventType.fromInt(type);
        }
    }
    
    // Window class
    public static class Window {
        private Pointer handle;
        private boolean running;
        
        public interface PaintCallback {
            void onPaint(Pointer ctx);
        }
        
        public interface EventCallback {
            void onEvent(PlatformEvent event);
        }
        
        public Window(String title, int x, int y, int width, int height) {
            handle = GUILibrary.INSTANCE.platform_create_window(title, x, y, width, height);
            if (handle == null) {
                throw new RuntimeException("Failed to create window");
            }
        }
        
        public void show() {
            GUILibrary.INSTANCE.platform_show_window(handle);
        }
        
        public void run(PaintCallback onPaint, EventCallback onEvent) {
            running = true;
            PlatformEvent event = new PlatformEvent();
            
            while (running) {
                while (GUILibrary.INSTANCE.platform_poll_event(handle, event) != 0) {
                    if (event.getType() == EventType.CLOSE) {
                        running = false;
                        break;
                    }
                    
                    if (event.getType() == EventType.PAINT) {
                        Pointer ctx = GUILibrary.INSTANCE.platform_begin_paint(handle);
                        if (onPaint != null) {
                            onPaint.onPaint(ctx);
                        }
                        GUILibrary.INSTANCE.platform_end_paint(handle, ctx);
                    } else if (onEvent != null) {
                        onEvent.onEvent(event);
                    }
                }
            }
        }
        
        public void close() {
            running = false;
        }
        
        public void destroy() {
            if (handle != null) {
                GUILibrary.INSTANCE.platform_destroy_window(handle);
                handle = null;
            }
        }
        
        @Override
        protected void finalize() {
            destroy();
        }
    }
    
    // Button class
    public static class Button {
        private int x, y, width, height;
        private String label;
        private boolean hovered;
        private boolean pressed;
        private Runnable onClick;
        
        public Button(int x, int y, int width, int height, String label) {
            this.x = x;
            this.y = y;
            this.width = width;
            this.height = height;
            this.label = label;
        }
        
        public void setOnClick(Runnable callback) {
            this.onClick = callback;
        }
        
        public boolean contains(int px, int py) {
            return px >= x && px <= x + width && py >= y && py <= y + height;
        }
        
        public void handleEvent(PlatformEvent event) {
            switch (event.getType()) {
                case MOUSE_MOVE:
                    hovered = contains(event.x, event.y);
                    break;
                
                case MOUSE_DOWN:
                    if (contains(event.x, event.y)) {
                        pressed = true;
                    }
                    break;
                
                case MOUSE_UP:
                    if (pressed && contains(event.x, event.y)) {
                        if (onClick != null) {
                            onClick.run();
                        }
                    }
                    pressed = false;
                    break;
            }
        }
        
        public void draw(Pointer ctx) {
            byte r, g, b;
            
            if (pressed) {
                r = (byte)204; g = (byte)228; b = (byte)247;
            } else if (hovered) {
                r = (byte)229; g = (byte)241; b = (byte)251;
            } else {
                r = (byte)225; g = (byte)225; b = (byte)225;
            }
            
            GUILibrary.INSTANCE.platform_fill_rect(ctx, x, y, width, height, r, g, b);
            GUILibrary.INSTANCE.platform_draw_rect(ctx, x, y, width, height, 
                                                   (byte)120, (byte)120, (byte)120);
            GUILibrary.INSTANCE.platform_draw_text(ctx, x + 10, y + 20, label,
                                                   (byte)0, (byte)0, (byte)0);
        }
    }
}
```

**Java használat példa:**

```java
// Main.java

import GUI.*;

public class Main {
    public static void main(String[] args) {
        Window window = new Window("Java GUI Példa", 100, 100, 400, 300);
        
        List<Button> buttons = new ArrayList<>();
        buttons.add(new Button(50, 50, 150, 40, "Java Gomb 1"));
        buttons.add(new Button(50, 110, 150, 40, "Java Gomb 2"));
        buttons.add(new Button(50, 170, 150, 40, "Kilépés"));
        
        final int[] clickCount = {0};
        
        buttons.get(0).setOnClick(() -> {
            clickCount[0]++;
            System.out.println("Gomb 1 kattintva! Összesen: " + clickCount[0]);
        });
        
        buttons.get(1).setOnClick(() -> {
            System.out.println("Gomb 2 kattintva!");
        });
        
        buttons.get(2).setOnClick(() -> {
            System.out.println("Kilépés...");
            window.close();
        });
        
        window.show();
        
        window.run(
            // Paint callback
            ctx -> {
                GUILibrary.INSTANCE.platform_clear(ctx, (byte)240, (byte)240, (byte)240);
                
                for (Button btn : buttons) {
                    btn.draw(ctx);
                }
                
                GUILibrary.INSTANCE.platform_draw_text(ctx, 10, 10, 
                    "Java GUI Library", (byte)0, (byte)0, (byte)0);
            },
            // Event callback
            event -> {
                for (Button btn : buttons) {
                    btn.handleEvent(event);
                }
            }
        );
        
        window.destroy();
    }
}
```

---

## Összefoglalás

### Mit tanultunk?

1. **Alapok**: Ablakkezelés, eseményciklus
2. **Widgetek**: Button, TextBox készítése nulláról
3. **Layout rendszerek**: Automatikus elrendezés
4. **Szövegkezelés**: Input mezők, fókusz kezelés
5. **Eseménypropagáció**: Bubbling és capture
6. **Render backend**: Platformfüggetlen rajzolás
7. **Designer**: Vizuális GUI szerkesztő
8. **IMGUI**: Immediate mode GUI megközelítés
9. **Platformfüggetlenség**: Egységes API Windows/Linux-ra
10. **Language bindings**: C++, Python, Java wrapper

### Következő lépések

**Fejlesztési irányok:**

1. **További widgetek**:
   - ComboBox (legördülő lista)
   - ListView, TreeView
   - TabControl
   - ScrollBar és ScrollView
   - Menu és ToolBar

2. **Téma rendszer**:
   - Színsémák
   - Skin-ek
   - CSS-szerű stílusok

3. **Animációk**:
   - Tweening rendszer
   - Átmenetek widgetek között

4. **OpenGL/Vulkan backend**:
   - GPU gyorsítás
   - Shader támogatás
   - 3D widgetek

5. **Hálózati komponensek**:
   - Aszinkron műveletek
   - Progress bar-ok
   - Background task-ok

6. **Accessibility**:
   - Screen reader támogatás
   - Keyboard navigation
   - High contrast témák

### Ajánlott olvasmányok

**Könyvek:**
- "Programming Windows" by Charles Petzold
- "Xlib Programming Manual"
- "GUI Bloopers" by Jeff Johnson

**Open source projektek tanulmányozásra:**
- **GTK+**: Modern C GUI toolkit
- **Qt**: C++ cross-platform framework
- **Dear ImGui**: Immediate mode GUI
- **nuklear**: Single-header IMGUI library
- **FLTK**: Fast Light Toolkit
- **SDL2**: Simple DirectMedia Layer

**Online források:**
- Win32 API dokumentáció (Microsoft Docs)
- X11 documentation (X.org)
- OpenGL tutorials (learnopengl.com)

### Gyakorlati projektek

**Kezdő szint:**
1. Számológép GUI
2. Jegyzettömb alkalmazás
3. Rajzoló program (paint clone)

**Haladó szint:**
1. Fájlkezelő (file browser)
2. Zenei lejátszó UI
3. Chat alkalmazás UI
4. Egyszerű IDE (code editor)

**Professzionális szint:**
1. Teljes GUI framework másik nyelvhez
2. Visual form designer
3. Game engine editor UI
4. CAD/3D modeling UI

---

## Függelék: Teljes Példa Kód Struktúra

```
gui_project/
├── include/
│   ├── platform.h
│   ├── widget.h
│   ├── button.h
│   ├── textbox.h
│   ├── layout.h
│   └── designer.h
├── src/
│   ├── platform_win32.c
│   ├── platform_x11.c
│   ├── widget.c
│   ├── button.c
│   ├── textbox.c
│   ├── layout.c
│   └── designer.c
├── bindings/
│   ├── cpp/
│   │   ├── gui.hpp
│   │   └── example.cpp
│   ├── python/
│   │   ├── gui.py
│   │   └── example.py
│   └── java/
│       ├── GUI.java
│       └── Main.java
├── examples/
│   ├── 01_minimal_window.c
│   ├── 02_button_example.c
│   ├── 03_layout_example.c
│   ├── 04_textbox_example.c
│   ├── 05_designer.c
│   └── 06_imgui_example.c
├── Makefile
└── README.md
```

---

## Epilógus

Gratulálunk! Végigjártad az utat a nullától egy működő GUI rendszerig. Most már:

- Érted, hogyan működnek a GUI rendszerek belülről
- Képes vagy saját widgeteket készíteni
- Tudod, hogyan építs fel egy teljes GUI frameworköt
- Ismered a platformfüggetlen programozás alapjait
- Láttad, hogyan lehet más nyelvekhez binding-okat készíteni

A GUI programozás egy folyamatosan fejlődő terület. A modern web technológiák (Electron, WebView) és a deklaratív UI keretrendszerek (React Native, Flutter) új irányokat mutatnak, de az alapelvek változatlanok maradnak.

Sok sikert a saját GUI projektjeidhez! 🚀

---

**Könyv vége**

*Verzió: 1.0*  
*Utolsó frissítés: 2025. október*

### 10.2 Python Binding (ctypes)

Python wrapper készítése a C library-hez ctypes használatával.

```python
# gui.py - Python wrapper

import ctypes
import sys
from enum import IntEnum

# Platform függő library betöltése
if sys.platform == 'win32':
    lib = ctypes.CDLL('./gui.dll')
elif sys.platform.startswith('linux'):
    lib = ctypes.CDLL('./libgui.so')
else:
    raise RuntimeError("Unsupported platform")

# Esemény típusok
class EventType(IntEnum):
    NONE = 0
    CLOSE = 1
    PAINT = 2
    MOUSE_DOWN = 3
    MOUSE_UP = 4
    MOUSE_MOVE = 5
    KEY_DOWN = 6
    KEY_UP = 7
    RESIZE = 8

# PlatformEvent struktúra
class PlatformEvent(ctypes.Structure):
    _fields_ = [
        ("type", ctypes.c_int),
        ("x", ctypes.c_int),
        ("y", ctypes.c_int),
        ("button", ctypes.c_int),
        ("key", ctypes.c_int),
        ("width", ctypes.c_int),
        ("height", ctypes.c_int)
    ]

# Function prototypes
lib.platform_create_window.argtypes = [ctypes.c_char_p, ctypes.c_int, 
                                       ctypes.c_int, ctypes.c_int, ctypes.c_int]
lib.platform_create_window.restype = ctypes.c_void_p

lib.platform_destroy_window.argtypes = [ctypes.c_void_p]
lib.platform_destroy_window.restype = None

lib.platform_show_window.argtypes = [ctypes.c_void_p]
lib.platform_show_window.restype = None

lib.platform_poll_event.argtypes = [ctypes.c_void_p, ctypes.POINTER(PlatformEvent)]
lib.platform_poll_event.restype = ctypes.c_int

lib.platform_begin_paint.argtypes = [ctypes.c_void_p]
lib.platform_begin_paint.restype = ctypes.c_void_p

lib.platform_end_paint.argtypes = [ctypes.c_void_p, ctypes.c_void_p]
lib.platform_end_paint.restype = None

lib.platform_clear.argtypes = [ctypes.c_void_p, ctypes.c_ubyte, 
                               ctypes.c_ubyte, ctypes.c_ubyte]---

## 9. Fejezet: Platformfüggetlenség

Most nézzük meg, hogyan lehet a GUI kódot platformfüggetlenné tenni, mint a Qt vagy GTK.

### 9.1 Absztrakciós Rétegek

**Három fő réteg:**
1. **Platform Layer**: OS-specifikus kód (Win32, X11, Cocoa)
2. **Abstraction Layer**: Közös interfész
3. **Widget Layer**: Magas szintű komponensek

### 9.2 Platform Absztrakció

```c
// platform.h - Platform független interfész

#ifndef PLATFORM_H
#define PLATFORM_H

// Platform típusok
typedef enum {
    PLATFORM_WINDOWS,
    PLATFORM_LINUX,
    PLATFORM_MACOS
} PlatformType;

// Ablak handle (platform független)
typedef struct PlatformWindow PlatformWindow;

// Rajzolási context
typedef struct PlatformContext PlatformContext;

// Esemény típusok
typedef enum {
    PLATFORM_EVENT_NONE,
    PLATFORM_EVENT_CLOSE,
    PLATFORM_EVENT_PAINT,
    PLATFORM_EVENT_MOUSE_DOWN,
    PLATFORM_EVENT_MOUSE_UP,
    PLATFORM_EVENT_MOUSE_MOVE,
    PLATFORM_EVENT_KEY_DOWN,
    PLATFORM_EVENT_KEY_UP,
    PLATFORM_EVENT_RESIZE
} PlatformEventType;

// Platform esemény
typedef struct {
    PlatformEventType type;
    int x, y;
    int button;
    int key;
    int width, height;
} PlatformEvent;

// Platform API
PlatformWindow* platform_create_window(const char *title, int x, int y, int w, int h);
void platform_destroy_window(PlatformWindow *window);
void platform_show_window(PlatformWindow *window);
int platform_poll_event(PlatformWindow *window, PlatformEvent *event);
PlatformContext* platform_begin_paint(PlatformWindow *window);
void platform_end_paint(PlatformWindow *window, PlatformContext *ctx);

// Rajzolási függvények
void platform_clear(PlatformContext *ctx, unsigned char r, unsigned char g, unsigned char b);
void platform_fill_rect(PlatformContext *ctx, int x, int y, int w, int h, 
                       unsigned char r, unsigned char g, unsigned char b);
void platform_draw_rect(PlatformContext *ctx, int x, int y, int w, int h,
                       unsigned char r, unsigned char g, unsigned char b);
void platform_draw_text(PlatformContext *ctx, int x, int y, const char *text,
                       unsigned char r, unsigned char g, unsigned char b);
void platform_draw_line(PlatformContext *ctx, int x1, int y1, int x2, int y2,
                       unsigned char r, unsigned char g, unsigned char b, int width);

// Platform lekérdezés
PlatformType platform_get_type();

#endif
```

### 9.3 Windows Implementáció

```c
// platform_win32.c

#ifdef _WIN32

#include "platform.h"
#include <windows.h>
#include <stdlib.h>

struct PlatformWindow {
    HWND hwnd;
    HINSTANCE hinstance;
    int should_close;
    PlatformEvent pending_event;
    int has_pending;
};

struct PlatformContext {
    HDC hdc;
    PAINTSTRUCT ps;
    PlatformWindow *window;
};

// Esemény konverzió
static LRESULT CALLBACK WindowProcInternal(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    PlatformWindow *window = (PlatformWindow*)GetWindowLongPtr(hwnd, GWLP_USERDATA);
    
    if (window && !window->has_pending) {
        PlatformEvent *e = &window->pending_event;
        
        switch (uMsg) {
            case WM_CLOSE:
                e->type = PLATFORM_EVENT_CLOSE;
                window->has_pending = 1;
                return 0;
            
            case WM_PAINT:
                e->type = PLATFORM_EVENT_PAINT;
                window->has_pending = 1;
                break;
            
            case WM_LBUTTONDOWN:
                e->type = PLATFORM_EVENT_MOUSE_DOWN;
                e->x = LOWORD(lParam);
                e->y = HIWORD(lParam);
                e->button = 1;
                window->has_pending = 1;
                return 0;
            
            case WM_LBUTTONUP:
                e->type = PLATFORM_EVENT_MOUSE_UP;
                e->x = LOWORD(lParam);
                e->y = HIWORD(lParam);
                e->button = 1;
                window->has_pending = 1;
                return 0;
            
            case WM_MOUSEMOVE:
                e->type = PLATFORM_EVENT_MOUSE_MOVE;
                e->x = LOWORD(lParam);
                e->y = HIWORD(lParam);
                window->has_pending = 1;
                return 0;
            
            case WM_KEYDOWN:
                e->type = PLATFORM_EVENT_KEY_DOWN;
                e->key = (int)wParam;
                window->has_pending = 1;
                return 0;
            
            case WM_SIZE:
                e->type = PLATFORM_EVENT_RESIZE;
                e->width = LOWORD(lParam);
                e->height = HIWORD(lParam);
                window->has_pending = 1;
                return 0;
        }
    }
    
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

PlatformWindow* platform_create_window(const char *title, int x, int y, int w, int h) {
    HINSTANCE hinstance = GetModuleHandle(NULL);
    const char CLASS_NAME[] = "PlatformWindowClass";
    
    // Ablak osztály regisztrálása (csak egyszer)
    static int registered = 0;
    if (!registered) {
        WNDCLASSA wc = {0};
        wc.lpfnWndProc = WindowProcInternal;
        wc.hInstance = hinstance;
        wc.lpszClassName = CLASS_NAME;
        wc.hCursor = LoadCursor(NULL, IDC_ARROW);
        RegisterClassA(&wc);
        registered = 1;
    }
    
    // Ablak létrehozása
    HWND hwnd = CreateWindowExA(
        0, CLASS_NAME, title, WS_OVERLAPPEDWINDOW,
        x, y, w, h,
        NULL, NULL, hinstance, NULL
    );
    
    if (!hwnd) return NULL;
    
    PlatformWindow *window = malloc(sizeof(PlatformWindow));
    window->hwnd = hwnd;
    window->hinstance = hinstance;
    window->should_close = 0;
    window->has_pending = 0;
    
    SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)window);
    
    return window;
}

void platform_destroy_window(PlatformWindow *window) {
    if (window) {
        DestroyWindow(window->hwnd);
        free(window);
    }
}

void platform_show_window(PlatformWindow *window) {
    ShowWindow(window->hwnd, SW_SHOW);
    UpdateWindow(window->hwnd);
}

int platform_poll_event(PlatformWindow *window, PlatformEvent *event) {
    // Először ellenőrizzük a pending eseményt
    if (window->has_pending) {
        *event = window->pending_event;
        window->has_pending = 0;
        return 1;
    }
    
    // Windows üzenetek feldolgozása
    MSG msg;
    if (PeekMessage(&msg, window->hwnd, 0, 0, PM_REMOVE)) {
        if (msg.message == WM_QUIT) {
            event->type = PLATFORM_EVENT_CLOSE;
            return 1;
        }
        TranslateMessage(&msg);
        DispatchMessage(&msg);
        
        // Ellenőrizzük újra a pendinget
        if (window->has_pending) {
            *event = window->pending_event;
            window->has_pending = 0;
            return 1;
        }
    }
    
    return 0;
}

PlatformContext* platform_begin_paint(PlatformWindow *window) {
    PlatformContext *ctx = malloc(sizeof(PlatformContext));
    ctx->window = window;
    ctx->hdc = BeginPaint(window->hwnd, &ctx->ps);
    return ctx;
}

void platform_end_paint(PlatformWindow *window, PlatformContext *ctx) {
    EndPaint(window->hwnd, &ctx->ps);
    free(ctx);
}

void platform_clear(PlatformContext *ctx, unsigned char r, unsigned char g, unsigned char b) {
    HBRUSH brush = CreateSolidBrush(RGB(r, g, b));
    FillRect(ctx->hdc, &ctx->ps.rcPaint, brush);
    DeleteObject(brush);
}

void platform_fill_rect(PlatformContext *ctx, int x, int y, int w, int h,
                       unsigned char r, unsigned char g, unsigned char b) {
    HBRUSH brush = CreateSolidBrush(RGB(r, g, b));
    RECT rect = {x, y, x + w, y + h};
    FillRect(ctx->hdc, &rect, brush);
    DeleteObject(brush);
}

void platform_draw_rect(PlatformContext *ctx, int x, int y, int w, int h,
                       unsigned char r, unsigned char g, unsigned char b) {
    HPEN pen = CreatePen(PS_SOLID, 1, RGB(r, g, b));
    HPEN oldPen = SelectObject(ctx->hdc, pen);
    HBRUSH oldBrush = SelectObject(ctx->hdc, GetStockObject(NULL_BRUSH));
    
    Rectangle(ctx->hdc, x, y, x + w, y + h);
    
    SelectObject(ctx->hdc, oldBrush);
    SelectObject(ctx->hdc, oldPen);
    DeleteObject(pen);
}

void platform_draw_text(PlatformContext *ctx, int x, int y, const char *text,
                       unsigned char r, unsigned char g, unsigned char b) {
    SetBkMode(ctx->hdc, TRANSPARENT);
    SetTextColor(ctx->hdc, RGB(r, g, b));
    TextOutA(ctx->hdc, x, y, text, strlen(text));
}

void platform_draw_line(PlatformContext *ctx, int x1, int y1, int x2, int y2,
                       unsigned char r, unsigned char g, unsigned char b, int width) {
    HPEN pen = CreatePen(PS_SOLID, width, RGB(r, g, b));
    HPEN oldPen = SelectObject(ctx->hdc, pen);
    
    MoveToEx(ctx->hdc, x1, y1, NULL);
    LineTo(ctx->hdc, x2, y2);
    
    SelectObject(ctx->hdc, oldPen);
    DeleteObject(pen);
}

PlatformType platform_get_type() {
    return PLATFORM_WINDOWS;
}

#endif // _WIN32
```

### 9.4 Linux (X11) Implementáció

```c
// platform_x11.c

#ifdef __linux__

#include "platform.h"
#include <X11/Xlib.h>
#include <stdlib.h>
#include <string.h>

struct PlatformWindow {
    Display *display;
    Window window;
    int screen;
    GC gc;
    Atom wm_delete_window;
    int width, height;
};

struct PlatformContext {
    Display *display;
    Window window;
    GC gc;
    PlatformWindow *platform_window;
};

PlatformWindow* platform_create_window(const char *title, int x, int y, int w, int h) {
    Display *display = XOpenDisplay(NULL);
    if (!display) return NULL;
    
    int screen = DefaultScreen(display);
    
    Window window = XCreateSimpleWindow(
        display,
        RootWindow(display, screen),
        x, y, w, h, 1,
        BlackPixel(display, screen),
        WhitePixel(display, screen)
    );
    
    XSelectInput(display, window,
                 ExposureMask | KeyPressMask | ButtonPressMask |
                 ButtonReleaseMask | PointerMotionMask | StructureNotifyMask);
    
    XStoreName(display, window, title);
    
    // WM_DELETE_WINDOW protokoll
    Atom wm_delete = XInternAtom(display, "WM_DELETE_WINDOW", False);
    XSetWMProtocols(display, window, &wm_delete, 1);
    
    GC gc = XCreateGC(display, window, 0, NULL);
    
    PlatformWindow *pw = malloc(sizeof(PlatformWindow));
    pw->display = display;
    pw->window = window;
    pw->screen = screen;
    pw->gc = gc;
    pw->wm_delete_window = wm_delete;
    pw->width = w;
    pw->height = h;
    
    return pw;
}

void platform_destroy_window(PlatformWindow *window) {
    if (window) {
        XFreeGC(window->display, window->gc);
        XDestroyWindow(window->display, window->window);
        XCloseDisplay(window->display);
        free(window);
    }
}

void platform_show_window(PlatformWindow *window) {
    XMapWindow(window->display, window->window);
    XFlush(window->display);
}

int platform_poll_event(PlatformWindow *window, PlatformEvent *event) {
    if (!XPending(window->display)) {
        return 0;
    }
    
    XEvent xevent;
    XNextEvent(window->display, &xevent);
    
    switch (xevent.type) {
        case Expose:
            if (xevent.xexpose.count == 0) {
                event->type = PLATFORM_EVENT_PAINT;
                return 1;
            }
            break;
        
        case ButtonPress:
            event->type = PLATFORM_EVENT_MOUSE_DOWN;
            event->x = xevent.xbutton.x;
            event->y = xevent.xbutton.y;
            event->button = xevent.xbutton.button;
            return 1;
        
        case ButtonRelease:
            event->type = PLATFORM_EVENT_MOUSE_UP;
            event->x = xevent.xbutton.x;
            event->y = xevent.xbutton.y;
            event->button = xevent.xbutton.button;
            return 1;
        
        case MotionNotify:
            event->type = PLATFORM_EVENT_MOUSE_MOVE;
            event->x = xevent.xmotion.x;
            event->y = xevent.xmotion.y;
            return 1;
        
        case KeyPress:
            event->type = PLATFORM_EVENT_KEY_DOWN;
            event->key = XLookupKeysym(&xevent.xkey, 0);
            return 1;
        
        case ConfigureNotify:
            if (xevent.xconfigure.width != window->width ||
                xevent.xconfigure.height != window->height) {
                window->width = xevent.xconfigure.width;
                window->height = xevent.xconfigure.height;
                event->type = PLATFORM_EVENT_RESIZE;
                event->width = window->width;
                event->height = window->height;
                return 1;
            }
            break;
        
        case ClientMessage:
            if (xevent.xclient.data.l[0] == window->wm_delete_window) {
                event->type = PLATFORM_EVENT_CLOSE;
                return 1;
            }
            break;
    }
    
    return 0;
}

PlatformContext* platform_begin_paint(PlatformWindow *window) {
    PlatformContext *ctx = malloc(sizeof(PlatformContext));
    ctx->display = window->display;
    ctx->window = window->window;
    ctx->gc = window->gc;
    ctx->platform_window = window;
    return ctx;
}

void platform_end_paint(PlatformWindow *window, PlatformContext *ctx) {
    XFlush(window->display);
    free(ctx);
}

void platform_clear(PlatformContext *ctx, unsigned char r, unsigned char g, unsigned char b) {
    unsigned long pixel = (r << 16) | (g << 8) | b;
    XSetForeground(ctx->display, ctx->gc, pixel);
    XFillRectangle(ctx->display, ctx->window, ctx->gc, 
                   0, 0, ctx->platform_window->width, ctx->platform_window->height);
}

void platform_fill_rect(PlatformContext *ctx, int x, int y, int w, int h,
                       unsigned char r, unsigned char g, unsigned char b) {
    unsigned long pixel = (r << 16) | (g << 8) | b;
    XSetForeground(ctx->display, ctx->gc, pixel);
    XFillRectangle(ctx->display, ctx->window, ctx->gc, x, y, w, h);
}

void platform_draw_rect(PlatformContext *ctx, int x, int y, int w, int h,
                       unsigned char r, unsigned char g, unsigned char b) {
    unsigned long pixel = (r << 16) | (g << 8) | b;
    XSetForeground(ctx->display, ctx->gc, pixel);
    XDrawRectangle(ctx->display, ctx->window, ctx->gc, x, y, w, h);
}

void platform_draw_text(PlatformContext *ctx, int x, int y, const char *text,
                       unsigned char r, unsigned char g, unsigned char b) {
    unsigned long pixel = (r << 16) | (g << 8) | b;
    XSetForeground(ctx->display, ctx->gc, pixel);
    XDrawString(ctx->display, ctx->window, ctx->gc, x, y, text, strlen(text));
}

void platform_draw_line(PlatformContext *ctx, int x1, int y1, int x2, int y2,
                       unsigned char r, unsigned char g, unsigned char b, int width) {
    unsigned long pixel = (r << 16) | (g << 8) | b;
    XSetForeground(ctx->display, ctx->gc, pixel);
    XSetLineAttributes(ctx->display, ctx->gc, width, LineSolid, CapRound, JoinRound);
    XDrawLine(ctx->display, ctx->window, ctx->gc, x1, y1, x2, y2);
}

PlatformType platform_get_type() {
    return PLATFORM_LINUX;
}

#endif // __linux__
```

### 9.5 Platformfüggetlen Példa Alkalmazás

```c
// main.c - Platformfüggetlen GUI alkalmazás

#include "platform.h"
#include <stdio.h>
#include <stdlib.h>

// Egyszerű button állapot
typedef struct {
    int x, y, w, h;
    char label[64];
    int is_hovered;
    int is_pressed;
} SimpleButton;

SimpleButton button1 = {50, 50, 150, 40, "Kattints rám!", 0, 0};
SimpleButton button2 = {50, 110, 150, 40, "Kilépés", 0, 0};

int button_contains(SimpleButton *btn, int x, int y) {
    return x >= btn->x && x <= btn->x + btn->w &&
           y >= btn->y && y <= btn->y + btn->h;
}

void button_draw(SimpleButton *btn, PlatformContext *ctx) {
    unsigned char r, g, b;
    
    if (btn->is_pressed) {
        r = 204; g = 228; b = 247;
    } else if (btn->is_hovered) {
        r = 229; g = 241; b = 251;
    } else {
        r = 225; g = 225; b = 225;
    }
    
    platform_fill_rect(ctx, btn->x, btn->y, btn->w, btn->h, r, g, b);
    platform_draw_rect(ctx, btn->x, btn->y, btn->w, btn->h, 120, 120, 120);
    platform_draw_text(ctx, btn->x + 10, btn->y + 20, btn->label, 0, 0, 0);
}

int main() {
    // Platform típus kiírása
    PlatformType platform = platform_get_type();
    printf("Platform: %s\n", 
           platform == PLATFORM_WINDOWS ? "Windows" :
           platform == PLATFORM_LINUX ? "Linux" : "Unknown");
    
    // Ablak létrehozása
    PlatformWindow *window = platform_create_window(
        "Platformfüggetlen GUI", 100, 100, 400, 300
    );
    
    if (!window) {
        printf("Hiba: Ablak létrehozása sikertelen!\n");
        return 1;
    }
    
    platform_show_window(window);
    
    // Főciklus
    int running = 1;
    while (running) {
        PlatformEvent event;
        
        while (platform_poll_event(window, &event)) {
            switch (event.type) {
                case PLATFORM_EVENT_CLOSE:
                    running = 0;
                    break;
                
                case PLATFORM_EVENT_PAINT: {
                    PlatformContext *ctx = platform_begin_paint(window);
                    
                    // Háttér
                    platform_clear(ctx, 240, 240, 240);
                    
                    // Gombok rajzolása
                    button_draw(&button1, ctx);
                    button_draw(&button2, ctx);
                    
                    // Információ
                    platform_draw_text(ctx, 10, 10, "Platformfüggetlen GUI példa", 0, 0, 0);
                    
                    platform_end_paint(window, ctx);
                    break;
                }
                
                case PLATFORM_EVENT_MOUSE_MOVE:
                    button1.is_hovered = button_contains(&button1, event.x, event.y);
                    button2.is_hovered = button_contains(&button2, event.x, event.y);
                    // Újrarajzolás kérés platform specifikus módon kellene
                    break;
                
                case PLATFORM_EVENT_MOUSE_DOWN:
                    if (button_contains(&button1, event.x, event.y)) {
                        button1.is_pressed = 1;
                    }
                    if (button_contains(&button2, event.x, event.y)) {
                        button2.is_pressed = 1;
                    }
                    break;
                
                case PLATFORM_EVENT_MOUSE_UP:
                    if (button1.is_pressed && button_contains(&button1, event.x, event.y)) {
                        printf("Button 1 kattintva!\n");
                    }
                    if (button2.is_pressed && button_contains(&button2, event.x, event.y)) {
                        printf("Kilépés...\n");
                        running = 0;
                    }
                    button1.is_pressed = 0;
                    button2.is_pressed = 0;
                    break;
                
                case PLATFORM_EVENT_RESIZE:
                    printf("Ablak átméretezve: %dx%d\n", event.width, event.height);
                    break;
            }
        }
    }
    
    platform_destroy_window(window);
    return 0;
}
```

### 9.6 Fordítás Platform Szerint

**Makefile:**

```makefile
# Makefile platformfüggetlen GUI-hoz

CC = gcc
CFLAGS = -Wall -O2

# Platform detektálás
ifeq ($(OS),Windows_NT)
    PLATFORM = WIN32
    PLATFORM_SRC = platform_win32.c
    LIBS = -lgdi32 -mwindows
    OUTPUT = app.exe
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Linux)
        PLATFORM = LINUX
        PLATFORM_SRC = platform_x11.c
        LIBS = -lX11
        OUTPUT = app
    endif
endif

all:
	$(CC) $(CFLAGS) -D$(PLATFORM) main.c $(PLATFORM_SRC) -o $(OUTPUT) $(LIBS)

clean:
	rm -f $(OUTPUT) *.o
```

---

## 10. Fejezet: Binding Más Nyelvekhez

### 10.1 C++ Binding

C++ wrapper készítése a C GUI library-hez.

```cpp
// gui.hpp - C++ wrapper

#ifndef GUI_HPP
#define GUI_HPP

#include "platform.h"
#include <string>
#include <functional>
#include <memory>

namespace GUI {

// RAII Window wrapper
class Window {
private:
    PlatformWindow *m_window;
    bool m_running;

public:
    Window(const std::string& title, int x, int y, int width, int height)
        : m_running(false) {
        m_window = platform_create_window(title.c_str(), x, y, width, height);
        if (!m_window) {
            throw std::runtime_error("Failed to create window");
        }
    }
    
    ~Window() {
        if (m_window) {
            platform_destroy_window(m_window);
        }
    }
    
    // Move semantics
    Window(Window&& other) noexcept
        : m_window(other.m_window), m_running(other.m_running) {
        other.m_window = nullptr;
    }
    
    Window& operator=(Window&& other) noexcept {
        if (this != &other) {
            if (m_window) {
                platform_destroy_window(m_window);
            }
            m_window = other.m_window;
            m_running = other.m_running;
            other.m_window = nullptr;
        }
        return *this;
    }
    
    // Copy tiltása
    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;
    
    void show() {
        platform_show_window(m_window);
    }
    
    void run(std::function<void(PlatformContext*)> onPaint,
             std::function<void(const PlatformEvent&)> onEvent = nullptr) {
        m_running = true;
        
        while (m_running) {
            PlatformEvent event;
            
            while (platform_poll_event(m_window, &event)) {
                if (event.type == PLATFORM_EVENT_CLOSE) {
                    m_running = false;
                    break;
                }
                
                if (event.type == PLATFORM_EVENT_PAINT) {
                    PlatformContext *ctx = platform_begin_paint(m_window);
                    if (onPaint) {
                        onPaint(ctx);
                    }
                    platform_end_paint(m_window, ctx);
                } else if (onEvent) {
                    onEvent(event);
                }
            }
        }
    }
    
    void close() {
        m_running = false;
    }
};

// Button class
class Button {
private:
    int m_x, m_y, m_width, m_height;
    std::string m_label;
    bool m_hovered;
    bool m_pressed;
    std::function<void()> m_onClick;

public:
    Button(int x, int y, int width, int height, const std::string& label)
        : m_x(x), m_y(y), m_width(width), m_height(height),
          m_label(label), m_hovered(false), m_pressed(false) {}
    
    void setOnClick(std::function<void()> callback) {
        m_onClick = callback;
    }
    
    bool contains(int x, int y) const {
        return x >= m_x && x <= m_x + m_width &&
               y >= m_y && y <= m_y + m_height;
    }
    
    void handleEvent(const PlatformEvent& event) {
        switch (event.type) {
            case PLATFORM_EVENT_MOUSE_MOVE:
                m_hovered = contains(event.x, event.y);
                break;
            
            case PLATFORM_EVENT_MOUSE_DOWN:
                if (contains(event.x, event.y)) {
                    m_pressed = true;
                }
                break;
            
            case PLATFORM_EVENT_MOUSE_UP:
                if (m_pressed && contains(event.x, event.y)) {
                    if (m_onClick) {
                        m_onClick();
                    }
                }
                m_pressed = false;
                break;
        }
    }
    
    void draw(PlatformContext *ctx) const {
        unsigned char r, g, b;
        
        if (m_pressed) {
            r = 204; g = 228; b = 247;
        } else if (m_hovered) {
            r = 229; g = 241; b = 251;
        } else {
            r = 225; g = 225; b = 225;
        }
        
        platform_fill_rect(ctx, m_x, m_y, m_width, m_height, r, g, b);
        platform_draw_rect(ctx, m_x, m_y, m_width, m_height, 120, 120, 120);
        platform_draw_text(ctx, m_x + 10, m_y + 20, m_label.c_str(), 0, 0, 0);
    }
};

} // namespace GUI

#endif // GUI_HPP
```

**C++ használat példa:**

```cpp
// main.cpp

#include "gui.hpp"
#include <iostream>
#include <vector>

int main() {
    try {
        GUI::Window window("C++ GUI Példa", 100, 100, 400, 300);
        
        std::vector<GUI::Button> buttons;
        buttons.emplace_back(50, 50, 150, 40, "C++ Gomb 1");
        buttons.emplace_back(50, 110, 150, 40, "C++ Gomb 2");
        buttons.emplace_back(50, 170, 150, 40, "Kilépés");
        
        int clickCount = 0;
        
        buttons[0].setOnClick([&clickCount]() {
            clickCount++;
            std::cout << "Gomb 1 kattintva! Összesen: " << clickCount << std::endl;
        });
        
        buttons[1].setOnClick([]() {
            std::cout << "Gomb 2 kattintva!" << std::endl;
        });
        
        buttons[2].setOnClick([&window]() {
            std::cout << "Kilépés..." << std::endl;
            window.close();
        });
        
        window.show();
        
        window.run(
            // onPaint callback
            [&buttons](PlatformContext *ctx) {
                platform_clear(ctx, 240, 240, 240);
                
                for (const auto& btn : buttons) {
                    btn.draw(ctx);
                }
                
                platform_draw_text(ctx, 10, 10, "C++ GUI Library", 0, 0, 0);
            },
            // onEvent callback
            [&buttons](const PlatformEvent& event) {
                for (auto& btn : buttons) {
                    btn.handleEvent(event);
                }
            }
        );
        
    } catch (const std::exception& e) {
        std::cerr << "Hiba: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
```

### 10.2 Python Binding (ctypes)// Kiválasztás
void designer_select(Designer *d, int x, int y) {
    d->selected = NULL;
    
    // Fordított sorrend (legfelső widget először)
    for (int i = d->widget_count - 1; i >= 0; i--) {
        Widget *w = d->widgets[i];
        if (widget_contains_point(w, x, y)) {
            d->selected = w;
            printf("Widget kiválasztva: %p\n", (void*)w);
            break;
        }
    }
}

// Drag start
void designer_start_drag(Designer *d, int x, int y) {
    if (d->selected != NULL) {
        d->dragging = 1;
        d->drag_start_x = x;
        d->drag_start_y = y;
        d->widget_offset_x = d->selected->bounds.x - x;
        d->widget_offset_y = d->selected->bounds.y - y;
    }
}

// Drag move
void designer_drag(Designer *d, int x, int y) {
    if (d->dragging && d->selected != NULL) {
        d->selected->bounds.x = x + d->widget_offset_x;
        d->selected->bounds.y = y + d->widget_offset_y;
    }
}

// Drag end
void designer_end_drag(Designer *d) {
    d->dragging = 0;
}

// Új widget létrehozása
void designer_create_widget(Designer *d, int x, int y) {
    Widget *w = widget_create();
    w->bounds.x = x;
    w->bounds.y = y;
    w->bounds.width = 120;
    w->bounds.height = 35;
    
    switch (d->mode) {
        case DESIGNER_MODE_CREATE_BUTTON: {
            Button *btn = button_create(x, y, 120, 35, "Új Gomb");
            w->user_data = btn;
            w->draw = widget_button_draw;
            break;
        }
        case DESIGNER_MODE_CREATE_TEXTBOX: {
            TextBox *tb = textbox_create(x, y, 150, 35);
            w->user_data = tb;
            w->bounds.width = 150;
            break;
        }
        case DESIGNER_MODE_CREATE_PANEL: {
            w->bounds.width = 200;
            w->bounds.height = 150;
            w->draw = panel_draw;
            break;
        }
        default:
            break;
    }
    
    designer_add_widget(d, w);
    d->selected = w;
    d->mode = DESIGNER_MODE_SELECT;  // Vissza select módba
}

// Designer rajzolás
void designer_draw(Designer *d, void *context) {
    HDC hdc = (HDC)context;
    
    // Háttér (rács)
    HBRUSH brush = CreateSolidBrush(RGB(250, 250, 250));
    RECT rect = {0, 0, d->root->bounds.width, d->root->bounds.height};
    FillRect(hdc, &rect, brush);
    DeleteObject(brush);
    
    // Rács rajzolás
    HPEN gridPen = CreatePen(PS_DOT, 1, RGB(220, 220, 220));
    HPEN oldPen = SelectObject(hdc, gridPen);
    
    for (int x = 0; x < d->root->bounds.width; x += 20) {
        MoveToEx(hdc, x, 0, NULL);
        LineTo(hdc, x, d->root->bounds.height);
    }
    for (int y = 0; y < d->root->bounds.height; y += 20) {
        MoveToEx(hdc, 0, y, NULL);
        LineTo(hdc, d->root->bounds.width, y);
    }
    
    SelectObject(hdc, oldPen);
    DeleteObject(gridPen);
    
    // Widgetek rajzolása
    widget_draw_recursive(d->root, context);
    
    // Kiválasztott widget kiemelése
    if (d->selected != NULL) {
        HPEN selectPen = CreatePen(PS_SOLID, 2, RGB(0, 120, 215));
        HPEN oldSelectPen = SelectObject(hdc, selectPen);
        HBRUSH oldBrush = SelectObject(hdc, GetStockObject(NULL_BRUSH));
        
        Rectangle(hdc, d->selected->bounds.x - 2, d->selected->bounds.y - 2,
                  d->selected->bounds.x + d->selected->bounds.width + 2,
                  d->selected->bounds.y + d->selected->bounds.height + 2);
        
        // Méretezési fogantyúk (resize handles)
        int handle_size = 6;
        HBRUSH handleBrush = CreateSolidBrush(RGB(0, 120, 215));
        
        // Bal felső
        RECT handle = {d->selected->bounds.x - handle_size/2, 
                       d->selected->bounds.y - handle_size/2,
                       d->selected->bounds.x + handle_size/2,
                       d->selected->bounds.y + handle_size/2};
        FillRect(hdc, &handle, handleBrush);
        
        // Jobb felső
        handle.left = d->selected->bounds.x + d->selected->bounds.width - handle_size/2;
        handle.right = d->selected->bounds.x + d->selected->bounds.width + handle_size/2;
        FillRect(hdc, &handle, handleBrush);
        
        // Bal alsó
        handle.left = d->selected->bounds.x - handle_size/2;
        handle.right = d->selected->bounds.x + handle_size/2;
        handle.top = d->selected->bounds.y + d->selected->bounds.height - handle_size/2;
        handle.bottom = d->selected->bounds.y + d->selected->bounds.height + handle_size/2;
        FillRect(hdc, &handle, handleBrush);
        
        // Jobb alsó
        handle.left = d->selected->bounds.x + d->selected->bounds.width - handle_size/2;
        handle.right = d->selected->bounds.x + d->selected->bounds.width + handle_size/2;
        FillRect(hdc, &handle, handleBrush);
        
        DeleteObject(handleBrush);
        SelectObject(hdc, oldBrush);
        SelectObject(hdc, oldSelectPen);
        DeleteObject(selectPen);
    }
}

// Property Panel (egyszerűsített)
typedef struct {
    Rect bounds;
    Widget *target;
} PropertyPanel;

void property_panel_draw(PropertyPanel *pp, HDC hdc) {
    if (pp->target == NULL) return;
    
    // Panel háttér
    HBRUSH brush = CreateSolidBrush(RGB(240, 240, 240));
    RECT rect = {pp->bounds.x, pp->bounds.y,
                 pp->bounds.x + pp->bounds.width,
                 pp->bounds.y + pp->bounds.height};
    FillRect(hdc, &rect, brush);
    DeleteObject(brush);
    
    // Keret
    HPEN pen = CreatePen(PS_SOLID, 1, RGB(180, 180, 180));
    HPEN oldPen = SelectObject(hdc, pen);
    Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);
    SelectObject(hdc, oldPen);
    DeleteObject(pen);
    
    // Tulajdonságok kiírása
    SetBkMode(hdc, TRANSPARENT);
    char buffer[256];
    int y = pp->bounds.y + 10;
    
    TextOutA(hdc, pp->bounds.x + 10, y, "Tulajdonságok:", 15);
    y += 25;
    
    sprintf(buffer, "X: %d", pp->target->bounds.x);
    TextOutA(hdc, pp->bounds.x + 10, y, buffer, strlen(buffer));
    y += 20;
    
    sprintf(buffer, "Y: %d", pp->target->bounds.y);
    TextOutA(hdc, pp->bounds.x + 10, y, buffer, strlen(buffer));
    y += 20;
    
    sprintf(buffer, "Width: %d", pp->target->bounds.width);
    TextOutA(hdc, pp->bounds.x + 10, y, buffer, strlen(buffer));
    y += 20;
    
    sprintf(buffer, "Height: %d", pp->target->bounds.height);
    TextOutA(hdc, pp->bounds.x + 10, y, buffer, strlen(buffer));
}

// Export JSON
void designer_export_json(Designer *d, const char *filename) {
    FILE *f = fopen(filename, "w");
    if (!f) return;
    
    fprintf(f, "{\n");
    fprintf(f, "  \"widgets\": [\n");
    
    for (int i = 0; i < d->widget_count; i++) {
        Widget *w = d->widgets[i];
        fprintf(f, "    {\n");
        fprintf(f, "      \"type\": \"");
        
        if (w->user_data && w->draw == widget_button_draw) {
            Button *btn = (Button*)w->user_data;
            fprintf(f, "button\",\n");
            fprintf(f, "      \"label\": \"%s\",\n", btn->label);
        } else if (w->draw == panel_draw) {
            fprintf(f, "panel\",\n");
        } else {
            fprintf(f, "unknown\",\n");
        }
        
        fprintf(f, "      \"x\": %d,\n", w->bounds.x);
        fprintf(f, "      \"y\": %d,\n", w->bounds.y);
        fprintf(f, "      \"width\": %d,\n", w->bounds.width);
        fprintf(f, "      \"height\": %d\n", w->bounds.height);
        fprintf(f, "    }%s\n", (i < d->widget_count - 1) ? "," : "");
    }
    
    fprintf(f, "  ]\n");
    fprintf(f, "}\n");
    
    fclose(f);
    printf("UI export: %s\n", filename);
}

// Export C kód
void designer_export_c_code(Designer *d, const char *filename) {
    FILE *f = fopen(filename, "w");
    if (!f) return;
    
    fprintf(f, "// Generált UI kód\n\n");
    fprintf(f, "#include \"gui.h\"\n\n");
    fprintf(f, "void create_ui(Widget *parent) {\n");
    
    for (int i = 0; i < d->widget_count; i++) {
        Widget *w = d->widgets[i];
        
        if (w->user_data && w->draw == widget_button_draw) {
            Button *btn = (Button*)w->user_data;
            fprintf(f, "    Button *btn%d = button_create(%d, %d, %d, %d, \"%s\");\n",
                    i, w->bounds.x, w->bounds.y, w->bounds.width, w->bounds.height,
                    btn->label);
        } else if (w->draw == panel_draw) {
            fprintf(f, "    Widget *panel%d = widget_create();\n", i);
            fprintf(f, "    panel%d->bounds = (Rect){%d, %d, %d, %d};\n",
                    i, w->bounds.x, w->bounds.y, w->bounds.width, w->bounds.height);
            fprintf(f, "    panel%d->draw = panel_draw;\n", i);
        }
    }
    
    fprintf(f, "}\n");
    fclose(f);
    printf("C kód export: %s\n", filename);
}
```

### 7.2 Teljes Designer Példa

```c
#include <windows.h>

Designer *designer;
PropertyPanel *propPanel;

LRESULT CALLBACK DesignerWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_CREATE: {
            designer = designer_create();
            designer->root->bounds.width = 800;
            designer->root->bounds.height = 600;
            
            propPanel = malloc(sizeof(PropertyPanel));
            propPanel->bounds = (Rect){810, 10, 200, 300};
            propPanel->target = NULL;
            return 0;
        }
        
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
        
        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);
            
            // Designer terület rajzolása
            designer_draw(designer, hdc);
            
            // Property panel rajzolása
            if (designer->selected) {
                propPanel->target = designer->selected;
                property_panel_draw(propPanel, hdc);
            }
            
            // Toolbar (egyszerűsített)
            SetBkMode(hdc, TRANSPARENT);
            TextOutA(hdc, 10, 610, "Módok: [S]elect [B]utton [T]extBox [P]anel", 44);
            
            char mode_str[50];
            sprintf(mode_str, "Aktuális mód: %d", designer->mode);
            TextOutA(hdc, 10, 630, mode_str, strlen(mode_str));
            
            EndPaint(hwnd, &ps);
            return 0;
        }
        
        case WM_LBUTTONDOWN: {
            int x = LOWORD(lParam);
            int y = HIWORD(lParam);
            
            if (designer->mode == DESIGNER_MODE_SELECT) {
                designer_select(designer, x, y);
                designer_start_drag(designer, x, y);
            } else {
                designer_create_widget(designer, x, y);
            }
            
            InvalidateRect(hwnd, NULL, FALSE);
            return 0;
        }
        
        case WM_LBUTTONUP: {
            designer_end_drag(designer);
            return 0;
        }
        
        case WM_MOUSEMOVE: {
            int x = LOWORD(lParam);
            int y = HIWORD(lParam);
            
            if (wParam & MK_LBUTTON) {
                designer_drag(designer, x, y);
                InvalidateRect(hwnd, NULL, FALSE);
            }
            return 0;
        }
        
        case WM_KEYDOWN: {
            switch (wParam) {
                case 'S':
                    designer->mode = DESIGNER_MODE_SELECT;
                    break;
                case 'B':
                    designer->mode = DESIGNER_MODE_CREATE_BUTTON;
                    break;
                case 'T':
                    designer->mode = DESIGNER_MODE_CREATE_TEXTBOX;
                    break;
                case 'P':
                    designer->mode = DESIGNER_MODE_CREATE_PANEL;
                    break;
                case VK_DELETE:
                    // TODO: Törlés implementálása
                    break;
                case VK_F5:
                    designer_export_json(designer, "ui_design.json");
                    designer_export_c_code(designer, "ui_generated.c");
                    MessageBoxA(hwnd, "UI exportálva!", "Info", MB_OK);
                    break;
            }
            InvalidateRect(hwnd, NULL, FALSE);
            return 0;
        }
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
```

---

## 8. Fejezet: Immediate Mode GUI

Az Immediate Mode GUI (IMGUI) másik megközelítés a GUI programozásra, ahol a UI kódot minden frame-ben újra lefuttatjuk.

### 8.1 Retained Mode vs Immediate Mode

**Retained Mode (amit eddig csináltunk):**
- Widgetek objektumként léteznek
- Állapot a widgetekben tárolódik
- Eseménykezelés callback-ekkel

**Immediate Mode:**
- Nincs widget objektum állapot
- UI kód minden frame-ben lefut
- Egyszerűbb, kevesebb memória

### 8.2 Egyszerű IMGUI Implementáció

```c
#include <string.h>
#include <stdio.h>

// IMGUI Context
typedef struct {
    // Input állapot
    int mouse_x, mouse_y;
    int mouse_down;
    int mouse_clicked;
    
    // Hot & Active widget
    int hot_item;
    int active_item;
    
    // ID generálás
    int last_widget_id;
    
    // Render context
    void *render_context;
} IMGUIContext;

// Globális context
static IMGUIContext g_imgui;

// Inicializálás
void imgui_init() {
    memset(&g_imgui, 0, sizeof(IMGUIContext));
}

// Frame kezdés
void imgui_begin_frame(int mouse_x, int mouse_y, int mouse_down) {
    g_imgui.mouse_x = mouse_x;
    g_imgui.mouse_y = mouse_y;
    
    g_imgui.mouse_clicked = (!mouse_down && g_imgui.mouse_down);
    g_imgui.mouse_down = mouse_down;
    
    g_imgui.hot_item = 0;
    g_imgui.last_widget_id = 1;
}

// Frame vége
void imgui_end_frame() {
    if (!g_imgui.mouse_down) {
        g_imgui.active_item = 0;
    }
}

// ID generálás
int imgui_gen_id() {
    return g_imgui.last_widget_id++;
}

// Hit test
int imgui_region_hit(int x, int y, int w, int h) {
    return g_imgui.mouse_x >= x && g_imgui.mouse_x <= x + w &&
           g_imgui.mouse_y >= y && g_imgui.mouse_y <= y + h;
}

// Button widget
int imgui_button(int id, int x, int y, int w, int h, const char *label) {
    HDC hdc = (HDC)g_imgui.render_context;
    
    // Hit test
    if (imgui_region_hit(x, y, w, h)) {
        g_imgui.hot_item = id;
        if (g_imgui.active_item == 0 && g_imgui.mouse_down) {
            g_imgui.active_item = id;
        }
    }
    
    // Állapot meghatározása
    int is_hot = (g_imgui.hot_item == id);
    int is_active = (g_imgui.active_item == id);
    
    // Rajzolás
    COLORREF bg_color;
    if (is_active) {
        bg_color = RGB(204, 228, 247);
    } else if (is_hot) {
        bg_color = RGB(229, 241, 251);
    } else {
        bg_color = RGB(225, 225, 225);
    }
    
    HBRUSH brush = CreateSolidBrush(bg_color);
    RECT rect = {x, y, x + w, y + h};
    FillRect(hdc, &rect, brush);
    DeleteObject(brush);
    
    // Keret
    HPEN pen = CreatePen(PS_SOLID, 1, RGB(120, 120, 120));
    HPEN oldPen = SelectObject(hdc, pen);
    Rectangle(hdc, x, y, x + w, y + h);
    SelectObject(hdc, oldPen);
    DeleteObject(pen);
    
    // Szöveg
    SetBkMode(hdc, TRANSPARENT);
    DrawTextA(hdc, label, -1, &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    
    // Kattintás detektálás
    return is_active && is_hot && g_imgui.mouse_clicked;
}

// Slider widget
int imgui_slider(int id, int x, int y, int w, int h, int *value, int min, int max) {
    HDC hdc = (HDC)g_imgui.render_context;
    
    int changed = 0;
    
    // Hit test
    if (imgui_region_hit(x, y, w, h)) {
        g_imgui.hot_item = id;
        if (g_imgui.active_item == 0 && g_imgui.mouse_down) {
            g_imgui.active_item = id;
        }
    }
    
    // Érték frissítés húzáskor
    if (g_imgui.active_item == id && g_imgui.mouse_down) {
        float ratio = (float)(g_imgui.mouse_x - x) / w;
        if (ratio < 0) ratio = 0;
        if (ratio > 1) ratio = 1;
        
        int new_value = min + (int)(ratio * (max - min));
        if (new_value != *value) {
            *value = new_value;
            changed = 1;
        }
    }
    
    // Rajzolás - háttér
    HBRUSH brush = CreateSolidBrush(RGB(200, 200, 200));
    RECT rect = {x, y, x + w, y + h};
    FillRect(hdc, &rect, brush);
    DeleteObject(brush);
    
    // Slider pozíció
    float ratio = (float)(*value - min) / (max - min);
    int slider_x = x + (int)(ratio * w);
    
    // Slider rajzolás
    HBRUSH sliderBrush = CreateSolidBrush(RGB(0, 120, 215));
    RECT sliderRect = {slider_x - 5, y - 2, slider_x + 5, y + h + 2};
    FillRect(hdc, &sliderRect, sliderBrush);
    DeleteObject(sliderBrush);
    
    // Érték kiírása
    char buffer[32];
    sprintf(buffer, "%d", *value);
    SetBkMode(hdc, TRANSPARENT);
    TextOutA(hdc, x + w + 10, y + 2, buffer, strlen(buffer));
    
    return changed;
}

// Text label
void imgui_label(int x, int y, const char *text) {
    HDC hdc = (HDC)g_imgui.render_context;
    SetBkMode(hdc, TRANSPARENT);
    TextOutA(hdc, x, y, text, strlen(text));
}

// Checkbox
int imgui_checkbox(int id, int x, int y, int size, const char *label, int *checked) {
    HDC hdc = (HDC)g_imgui.render_context;
    
    int changed = 0;
    
    // Hit test
    if (imgui_region_hit(x, y, size, size)) {
        g_imgui.hot_item = id;
        if (g_imgui.active_item == 0 && g_imgui.mouse_down) {
            g_imgui.active_item = id;
        }
    }
    
    // Toggle on click
    if (g_imgui.active_item == id && g_imgui.hot_item == id && g_imgui.mouse_clicked) {
        *checked = !(*checked);
        changed = 1;
    }
    
    // Box rajzolás
    HBRUSH brush = CreateSolidBrush(RGB(255, 255, 255));
    RECT rect = {x, y, x + size, y + size};
    FillRect(hdc, &rect, brush);
    DeleteObject(brush);
    
    HPEN pen = CreatePen(PS_SOLID, 1, RGB(120, 120, 120));
    HPEN oldPen = SelectObject(hdc, pen);
    Rectangle(hdc, x, y, x + size, y + size);
    SelectObject(hdc, oldPen);
    DeleteObject(pen);
    
    // Checkmark ha be van pipálva
    if (*checked) {
        HPEN checkPen = CreatePen(PS_SOLID, 2, RGB(0, 120, 0));
        oldPen = SelectObject(hdc, checkPen);
        
        MoveToEx(hdc, x + 3, y + size/2, NULL);
        LineTo(hdc, x + size/2, y + size - 3);
        LineTo(hdc, x + size - 3, y + 3);
        
        SelectObject(hdc, oldPen);
        DeleteObject(checkPen);
    }
    
    // Label
    SetBkMode(hdc, TRANSPARENT);
    TextOutA(hdc, x + size + 5, y + 2, label, strlen(label));
    
    return changed;
}
```

### 8.3 IMGUI Példa Alkalmazás

```c
#include <windows.h>

int slider_value = 50;
int checkbox1 = 0;
int checkbox2 = 1;
int button_click_count = 0;

LRESULT CALLBACK IMGUIWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    static int mouse_down = 0;
    
    switch (uMsg) {
        case WM_CREATE:
            imgui_init();
            return 0;
        
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
        
        case WM_LBUTTONDOWN:
            mouse_down = 1;
            InvalidateRect(hwnd, NULL, FALSE);
            return 0;
        
        case WM_LBUTTONUP:
            mouse_down = 0;
            InvalidateRect(hwnd, NULL, FALSE);
            return 0;
        
        case WM_MOUSEMOVE:
            if (mouse_down) {
                InvalidateRect(hwnd, NULL, FALSE);
            }
            return 0;
        
        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);
            
            // Háttér
            HBRUSH brush = CreateSolidBrush(RGB(240, 240, 240));
            FillRect(hdc, &ps.rcPaint, brush);
            DeleteObject(brush);
            
            // IMGUI frame kezdés
            POINT pt;
            GetCursorPos(&pt);
            ScreenToClient(hwnd, &pt);
            imgui_begin_frame(pt.x, pt.y, mouse_down);
            g_imgui.render_context = hdc;
            
            // UI kód - minden frame-ben lefut!
            imgui_label(20, 20, "Immediate Mode GUI Demo");
            
            // Gombok
            if (imgui_button(imgui_gen_id(), 20, 50, 150, 35, "Kattints rám!")) {
                button_click_count++;
            }
            
            char count_str[50];
            sprintf(count_str, "Kattintások: %d", button_click_count);
            imgui_label(20, 95, count_str);
            
            // Slider
            imgui_label(20, 130, "Slider:");
            if (imgui_slider(imgui_gen_id(), 20, 150, 200, 20, &slider_value, 0, 100)) {
                printf("Slider érték változott: %d\n", slider_value);
            }
            
            // Checkboxok
            imgui_checkbox(imgui_gen_id(), 20, 190, 20, "Első checkbox", &checkbox1);
            imgui_checkbox(imgui_gen_id(), 20, 220, 20, "Második checkbox", &checkbox2);
            
            // Dinamikus tartalom a slider értéke alapján
            imgui_label(20, 260, "Dinamikus tartalom:");
            for (int i = 0; i < slider_value / 10; i++) {
                imgui_button(imgui_gen_id(), 20 + i * 30, 290, 25, 25, "*");
            }
            
            // Frame vége
            imgui_end_frame();
            
            EndPaint(hwnd, &ps);
            return 0;
        }
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
```

### 8.4 Retained Mode vs IMGUI Összehasonlítás

| Szempont | Retained Mode | Immediate Mode |
|----------|---------------|----------------|
| Memória | Több (widgetek tárolása) | Kevesebb (nincs állapot) |
| Komplexitás | Nagyobb (event handling) | Egyszerűbb (lineáris kód) |
| Dinamikus UI | Nehezebb | Könnyebb |
| Teljesítmény | Jobb (csak változásnál rajzol) | Lassabb (minden frame) |
| Animációk | Támogatott | Természetes |
| Használat | Nagy alkalmazások | Eszközök, debug UI |

---

## 9. Fejezet: Platformfüggetlenség

Most nézzük meg, hogyan lehet a GUI kódot platformfüggetlenné tenni, mint a Qt vagy GTK.# GUI Programozás C Nyelvben: A Nullától a Szerkesztőig

## Teljes útmutató gyakorlati projektekkel

**Szerző:** Claude AI  
**Verzió:** 1.0  
**Dátum:** 2025. október

---

## Tartalomjegyzék

1. [Bevezetés](#bevezetés)
2. [1. Fejezet: Minimális Ablak + Event Loop](#1-fejezet-minimális-ablak--event-loop)
3. [2. Fejezet: Egyszerű Widget - Button](#2-fejezet-egyszerű-widget---button)
4. [3. Fejezet: Layout Manager](#3-fejezet-layout-manager)
5. [4. Fejezet: Szöveg Kirajzolás és Input Kezelés](#4-fejezet-szöveg-kirajzolás-és-input-kezelés)
6. [5. Fejezet: Event Bubbling és Capture](#5-fejezet-event-bubbling-és-capture)
7. [6. Fejezet: Render Backend](#6-fejezet-render-backend)
8. [7. Fejezet: Mini Designer](#7-fejezet-mini-designer)
9. [8. Fejezet: Immediate Mode GUI](#8-fejezet-immediate-mode-gui)
10. [9. Fejezet: Platformfüggetlenség](#9-fejezet-platformfüggetlenség)
11. [10. Fejezet: Binding Más Nyelvekhez](#10-fejezet-binding-más-nyelvekhez)

---

## Bevezetés

Ez a könyv végigvezet téged a grafikus felhasználói felületek (GUI) készítésének alapjaitól a professzionális szerkesztők megértéséig. Megtanulod:

- Hogyan működnek a modern GUI rendszerek belülről
- Hogyan készíthetsz saját komponenseket nulláról
- Hogyan készíthetsz vizuális GUI szerkesztőt (mint Android Studio vagy Eclipse)
- Hogyan teheted platformfüggetlenné a kódodat
- Hogyan kapcsolhatsz más nyelvekhez (C++, Java, Python)

### Előfeltételek

- Alapvető C programozási ismeretek
- Mutatók, struktúrák, dinamikus memóriakezelés ismerete
- Alapvető matematikai ismeretek (koordináta rendszer, geometria)

### Fejlesztői környezet

**Windows:**
- MinGW-w64 vagy Visual Studio
- GDI32 library

**Linux:**
- GCC
- X11 development libraries: `sudo apt-get install libx11-dev`

---

## 1. Fejezet: Minimális Ablak + Event Loop

### 1.1 Mi az a GUI?

A grafikus felhasználói felület (GUI) egy vizuális interfész, amely lehetővé teszi a felhasználók számára, hogy grafikus elemekkel (gombok, ablakok, menük) kommunikáljanak a programmal.

**Alapfogalmak:**
- **Ablak (Window):** A GUI alapegysége, egy téglalap alakú terület a képernyőn
- **Widget:** Újrafelhasználható UI komponens (gomb, szövegmező, stb.)
- **Event (Esemény):** Felhasználói akció (kattintás, billentyű lenyomás)
- **Event Loop:** A program fő ciklusa, amely folyamatosan figyeli az eseményeket

### 1.2 Windows Platform (Win32 API)

#### Alapfogalmak

- **HWND**: Ablak handle (azonosító)
- **MSG**: Üzenet struktúra
- **WNDCLASS**: Ablak osztály definíció
- **Message Loop**: Eseményciklus

#### Példakód: Minimális ablak Windowson

```c
#include <windows.h>
#include <stdio.h>

// Ablak üzenet-kezelő függvény (window procedure)
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_DESTROY:
            // Ablak bezárása
            PostQuitMessage(0);
            return 0;
        
        case WM_PAINT: {
            // Rajzolási esemény
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);
            
            // Kék háttér rajzolása
            HBRUSH brush = CreateSolidBrush(RGB(30, 144, 255));
            FillRect(hdc, &ps.rcPaint, brush);
            DeleteObject(brush);
            
            // Fehér vonal rajzolása
            HPEN pen = CreatePen(PS_SOLID, 3, RGB(255, 255, 255));
            HPEN oldPen = SelectObject(hdc, pen);
            MoveToEx(hdc, 50, 50, NULL);
            LineTo(hdc, 200, 150);
            SelectObject(hdc, oldPen);
            DeleteObject(pen);
            
            // Szöveg kiírása
            SetBkMode(hdc, TRANSPARENT);
            SetTextColor(hdc, RGB(255, 255, 255));
            TextOutA(hdc, 50, 200, "Első GUI ablak!", 15);
            
            EndPaint(hwnd, &ps);
            return 0;
        }
        
        case WM_LBUTTONDOWN: {
            // Bal egérgomb lenyomása
            int x = LOWORD(lParam);
            int y = HIWORD(lParam);
            char buffer[100];
            sprintf(buffer, "Kattintás: (%d, %d)", x, y);
            MessageBoxA(hwnd, buffer, "Esemény", MB_OK);
            return 0;
        }
        
        case WM_KEYDOWN: {
            // Billentyű lenyomása
            if (wParam == VK_ESCAPE) {
                PostQuitMessage(0);
            }
            return 0;
        }
    }
    
    // Alapértelmezett üzenet feldolgozás
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
                   LPSTR lpCmdLine, int nCmdShow) {
    const char CLASS_NAME[] = "MinimalWindowClass";
    
    // 1. Ablak osztály regisztrálása
    WNDCLASSA wc = {0};
    wc.lpfnWndProc = WindowProc;           // Üzenet kezelő függvény
    wc.hInstance = hInstance;              // Alkalmazás példány
    wc.lpszClassName = CLASS_NAME;         // Osztály név
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);  // Egér kurzor
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    
    if (!RegisterClassA(&wc)) {
        MessageBoxA(NULL, "Ablak osztály regisztrálása sikertelen!", "Hiba", MB_OK);
        return 0;
    }
    
    // 2. Ablak létrehozása
    HWND hwnd = CreateWindowExA(
        0,                              // Kiterjesztett stílusok
        CLASS_NAME,                     // Ablak osztály név
        "Első GUI Ablak",              // Ablak címe
        WS_OVERLAPPEDWINDOW,           // Ablak stílus
        CW_USEDEFAULT, CW_USEDEFAULT,  // Pozíció (x, y)
        640, 480,                      // Méret (szélesség, magasság)
        NULL,                          // Szülő ablak
        NULL,                          // Menü
        hInstance,                     // Alkalmazás példány
        NULL                           // További paraméterek
    );
    
    if (hwnd == NULL) {
        MessageBoxA(NULL, "Ablak létrehozása sikertelen!", "Hiba", MB_OK);
        return 0;
    }
    
    // 3. Ablak megjelenítése
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);
    
    // 4. Eseményciklus (Message Loop)
    MSG msg = {0};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);  // Billentyű üzenetek fordítása
        DispatchMessage(&msg);   // Üzenet továbbítása a WindowProc-hoz
    }
    
    return (int)msg.wParam;
}
```

**Fordítás:**
```bash
gcc minimal_window.c -o minimal_window.exe -lgdi32 -mwindows
```

**Vagy Visual Studio-ban:**
```bash
cl minimal_window.c user32.lib gdi32.lib
```

---

### 1.3 Linux Platform (X11)

Linuxon az X11 vagy Wayland rendszereket használjuk. Az X11 szélesebb körben támogatott.

#### X11 Alapfogalmak

- **Display**: Kapcsolat az X szerverrel
- **Window**: Ablak azonosító
- **GC (Graphics Context)**: Rajzolási kontextus
- **XEvent**: Esemény struktúra

#### Példakód: X11 ablak

```c
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    Display *display;
    Window window;
    XEvent event;
    int screen;
    
    // 1. X szerver kapcsolat megnyitása
    display = XOpenDisplay(NULL);
    if (display == NULL) {
        fprintf(stderr, "Nem lehet megnyitni az X display-t\n");
        exit(1);
    }
    
    screen = DefaultScreen(display);
    
    // 2. Ablak létrehozása
    window = XCreateSimpleWindow(
        display,
        RootWindow(display, screen),  // Szülő ablak
        100, 100,                     // Pozíció (x, y)
        640, 480,                     // Méret (szélesség, magasság)
        1,                            // Keret vastagság
        BlackPixel(display, screen),  // Keret szín
        WhitePixel(display, screen)   // Háttér szín
    );
    
    // 3. Esemény típusok regisztrálása
    XSelectInput(display, window, 
                 ExposureMask | KeyPressMask | ButtonPressMask | 
                 StructureNotifyMask);
    
    // 4. Ablak megjelenítése
    XMapWindow(display, window);
    
    // 5. Ablak cím beállítása
    XStoreName(display, window, "Első X11 Ablak");
    
    // 6. Ablak bezárás kezelése (WM_DELETE_WINDOW)
    Atom wmDeleteMessage = XInternAtom(display, "WM_DELETE_WINDOW", False);
    XSetWMProtocols(display, window, &wmDeleteMessage, 1);
    
    // 7. Eseményciklus
    int running = 1;
    while (running) {
        XNextEvent(display, &event);
        
        switch (event.type) {
            case Expose: {
                // Újrarajzolás szükséges
                if (event.xexpose.count == 0) {
                    // Graphics Context létrehozása
                    GC gc = XCreateGC(display, window, 0, NULL);
                    
                    // Kék háttér
                    XSetForeground(display, gc, 0x1E90FF);
                    XFillRectangle(display, window, gc, 0, 0, 640, 480);
                    
                    // Fehér vonal
                    XSetForeground(display, gc, 0xFFFFFF);
                    XSetLineAttributes(display, gc, 3, LineSolid, 
                                       CapRound, JoinRound);
                    XDrawLine(display, window, gc, 50, 50, 200, 150);
                    
                    // Szöveg kiírása
                    XDrawString(display, window, gc, 50, 200, 
                                "Első X11 ablak!", 16);
                    
                    XFreeGC(display, gc);
                }
                break;
            }
            
            case ButtonPress: {
                // Egér kattintás
                printf("Egér kattintás: (%d, %d) gomb: %d\n", 
                       event.xbutton.x, event.xbutton.y, 
                       event.xbutton.button);
                break;
            }
            
            case KeyPress: {
                // Billentyű lenyomása
                char buffer[32];
                KeySym keysym;
                int len = XLookupString(&event.xkey, buffer, 
                                        sizeof(buffer), &keysym, NULL);
                if (len > 0) {
                    printf("Billentyű: %s\n", buffer);
                }
                if (keysym == XK_Escape) {
                    running = 0;
                }
                break;
            }
            
            case ClientMessage: {
                // Ablak bezárás kérés
                if (event.xclient.data.l[0] == wmDeleteMessage) {
                    running = 0;
                }
                break;
            }
        }
    }
    
    // 8. Takarítás
    XDestroyWindow(display, window);
    XCloseDisplay(display);
    
    return 0;
}
```

**Fordítás:**
```bash
gcc minimal_window_x11.c -o minimal_window_x11 -lX11
```

**Telepítés (ha szükséges):**
```bash
# Ubuntu/Debian
sudo apt-get install libx11-dev

# Fedora/RHEL
sudo dnf install libX11-devel
```

---

### 1.4 Eseményciklus Mélyebb Megértése

Az eseményciklus a GUI programok szíve. Folyamatosan figyeli az operációs rendszer üzeneteit.

#### Eseménytípusok

1. **Input események**: egér mozgás, kattintás, billentyűzet
2. **Ablakesemények**: méretezés, mozgatás, bezárás, minimalizálás
3. **Rajzolási események**: újrarajzolás szükséges (WM_PAINT, Expose)
4. **Timer események**: időzített akciók
5. **Custom események**: saját üzenetek

#### Saját Eseménykezelő Rendszer

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Esemény típusok
typedef enum {
    EVENT_NONE,
    EVENT_MOUSE_DOWN,
    EVENT_MOUSE_UP,
    EVENT_MOUSE_MOVE,
    EVENT_KEY_DOWN,
    EVENT_KEY_UP,
    EVENT_PAINT,
    EVENT_QUIT
} EventType;

// Esemény struktúra
typedef struct {
    EventType type;
    int x, y;           // egér koordináták
    int button;         // egér gomb (1=bal, 2=közép, 3=jobb)
    char key;           // billentyű karakter
    int keycode;        // billentyű kód
    void *user_data;    // extra adat
} Event;

// Callback függvény típus
typedef void (*EventCallback)(Event *event);

// Eseményfigyelő
typedef struct EventListener {
    EventType type;
    EventCallback callback;
    void *user_data;
    struct EventListener *next;
} EventListener;

// Eseményrendszer
typedef struct {
    EventListener *listeners;
    Event event_queue[100];
    int queue_size;
    int running;
} EventSystem;

// Eseményrendszer inicializálása
void event_system_init(EventSystem *es) {
    es->listeners = NULL;
    es->queue_size = 0;
    es->running = 1;
}

// Eseményfigyelő hozzáadása
void event_add_listener(EventSystem *es, EventType type, 
                       EventCallback callback, void *user_data) {
    EventListener *listener = malloc(sizeof(EventListener));
    listener->type = type;
    listener->callback = callback;
    listener->user_data = user_data;
    listener->next = es->listeners;
    es->listeners = listener;
}

// Esemény küldése a sorba
void event_push(EventSystem *es, Event *event) {
    if (es->queue_size < 100) {
        es->event_queue[es->queue_size++] = *event;
    } else {
        fprintf(stderr, "Figyelmeztetés: Esemény sor megtelt!\n");
    }
}

// Események feldolgozása
void event_process(EventSystem *es) {
    for (int i = 0; i < es->queue_size; i++) {
        Event *event = &es->event_queue[i];
        
        // Végigmegyünk az összes figyelőn
        EventListener *listener = es->listeners;
        while (listener != NULL) {
            // Ha a típus egyezik vagy EVENT_NONE (minden esemény)
            if (listener->type == event->type || listener->type == EVENT_NONE) {
                listener->callback(event);
            }
            listener = listener->next;
        }
        
        // QUIT esemény kezelése
        if (event->type == EVENT_QUIT) {
            es->running = 0;
        }
    }
    
    // Sor ürítése
    es->queue_size = 0;
}

// Tisztítás
void event_system_cleanup(EventSystem *es) {
    EventListener *current = es->listeners;
    while (current != NULL) {
        EventListener *next = current->next;
        free(current);
        current = next;
    }
    es->listeners = NULL;
}

// Példa callback függvények
void on_mouse_down(Event *e) {
    printf("Egér lenyomva: (%d, %d) gomb: %d\n", e->x, e->y, e->button);
}

void on_mouse_move(Event *e) {
    printf("Egér mozgás: (%d, %d)\n", e->x, e->y);
}

void on_key_down(Event *e) {
    printf("Billentyű lenyomva: '%c' (kód: %d)\n", e->key, e->keycode);
}

void on_any_event(Event *e) {
    printf("Esemény történt: típus=%d\n", e->type);
}

// Használat példa
int main() {
    EventSystem es;
    event_system_init(&es);
    
    // Figyelők regisztrálása
    event_add_listener(&es, EVENT_MOUSE_DOWN, on_mouse_down, NULL);
    event_add_listener(&es, EVENT_MOUSE_MOVE, on_mouse_move, NULL);
    event_add_listener(&es, EVENT_KEY_DOWN, on_key_down, NULL);
    event_add_listener(&es, EVENT_NONE, on_any_event, NULL);  // Minden esemény
    
    // Események szimulálása
    Event e1 = {EVENT_MOUSE_DOWN, 100, 150, 1, 0, 0, NULL};
    Event e2 = {EVENT_MOUSE_MOVE, 105, 155, 0, 0, 0, NULL};
    Event e3 = {EVENT_KEY_DOWN, 0, 0, 0, 'A', 65, NULL};
    Event e4 = {EVENT_QUIT, 0, 0, 0, 0, 0, NULL};
    
    event_push(&es, &e1);
    event_push(&es, &e2);
    event_push(&es, &e3);
    event_push(&es, &e4);
    
    // Feldolgozás
    event_process(&es);
    
    printf("Rendszer fut: %d\n", es.running);
    
    // Takarítás
    event_system_cleanup(&es);
    
    return 0;
}
```

---

## 2. Fejezet: Egyszerű Widget - Button

Most készítünk egy működő gombot, amely reagál az egér eseményekre és különböző állapotokban jelenik meg.

### 2.1 Widget Alapstruktúra

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Téglalap struktúra
typedef struct {
    int x, y;           // pozíció
    int width, height;  // méret
} Rect;

// Gomb állapotok
typedef enum {
    BUTTON_STATE_NORMAL,
    BUTTON_STATE_HOVER,
    BUTTON_STATE_PRESSED,
    BUTTON_STATE_DISABLED
} ButtonState;

// Gomb struktúra
typedef struct Button {
    Rect bounds;
    char label[64];
    ButtonState state;
    void (*on_click)(struct Button *btn);
    void *user_data;
} Button;

// Hit test - benne van-e a pont a gombban
int button_contains(Button *btn, int x, int y) {
    return x >= btn->bounds.x && 
           x <= btn->bounds.x + btn->bounds.width &&
           y >= btn->bounds.y && 
           y <= btn->bounds.y + btn->bounds.height;
}

// Téglalap-téglalap ütközés vizsgálat
int rect_intersects(Rect *r1, Rect *r2) {
    return !(r2->x > r1->x + r1->width ||
             r2->x + r2->width < r1->x ||
             r2->y > r1->y + r1->height ||
             r2->y + r2->height < r1->y);
}

// Eseménykezelés - egér mozgás
void button_on_mouse_move(Button *btn, int x, int y) {
    if (btn->state == BUTTON_STATE_DISABLED) return;
    
    if (button_contains(btn, x, y)) {
        if (btn->state == BUTTON_STATE_NORMAL) {
            btn->state = BUTTON_STATE_HOVER;
            printf("Gomb hover: %s\n", btn->label);
        }
    } else {
        if (btn->state == BUTTON_STATE_HOVER) {
            btn->state = BUTTON_STATE_NORMAL;
        }
    }
}

// Eseménykezelés - egér lenyomás
void button_on_mouse_down(Button *btn, int x, int y) {
    if (btn->state == BUTTON_STATE_DISABLED) return;
    
    if (button_contains(btn, x, y)) {
        btn->state = BUTTON_STATE_PRESSED;
        printf("Gomb lenyomva: %s\n", btn->label);
    }
}

// Eseménykezelés - egér felengedés
void button_on_mouse_up(Button *btn, int x, int y) {
    if (btn->state == BUTTON_STATE_DISABLED) return;
    
    if (btn->state == BUTTON_STATE_PRESSED) {
        if (button_contains(btn, x, y)) {
            printf("Gomb kattintás: %s\n", btn->label);
            // Callback hívása
            if (btn->on_click) {
                btn->on_click(btn);
            }
        }
        btn->state = button_contains(btn, x, y) ? 
                     BUTTON_STATE_HOVER : BUTTON_STATE_NORMAL;
    }
}

// Gomb létrehozása
Button* button_create(int x, int y, int w, int h, const char *label) {
    Button *btn = malloc(sizeof(Button));
    btn->bounds.x = x;
    btn->bounds.y = y;
    btn->bounds.width = w;
    btn->bounds.height = h;
    strncpy(btn->label, label, 63);
    btn->label[63] = '\0';
    btn->state = BUTTON_STATE_NORMAL;
    btn->on_click = NULL;
    btn->user_data = NULL;
    return btn;
}

// Gomb felszabadítása
void button_destroy(Button *btn) {
    free(btn);
}
```

### 2.2 Button Rajzolás Windows GDI-vel

```c
#include <windows.h>

void button_draw(Button *btn, HDC hdc) {
    COLORREF bg_color, text_color, border_color;
    
    // Színek állapot szerint
    switch (btn->state) {
        case BUTTON_STATE_NORMAL:
            bg_color = RGB(225, 225, 225);
            text_color = RGB(0, 0, 0);
            border_color = RGB(120, 120, 120);
            break;
        case BUTTON_STATE_HOVER:
            bg_color = RGB(229, 241, 251);
            text_color = RGB(0, 0, 0);
            border_color = RGB(0, 120, 215);
            break;
        case BUTTON_STATE_PRESSED:
            bg_color = RGB(204, 228, 247);
            text_color = RGB(0, 0, 0);
            border_color = RGB(0, 84, 153);
            break;
        case BUTTON_STATE_DISABLED:
            bg_color = RGB(240, 240, 240);
            text_color = RGB(160, 160, 160);
            border_color = RGB(180, 180, 180);
            break;
    }
    
    // Háttér rajzolása
    HBRUSH brush = CreateSolidBrush(bg_color);
    RECT rect = {btn->bounds.x, btn->bounds.y, 
                 btn->bounds.x + btn->bounds.width, 
                 btn->bounds.y + btn->bounds.height};
    FillRect(hdc, &rect, brush);
    DeleteObject(brush);
    
    // Keret rajzolása
    HPEN pen = CreatePen(PS_SOLID, 1, border_color);
    HPEN oldPen = SelectObject(hdc, pen);
    
    MoveToEx(hdc, btn->bounds.x, btn->bounds.y, NULL);
    LineTo(hdc, btn->bounds.x + btn->bounds.width, btn->bounds.y);
    LineTo(hdc, btn->bounds.x + btn->bounds.width, 
           btn->bounds.y + btn->bounds.height);
    LineTo(hdc, btn->bounds.x, btn->bounds.y + btn->bounds.height);
    LineTo(hdc, btn->bounds.x, btn->bounds.y);
    
    SelectObject(hdc, oldPen);
    DeleteObject(pen);
    
    // Szöveg rajzolása
    SetBkMode(hdc, TRANSPARENT);
    SetTextColor(hdc, text_color);
    
    // Font létrehozása
    HFONT font = CreateFontA(
        16, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE,
        DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
        CLEARTYPE_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Segoe UI"
    );
    HFONT oldFont = SelectObject(hdc, font);
    
    DrawTextA(hdc, btn->label, -1, &rect, 
              DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    
    SelectObject(hdc, oldFont);
    DeleteObject(font);
}
```

### 2.3 Button Rajzolás X11-gyel

```c
#include <X11/Xlib.h>

void button_draw_x11(Button *btn, Display *display, Window window, GC gc) {
    unsigned long bg_color, text_color, border_color;
    
    // Színek állapot szerint (RGB hex)
    switch (btn->state) {
        case BUTTON_STATE_NORMAL:
            bg_color = 0xE1E1E1;
            text_color = 0x000000;
            border_color = 0x787878;
            break;
        case BUTTON_STATE_HOVER:
            bg_color = 0xE5F1FB;
            text_color = 0x000000;
            border_color = 0x0078D7;
            break;
        case BUTTON_STATE_PRESSED:
            bg_color = 0xCCE4F7;
            text_color = 0x000000;
            border_color = 0x005499;
            break;
        case BUTTON_STATE_DISABLED:
            bg_color = 0xF0F0F0;
            text_color = 0xA0A0A0;
            border_color = 0xB4B4B4;
            break;
    }
    
    // Háttér
    XSetForeground(display, gc, bg_color);
    XFillRectangle(display, window, gc, 
                   btn->bounds.x, btn->bounds.y, 
                   btn->bounds.width, btn->bounds.height);
    
    // Keret
    XSetForeground(display, gc, border_color);
    XDrawRectangle(display, window, gc, 
                   btn->bounds.x, btn->bounds.y, 
                   btn->bounds.width, btn->bounds.height);
    
    // Szöveg (középre igazítva)
    XSetForeground(display, gc, text_color);
    int text_len = strlen(btn->label);
    
    // Szöveg méretének becslése (egyszerűsített)
    int text_width = text_len * 7;  // ~7 pixel per karakter
    int text_height = 14;
    
    int text_x = btn->bounds.x + (btn->bounds.width - text_width) / 2;
    int text_y = btn->bounds.y + (btn->bounds.height + text_height) / 2;
    
    XDrawString(display, window, gc, text_x, text_y, 
                btn->label, text_len);
}
```

### 2.4 Teljes Példa - Működő Gombok Windowson

```c
#include <windows.h>
#include <stdio.h>

// ... (Button struktúra és függvények a fenti kódból) ...

Button *btn1, *btn2, *btn3;
int click_count = 0;

// Callback függvények
void on_button1_click(Button *btn) {
    click_count++;
    char msg[100];
    sprintf(msg, "Gomb 1 kattintva! Összesen: %d", click_count);
    MessageBoxA(NULL, msg, "Info", MB_OK);
}

void on_button2_click(Button *btn) {
    MessageBoxA(NULL, "Gomb 2 kattintva!", "Info", MB_OK);
}

void on_button3_click(Button *btn) {
    // Gomb 1 állapotának váltása
    if (btn1->state == BUTTON_STATE_DISABLED) {
        btn1->state = BUTTON_STATE_NORMAL;
        strcpy(btn->label, "Letiltás");
    } else {
        btn1->state = BUTTON_STATE_DISABLED;
        strcpy(btn->label, "Engedélyezés");
    }
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_CREATE:
            // Gombok létrehozása
            btn1 = button_create(50, 50, 150, 40, "Kattints rám!");
            btn1->on_click = on_button1_click;
            
            btn2 = button_create(50, 110, 150, 40, "Második gomb");
            btn2->on_click = on_button2_click;
            
            btn3 = button_create(50, 170, 150, 40, "Letiltás");
            btn3->on_click = on_button3_click;
            return 0;
        
        case WM_DESTROY:
            // Takarítás
            button_destroy(btn1);
            button_destroy(btn2);
            button_destroy(btn3);
            PostQuitMessage(0);
            return 0;
        
        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);
            
            // Fehér háttér
            HBRUSH brush = CreateSolidBrush(RGB(255, 255, 255));
            FillRect(hdc, &ps.rcPaint, brush);
            DeleteObject(brush);
            
            // Gombok rajzolása
            button_draw(btn1, hdc);
            button_draw(btn2, hdc);
            button_draw(btn3, hdc);
            
            // Számláló kiírása
            char buffer[50];
            sprintf(buffer, "Kattintások: %d", click_count);
            SetBkMode(hdc, TRANSPARENT);
            TextOutA(hdc, 50, 230, buffer, strlen(buffer));
            
            EndPaint(hwnd, &ps);
            return 0;
        }
        
        case WM_MOUSEMOVE: {
            int x = LOWORD(lParam);
            int y = HIWORD(lParam);
            button_on_mouse_move(btn1, x, y);
            button_on_mouse_move(btn2, x, y);
            button_on_mouse_move(btn3, x, y);
            InvalidateRect(hwnd, NULL, FALSE);
            return 0;
        }
        
        case WM_LBUTTONDOWN: {
            int x = LOWORD(lParam);
            int y = HIWORD(lParam);
            button_on_mouse_down(btn1, x, y);
            button_on_mouse_down(btn2, x, y);
            button_on_mouse_down(btn3, x, y);
            InvalidateRect(hwnd, NULL, FALSE);
            return 0;
        }
        
        case WM_LBUTTONUP: {
            int x = LOWORD(lParam);
            int y = HIWORD(lParam);
            button_on_mouse_up(btn1, x, y);
            button_on_mouse_up(btn2, x, y);
            button_on_mouse_up(btn3, x, y);
            InvalidateRect(hwnd, NULL, FALSE);
            return 0;
        }
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nCmdShow) {
    const char CLASS_NAME[] = "ButtonExampleClass";
    
    WNDCLASSA wc = {0};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    
    RegisterClassA(&wc);
    
    HWND hwnd = CreateWindowExA(
        0, CLASS_NAME, "Gomb Példa",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 400, 350,
        NULL, NULL, hInstance, NULL
    );
    
    if (!hwnd) return 0;
    
    ShowWindow(hwnd, nCmdShow);
    
    MSG msg = {0};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    
    return 0;
}
```

---

## 3. Fejezet: Layout Manager

A layout managerek automatikusan pozícionálják a widgeteket. Készítünk egy egyszerű vertical és horizontal layout kezelőt.

### 3.1 Layout Alapok

A layout manager felelősségei:
- Widgetek automatikus elhelyezése
- Méret újraszámítás ablak átméretezésekor
- Spacing (távolság) és padding (belső margó) kezelése

#### Layout típusok

1. **Vertical Layout**: Függőleges elrendezés (egymás alatt)
2. **Horizontal Layout**: Vízszintes elrendezés (egymás mellett)
3. **Grid Layout**: Rácsos elrendezés (táblázat)
4. **Absolute Layout**: Abszolút pozíció (manuális)

### 3.2 Layout Implementáció

```c
#include <stdio.h>
#include <stdlib.h>

typedef enum {
    LAYOUT_VERTICAL,
    LAYOUT_HORIZONTAL,
    LAYOUT_GRID
} LayoutType;

// Általános widget struktúra
typedef struct Widget {
    Rect bounds;
    void (*draw)(struct Widget *w, void *context);
    void (*on_mouse_down)(struct Widget *w, int x, int y);
    void (*on_mouse_up)(struct Widget *w, int x, int y);
    void (*on_mouse_move)(struct Widget *w, int x, int y);
    void *user_data;
    int min_width, min_height;   // Minimális méret
    int max_width, max_height;   // Maximális méret
    float weight;                 // Súly (flex layout esetén)
} Widget;

// Layout struktúra
typedef struct {
    LayoutType type;
    Rect bounds;
    Widget **children;
    int child_count;
    int capacity;
    int spacing;        // távolság a widgetek között
    int padding;        // belső margó
    int grid_cols;      // grid esetén oszlopok száma
} Layout;

// Layout létrehozása
Layout* layout_create(LayoutType type, int x, int y, int w, int h) {
    Layout *layout = malloc(sizeof(Layout));
    layout->type = type;
    layout->bounds.x = x;
    layout->bounds.y = y;
    layout->bounds.width = w;
    layout->bounds.height = h;
    layout->children = malloc(sizeof(Widget*) * 10);
    layout->child_count = 0;
    layout->capacity = 10;
    layout->spacing = 5;
    layout->padding = 10;
    layout->grid_cols = 2;
    return layout;
}

// Widget hozzáadása
void layout_add_widget(Layout *layout, Widget *widget) {
    if (layout->child_count >= layout->capacity) {
        layout->capacity *= 2;
        layout->children = realloc(layout->children, 
                                   sizeof(Widget*) * layout->capacity);
    }
    layout->children[layout->child_count++] = widget;
}

// Widget eltávolítása
void layout_remove_widget(Layout *layout, Widget *widget) {
    for (int i = 0; i < layout->child_count; i++) {
        if (layout->children[i] == widget) {
            // Eltolás
            for (int j = i; j < layout->child_count - 1; j++) {
                layout->children[j] = layout->children[j + 1];
            }
            layout->child_count--;
            return;
        }
    }
}

// Vertical layout számítás
void layout_calculate_vertical(Layout *layout) {
    if (layout->child_count == 0) return;
    
    int available_width = layout->bounds.width - 2 * layout->padding;
    int available_height = layout->bounds.height - 2 * layout->padding;
    
    // Spacing levonása
    int total_spacing = (layout->child_count - 1) * layout->spacing;
    available_height -= total_spacing;
    
    // Súlyok összege
    float total_weight = 0;
    for (int i = 0; i < layout->child_count; i++) {
        total_weight += layout->children[i]->weight;
    }
    
    if (total_weight == 0) total_weight = layout->child_count;
    
    // Widgetek elhelyezése
    int current_y = layout->bounds.y + layout->padding;
    
    for (int i = 0; i < layout->child_count; i++) {
        Widget *w = layout->children[i];
        float weight = w->weight > 0 ? w->weight : 1.0f;
        
        int widget_height = (int)(available_height * weight / total_weight);
        
        // Határok ellenőrzése
        if (w->min_height > 0 && widget_height < w->min_height) {
            widget_height = w->min_height;
        }
        if (w->max_height > 0 && widget_height > w->max_height) {
            widget_height = w->max_height;
        }
        
        w->bounds.x = layout->bounds.x + layout->padding;
        w->bounds.y = current_y;
        w->bounds.width = available_width;
        w->bounds.height = widget_height;
        
        current_y += widget_height + layout->spacing;
    }
}

// Horizontal layout számítás
void layout_calculate_horizontal(Layout *layout) {
    if (layout->child_count == 0) return;
    
    int available_width = layout->bounds.width - 2 * layout->padding;
    int available_height = layout->bounds.height - 2 * layout->padding;
    
    int total_spacing = (layout->child_count - 1) * layout->spacing;
    available_width -= total_spacing;
    
    float total_weight = 0;
    for (int i = 0; i < layout->child_count; i++) {
        total_weight += layout->children[i]->weight;
    }
    
    if (total_weight == 0) total_weight = layout->child_count;
    
    int current_x = layout->bounds.x + layout->padding;
    
    for (int i = 0; i < layout->child_count; i++) {
        Widget *w = layout->children[i];
        float weight = w->weight > 0 ? w->weight : 1.0f;
        
        int widget_width = (int)(available_width * weight / total_weight);
        
        if (w->min_width > 0 && widget_width < w->min_width) {
            widget_width = w->min_width;
        }
        if (w->max_width > 0 && widget_width > w->max_width) {
            widget_width = w->max_width;
        }
        
        w->bounds.x = current_x;
        w->bounds.y = layout->bounds.y + layout->padding;
        w->bounds.width = widget_width;
        w->bounds.height = available_height;
        
        current_x += widget_width + layout->spacing;
    }
}

// Grid layout számítás
void layout_calculate_grid(Layout *layout) {
    if (layout->child_count == 0) return;
    
    int cols = layout->grid_cols;
    int rows = (layout->child_count + cols - 1) / cols;  // Kerekítés felfelé
    
    int available_width = layout->bounds.width - 2 * layout->padding;
    int available_height = layout->bounds.height - 2 * layout->padding;
    
    int total_h_spacing = (cols - 1) * layout->spacing;
    int total_v_spacing = (rows - 1) * layout->spacing;
    
    int cell_width = (available_width - total_h_spacing) / cols;
    int cell_height = (available_height - total_v_spacing) / rows;
    
    for (int i = 0; i < layout->child_count; i++) {
        Widget *w = layout->children[i];
        
        int row = i / cols;
        int col = i % cols;
        
        w->bounds.x = layout->bounds.x + layout->padding + 
                      col * (cell_width + layout->spacing);
        w->bounds.y = layout->bounds.y + layout->padding + 
                      row * (cell_height + layout->spacing);
        w->bounds.width = cell_width;
        w->bounds.height = cell_height;
    }
}

// Layout újraszámolása
void layout_recalculate(Layout *layout) {
    switch (layout->type) {
        case LAYOUT_VERTICAL:
            layout_calculate_vertical(layout);
            break;
        case LAYOUT_HORIZONTAL:
            layout_calculate_horizontal(layout);
            break;
        case LAYOUT_GRID:
            layout_calculate_grid(layout);
            break;
    }
}

// Összes widget kirajzolása
void layout_draw(Layout *layout, void *context) {
    for (int i = 0; i < layout->child_count; i++) {
        if (layout->children[i]->draw) {
            layout->children[i]->draw(layout->children[i], context);
        }
    }
}

// Egér esemény továbbítás
void layout_on_mouse_down(Layout *layout, int x, int y) {
    for (int i = 0; i < layout->child_count; i++) {
        Widget *w = layout->children[i];
        if (w->on_mouse_down) {
            w->on_mouse_down(w, x, y);
        }
    }
}

void layout_on_mouse_up(Layout *layout, int x, int y) {
    for (int i = 0; i < layout->child_count; i++) {
        Widget *w = layout->children[i];
        if (w->on_mouse_up) {
            w->on_mouse_up(w, x, y);
        }
    }
}

void layout_on_mouse_move(Layout *layout, int x, int y) {
    for (int i = 0; i < layout->child_count; i++) {
        Widget *w = layout->children[i];
        if (w->on_mouse_move) {
            w->on_mouse_move(w, x, y);
        }
    }
}

// Takarítás
void layout_destroy(Layout *layout) {
    free(layout->children);
    free(layout);
}
```

### 3.3 Widget Wrapper Buttonnál

```c
// Button widget wrapperek
void widget_button_draw(Widget *w, void *context) {
    HDC hdc = (HDC)context;
    Button *btn = (Button*)w->user_data;
    btn->bounds = w->bounds;
    button_draw(btn, hdc);
}

void widget_button_mouse_down(Widget *w, int x, int y) {
    Button *btn = (Button*)w->user_data;
    button_on_mouse_down(btn, x, y);
}

void widget_button_mouse_up(Widget *w, int x, int y) {
    Button *btn = (Button*)w->user_data;
    button_on_mouse_up(btn, x, y);
}

void widget_button_mouse_move(Widget *w, int x, int y) {
    Button *btn = (Button*)w->user_data;
    button_on_mouse_move(btn, x, y);
}

Widget* widget_from_button(Button *btn) {
    Widget *w = malloc(sizeof(Widget));
    w->bounds = btn->bounds;
    w->draw = widget_button_draw;
    w->on_mouse_down = widget_button_mouse_down;
    w->on_mouse_up = widget_button_mouse_up;
    w->on_mouse_move = widget_button_mouse_move;
    w->user_data = btn;
    w->min_width = 0;
    w->min_height = 0;
    w->max_width = 0;
    w->max_height = 0;
    w->weight = 1.0f;
    return w;
}
```

### 3.4 Teljes Példa Layout-tal

```c
#include <windows.h>

Layout *main_layout;

void on_button_click(Button *btn) {
    char msg[100];
    sprintf(msg, "Gomb kattintva: %s", btn->label);
    MessageBoxA(NULL, msg, "Info", MB_OK);
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_CREATE: {
            // Vertical layout létrehozása
            main_layout = layout_create(LAYOUT_VERTICAL, 10, 10, 380, 460);
            main_layout->spacing = 10;
            main_layout->padding = 15;
            
            // Gombok létrehozása és hozzáadása
            const char *labels[] = {
                "Első gomb", "Második gomb", "Harmadik gomb",
                "Negyedik gomb", "Ötödik gomb"
            };
            
            for (int i = 0; i < 5; i++) {
                Button *btn = button_create(0, 0, 0, 0, labels[i]);
                btn->on_click = on_button_click;
                
                Widget *w = widget_from_button(btn);
                w->weight = (i == 2) ? 2.0f : 1.0f;  // Harmadik gomb kétszer nagyobb
                
                layout_add_widget(main_layout, w);
            }
            
            layout_recalculate(main_layout);
            return 0;
        }
        
        case WM_SIZE: {
            // Ablak méret változásakor
            RECT rect;
            GetClientRect(hwnd, &rect);
            main_layout->bounds.width = rect.right - 20;
            main_layout->bounds.height = rect.bottom - 20;
            layout_recalculate(main_layout);
            InvalidateRect(hwnd, NULL, FALSE);
            return 0;
        }
        
        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);
            
            // Háttér
            HBRUSH brush = CreateSolidBrush(RGB(240, 240, 240));
            FillRect(hdc, &ps.rcPaint, brush);
            DeleteObject(brush);
            
            // Layout kirajzolása
            layout_draw(main_layout, hdc);
            
            EndPaint(hwnd, &ps);
            return 0;
        }
        
        case WM_MOUSEMOVE: {
            int x = LOWORD(lParam);
            int y = HIWORD(lParam);
            layout_on_mouse_move(main_layout, x, y);
            InvalidateRect(hwnd, NULL, FALSE);
            return 0;
        }
        
        case WM_LBUTTONDOWN: {
            int x = LOWORD(lParam);
            int y = HIWORD(lParam);
            layout_on_mouse_down(main_layout, x, y);
            InvalidateRect(hwnd, NULL, FALSE);
            return 0;
        }
        
        case WM_LBUTTONUP: {
            int x = LOWORD(lParam);
            int y = HIWORD(lParam);
            layout_on_mouse_up(main_layout, x, y);
            InvalidateRect(hwnd, NULL, FALSE);
            return 0;
        }
        
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
```

---

## 4. Fejezet: Szöveg Kirajzolás és Input Kezelés

Most készítünk egy text input mezőt, amely kezeli a fókuszt és a billentyűzet bevitelt.

### 4.1 TextBox Widget

```c
#include <string.h>
#include <ctype.h>

typedef struct {
    Rect bounds;
    char text[256];
    int cursor_pos;
    int has_focus;
    int max_length;
    int selection_start;
    int selection_end;
} TextBox;

// TextBox létrehozása
TextBox* textbox_create(int x, int y, int w, int h) {
    TextBox *tb = malloc(sizeof(TextBox));
    tb->bounds.x = x;
    tb->bounds.y = y;
    tb->bounds.width = w;
    tb->bounds.height = h;
    tb->text[0] = '\0';
    tb->cursor_pos = 0;
    tb->has_focus = 0;
    tb->max_length = 255;
    tb->selection_start = -1;
    tb->selection_end = -1;
    return tb;
}

// Hit test
int textbox_contains(TextBox *tb, int x, int y) {
    return x >= tb->bounds.x && 
           x <= tb->bounds.x + tb->bounds.width &&
           y >= tb->bounds.y && 
           y <= tb->bounds.y + tb->bounds.height;
}

// Kattintás kezelése (fókusz)
void textbox_on_mouse_down(TextBox *tb, int x, int y) {
    tb->has_focus = textbox_contains(tb, x, y);
    if (tb->has_focus) {
        printf("TextBox fókusz kapott\n");
    }
}

// Karakter hozzáadása
void textbox_add_char(TextBox *tb, char c) {
    if (!tb->has_focus) return;
    
    int len = strlen(tb->text);
    if (len >= tb->max_length) return;
    
    // Nyomtatható karakter ellenőrzése
    if (isprint(c)) {
        // Beszúrás a kurzor pozíciójára
        memmove(&tb->text[tb->cursor_pos + 1], 
                &tb->text[tb->cursor_pos], 
                len - tb->cursor_pos + 1);
        tb->text[tb->cursor_pos] = c;
        tb->cursor_pos++;
    }
}

// Backspace kezelése
void textbox_backspace(TextBox *tb) {
    if (!tb->has_focus || tb->cursor_pos == 0) return;
    
    int len = strlen(tb->text);
    memmove(&tb->text[tb->cursor_pos - 1], 
            &tb->text[tb->cursor_pos], 
            len - tb->cursor_pos + 1);
    tb->cursor_pos--;
}

// Delete kezelése
void textbox_delete(TextBox *tb) {
    if (!tb->has_focus) return;
    
    int len = strlen(tb->text);
    if (tb->cursor_pos >= len) return;
    
    memmove(&tb->text[tb->cursor_pos], 
            &tb->text[tb->cursor_pos + 1], 
            len - tb->cursor_pos);
}

// Kurzor mozgatás
void textbox_move_cursor(TextBox *tb, int direction) {
    if (!tb->has_focus) return;
    
    int len = strlen(tb->text);
    tb->cursor_pos += direction;
    
    if (tb->cursor_pos < 0) tb->cursor_pos = 0;
    if (tb->cursor_pos > len) tb->cursor_pos = len;
}

// Home/End
void textbox_cursor_home(TextBox *tb) {
    if (tb->has_focus) tb->cursor_pos = 0;
}

void textbox_cursor_end(TextBox *tb) {
    if (tb->has_focus) tb->cursor_pos = strlen(tb->text);
}

// Billentyűzet esemény kezelése
void textbox_on_key(TextBox *tb, int key, int is_special) {
    if (!tb->has_focus) return;
    
    if (is_special) {
        // Speciális billentyűk (nyilak, backspace, delete, stb.)
        switch (key) {
            case VK_LEFT:
                textbox_move_cursor(tb, -1);
                break;
            case VK_RIGHT:
                textbox_move_cursor(tb, 1);
                break;
            case VK_HOME:
                textbox_cursor_home(tb);
                break;
            case VK_END:
                textbox_cursor_end(tb);
                break;
            case VK_BACK:
                textbox_backspace(tb);
                break;
            case VK_DELETE:
                textbox_delete(tb);
                break;
        }
    } else {
        // Normál karakter
        textbox_add_char(tb, (char)key);
    }
}
```

### 4.2 TextBox Rajzolás Windows GDI

```c
#include <windows.h>

void textbox_draw(TextBox *tb, HDC hdc) {
    // Színek
    COLORREF bg_color = RGB(255, 255, 255);
    COLORREF border_color = tb->has_focus ? RGB(0, 120, 215) : RGB(120, 120, 120);
    COLORREF text_color = RGB(0, 0, 0);
    COLORREF cursor_color = RGB(0, 0, 0);
    
    // Háttér
    HBRUSH brush = CreateSolidBrush(bg_color);
    RECT rect = {tb->bounds.x, tb->bounds.y,
                 tb->bounds.x + tb->bounds.width,
                 tb->bounds.y + tb->bounds.height};
    FillRect(hdc, &rect, brush);
    DeleteObject(brush);
    
    // Keret
    HPEN pen = CreatePen(PS_SOLID, tb->has_focus ? 2 : 1, border_color);
    HPEN oldPen = SelectObject(hdc, pen);
    
    Rectangle(hdc, tb->bounds.x, tb->bounds.y,
              tb->bounds.x + tb->bounds.width,
              tb->bounds.y + tb->bounds.height);
    
    SelectObject(hdc, oldPen);
    DeleteObject(pen);
    
    // Szöveg rajzolása
    if (strlen(tb->text) > 0) {
        SetBkMode(hdc, TRANSPARENT);
        SetTextColor(hdc, text_color);
        
        // Font
        HFONT font = CreateFontA(
            16, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE,
            DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
            CLEARTYPE_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Consolas"
        );
        HFONT oldFont = SelectObject(hdc, font);
        
        RECT textRect = {tb->bounds.x + 5, tb->bounds.y + 5,
                         tb->bounds.x + tb->bounds.width - 5,
                         tb->bounds.y + tb->bounds.height - 5};
        
        DrawTextA(hdc, tb->text, -1, &textRect, DT_LEFT | DT_VCENTER | DT_SINGLELINE);
        
        SelectObject(hdc, oldFont);
        DeleteObject(font);
    }
    
    // Kurzor rajzolása (ha fókuszban van)
    if (tb->has_focus) {
        // Kurzor pozíció számítása
        HDC tempDC = CreateCompatibleDC(hdc);
        HFONT font = CreateFontA(
            16, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE,
            DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
            CLEARTYPE_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Consolas"
        );
        SelectObject(tempDC, font);
        
        // Szöveg szélesség mérése a kurzor pozíciójáig
        SIZE size;
        char temp[256];
        strncpy(temp, tb->text, tb->cursor_pos);
        temp[tb->cursor_pos] = '\0';
        GetTextExtentPoint32A(tempDC, temp, tb->cursor_pos, &size);
        
        DeleteDC(tempDC);
        DeleteObject(font);
        
        // Kurzor vonal rajzolása
        int cursor_x = tb->bounds.x + 5 + size.cx;
        int cursor_y1 = tb->bounds.y + 5;
        int cursor_y2 = tb->bounds.y + tb->bounds.height - 5;
        
        HPEN cursorPen = CreatePen(PS_SOLID, 2, cursor_color);
        HPEN oldCursorPen = SelectObject(hdc, cursorPen);
        
        MoveToEx(hdc, cursor_x, cursor_y1, NULL);
        LineTo(hdc, cursor_x, cursor_y2);
        
        SelectObject(hdc, oldCursorPen);
        DeleteObject(cursorPen);
    }
}
```

### 4.3 Teljes Példa TextBox-szal

```c
#include <windows.h>
#include <stdio.h>

TextBox *tb1, *tb2;
Button *submitBtn;

void on_submit_click(Button *btn) {
    char msg[512];
    sprintf(msg, "Név: %s\nEmail: %s", tb1->text, tb2->text);
    MessageBoxA(NULL, msg, "Form Adatok", MB_OK);
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_CREATE: {
            tb1 = textbox_create(50, 50, 300, 35);
            tb2 = textbox_create(50, 110, 300, 35);
            
            submitBtn = button_create(50, 170, 120, 35, "Küldés");
            submitBtn->on_click = on_submit_click;
            return 0;
        }
        
        case WM_DESTROY:
            free(tb1);
            free(tb2);
            free(submitBtn);
            PostQuitMessage(0);
            return 0;
        
        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);
            
            // Háttér
            HBRUSH brush = CreateSolidBrush(RGB(240, 240, 240));
            FillRect(hdc, &ps.rcPaint, brush);
            DeleteObject(brush);
            
            // Címkék
            SetBkMode(hdc, TRANSPARENT);
            TextOutA(hdc, 50, 30, "Név:", 5);
            TextOutA(hdc, 50, 90, "Email:", 6);
            
            // Widgetek rajzolása
            textbox_draw(tb1, hdc);
            textbox_draw(tb2, hdc);
            button_draw(submitBtn, hdc);
            
            EndPaint(hwnd, &ps);
            return 0;
        }
        
        case WM_LBUTTONDOWN: {
            int x = LOWORD(lParam);
            int y = HIWORD(lParam);
            
            textbox_on_mouse_down(tb1, x, y);
            textbox_on_mouse_down(tb2, x, y);
            button_on_mouse_down(submitBtn, x, y);
            
            InvalidateRect(hwnd, NULL, FALSE);
            return 0;
        }
        
        case WM_LBUTTONUP: {
            int x = LOWORD(lParam);
            int y = HIWORD(lParam);
            button_on_mouse_up(submitBtn, x, y);
            InvalidateRect(hwnd, NULL, FALSE);
            return 0;
        }
        
        case WM_MOUSEMOVE: {
            int x = LOWORD(lParam);
            int y = HIWORD(lParam);
            button_on_mouse_move(submitBtn, x, y);
            InvalidateRect(hwnd, NULL, FALSE);
            return 0;
        }
        
        case WM_CHAR: {
            // Normál karakter
            char c = (char)wParam;
            if (tb1->has_focus) {
                textbox_add_char(tb1, c);
            } else if (tb2->has_focus) {
                textbox_add_char(tb2, c);
            }
            InvalidateRect(hwnd, NULL, FALSE);
            return 0;
        }
        
        case WM_KEYDOWN: {
            // Speciális billentyűk
            TextBox *active = tb1->has_focus ? tb1 : (tb2->has_focus ? tb2 : NULL);
            if (active) {
                textbox_on_key(active, wParam, 1);
                InvalidateRect(hwnd, NULL, FALSE);
            }
            return 0;
        }
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nCmdShow) {
    const char CLASS_NAME[] = "TextBoxExampleClass";
    
    WNDCLASSA wc = {0};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    
    RegisterClassA(&wc);
    
    HWND hwnd = CreateWindowExA(
        0, CLASS_NAME, "TextBox Példa",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 450, 300,
        NULL, NULL, hInstance, NULL
    );
    
    if (!hwnd) return 0;
    
    ShowWindow(hwnd, nCmdShow);
    
    MSG msg = {0};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    
    return 0;
}
```

---

## 5. Fejezet: Event Bubbling és Capture

Az esemény propagáció (terjedés) lehetővé teszi, hogy a widgetek hierarchikusan kezeljék az eseményeket.

### 5.1 Esemény Terjedés Modellje

**Event Bubbling (Buborékolás):**
- Az esemény a legmélyebb widgettől felfelé halad
- Például: `Button → Panel → Window`

**Event Capture (Elfogás):**
- Az esemény felülről lefelé halad
- Például: `Window → Panel → Button`

### 5.2 Widget Hierarchia

```c
typedef struct Widget Widget;

struct Widget {
    Rect bounds;
    Widget *parent;
    Widget **children;
    int child_count;
    int capacity;
    
    // Event handlerek
    int (*on_mouse_down)(Widget *w, int x, int y);  // return 1 = consumed
    int (*on_mouse_up)(Widget *w, int x, int y);
    int (*on_mouse_move)(Widget *w, int x, int y);
    int (*on_key_down)(Widget *w, int key);
    
    void (*draw)(Widget *w, void *context);
    void *user_data;
    
    int visible;
    int enabled;
};

// Widget létrehozása
Widget* widget_create() {
    Widget *w = malloc(sizeof(Widget));
    w->bounds.x = 0;
    w->bounds.y = 0;
    w->bounds.width = 100;
    w->bounds.height = 30;
    w->parent = NULL;
    w->children = malloc(sizeof(Widget*) * 10);
    w->child_count = 0;
    w->capacity = 10;
    w->on_mouse_down = NULL;
    w->on_mouse_up = NULL;
    w->on_mouse_move = NULL;
    w->on_key_down = NULL;
    w->draw = NULL;
    w->user_data = NULL;
    w->visible = 1;
    w->enabled = 1;
    return w;
}

// Gyerek hozzáadása
void widget_add_child(Widget *parent, Widget *child) {
    if (parent->child_count >= parent->capacity) {
        parent->capacity *= 2;
        parent->children = realloc(parent->children,
                                   sizeof(Widget*) * parent->capacity);
    }
    parent->children[parent->child_count++] = child;
    child->parent = parent;
}

// Hit test (találat vizsgálat)
int widget_contains_point(Widget *w, int x, int y) {
    return x >= w->bounds.x && x <= w->bounds.x + w->bounds.width &&
           y >= w->bounds.y && y <= w->bounds.y + w->bounds.height;
}

// Widget keresése pozíció alapján (legmélyebb widget)
Widget* widget_find_at(Widget *w, int x, int y) {
    if (!w->visible || !widget_contains_point(w, x, y)) {
        return NULL;
    }
    
    // Először a gyerekekben keresünk (fordított sorrend = legfelső rajzolandó)
    for (int i = w->child_count - 1; i >= 0; i--) {
        Widget *found = widget_find_at(w->children[i], x, y);
        if (found != NULL) {
            return found;
        }
    }
    
    // Ha nincs gyerek találat, akkor ez a widget
    return w;
}

// Event Bubbling - Egér lenyomás
int widget_dispatch_mouse_down_bubble(Widget *w, int x, int y) {
    // 1. Legmélyebb widget megkeresése
    Widget *target = widget_find_at(w, x, y);
    if (target == NULL) return 0;
    
    // 2. Bubbling - alulról felfelé
    Widget *current = target;
    while (current != NULL) {
        if (current->enabled && current->on_mouse_down) {
            int consumed = current->on_mouse_down(current, x, y);
            if (consumed) {
                printf("Esemény elfogyasztva: %p\n", (void*)current);
                return 1;  // Esemény elfogyasztva
            }
        }
        current = current->parent;
    }
    
    return 0;
}

// Event Capture - Egér lenyomás (felülről lefelé)
int widget_dispatch_mouse_down_capture(Widget *w, int x, int y, Widget *target) {
    if (!w->visible) return 0;
    
    // Ha ez a célpont, megállunk
    if (w == target) {
        if (w->enabled && w->on_mouse_down) {
            return w->on_mouse_down(w, x, y);
        }
        return 0;
    }
    
    // Capture fázis - handler hívása
    if (w->enabled && w->on_mouse_down) {
        int consumed = w->on_mouse_down(w, x, y);
        if (consumed) return 1;
    }
    
    // Továbbhaladás a gyerekekhez
    for (int i = 0; i < w->child_count; i++) {
        if (widget_dispatch_mouse_down_capture(w->children[i], x, y, target)) {
            return 1;
        }
    }
    
    return 0;
}

// Teljes eseménykezelés (Capture → Target → Bubble)
int widget_dispatch_mouse_down_full(Widget *root, int x, int y) {
    // 1. Célpont megkeresése
    Widget *target = widget_find_at(root, x, y);
    if (target == NULL) return 0;
    
    printf("Esemény célpont: %p\n", (void*)target);
    
    // 2. Capture fázis (felülről lefelé a célpontig)
    if (widget_dispatch_mouse_down_capture(root, x, y, target)) {
        return 1;
    }
    
    // 3. Target fázis
    if (target->enabled && target->on_mouse_down) {
        int consumed = target->on_mouse_down(target, x, y);
        if (consumed) return 1;
    }
    
    // 4. Bubble fázis (célponttól felfelé, de kihagyjuk a targetot)
    Widget *current = target->parent;
    while (current != NULL) {
        if (current->enabled && current->on_mouse_down) {
            int consumed = current->on_mouse_down(current, x, y);
            if (consumed) return 1;
        }
        current = current->parent;
    }
    
    return 0;
}

// Rekurzív rajzolás (szülőtől gyerekekhez)
void widget_draw_recursive(Widget *w, void *context) {
    if (!w->visible) return;
    
    // Widget rajzolása
    if (w->draw) {
        w->draw(w, context);
    }
    
    // Gyerekek rajzolása
    for (int i = 0; i < w->child_count; i++) {
        widget_draw_recursive(w->children[i], context);
    }
}
```

### 5.3 Példa Használat

```c
// Panel widget (konténer)
int panel_on_mouse_down(Widget *w, int x, int y) {
    printf("Panel kattintás: (%d, %d)\n", x, y);
    return 0;  // Nem fogyasztjuk el, tovább megy
}

void panel_draw(Widget *w, void *context) {
    HDC hdc = (HDC)context;
    
    // Panel háttér
    HBRUSH brush = CreateSolidBrush(RGB(200, 200, 200));
    RECT rect = {w->bounds.x, w->bounds.y,
                 w->bounds.x + w->bounds.width,
                 w->bounds.y + w->bounds.height};
    FillRect(hdc, &rect, brush);
    DeleteObject(brush);
    
    // Keret
    HPEN pen = CreatePen(PS_SOLID, 1, RGB(100, 100, 100));
    HPEN oldPen = SelectObject(hdc, pen);
    Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);
    SelectObject(hdc, oldPen);
    DeleteObject(pen);
}

// Button handler (elfogyasztja az eseményt)
int button_widget_on_mouse_down(Widget *w, int x, int y) {
    Button *btn = (Button*)w->user_data;
    button_on_mouse_down(btn, x, y);
    return 1;  // Esemény elfogyasztva
}

// Példa hierarchia építés
Widget *root, *panel1, *panel2, *btn1, *btn2;

void create_widget_hierarchy() {
    // Root (ablak)
    root = widget_create();
    root->bounds = (Rect){0, 0, 400, 300};
    
    // Panel 1
    panel1 = widget_create();
    panel1->bounds = (Rect){10, 10, 180, 280};
    panel1->on_mouse_down = panel_on_mouse_down;
    panel1->draw = panel_draw;
    widget_add_child(root, panel1);
    
    // Button 1 (panel1 gyereke)
    btn1 = widget_create();
    btn1->bounds = (Rect){20, 20, 140, 35};
    btn1->on_mouse_down = button_widget_on_mouse_down;
    btn1->user_data = button_create(20, 20, 140, 35, "Gomb 1");
    widget_add_child(panel1, btn1);
    
    // Panel 2
    panel2 = widget_create();
    panel2->bounds = (Rect){210, 10, 180, 280};
    panel2->on_mouse_down = panel_on_mouse_down;
    panel2->draw = panel_draw;
    widget_add_child(root, panel2);
    
    // Button 2 (panel2 gyereke)
    btn2 = widget_create();
    btn2->bounds = (Rect){220, 20, 140, 35};
    btn2->on_mouse_down = button_widget_on_mouse_down;
    btn2->user_data = button_create(220, 20, 140, 35, "Gomb 2");
    widget_add_child(panel2, btn2);
}
```

---

## 6. Fejezet: Render Backend

### 6.1 Absztrakciós Réteg

Platformfüggetlen rajzolási interfész létrehozása.

```c
// Render backend típusok
typedef enum {
    RENDER_BACKEND_GDI,      // Windows GDI
    RENDER_BACKEND_X11,      // Linux X11
    RENDER_BACKEND_CAIRO,    // Cairo (cross-platform)
    RENDER_BACKEND_OPENGL    // OpenGL
} RenderBackendType;

// Szín struktúra
typedef struct {
    unsigned char r, g, b, a;
} Color;

// Render context
typedef struct RenderContext {
    RenderBackendType type;
    void *native_context;  // HDC, GC, stb.
    int width, height;
    
    // Function pointers
    void (*clear)(struct RenderContext *ctx, Color color);
    void (*draw_rect)(struct RenderContext *ctx, Rect rect, Color color);
    void (*fill_rect)(struct RenderContext *ctx, Rect rect, Color color);
    void (*draw_text)(struct RenderContext *ctx, int x, int y, const char *text, Color color);
    void (*draw_line)(struct RenderContext *ctx, int x1, int y1, int x2, int y2, Color color, int width);
} RenderContext;

// Színek létrehozása
Color color_rgb(unsigned char r, unsigned char g, unsigned char b) {
    Color c = {r, g, b, 255};
    return c;
}

Color color_rgba(unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
    Color c = {r, g, b, a};
    return c;
}

// Windows GDI implementáció
void render_gdi_clear(RenderContext *ctx, Color color) {
    HDC hdc = (HDC)ctx->native_context;
    HBRUSH brush = CreateSolidBrush(RGB(color.r, color.g, color.b));
    RECT rect = {0, 0, ctx->width, ctx->height};
    FillRect(hdc, &rect, brush);
    DeleteObject(brush);
}

void render_gdi_fill_rect(RenderContext *ctx, Rect rect, Color color) {
    HDC hdc = (HDC)ctx->native_context;
    HBRUSH brush = CreateSolidBrush(RGB(color.r, color.g, color.b));
    RECT r = {rect.x, rect.y, rect.x + rect.width, rect.y + rect.height};
    FillRect(hdc, &r, brush);
    DeleteObject(brush);
}

void render_gdi_draw_rect(RenderContext *ctx, Rect rect, Color color) {
    HDC hdc = (HDC)ctx->native_context;
    HPEN pen = CreatePen(PS_SOLID, 1, RGB(color.r, color.g, color.b));
    HPEN oldPen = SelectObject(hdc, pen);
    HBRUSH oldBrush = SelectObject(hdc, GetStockObject(NULL_BRUSH));
    
    Rectangle(hdc, rect.x, rect.y, rect.x + rect.width, rect.y + rect.height);
    
    SelectObject(hdc, oldBrush);
    SelectObject(hdc, oldPen);
    DeleteObject(pen);
}

void render_gdi_draw_text(RenderContext *ctx, int x, int y, const char *text, Color color) {
    HDC hdc = (HDC)ctx->native_context;
    SetBkMode(hdc, TRANSPARENT);
    SetTextColor(hdc, RGB(color.r, color.g, color.b));
    TextOutA(hdc, x, y, text, strlen(text));
}

void render_gdi_draw_line(RenderContext *ctx, int x1, int y1, int x2, int y2, 
                          Color color, int width) {
    HDC hdc = (HDC)ctx->native_context;
    HPEN pen = CreatePen(PS_SOLID, width, RGB(color.r, color.g, color.b));
    HPEN oldPen = SelectObject(hdc, pen);
    
    MoveToEx(hdc, x1, y1, NULL);
    LineTo(hdc, x2, y2);
    
    SelectObject(hdc, oldPen);
    DeleteObject(pen);
}

// GDI context létrehozása
RenderContext* render_context_create_gdi(HDC hdc, int width, int height) {
    RenderContext *ctx = malloc(sizeof(RenderContext));
    ctx->type = RENDER_BACKEND_GDI;
    ctx->native_context = hdc;
    ctx->width = width;
    ctx->height = height;
    
    ctx->clear = render_gdi_clear;
    ctx->fill_rect = render_gdi_fill_rect;
    ctx->draw_rect = render_gdi_draw_rect;
    ctx->draw_text = render_gdi_draw_text;
    ctx->draw_line = render_gdi_draw_line;
    
    return ctx;
}

// X11 implementáció
#ifdef __linux__
void render_x11_clear(RenderContext *ctx, Color color) {
    Display *display = ((struct { Display *d; Window w; GC gc; }*)ctx->native_context)->d;
    Window window = ((struct { Display *d; Window w; GC gc; }*)ctx->native_context)->w;
    GC gc = ((struct { Display *d; Window w; GC gc; }*)ctx->native_context)->gc;
    
    unsigned long pixel = (color.r << 16) | (color.g << 8) | color.b;
    XSetForeground(display, gc, pixel);
    XFillRectangle(display, window, gc, 0, 0, ctx->width, ctx->height);
}

void render_x11_fill_rect(RenderContext *ctx, Rect rect, Color color) {
    Display *display = ((struct { Display *d; Window w; GC gc; }*)ctx->native_context)->d;
    Window window = ((struct { Display *d; Window w; GC gc; }*)ctx->native_context)->w;
    GC gc = ((struct { Display *d; Window w; GC gc; }*)ctx->native_context)->gc;
    
    unsigned long pixel = (color.r << 16) | (color.g << 8) | color.b;
    XSetForeground(display, gc, pixel);
    XFillRectangle(display, window, gc, rect.x, rect.y, rect.width, rect.height);
}
#endif

// Widget rajzolás platformfüggetlen módon
void widget_draw_with_context(Widget *w, RenderContext *ctx) {
    // Háttér
    ctx->fill_rect(ctx, w->bounds, color_rgb(225, 225, 225));
    
    // Keret
    ctx->draw_rect(ctx, w->bounds, color_rgb(100, 100, 100));
    
    // Szöveg (ha van user_data és az Button)
    if (w->user_data) {
        Button *btn = (Button*)w->user_data;
        int text_x = w->bounds.x + 10;
        int text_y = w->bounds.y + 10;
        ctx->draw_text(ctx, text_x, text_y, btn->label, color_rgb(0, 0, 0));
    }
}
```

---

## 7. Fejezet: Mini Designer

Most készítünk egy egyszerű vizuális szerkesztőt, ahol drag&drop-pal mozgathatjuk a komponenseket.

### 7.1 Designer Állapot

```c
typedef enum {
    DESIGNER_MODE_SELECT,
    DESIGNER_MODE_CREATE_BUTTON,
    DESIGNER_MODE_CREATE_TEXTBOX,
    DESIGNER_MODE_CREATE_PANEL
} DesignerMode;

typedef struct {
    Widget *root;
    Widget *selected;
    DesignerMode mode;
    
    int dragging;
    int drag_start_x, drag_start_y;
    int widget_offset_x, widget_offset_y;
    
    Widget **widgets;
    int widget_count;
    int capacity;
} Designer;

// Designer létrehozása
Designer* designer_create() {
    Designer *d = malloc(sizeof(Designer));
    d->root = widget_create();
    d->root->bounds = (Rect){0, 0, 800, 600};
    d->selected = NULL;
    d->mode = DESIGNER_MODE_SELECT;
    d->dragging = 0;
    d->widgets = malloc(sizeof(Widget*) * 100);
    d->widget_count = 0;
    d->capacity = 100;
    return d;
}

// Widget hozzáadása
void designer_add_widget(Designer *d, Widget *w) {
    if (d->widget_count >= d->capacity) {
        d->capacity *= 2;
        d->widgets = realloc(d->widgets, sizeof(Widget*) * d->capacity);
    }
    d->widgets[d->widget_count++] = w;
    widget_add_child(d->root, w);
}

// Kiválasztás
    