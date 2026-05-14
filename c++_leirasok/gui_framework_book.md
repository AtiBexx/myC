# Saját GUI Framework írása C és C++ nyelven
### Az operációs rendszer ablakkezelője nélkül, az alapoktól

---

> "Ha megérted hogyan rajzol egy pixel a képernyőre, megértesz mindent."

---

## Tartalom

1. Bevezetés — Mi az a GUI framework?
2. A képernyő és a pixel
3. Framebuffer — közvetlen rajzolás
4. Alaprajzoló függvények C-ben
5. Eseménykezelés — billentyűzet és egér
6. Widget rendszer C-ben
7. Átváltás C++-ra — osztályok és öröklés
8. Layout rendszer
9. Saját Swing-szerű framework C++-ban
10. Cross-platform réteg
11. Teljes példa alkalmazás

---

# 1. fejezet — Mi az a GUI framework?

## 1.1 Amit mindenki használ, de senki nem ért

Amikor megnyomsz egy gombot egy ablakban, sok minden történik a háttérben. A Windows HWND, a Java Swing, a Qt — mind ugyanazt csinálják, csak különböző absztrakciós szinteken.

A legtöbb fejlesztő csak a legfelső szintet látja:

```
[Gomb kattintás] → onClick() → a te kódod fut
```

De alatta ez történik:

```
Egér hardver
    ↓
OS driver (IRQ interrupt)
    ↓
OS eseménysor (event queue)
    ↓
Ablakkezelő (HWND / X11 Window)
    ↓
Framework (Swing / Qt / Win32)
    ↓
Widget (JButton / QPushButton)
    ↓
A te onClick() függvényed
```

Ebben a könyvben ezt az egész láncot felépítjük — az alapoktól.

## 1.2 Mit fogunk építeni?

Egy teljes, működő GUI frameworköt amely képes:

- Pixeleket rajzolni a képernyőre közvetlenül
- Téglalapokat, köröket, szöveget megjeleníteni
- Ablakokat, gombokat, beviteli mezőket kezelni
- Egér és billentyűzet eseményeket fogadni
- Layoutot kezelni (elemek elrendezése)
- Cross-platform módon működni (Linux + Windows)

## 1.3 Amit NEM fogunk használni

- `windows.h` CreateWindow / HWND
- X11 / Xlib ablakkezelés
- Qt, GTK, wxWidgets
- OpenGL / DirectX (csak a végén opcionálisan)
- Semmilyen GUI könyvtár

Amit IGEN fogunk használni:

- **Linux:** `/dev/fb0` framebuffer + `/dev/input` eseménykezelés
- **Windows:** GDI `GetDC` + `SetPixel` a legalacsonyabb szinten
- Standard C könyvtár (`stdio.h`, `stdlib.h`, `string.h`)

---

# 2. fejezet — A képernyő és a pixel

## 2.1 Mi az a pixel?

A képernyő egy nagy tömb — minden elem egy pixel. Egy Full HD képernyő:

```
1920 × 1080 = 2 073 600 pixel
```

Minden pixel általában 4 byte-ból áll (32 bites szín):

```
Byte 0: Blue  (0-255)
Byte 1: Green (0-255)
Byte 2: Red   (0-255)
Byte 3: Alpha (0-255, átlátszóság)
```

Tehát egy Full HD képernyő framebuffer mérete:

```
1920 × 1080 × 4 byte = ~8 MB
```

## 2.2 Hogyan tárolódik a memóriában?

A képernyő sorokban tárolódik — bal felső saroktól jobbra, majd le:

```
[0,0] [1,0] [2,0] ... [1919,0]   ← első sor
[0,1] [1,1] [2,1] ... [1919,1]   ← második sor
...
[0,1079] ...        [1919,1079]   ← utolsó sor
```

Egy pixel memóriacíme:

```c
int index = y * width + x;
uint32_t* framebuffer = ...; // a memória kezdete
framebuffer[index] = color;  // pixel beírása
```

Ez a **legfontosabb képlet** az egész könyvben — mindent erre építünk.

## 2.3 Színek kódolása

```c
// Szín összerakása C-ben
uint32_t color_rgb(uint8_t r, uint8_t g, uint8_t b) {
    return (r << 16) | (g << 8) | b;
}

// Előre definiált színek
#define COLOR_BLACK   0x000000
#define COLOR_WHITE   0xFFFFFF
#define COLOR_RED     0xFF0000
#define COLOR_GREEN   0x00FF00
#define COLOR_BLUE    0x0000FF
#define COLOR_GRAY    0x808080
#define COLOR_YELLOW  0xFFFF00
```

---

# 3. fejezet — Framebuffer, közvetlen rajzolás

## 3.1 Linux Framebuffer (`/dev/fb0`)

Linuxon a `/dev/fb0` egy speciális fájl ami közvetlenül a videómemóriára mutat. Ha ide írunk, azonnal megjelenik a képernyőn — OS ablakkezelő nélkül.

```c
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <linux/fb.h>
#include <stdint.h>
#include <string.h>

typedef struct {
    int fd;                    // fájl leíró
    uint32_t* buffer;          // memória pointer
    int width;                 // képernyő szélesség
    int height;                // képernyő magasság
    int size;                  // teljes méret byte-ban
} Framebuffer;

// Framebuffer megnyitása
Framebuffer* fb_open(const char* device) {
    Framebuffer* fb = malloc(sizeof(Framebuffer));

    fb->fd = open(device, O_RDWR);
    if (fb->fd < 0) {
        perror("Nem lehet megnyitni a framebuffert");
        free(fb);
        return NULL;
    }

    // Képernyő adatok lekérése
    struct fb_var_screeninfo vinfo;
    ioctl(fb->fd, FBIOGET_VSCREENINFO, &vinfo);

    fb->width  = vinfo.xres;
    fb->height = vinfo.yres;
    fb->size   = fb->width * fb->height * (vinfo.bits_per_pixel / 8);

    // Memória leképezés - ez a varázslat
    fb->buffer = mmap(0, fb->size,
                      PROT_READ | PROT_WRITE,
                      MAP_SHARED, fb->fd, 0);

    if (fb->buffer == MAP_FAILED) {
        perror("mmap sikertelen");
        close(fb->fd);
        free(fb);
        return NULL;
    }

    printf("Framebuffer: %dx%d\n", fb->width, fb->height);
    return fb;
}

// Framebuffer bezárása
void fb_close(Framebuffer* fb) {
    munmap(fb->buffer, fb->size);
    close(fb->fd);
    free(fb);
}

// Pixel rajzolása - ez az alapművelet
void fb_set_pixel(Framebuffer* fb, int x, int y, uint32_t color) {
    if (x < 0 || x >= fb->width || y < 0 || y >= fb->height) return;
    fb->buffer[y * fb->width + x] = color;
}

// Képernyő törlése
void fb_clear(Framebuffer* fb, uint32_t color) {
    for (int i = 0; i < fb->width * fb->height; i++)
        fb->buffer[i] = color;
}
```

## 3.2 Windows GDI — legalacsonyabb szint

Windowson a legalacsonyabb szint a `GetDC` + `SetPixel` kombináció — ez az egyetlen Win32 hívásunk:

```c
#ifdef _WIN32
#include <windows.h>

typedef struct {
    HDC     hdc;       // Device Context
    HWND    hwnd;      // ablak handle (minimális)
    int     width;
    int     height;
    uint32_t* buffer;  // saját back buffer
} Framebuffer;

Framebuffer* fb_open_windows(int width, int height) {
    Framebuffer* fb = malloc(sizeof(Framebuffer));
    fb->width  = width;
    fb->height = height;
    fb->buffer = malloc(width * height * sizeof(uint32_t));

    // Minimális ablak csak a DC-hez
    fb->hwnd = GetConsoleWindow();
    fb->hdc  = GetDC(fb->hwnd);
    return fb;
}

// Back buffer flush a képernyőre
void fb_flush_windows(Framebuffer* fb) {
    for (int y = 0; y < fb->height; y++) {
        for (int x = 0; x < fb->width; x++) {
            uint32_t c = fb->buffer[y * fb->width + x];
            SetPixel(fb->hdc, x, y,
                RGB((c >> 16) & 0xFF, (c >> 8) & 0xFF, c & 0xFF));
        }
    }
}
#endif
```

## 3.3 Cross-platform wrapper

Most csinálunk egy egységes interface-t amely mindkét platformon működik:

```c
// gui_platform.h
#ifndef GUI_PLATFORM_H
#define GUI_PLATFORM_H

#include <stdint.h>

typedef struct GUI_Surface GUI_Surface;

// Ezeket minden platformon meg kell valósítani
GUI_Surface* gui_surface_create(int width, int height, const char* title);
void         gui_surface_destroy(GUI_Surface* s);
void         gui_surface_set_pixel(GUI_Surface* s, int x, int y, uint32_t color);
void         gui_surface_flush(GUI_Surface* s);
void         gui_surface_clear(GUI_Surface* s, uint32_t color);
int          gui_surface_width(GUI_Surface* s);
int          gui_surface_height(GUI_Surface* s);

#endif
```

---

# 4. fejezet — Alaprajzoló függvények C-ben

Most hogy tudunk pixelt rajzolni, felépítjük a rajzoló könyvtárat.

## 4.1 Vonal — Bresenham algoritmus

A Bresenham vonal algoritmus az egyik legelegánsabb algoritmus a számítástechnikában — csak egész számokkal dolgozik, nincs lebegőpontos számítás:

```c
// gui_draw.h / gui_draw.c

void gui_draw_line(GUI_Surface* s,
                   int x0, int y0,
                   int x1, int y1,
                   uint32_t color) {
    int dx =  abs(x1 - x0);
    int dy = -abs(y1 - y0);
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;
    int err = dx + dy;

    while (1) {
        gui_surface_set_pixel(s, x0, y0, color);
        if (x0 == x1 && y0 == y1) break;
        int e2 = 2 * err;
        if (e2 >= dy) { err += dy; x0 += sx; }
        if (e2 <= dx) { err += dx; y0 += sy; }
    }
}
```

## 4.2 Téglalap

```c
// Csak keret
void gui_draw_rect(GUI_Surface* s,
                   int x, int y,
                   int w, int h,
                   uint32_t color) {
    gui_draw_line(s, x,     y,     x+w-1, y,     color); // felső
    gui_draw_line(s, x,     y+h-1, x+w-1, y+h-1, color); // alsó
    gui_draw_line(s, x,     y,     x,     y+h-1, color); // bal
    gui_draw_line(s, x+w-1, y,     x+w-1, y+h-1, color); // jobb
}

// Kitöltött
void gui_fill_rect(GUI_Surface* s,
                   int x, int y,
                   int w, int h,
                   uint32_t color) {
    for (int row = y; row < y + h; row++)
        for (int col = x; col < x + w; col++)
            gui_surface_set_pixel(s, col, row, color);
}
```

## 4.3 Kör — Midpoint Circle algoritmus

```c
void gui_draw_circle(GUI_Surface* s,
                     int cx, int cy, int r,
                     uint32_t color) {
    int x = r, y = 0;
    int p = 1 - r;

    // 8 szimmetria pont egyszerre
    auto put = [&](int px, int py) {
        gui_surface_set_pixel(s, cx+px, cy+py, color);
        gui_surface_set_pixel(s, cx-px, cy+py, color);
        gui_surface_set_pixel(s, cx+px, cy-py, color);
        gui_surface_set_pixel(s, cx-px, cy-py, color);
        gui_surface_set_pixel(s, cx+py, cy+px, color);
        gui_surface_set_pixel(s, cx-py, cy+px, color);
        gui_surface_set_pixel(s, cx+py, cy-px, color);
        gui_surface_set_pixel(s, cx-py, cy-px, color);
    };

    while (x >= y) {
        put(x, y);
        y++;
        if (p <= 0) p += 2*y + 1;
        else { x--; p += 2*(y-x) + 1; }
    }
}

// C verzió (lambda nélkül)
void gui_draw_circle_c(GUI_Surface* s,
                       int cx, int cy, int r,
                       uint32_t color) {
    int x = r, y = 0, p = 1 - r;
    while (x >= y) {
        gui_surface_set_pixel(s, cx+x, cy+y, color);
        gui_surface_set_pixel(s, cx-x, cy+y, color);
        gui_surface_set_pixel(s, cx+x, cy-y, color);
        gui_surface_set_pixel(s, cx-x, cy-y, color);
        gui_surface_set_pixel(s, cx+y, cy+x, color);
        gui_surface_set_pixel(s, cx-y, cy+x, color);
        gui_surface_set_pixel(s, cx+y, cy-x, color);
        gui_surface_set_pixel(s, cx-y, cy-x, color);
        y++;
        if (p <= 0) p += 2*y + 1;
        else { x--; p += 2*(y-x) + 1; }
    }
}
```

## 4.4 Szöveg — Bitmap font

Szöveg megjelenítéséhez egy bitmap fontot használunk — minden karakter egy 8x8 pixeles minta:

```c
// Egyszerű 8x8 bitmap font (ASCII 32-127)
// Minden karakter 8 byte, minden byte egy sor
static const uint8_t FONT_8x8[96][8] = {
    // ' ' (space)
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
    // '!'
    { 0x18, 0x3C, 0x3C, 0x18, 0x18, 0x00, 0x18, 0x00 },
    // 'A'
    { 0x18, 0x3C, 0x66, 0x7E, 0x66, 0x66, 0x66, 0x00 },
    // ... (teljes font táblázat)
};

void gui_draw_char(GUI_Surface* s,
                   int x, int y,
                   char c,
                   uint32_t color) {
    if (c < 32 || c > 127) return;
    const uint8_t* glyph = FONT_8x8[c - 32];

    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            if (glyph[row] & (0x80 >> col))
                gui_surface_set_pixel(s, x + col, y + row, color);
        }
    }
}

void gui_draw_text(GUI_Surface* s,
                   int x, int y,
                   const char* text,
                   uint32_t color) {
    int cx = x;
    while (*text) {
        if (*text == '\n') { cx = x; y += 10; }
        else { gui_draw_char(s, cx, y, *text, color); cx += 9; }
        text++;
    }
}
```

---

# 5. fejezet — Eseménykezelés

## 5.1 Mi az esemény?

Minden GUI framework eseményeken alapul:

```
Egér mozog    → MOUSE_MOVE esemény  (x, y)
Gomb lenyom   → MOUSE_DOWN esemény  (x, y, button)
Billentyű     → KEY_DOWN esemény    (keycode)
Ablak átméret → RESIZE esemény      (w, h)
```

## 5.2 Esemény struktúra C-ben

```c
// gui_event.h

typedef enum {
    GUI_EVENT_NONE = 0,
    GUI_EVENT_MOUSE_MOVE,
    GUI_EVENT_MOUSE_DOWN,
    GUI_EVENT_MOUSE_UP,
    GUI_EVENT_KEY_DOWN,
    GUI_EVENT_KEY_UP,
    GUI_EVENT_QUIT,
    GUI_EVENT_RESIZE
} GUI_EventType;

typedef struct {
    GUI_EventType type;
    union {
        struct { int x, y, button; } mouse;
        struct { int keycode; char ch; } key;
        struct { int width, height; } resize;
    };
} GUI_Event;
```

## 5.3 Linux input kezelés (`/dev/input`)

```c
#include <linux/input.h>

typedef struct {
    int mouse_fd;
    int kbd_fd;
    int mouse_x, mouse_y;
} GUI_Input;

GUI_Input* gui_input_open() {
    GUI_Input* inp = malloc(sizeof(GUI_Input));
    inp->mouse_x = 0;
    inp->mouse_y = 0;

    // Egér eszköz (általában event1 vagy event2)
    inp->mouse_fd = open("/dev/input/event1", O_RDONLY | O_NONBLOCK);
    // Billentyűzet
    inp->kbd_fd   = open("/dev/input/event0", O_RDONLY | O_NONBLOCK);
    return inp;
}

int gui_input_poll(GUI_Input* inp, GUI_Event* event) {
    struct input_event ev;
    event->type = GUI_EVENT_NONE;

    // Egér olvasás
    if (read(inp->mouse_fd, &ev, sizeof(ev)) > 0) {
        if (ev.type == EV_REL) {
            if (ev.code == REL_X) inp->mouse_x += ev.value;
            if (ev.code == REL_Y) inp->mouse_y += ev.value;
            event->type    = GUI_EVENT_MOUSE_MOVE;
            event->mouse.x = inp->mouse_x;
            event->mouse.y = inp->mouse_y;
            return 1;
        }
        if (ev.type == EV_KEY && ev.code == BTN_LEFT) {
            event->type    = ev.value ? GUI_EVENT_MOUSE_DOWN : GUI_EVENT_MOUSE_UP;
            event->mouse.x = inp->mouse_x;
            event->mouse.y = inp->mouse_y;
            event->mouse.button = 1;
            return 1;
        }
    }

    // Billentyűzet olvasás
    if (read(inp->kbd_fd, &ev, sizeof(ev)) > 0) {
        if (ev.type == EV_KEY) {
            event->type        = ev.value ? GUI_EVENT_KEY_DOWN : GUI_EVENT_KEY_UP;
            event->key.keycode = ev.code;
            return 1;
        }
    }
    return 0;
}
```

---

# 6. fejezet — Widget rendszer C-ben

## 6.1 A Widget fogalma

Minden GUI elem (gomb, szövegmező, lista) egy **widget**. Minden widgetnek van:

- Pozíciója és mérete (x, y, w, h)
- Állapota (látható, aktív, fókuszban van-e)
- Rajzoló függvénye
- Eseménykezelő függvénye

## 6.2 Widget struktúra C-ben — Function pointerekkel

C-ben az öröklést function pointerekkel szimuláljuk:

```c
// gui_widget.h

typedef struct GUI_Widget GUI_Widget;

// "Virtuális" függvények function pointerekkel
typedef void (*GUI_DrawFn)  (GUI_Widget*, GUI_Surface*);
typedef int  (*GUI_EventFn) (GUI_Widget*, GUI_Event*);
typedef void (*GUI_FreeFn)  (GUI_Widget*);

struct GUI_Widget {
    int x, y, w, h;         // pozíció és méret
    int visible;             // látható-e
    int enabled;             // aktív-e
    uint32_t bg_color;       // háttérszín
    uint32_t fg_color;       // előtérszín

    GUI_DrawFn  draw;        // rajzolás
    GUI_EventFn on_event;    // eseménykezelés
    GUI_FreeFn  free;        // memória felszabadítás

    void* user_data;         // extra adat (callback stb.)

    // Gyermek widgetek (container-ekhez)
    GUI_Widget** children;
    int child_count;
    GUI_Widget*  parent;
};

// Alapfüggvények
GUI_Widget* gui_widget_create(int x, int y, int w, int h);
void        gui_widget_destroy(GUI_Widget* w);
void        gui_widget_draw(GUI_Widget* w, GUI_Surface* s);
int         gui_widget_handle_event(GUI_Widget* w, GUI_Event* e);
void        gui_widget_add_child(GUI_Widget* parent, GUI_Widget* child);

// Segédfüggvény: benne van-e a pont a widgetben
int gui_widget_contains(GUI_Widget* w, int x, int y) {
    return x >= w->x && x < w->x + w->w &&
           y >= w->y && y < w->y + w->h;
}
```

## 6.3 Gomb widget C-ben

```c
// gui_button.h / gui_button.c

typedef struct {
    GUI_Widget base;          // MINDIG az első mező!
    char       label[64];
    int        pressed;
    void (*on_click)(GUI_Widget*);  // callback
} GUI_Button;

static void button_draw(GUI_Widget* w, GUI_Surface* s) {
    GUI_Button* btn = (GUI_Button*)w;

    // Háttér
    uint32_t bg = btn->pressed ? 0x5588FF : 0x3366CC;
    gui_fill_rect(s, w->x, w->y, w->w, w->h, bg);

    // Keret
    uint32_t border = btn->pressed ? 0x2244AA : 0x88AAFF;
    gui_draw_rect(s, w->x, w->y, w->w, w->h, border);

    // Szöveg középre igazítva
    int text_w = strlen(btn->label) * 9;
    int text_x = w->x + (w->w - text_w) / 2;
    int text_y = w->y + (w->h - 8) / 2;
    gui_draw_text(s, text_x, text_y, btn->label, 0xFFFFFF);
}

static int button_event(GUI_Widget* w, GUI_Event* e) {
    GUI_Button* btn = (GUI_Button*)w;

    if (e->type == GUI_EVENT_MOUSE_DOWN &&
        gui_widget_contains(w, e->mouse.x, e->mouse.y)) {
        btn->pressed = 1;
        return 1;
    }
    if (e->type == GUI_EVENT_MOUSE_UP) {
        if (btn->pressed && gui_widget_contains(w, e->mouse.x, e->mouse.y)) {
            if (btn->on_click) btn->on_click(w);
        }
        btn->pressed = 0;
        return 1;
    }
    return 0;
}

GUI_Widget* gui_button_create(int x, int y, int w, int h,
                               const char* label,
                               void (*on_click)(GUI_Widget*)) {
    GUI_Button* btn = calloc(1, sizeof(GUI_Button));
    btn->base.x = x; btn->base.y = y;
    btn->base.w = w; btn->base.h = h;
    btn->base.draw     = button_draw;
    btn->base.on_event = button_event;
    btn->base.free     = (GUI_FreeFn)free;
    strncpy(btn->label, label, 63);
    btn->on_click = on_click;
    return (GUI_Widget*)btn;
}
```

## 6.4 Szövegmező widget C-ben

```c
typedef struct {
    GUI_Widget base;
    char       text[256];
    int        cursor_pos;
    int        focused;
} GUI_TextInput;

static void textinput_draw(GUI_Widget* w, GUI_Surface* s) {
    GUI_TextInput* ti = (GUI_TextInput*)w;

    // Háttér
    gui_fill_rect(s, w->x, w->y, w->w, w->h, 0xFFFFFF);

    // Keret — kék ha fókuszban van
    uint32_t border = ti->focused ? 0x3366CC : 0x888888;
    gui_draw_rect(s, w->x, w->y, w->w, w->h, border);

    // Szöveg
    gui_draw_text(s, w->x + 4, w->y + (w->h - 8) / 2, ti->text, 0x000000);

    // Kurzor
    if (ti->focused) {
        int cx = w->x + 4 + ti->cursor_pos * 9;
        gui_draw_line(s, cx, w->y + 3, cx, w->y + w->h - 4, 0x000000);
    }
}

static int textinput_event(GUI_Widget* w, GUI_Event* e) {
    GUI_TextInput* ti = (GUI_TextInput*)w;

    if (e->type == GUI_EVENT_MOUSE_DOWN) {
        ti->focused = gui_widget_contains(w, e->mouse.x, e->mouse.y);
        return ti->focused;
    }

    if (ti->focused && e->type == GUI_EVENT_KEY_DOWN) {
        int len = strlen(ti->text);
        if (e->key.keycode == KEY_BACKSPACE && ti->cursor_pos > 0) {
            memmove(ti->text + ti->cursor_pos - 1,
                    ti->text + ti->cursor_pos,
                    len - ti->cursor_pos + 1);
            ti->cursor_pos--;
        } else if (e->key.ch >= 32 && e->key.ch < 127 && len < 255) {
            memmove(ti->text + ti->cursor_pos + 1,
                    ti->text + ti->cursor_pos,
                    len - ti->cursor_pos + 1);
            ti->text[ti->cursor_pos++] = e->key.ch;
        }
        return 1;
    }
    return 0;
}

GUI_Widget* gui_textinput_create(int x, int y, int w, int h) {
    GUI_TextInput* ti = calloc(1, sizeof(GUI_TextInput));
    ti->base.x = x; ti->base.y = y;
    ti->base.w = w; ti->base.h = h;
    ti->base.draw     = textinput_draw;
    ti->base.on_event = textinput_event;
    ti->base.free     = (GUI_FreeFn)free;
    return (GUI_Widget*)ti;
}
```

---

# 7. fejezet — Átváltás C++-ra

## 7.1 Miért C++?

A C-s megközelítés működik, de látható a korlátja:
- A function pointerek kézzel vannak beállítva
- Nincs típusbiztonság az `(GUI_Button*)` castolásokban
- A `children` tömb manuális kezelése bonyolult

C++-ban mindez sokkal elegánsabb lesz öröklés és virtuális függvények segítségével.

## 7.2 Widget alap osztály C++-ban

```cpp
// Widget.hpp
#pragma once
#include <vector>
#include <memory>
#include <string>
#include <functional>
#include "Surface.hpp"
#include "Event.hpp"

class Widget {
public:
    int x, y, w, h;
    bool visible = true;
    bool enabled = true;
    uint32_t bg_color = 0x2D2D2D;
    uint32_t fg_color = 0xFFFFFF;

    Widget* parent = nullptr;
    std::vector<std::unique_ptr<Widget>> children;

    Widget(int x, int y, int w, int h)
        : x(x), y(y), w(w), h(h) {}

    virtual ~Widget() = default;

    // Virtuális függvények — minden widget felülírja
    virtual void draw(Surface& s) {
        // Alapból kirajzolja a gyerekeket
        for (auto& child : children)
            if (child->visible) child->draw(s);
    }

    virtual bool onEvent(const Event& e) {
        // Gyerekeknek továbbítja az eseményt (fordított sorrendben)
        for (auto it = children.rbegin(); it != children.rend(); ++it)
            if ((*it)->enabled && (*it)->onEvent(e)) return true;
        return false;
    }

    // Segédfüggvények
    bool contains(int px, int py) const {
        return px >= x && px < x+w && py >= y && py < y+h;
    }

    void addChild(std::unique_ptr<Widget> child) {
        child->parent = this;
        children.push_back(std::move(child));
    }

    // Abszolút pozíció (szülők figyelembevételével)
    int absX() const { return parent ? parent->absX() + x : x; }
    int absY() const { return parent ? parent->absY() + y : y; }
};
```

## 7.3 Button C++-ban

```cpp
// Button.hpp
#pragma once
#include "Widget.hpp"

class Button : public Widget {
public:
    std::string label;
    std::function<void()> onClick;

private:
    bool pressed = false;
    bool hovered = false;

public:
    Button(int x, int y, int w, int h, const std::string& label)
        : Widget(x, y, w, h), label(label) {}

    void draw(Surface& s) override {
        uint32_t bg = pressed ? 0x5588FF
                    : hovered ? 0x4477EE
                    :           0x3366CC;

        s.fillRect(x, y, w, h, bg);
        s.drawRect(x, y, w, h, pressed ? 0x2244AA : 0x88AAFF);

        int tx = x + (w - (int)label.size() * 9) / 2;
        int ty = y + (h - 8) / 2;
        s.drawText(tx, ty, label, 0xFFFFFF);
    }

    bool onEvent(const Event& e) override {
        if (e.type == Event::MOUSE_MOVE) {
            hovered = contains(e.mouse.x, e.mouse.y);
            return false;
        }
        if (e.type == Event::MOUSE_DOWN && contains(e.mouse.x, e.mouse.y)) {
            pressed = true; return true;
        }
        if (e.type == Event::MOUSE_UP) {
            if (pressed && contains(e.mouse.x, e.mouse.y) && onClick)
                onClick();
            pressed = false; return true;
        }
        return false;
    }
};
```

## 7.4 Label, Checkbox, Slider C++-ban

```cpp
// Label.hpp
class Label : public Widget {
public:
    std::string text;
    Label(int x, int y, const std::string& text)
        : Widget(x, y, text.size() * 9, 16), text(text) {}

    void draw(Surface& s) override {
        s.drawText(x, y, text, fg_color);
    }
};

// Checkbox.hpp
class Checkbox : public Widget {
public:
    std::string label;
    bool checked = false;
    std::function<void(bool)> onChange;

    Checkbox(int x, int y, const std::string& label)
        : Widget(x, y, 20 + label.size() * 9, 20), label(label) {}

    void draw(Surface& s) override {
        s.drawRect(x, y, 16, 16, 0x888888);
        if (checked) {
            s.drawLine(x+2,  y+8,  x+6,  y+12, 0x44FF44);
            s.drawLine(x+6,  y+12, x+14, y+3,  0x44FF44);
        }
        s.drawText(x + 22, y + 4, label, fg_color);
    }

    bool onEvent(const Event& e) override {
        if (e.type == Event::MOUSE_DOWN && contains(e.mouse.x, e.mouse.y)) {
            checked = !checked;
            if (onChange) onChange(checked);
            return true;
        }
        return false;
    }
};

// Slider.hpp
class Slider : public Widget {
public:
    float value = 0.5f;   // 0.0 - 1.0
    std::function<void(float)> onChange;

    Slider(int x, int y, int w)
        : Widget(x, y, w, 20) {}

    void draw(Surface& s) override {
        // Sáv
        s.fillRect(x + 8, y + 8, w - 16, 4, 0x555555);
        // Fogantyú
        int hx = x + 8 + (int)(value * (w - 16));
        s.fillRect(hx - 6, y + 2, 12, 16, 0x3366CC);
        s.drawRect(hx - 6, y + 2, 12, 16, 0x88AAFF);
    }

    bool onEvent(const Event& e) override {
        if ((e.type == Event::MOUSE_DOWN || e.type == Event::MOUSE_MOVE)
             && e.mouse.button && contains(e.mouse.x, e.mouse.y)) {
            value = (float)(e.mouse.x - x - 8) / (w - 16);
            value = value < 0 ? 0 : value > 1 ? 1 : value;
            if (onChange) onChange(value);
            return true;
        }
        return false;
    }
};
```

---

# 8. fejezet — Layout rendszer

## 8.1 Mi az a layout?

A layout automatikusan rendezi el a widgeteket — nem kell mindent kézzel pozicionálni.

```cpp
// Layout.hpp

// Vízszintes elrendezés
class HBoxLayout : public Widget {
    int padding;
    int spacing;
public:
    HBoxLayout(int x, int y, int w, int h, int padding = 4, int spacing = 4)
        : Widget(x, y, w, h), padding(padding), spacing(spacing) {}

    void addWidget(std::unique_ptr<Widget> child) {
        // Kiszámolja az X pozíciót
        int cx = x + padding;
        for (auto& c : children) cx += c->w + spacing;
        child->x = cx;
        child->y = y + (h - child->h) / 2;
        addChild(std::move(child));
    }
};

// Függőleges elrendezés
class VBoxLayout : public Widget {
    int padding;
    int spacing;
public:
    VBoxLayout(int x, int y, int w, int h, int padding = 4, int spacing = 4)
        : Widget(x, y, w, h), padding(padding), spacing(spacing) {}

    void addWidget(std::unique_ptr<Widget> child) {
        int cy = y + padding;
        for (auto& c : children) cy += c->h + spacing;
        child->x = x + padding;
        child->y = cy;
        addChild(std::move(child));
    }
};

// Grid elrendezés
class GridLayout : public Widget {
    int cols, padding, spacing;
    int col = 0, row = 0;
public:
    GridLayout(int x, int y, int w, int h, int cols,
               int padding = 4, int spacing = 4)
        : Widget(x, y, w, h), cols(cols),
          padding(padding), spacing(spacing) {}

    void addWidget(std::unique_ptr<Widget> child) {
        int cellW = (w - 2*padding - (cols-1)*spacing) / cols;
        child->x = x + padding + col * (cellW + spacing);
        child->y = y + padding + row * (child->h + spacing);
        if (++col >= cols) { col = 0; row++; }
        addChild(std::move(child));
    }
};
```

---

# 9. fejezet — Teljes GUI framework C++-ban

## 9.1 Application osztály — a belépési pont

```cpp
// Application.hpp
#pragma once
#include "Surface.hpp"
#include "EventSystem.hpp"
#include "Widget.hpp"

class Application {
    std::unique_ptr<Surface>     surface;
    std::unique_ptr<EventSystem> events;
    std::unique_ptr<Widget>      root;
    bool running = false;

public:
    Application(int width, int height, const std::string& title) {
        surface = std::make_unique<Surface>(width, height, title);
        events  = std::make_unique<EventSystem>();
        root    = std::make_unique<Widget>(0, 0, width, height);
    }

    void setRoot(std::unique_ptr<Widget> widget) {
        root = std::move(widget);
    }

    void addWidget(std::unique_ptr<Widget> widget) {
        root->addChild(std::move(widget));
    }

    int run() {
        running = true;
        while (running) {
            // 1. Eseménykezelés
            Event e;
            while (events->poll(e)) {
                if (e.type == Event::QUIT) { running = false; break; }
                root->onEvent(e);
            }

            // 2. Rajzolás
            surface->clear(0x1E1E1E);
            root->draw(*surface);
            surface->flush();

            // 3. ~60 FPS
            usleep(16000);
        }
        return 0;
    }
};
```

## 9.2 Teljes példa alkalmazás

```cpp
// main.cpp
#include "Application.hpp"
#include "Button.hpp"
#include "Label.hpp"
#include "TextInput.hpp"
#include "Checkbox.hpp"
#include "Slider.hpp"
#include "VBoxLayout.hpp"

int main() {
    Application app(800, 600, "Saját GUI Framework");

    auto layout = std::make_unique<VBoxLayout>(50, 50, 700, 500);

    // Cím
    auto title = std::make_unique<Label>(0, 0, "Saját GUI Framework - Demo");
    title->fg_color = 0xFFCC00;
    layout->addWidget(std::move(title));

    // Beviteli mező
    auto input = std::make_unique<TextInput>(0, 0, 300, 30);
    input->placeholder = "Írj valamit...";
    auto* inputPtr = input.get();
    layout->addWidget(std::move(input));

    // Eredmény label
    auto result = std::make_unique<Label>(0, 0, "");
    auto* resultPtr = result.get();
    layout->addWidget(std::move(result));

    // Gomb
    auto btn = std::make_unique<Button>(0, 0, 120, 35, "Küldés");
    btn->onClick = [inputPtr, resultPtr]() {
        resultPtr->text = "Beírtad: " + inputPtr->text;
    };
    layout->addWidget(std::move(btn));

    // Checkbox
    auto cb = std::make_unique<Checkbox>(0, 0, "Értesítések engedélyezése");
    cb->onChange = [](bool checked) {
        // logika
    };
    layout->addWidget(std::move(cb));

    // Csúszka
    auto slider = std::make_unique<Slider>(0, 0, 300);
    slider->onChange = [](float val) {
        // 0.0 - 1.0 közötti érték
    };
    layout->addWidget(std::move(slider));

    app.addWidget(std::move(layout));
    return app.run();
}
```

---

# 10. fejezet — Cross-platform réteg

## 10.1 A platform absztrakció

```cpp
// Platform.hpp
#pragma once

class Platform {
public:
    virtual ~Platform() = default;
    virtual bool init(int w, int h, const char* title) = 0;
    virtual void setPixel(int x, int y, uint32_t color) = 0;
    virtual void flush() = 0;
    virtual bool pollEvent(Event& e) = 0;
    virtual void close() = 0;

    static std::unique_ptr<Platform> create();
};

// Linux implementáció
class LinuxPlatform : public Platform {
    int fb_fd;
    uint32_t* fb_mem;
    int width, height;
    // /dev/input kezelés
public:
    bool init(int w, int h, const char* title) override { /* ... */ }
    void setPixel(int x, int y, uint32_t color) override {
        fb_mem[y * width + x] = color;
    }
    void flush() override { /* double buffering */ }
    bool pollEvent(Event& e) override { /* /dev/input olvasás */ }
};

// Windows implementáció
class WindowsPlatform : public Platform {
    HDC hdc;
    uint32_t* back_buffer;
    int width, height;
public:
    bool init(int w, int h, const char* title) override { /* ... */ }
    void setPixel(int x, int y, uint32_t color) override {
        back_buffer[y * width + x] = color;
    }
    void flush() override { /* back_buffer -> SetPixel */ }
    bool pollEvent(Event& e) override { /* Windows messages */ }
};

// Factory - eldönti melyiket hozza létre
std::unique_ptr<Platform> Platform::create() {
#ifdef _WIN32
    return std::make_unique<WindowsPlatform>();
#else
    return std::make_unique<LinuxPlatform>();
#endif
}
```

---

# 11. fejezet — Összefoglalás és továbblépés

## 11.1 Amit felépítettünk

```
gui_framework/
├── core/
│   ├── Surface.cpp/.hpp       ← framebuffer + rajzolás
│   ├── Event.hpp              ← esemény struktúrák
│   ├── EventSystem.cpp/.hpp   ← esemény olvasás
│   └── Application.cpp/.hpp  ← fő ciklus
├── widgets/
│   ├── Widget.cpp/.hpp        ← alap osztály
│   ├── Button.cpp/.hpp
│   ├── Label.cpp/.hpp
│   ├── TextInput.cpp/.hpp
│   ├── Checkbox.cpp/.hpp
│   └── Slider.cpp/.hpp
├── layout/
│   ├── HBoxLayout.hpp
│   ├── VBoxLayout.hpp
│   └── GridLayout.hpp
└── platform/
    ├── Platform.hpp
    ├── LinuxPlatform.cpp
    └── WindowsPlatform.cpp
```

## 11.2 Továbblépési lehetőségek

**Grafika:**
- PNG/BMP képek betöltése és megjelenítése
- TrueType fontok (stb_truetype.h — single header könyvtár)
- Antialiasing — simább vonalak és körök
- Alpha blending — átlátszóság

**Widgetek:**
- ScrollView — görgethető tartalom
- ListBox — elemek listája
- ComboBox — lenyíló lista
- MenuBar — menüsor
- TabView — fülek

**Teljesítmény:**
- Double buffering — villogásmentes rajzolás
- Dirty region — csak a megváltozott részek újrarajzolása
- Hardware gyorsítás — OpenGL vagy Vulkan backend

## 11.3 Inspirációs projektek

Ha mélyebbre akarsz menni, érdemes megnézni:
- **LVGL** — beágyazott rendszerekre szánt C GUI framework, nagyon jól megírt
- **Dear ImGui** — egyszerű immediate mode GUI C++-ban
- **SerenityOS LibGUI** — egy teljes, valódi OS GUI frameworkje C++-ban
- **Nuklear** — single-header C GUI könyvtár

---

*Ez a könyv egy kiindulópontot ad — a valódi tudás a kódolásból jön. Írj, törj, javíts, és fokozatosan fog összeállni a kép.*
