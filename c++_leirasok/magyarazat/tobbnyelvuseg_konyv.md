# 🌐 Többnyelvűség a Modern Programozásban

### CLI és GUI megoldások C++, C, Java, Kotlin és Python nyelveken

> *Konfigurációs fájlok • Dinamikus modellbetöltés • Platformfüggetlen megoldások*

---

## Tartalomjegyzék

1. [Előszó](#1-előszó)
2. [Az alapfogalmak: konfiguráció és többnyelvűség](#2-az-alapfogalmak)
3. [Konfigurációs fájlformátumok összehasonlítása](#3-konfigurációs-fájlformátumok)
4. [C++ megvalósítás – CLI és GUI](#4-c-megvalósítás)
5. [C megvalósítás – CLI](#5-c-megvalósítás)
6. [Java megvalósítás – CLI és Swing GUI](#6-java-megvalósítás)
7. [Kotlin megvalósítás – CLI és JavaFX GUI](#7-kotlin-megvalósítás)
8. [Python megvalósítás – CLI és tkinter GUI](#8-python-megvalósítás)
9. [Moduláris kódszerkezet és fájlszervezés](#9-moduláris-kódszerkezet)
10. [Platformfüggetlen tippek és bevált gyakorlatok](#10-platformfüggetlen-tippek)
11. [Összefoglalás és továbbfejlesztési irányok](#11-összefoglalás)

---

## 1. Előszó

Ez a könyv azoknak a fejlesztőknek szól, akik szeretnék programjaikat valóban **több nyelven működtetni** – nemcsak felhasználói felület szintjén, hanem a mélyen, a konfigurációs rendszer, az adatbetöltés és a futásidejű modellváltás szintjén is.

A példák egy fordítóprogram fejlesztéséből nőttek ki, amely gépi tanulási modelleket (**CTranslate2 + SentencePiece**) alkalmaz. Ugyanezek az elvek azonban alkalmazhatók bármilyen olyan szoftverre, ahol a „nyelv" fogalma dinamikusan cserélhető erőforrásokat jelent.

A könyv öt programozási nyelven mutatja be ugyanazt a megközelítést: **C++, C, Java, Kotlin és Python**. Minden fejezetben megtalálod a **CLI** (parancssori) és a **GUI** (grafikus) megoldásokat is.

> 📌 **Mire fókuszál ez a könyv?**
> - Konfigurációs fájlok tervezése és olvasása
> - Dinamikus nyelvválasztás futásidőben
> - Moduláris kódszerkezet (header/source szétválasztás)
> - Platformfüggetlen megoldások
> - CLI menük és GUI widgetek összehasonlítása

---

## 2. Az alapfogalmak

### Mi a „többnyelvűség" ebben a kontextusban?

Amikor fordítóprogramokról vagy NLP-eszközökről beszélünk, a „többnyelvűség" azt jelenti: a program képes legyen **futásidőben** különböző nyelvi párokat (modellfájlokat, szókészleteket) betölteni és kezelni, anélkül hogy újra kellene fordítani.

A klasszikus megközelítés: minden nyelvet **hardcoded konstansként** rögzítünk a kódban. Ez egyszerű, de merev. Ha új nyelvet kell hozzáadni, módosítani kell a forráskódot, újra fordítani, és újra tesztelni.

### A klasszikus vs. dinamikus architektúra

| Szempont | Hardcoded megoldás | Dinamikus (config) megoldás |
|---|---|---|
| Új nyelv hozzáadása | Forráskód módosítás + újrafordítás | Config fájl szerkesztése |
| Rugalmasság | Alacsony | Magas |
| Memóriahasználat | Minden modell betöltve | Csak az aktuális modell |
| Felhasználói testreszabás | Nem lehetséges | Könnyen lehetséges |
| Hibakezelés | Fordítási hiba | Futásidejű hibaüzenet |

### A dinamikus megközelítés előnyei

- ✅ Újrafordítás nélkül adható hozzá új nyelv
- ✅ A config fájlt bármilyen szövegszerkesztővel módosíthatja az adminisztrátor
- ✅ A modellek csak akkor töltődnek be, amikor szükség van rájuk (memória-hatékony)
- ✅ Hibás modell esetén a program nem omlik össze, csak üzenetet küld

### Az architektúra három rétege

```
┌─────────────────────────────────────┐
│           Felhasználói réteg        │  ← CLI menü / GUI ablak
├─────────────────────────────────────┤
│         Konfigurációs réteg         │  ← config.ini betöltése/mentése
├─────────────────────────────────────┤
│           Modell réteg              │  ← modellfájlok dinamikus betöltése
└─────────────────────────────────────┘
```

### Mappa- és fájlszerkezet (ajánlott)

```
projekt_mappa/
├── translator.exe          ← a futtatható program
├── config.ini              ← konfigurációs fájl
├── translations.txt        ← mentett fordítások (opcionális)
├── en-hu-f32/
│   ├── source.spm
│   └── model.bin
├── hu-en-f32/
│   ├── source.spm
│   └── model.bin
└── de-hu-f32/
    ├── source.spm
    └── model.bin
```

> 💡 **Kulcselv:** Az `.exe` mindig maga mellett keresi a modellmappákat. Ha a mappát áthelyezed, a program továbbra is működik – ez a **hordozhatóság** alapja.

---

## 3. Konfigurációs fájlformátumok

### A három fő lehetőség összehasonlítása

#### 1️⃣ Plain text / INI fájl (⭐ ajánlott)

**Mikor válaszd?** Szinte mindig. Egyszerű, átlátható, könnyen módosítható, nincs újrafordítás.

```ini
[Settings]
saveToFile=0
singleLineOutput=0

[Languages]
Angol-Magyar=en-hu-f32
Magyar-Angol=hu-en-f32
Nemet-Magyar=de-hu-f32
Magyar-Nemet=hu-de-f32
```

| Jellemző | Érték |
|---|---|
| Olvashatóság | ⭐⭐⭐⭐⭐ |
| Módosíthatóság | ⭐⭐⭐⭐⭐ |
| Sebesség | ⭐⭐⭐⭐ |
| Méret | Kicsi |
| Platformfüggetlenség | ⭐⭐⭐⭐⭐ |

#### 2️⃣ Bináris fájl (.sav)

**Mikor válaszd?** Csak akkor, ha extrém gyors betöltés szükséges és a fájlt soha nem kell kézzel szerkeszteni.

```cpp
void saveSettingsBinary() {
    ofstream f("settings.sav", ios::binary);
    f.write(reinterpret_cast<char*>(&saveToFile), sizeof(saveToFile));
    f.write(reinterpret_cast<char*>(&singleLineOutput), sizeof(singleLineOutput));
}

void loadSettingsBinary() {
    ifstream f("settings.sav", ios::binary);
    if (f.is_open()) {
        f.read(reinterpret_cast<char*>(&saveToFile), sizeof(saveToFile));
        f.read(reinterpret_cast<char*>(&singleLineOutput), sizeof(singleLineOutput));
    }
}
```

| Jellemző | Érték |
|---|---|
| Olvashatóság | ⭐ (nem emberi szemnek) |
| Módosíthatóság | ⭐ (csak programból) |
| Sebesség | ⭐⭐⭐⭐⭐ |
| Méret | Minimális |
| Platformfüggetlenség | ⭐⭐ (endianness-függő) |

#### 3️⃣ Hardcoded változók

**Mikor válaszd?** Prototípusnál, demónál – éles projektben kerüld.

```cpp
bool saveToFile = true;
bool singleLineOutput = false;
```

| Jellemző | Érték |
|---|---|
| Olvashatóság | ⭐⭐⭐⭐⭐ |
| Módosíthatóság | ⭐ (csak újrafordítással) |
| Sebesség | ⭐⭐⭐⭐⭐ |
| Rugalmasság | ❌ |

### Döntési fa

```
Kell-e a felhasználónak szerkeszteni a fájlt?
│
├── IGEN → INI / TXT fájl ✅
│
└── NEM → Kell-e maximális sebesség?
           │
           ├── IGEN → Bináris fájl
           │
           └── NEM → Egyszerű karakteres .sav
```

> 💡 **Következtetés:** A **`.ini` fájl** az egyértelmű győztes a legtöbb felhasználási esetre. Gyors, olvasható, hordozható, és bármikor bővíthető új beállításokkal.

---

## 4. C++ megvalósítás

### 4.1 CLI – Teljes dinamikus fordítóprogram

#### A struktúra (Language opció)

```cpp
struct LanguageOption {
    string name;       // Pl. "Angol-Magyar"
    string modelPath;  // Pl. "en-hu-f32"
};

vector<LanguageOption> availableLanguages;
```

#### Konfig betöltése (loadConfig)

```cpp
void loadConfig(const string& filename) {
    ifstream f(filename);
    if (!f.is_open()) {
        cerr << "Nem talalhato a konfig fajl: " << filename << endl;
        return;
    }

    string line;
    bool inLanguagesSection = false;

    while (getline(f, line)) {
        // Üres sor és komment kihagyása
        if (line.empty() || line[0] == ';') continue;

        // Szekció váltás detektálása
        if (line == "[Languages]") { inLanguagesSection = true;  continue; }
        if (line == "[Settings]")  { inLanguagesSection = false; continue; }

        size_t eqPos = line.find('=');
        if (eqPos == string::npos) continue;

        string key   = line.substr(0, eqPos);
        string value = line.substr(eqPos + 1);

        if (inLanguagesSection) {
            // key = "Angol-Magyar", value = "en-hu-f32"
            availableLanguages.push_back({key, value});
        } else {
            if (key == "saveToFile")      saveToFile      = (value == "1");
            if (key == "singleLineOutput") singleLineOutput = (value == "1");
        }
    }
    f.close();
}
```

#### Konfig mentése (saveConfig)

```cpp
void saveConfig(const string& filename) {
    ofstream f(filename);
    if (!f.is_open()) return;

    f << "[Settings]\n";
    f << "saveToFile="       << (saveToFile ? 1 : 0)       << "\n";
    f << "singleLineOutput=" << (singleLineOutput ? 1 : 0) << "\n";
    f << "\n[Languages]\n";

    for (const auto& lang : availableLanguages) {
        f << lang.name << "=" << lang.modelPath << "\n";
    }
    f.close();
}
```

#### Dinamikus menü és modellbetöltés (main)

```cpp
int main() {
#ifdef _WIN32
    system("chcp 65001 > nul");
    system("reg add HKCU\\Console /v VirtualTerminalLevel /t REG_DWORD /d 1 /f > nul 2>&1");
#endif

    loadConfig("config.ini");

    // Fallback: ha üres a config
    if (availableLanguages.empty()) {
        availableLanguages.push_back({"Angol-Magyar (Alap)", "en-hu-f32"});
        availableLanguages.push_back({"Magyar-Angol (Alap)", "hu-en-f32"});
    }

    while (true) {
        cout << "\n--- FOMENU ---\n";

        // Dinamikus menü generálása
        for (size_t i = 0; i < availableLanguages.size(); ++i)
            cout << (i + 1) << ". " << availableLanguages[i].name << "\n";

        int settingsIndex = availableLanguages.size() + 1;
        int exitIndex     = availableLanguages.size() + 2;

        cout << settingsIndex << ". Beallitasok\n";
        cout << exitIndex     << ". Kilepes\n";
        cout << "Valasztas: ";

        string choiceStr;
        getline(cin, choiceStr);

        int choice = 0;
        try { choice = stoi(choiceStr); } catch (...) { continue; }

        // Nyelv kiválasztása
        if (choice >= 1 && choice <= (int)availableLanguages.size()) {
            LanguageOption& sel = availableLanguages[choice - 1];
            string spmPath = sel.modelPath + "/source.spm";

            cout << "Modell betoltese: " << sel.name << " ...\n";

            ifstream check(spmPath);
            if (!check.good()) {
                cerr << "HIBA: Nem talalhato: " << spmPath << "\n";
                continue;
            }

            try {
                sentencepiece::SentencePieceProcessor sp;
                sp.Load(spmPath);

                ctranslate2::models::ModelLoader loader(sel.modelPath);
                ctranslate2::Translator translator(loader);

                translateLoop(translator, sp, sp);
            } catch (const exception& e) {
                cerr << "Hiba: " << e.what() << "\n";
            }
        }
        else if (choice == settingsIndex) { settingsMenu(); }
        else if (choice == exitIndex)     { saveConfig("config.ini"); exit(0); }
    }
    return 0;
}
```

#### A fordítóhurok (translateLoop)

```cpp
void translateLoop(ctranslate2::Translator& translator,
                   sentencepiece::SentencePieceProcessor& sp_source,
                   sentencepiece::SentencePieceProcessor& sp_target) {

    cout << "\n--- FORDITO MOD ---\n";
    cout << "Parancsok: /back (vissza), /cls (kepernyo torles)\n\n";

    string line;
    while (true) {
        if (!singleLineOutput) cout << "> ";
        getline(cin, line);

        if (line == "/back") { clearScreen(); break; }
        if (line == "/cls")  { clearScreen(); continue; }
        if (line.empty())    continue;

        // Tokenizálás
        vector<string> tokens;
        sp_source.Encode(line, &tokens);
        tokens.emplace_back("</s>");

        // Fordítás
        ctranslate2::TranslationOptions opts;
        opts.beam_size = 2;
        opts.max_decoding_length = 200;

        auto results = translator.translate_batch({tokens}, opts);

        string out;
        sp_target.Decode(results[0].output(), &out);

        // Kiírás
        if (singleLineOutput)
            cout << "\033[1A\033[2K\r" << line << " -> " << out << "\n";
        else
            cout << line << " -> " << out << "\n";

        // Mentés fájlba
        if (saveToFile) {
            ofstream f(outputFile, ios::app);
            if (f.is_open()) f << line << " -> " << out << "\n";
        }
    }
}
```

### 4.2 Moduláris fájlszerkezet (ajánlott)

Nagy projekteknél érdemes szétválasztani a fájlokat:

```
projekt/
├── main.cpp
├── config.h / config.cpp     ← konfiguráció betöltése/mentése
├── settings.h / settings.cpp ← beállítások kezelése
├── translator.h / translator.cpp ← fordítási logika
└── ui.h / ui.cpp             ← menük és kiírás
```

**settings.h**

```cpp
#pragma once
#include <string>
#include <vector>

struct LanguageOption {
    std::string name;
    std::string modelPath;
};

// Globális változók deklarációja
extern bool saveToFile;
extern bool singleLineOutput;
extern std::string outputFile;
extern std::vector<LanguageOption> availableLanguages;

// Függvény deklarációk
void loadConfig(const std::string& filename);
void saveConfig(const std::string& filename);
void settingsMenu();
```

**settings.cpp**

```cpp
#include "settings.h"
#include <fstream>
#include <iostream>

// Változók definíciója (csak itt!)
bool saveToFile        = false;
bool singleLineOutput  = false;
std::string outputFile = "translations.txt";
std::vector<LanguageOption> availableLanguages;

void loadConfig(const std::string& filename) {
    // ... (lásd fent)
}

void saveConfig(const std::string& filename) {
    // ... (lásd fent)
}
```

**main.cpp**

```cpp
#include "settings.h"
#include "translator.h"
#include <iostream>

int main() {
    loadConfig("config.ini");
    // ... menü logika ...
    saveConfig("config.ini");
    return 0;
}
```

> 💡 Az `extern` kulcsszó jelzi: a változó *másik* fordítási egységben van definiálva. Így több `.cpp` fájl ugyanazokat a globálisokat látja.

### 4.3 GUI megvalósítás – Qt alapok

Qt-ban a dinamikus nyelvi lista egy `QComboBox`-ba kerülhet:

```cpp
#include <QApplication>
#include <QComboBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

class TranslatorWindow : public QWidget {
    Q_OBJECT
public:
    TranslatorWindow(QWidget* parent = nullptr) : QWidget(parent) {
        auto* layout   = new QVBoxLayout(this);
        auto* langBox  = new QComboBox(this);
        auto* startBtn = new QPushButton("Fordítás indítása", this);

        // Dinamikus feltöltés a config alapján
        for (const auto& lang : availableLanguages)
            langBox->addItem(QString::fromStdString(lang.name));

        layout->addWidget(langBox);
        layout->addWidget(startBtn);

        connect(startBtn, &QPushButton::clicked, [=]() {
            int idx = langBox->currentIndex();
            if (idx >= 0 && idx < (int)availableLanguages.size()) {
                // Modell betöltése és fordítási ablak megnyitása
                loadAndStartTranslation(availableLanguages[idx]);
            }
        });
    }
};
```

---

## 5. C megvalósítás

C-ben nincs `vector` vagy `string`, ezért tömbökkel és `char*`-gal dolgozunk.

### 5.1 Struktúra és globálisok

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LANGUAGES 32
#define MAX_NAME_LEN  64
#define MAX_PATH_LEN  256

typedef struct {
    char name[MAX_NAME_LEN];
    char modelPath[MAX_PATH_LEN];
} LanguageOption;

static LanguageOption availableLanguages[MAX_LANGUAGES];
static int            languageCount = 0;
static bool           saveToFile   = false;
static bool           singleLine   = false;
```

### 5.2 Konfig betöltése

```c
void loadConfig(const char* filename) {
    FILE* f = fopen(filename, "r");
    if (!f) {
        fprintf(stderr, "Nem talalhato: %s\n", filename);
        return;
    }

    char line[512];
    bool inLanguages = false;

    while (fgets(line, sizeof(line), f)) {
        // Sortörés eltávolítása
        size_t len = strlen(line);
        if (len > 0 && line[len-1] == '\n') line[len-1] = '\0';

        if (line[0] == '\0' || line[0] == ';') continue;

        if (strcmp(line, "[Languages]") == 0) { inLanguages = true;  continue; }
        if (strcmp(line, "[Settings]")  == 0) { inLanguages = false; continue; }

        char* eq = strchr(line, '=');
        if (!eq) continue;

        *eq = '\0';          // line = key
        char* value = eq + 1; // value = érték

        if (inLanguages && languageCount < MAX_LANGUAGES) {
            strncpy(availableLanguages[languageCount].name,      line,  MAX_NAME_LEN - 1);
            strncpy(availableLanguages[languageCount].modelPath, value, MAX_PATH_LEN - 1);
            languageCount++;
        } else {
            if (strcmp(line, "saveToFile")       == 0) saveToFile = (value[0] == '1');
            if (strcmp(line, "singleLineOutput") == 0) singleLine = (value[0] == '1');
        }
    }
    fclose(f);
}
```

### 5.3 Dinamikus menü

```c
void showMenu(void) {
    printf("\n--- FOMENU ---\n");
    for (int i = 0; i < languageCount; i++)
        printf("%d. %s\n", i + 1, availableLanguages[i].name);

    printf("%d. Beallitasok\n", languageCount + 1);
    printf("%d. Kilepes\n",     languageCount + 2);
    printf("Valasztas: ");
}

int main(void) {
    loadConfig("config.ini");

    char input[16];
    while (1) {
        showMenu();
        if (!fgets(input, sizeof(input), stdin)) break;
        int choice = atoi(input);

        if (choice >= 1 && choice <= languageCount) {
            printf("Betoltes: %s\n", availableLanguages[choice-1].name);
            // ... modell betöltése C API-n keresztül ...
        } else if (choice == languageCount + 2) {
            printf("Kilepes...\n");
            break;
        }
    }
    return 0;
}
```

### 5.4 Bináris konfig mentése C-ben

```c
void saveSettingsBinary(const char* filename) {
    FILE* f = fopen(filename, "wb");
    if (!f) return;
    fwrite(&saveToFile, sizeof(bool), 1, f);
    fwrite(&singleLine, sizeof(bool), 1, f);
    fclose(f);
}

void loadSettingsBinary(const char* filename) {
    FILE* f = fopen(filename, "rb");
    if (!f) return;
    fread(&saveToFile, sizeof(bool), 1, f);
    fread(&singleLine, sizeof(bool), 1, f);
    fclose(f);
}
```

> ⚠️ **Figyelem:** A bináris fájl platformfüggő lehet (`bool` mérete, endianness). Csak akkor használd, ha biztosan ugyanazon a platformon fut minden telepítés.

---

## 6. Java megvalósítás

### 6.1 Modellosztályok

```java
// LanguageOption.java
public class LanguageOption {
    private final String name;
    private final String modelPath;

    public LanguageOption(String name, String modelPath) {
        this.name      = name;
        this.modelPath = modelPath;
    }

    public String getName()      { return name; }
    public String getModelPath() { return modelPath; }

    @Override
    public String toString() { return name; }
}
```

### 6.2 Konfig kezelő osztály

```java
// ConfigManager.java
import java.io.*;
import java.util.*;

public class ConfigManager {
    private boolean saveToFile      = false;
    private boolean singleLineOutput = false;
    private List<LanguageOption> languages = new ArrayList<>();

    public void load(String filename) throws IOException {
        File file = new File(filename);
        if (!file.exists()) return;

        boolean inLanguages = false;

        try (BufferedReader reader = new BufferedReader(new FileReader(file))) {
            String line;
            while ((line = reader.readLine()) != null) {
                line = line.trim();
                if (line.isEmpty() || line.startsWith(";")) continue;

                if (line.equals("[Languages]")) { inLanguages = true;  continue; }
                if (line.equals("[Settings]"))  { inLanguages = false; continue; }

                int eqIdx = line.indexOf('=');
                if (eqIdx < 0) continue;

                String key   = line.substring(0, eqIdx).trim();
                String value = line.substring(eqIdx + 1).trim();

                if (inLanguages) {
                    languages.add(new LanguageOption(key, value));
                } else {
                    switch (key) {
                        case "saveToFile"       -> saveToFile       = value.equals("1");
                        case "singleLineOutput" -> singleLineOutput = value.equals("1");
                    }
                }
            }
        }
    }

    public void save(String filename) throws IOException {
        try (PrintWriter writer = new PrintWriter(new FileWriter(filename))) {
            writer.println("[Settings]");
            writer.println("saveToFile="       + (saveToFile ? 1 : 0));
            writer.println("singleLineOutput=" + (singleLineOutput ? 1 : 0));
            writer.println();
            writer.println("[Languages]");
            for (LanguageOption lang : languages)
                writer.println(lang.getName() + "=" + lang.getModelPath());
        }
    }

    // Getterek
    public List<LanguageOption> getLanguages()     { return languages; }
    public boolean isSaveToFile()                  { return saveToFile; }
    public boolean isSingleLineOutput()            { return singleLineOutput; }
    public void setSaveToFile(boolean v)           { saveToFile = v; }
    public void setSingleLineOutput(boolean v)     { singleLineOutput = v; }
}
```

### 6.3 CLI menü

```java
// TranslatorCLI.java
import java.util.*;

public class TranslatorCLI {
    private final ConfigManager config;
    private final Scanner scanner = new Scanner(System.in);

    public TranslatorCLI(ConfigManager config) {
        this.config = config;
    }

    public void run() {
        List<LanguageOption> langs = config.getLanguages();

        while (true) {
            System.out.println("\n--- FOMENU ---");

            for (int i = 0; i < langs.size(); i++)
                System.out.println((i + 1) + ". " + langs.get(i).getName());

            int settingsIdx = langs.size() + 1;
            int exitIdx     = langs.size() + 2;
            System.out.println(settingsIdx + ". Beallitasok");
            System.out.println(exitIdx     + ". Kilepes");
            System.out.print("Valasztas: ");

            try {
                int choice = Integer.parseInt(scanner.nextLine().trim());

                if (choice >= 1 && choice <= langs.size()) {
                    startTranslation(langs.get(choice - 1));
                } else if (choice == settingsIdx) {
                    showSettings();
                } else if (choice == exitIdx) {
                    System.out.println("Viszlat!");
                    return;
                }
            } catch (NumberFormatException e) {
                // Érvénytelen input – újra kérdez
            }
        }
    }

    private void startTranslation(LanguageOption lang) {
        System.out.println("Betoltes: " + lang.getName() + " ...");
        // ... modell betöltése és fordítási ciklus ...
        System.out.println("(fordítási mód itt lenne)");
    }

    private void showSettings() {
        System.out.println("\n--- BEALLITASOK ---");
        System.out.println("1. Mentés fájlba: " + (config.isSaveToFile() ? "BE" : "KI"));
        System.out.println("2. Egysoros kimenet: " + (config.isSingleLineOutput() ? "BE" : "KI"));
        // ...
    }

    public static void main(String[] args) {
        ConfigManager config = new ConfigManager();
        try {
            config.load("config.ini");
        } catch (IOException e) {
            System.err.println("Konfig betöltési hiba: " + e.getMessage());
        }

        new TranslatorCLI(config).run();

        try {
            config.save("config.ini");
        } catch (IOException e) {
            System.err.println("Konfig mentési hiba: " + e.getMessage());
        }
    }
}
```

### 6.4 Swing GUI

```java
// TranslatorGUI.java
import javax.swing.*;
import java.awt.*;

public class TranslatorGUI extends JFrame {
    private final ConfigManager config;
    private final JComboBox<LanguageOption> languageBox;
    private final JTextArea inputArea;
    private final JTextArea outputArea;

    public TranslatorGUI(ConfigManager config) {
        this.config = config;

        setTitle("Fordítóprogram");
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        // Felső panel: nyelvválasztó
        JPanel topPanel = new JPanel(new FlowLayout());
        languageBox = new JComboBox<>();
        for (LanguageOption lang : config.getLanguages())
            languageBox.addItem(lang);

        JButton translateBtn = new JButton("Fordít");
        topPanel.add(new JLabel("Nyelv:"));
        topPanel.add(languageBox);
        topPanel.add(translateBtn);

        // Középső panel: szövegterületek
        inputArea  = new JTextArea(8, 40);
        outputArea = new JTextArea(8, 40);
        outputArea.setEditable(false);

        JPanel centerPanel = new JPanel(new GridLayout(1, 2, 10, 0));
        centerPanel.add(new JScrollPane(inputArea));
        centerPanel.add(new JScrollPane(outputArea));

        add(topPanel, BorderLayout.NORTH);
        add(centerPanel, BorderLayout.CENTER);

        // Fordítás gomb esemény
        translateBtn.addActionListener(e -> {
            LanguageOption selected = (LanguageOption) languageBox.getSelectedItem();
            if (selected != null) {
                String input = inputArea.getText().trim();
                // ... fordítás elvégzése ...
                outputArea.setText("(fordítás eredménye itt jelenne meg)");
            }
        });

        pack();
        setLocationRelativeTo(null);
    }

    public static void main(String[] args) {
        ConfigManager config = new ConfigManager();
        try { config.load("config.ini"); }
        catch (IOException e) { e.printStackTrace(); }

        SwingUtilities.invokeLater(() -> {
            new TranslatorGUI(config).setVisible(true);
        });
    }
}
```

---

## 7. Kotlin megvalósítás

### 7.1 Data class és konfig

```kotlin
// LanguageOption.kt
data class LanguageOption(
    val name: String,
    val modelPath: String
)
```

```kotlin
// ConfigManager.kt
import java.io.File

data class AppConfig(
    val saveToFile: Boolean = false,
    val singleLineOutput: Boolean = false,
    val languages: List<LanguageOption> = emptyList()
)

object ConfigManager {

    fun load(filename: String): AppConfig {
        val file = File(filename)
        if (!file.exists()) return AppConfig()

        var saveToFile       = false
        var singleLineOutput = false
        val languages        = mutableListOf<LanguageOption>()
        var inLanguages      = false

        file.forEachLine { rawLine ->
            val line = rawLine.trim()
            if (line.isEmpty() || line.startsWith(";")) return@forEachLine

            when (line) {
                "[Languages]" -> { inLanguages = true;  return@forEachLine }
                "[Settings]"  -> { inLanguages = false; return@forEachLine }
            }

            val eqIdx = line.indexOf('=')
            if (eqIdx < 0) return@forEachLine

            val key   = line.substring(0, eqIdx).trim()
            val value = line.substring(eqIdx + 1).trim()

            if (inLanguages) {
                languages.add(LanguageOption(key, value))
            } else {
                when (key) {
                    "saveToFile"       -> saveToFile       = value == "1"
                    "singleLineOutput" -> singleLineOutput = value == "1"
                }
            }
        }

        return AppConfig(saveToFile, singleLineOutput, languages)
    }

    fun save(filename: String, config: AppConfig) {
        File(filename).printWriter().use { out ->
            out.println("[Settings]")
            out.println("saveToFile=${if (config.saveToFile) 1 else 0}")
            out.println("singleLineOutput=${if (config.singleLineOutput) 1 else 0}")
            out.println()
            out.println("[Languages]")
            config.languages.forEach { lang ->
                out.println("${lang.name}=${lang.modelPath}")
            }
        }
    }
}
```

### 7.2 CLI menü – idiomatikus Kotlin

```kotlin
// main.kt
fun main() {
    var config = ConfigManager.load("config.ini")
    val languages = config.languages

    mainLoop@ while (true) {
        println("\n--- FOMENU ---")
        languages.forEachIndexed { i, lang ->
            println("${i + 1}. ${lang.name}")
        }
        println("${languages.size + 1}. Beallitasok")
        println("${languages.size + 2}. Kilepes")
        print("Valasztas: ")

        val choice = readLine()?.trim()?.toIntOrNull() ?: continue@mainLoop

        when {
            choice in 1..languages.size -> {
                val lang = languages[choice - 1]
                println("Betoltes: ${lang.name} ...")
                // startTranslation(lang, config)
            }
            choice == languages.size + 1 -> {
                config = showSettings(config)
                ConfigManager.save("config.ini", config)
            }
            choice == languages.size + 2 -> {
                println("Viszlat!")
                break@mainLoop
            }
        }
    }
}
```

### 7.3 JavaFX GUI – Kotlin stílusban

```kotlin
// TranslatorApp.kt
import javafx.application.Application
import javafx.geometry.Insets
import javafx.scene.Scene
import javafx.scene.control.*
import javafx.scene.layout.*
import javafx.stage.Stage

class TranslatorApp : Application() {
    override fun start(primaryStage: Stage) {
        val config = ConfigManager.load("config.ini")

        // Nyelvválasztó
        val langCombo = ComboBox<LanguageOption>().apply {
            items.addAll(config.languages)
            selectionModel.selectFirst()
            maxWidth = Double.MAX_VALUE
        }

        // Szövegterületek
        val inputArea  = TextArea().apply { promptText = "Írd be a fordítandó szöveget..."; prefHeight = 200.0 }
        val outputArea = TextArea().apply { isEditable = false; prefHeight = 200.0; promptText = "Fordítás..." }

        // Fordítás gomb
        val translateBtn = Button("⚡ Fordít").apply {
            maxWidth = Double.MAX_VALUE
            setOnAction {
                val lang = langCombo.selectionModel.selectedItem ?: return@setOnAction
                val text = inputArea.text.trim()
                if (text.isNotEmpty()) {
                    // outputArea.text = performTranslation(lang, text)
                    outputArea.text = "(fordítás: ${lang.name})"
                }
            }
        }

        // Layout
        val root = VBox(10.0).apply {
            padding = Insets(15.0)
            children.addAll(
                Label("Fordítási irány:"),
                langCombo,
                HBox(10.0, inputArea, outputArea).also {
                    HBox.setHgrow(inputArea,  javafx.scene.layout.Priority.ALWAYS)
                    HBox.setHgrow(outputArea, javafx.scene.layout.Priority.ALWAYS)
                },
                translateBtn
            )
        }

        primaryStage.apply {
            title = "Fordítóprogram"
            scene = Scene(root, 800.0, 500.0)
            show()
        }
    }
}

fun main() = Application.launch(TranslatorApp::class.java)
```

---

## 8. Python megvalósítás

### 8.1 Konfig kezelő osztály

```python
# config_manager.py
from dataclasses import dataclass, field
from typing import List
from pathlib import Path


@dataclass
class LanguageOption:
    name: str
    model_path: str

    def __str__(self):
        return self.name


@dataclass
class AppConfig:
    save_to_file:       bool = False
    single_line_output: bool = False
    languages:          List[LanguageOption] = field(default_factory=list)


class ConfigManager:
    def load(self, filename: str) -> AppConfig:
        path = Path(filename)
        if not path.exists():
            return AppConfig()

        config        = AppConfig()
        in_languages  = False

        with path.open(encoding="utf-8") as f:
            for raw_line in f:
                line = raw_line.strip()
                if not line or line.startswith(";"):
                    continue

                if line == "[Languages]":
                    in_languages = True
                    continue
                if line == "[Settings]":
                    in_languages = False
                    continue

                if "=" not in line:
                    continue
                key, _, value = line.partition("=")
                key, value = key.strip(), value.strip()

                if in_languages:
                    config.languages.append(LanguageOption(key, value))
                else:
                    if key == "saveToFile":
                        config.save_to_file = value == "1"
                    elif key == "singleLineOutput":
                        config.single_line_output = value == "1"

        return config

    def save(self, filename: str, config: AppConfig) -> None:
        with open(filename, "w", encoding="utf-8") as f:
            f.write("[Settings]\n")
            f.write(f"saveToFile={1 if config.save_to_file else 0}\n")
            f.write(f"singleLineOutput={1 if config.single_line_output else 0}\n")
            f.write("\n[Languages]\n")
            for lang in config.languages:
                f.write(f"{lang.name}={lang.model_path}\n")
```

### 8.2 CLI menü

```python
# cli.py
import os
from config_manager import ConfigManager, AppConfig

def clear_screen():
    os.system("cls" if os.name == "nt" else "clear")

def show_menu(config: AppConfig) -> None:
    print("\n--- FOMENU ---")
    for i, lang in enumerate(config.languages, 1):
        print(f"{i}. {lang.name}")
    n = len(config.languages)
    print(f"{n + 1}. Beallitasok")
    print(f"{n + 2}. Kilepes")

def main():
    manager = ConfigManager()
    config  = manager.load("config.ini")
    langs   = config.languages

    while True:
        show_menu(config)
        try:
            choice = int(input("Valasztas: "))
        except ValueError:
            continue

        if 1 <= choice <= len(langs):
            lang = langs[choice - 1]
            clear_screen()
            print(f"Betoltes: {lang.name} ({lang.model_path})...")
            translation_loop(lang, config)

        elif choice == len(langs) + 1:
            settings_menu(config, manager)

        elif choice == len(langs) + 2:
            manager.save("config.ini", config)
            print("Viszlat!")
            break

def translation_loop(lang, config: AppConfig):
    print(f"\n--- FORDITO MOD: {lang.name} ---")
    print("Parancsok: /back, /cls\n")

    # Modellek betöltése
    # sp = sentencepiece.SentencePieceProcessor()
    # sp.load(f"{lang.model_path}/source.spm")

    while True:
        text = input("> " if not config.single_line_output else "")
        if text == "/back":
            clear_screen()
            break
        if text == "/cls":
            clear_screen()
            continue
        if not text:
            continue

        # Fordítás (valós implementációban itt hívnád a modellt)
        result = f"(fordítás: {text})"

        if config.single_line_output:
            print(f"\033[1A\033[2K\r{text} -> {result}")
        else:
            print(f"{text} -> {result}")

        if config.save_to_file:
            with open("translations.txt", "a", encoding="utf-8") as f:
                f.write(f"{text} -> {result}\n")

if __name__ == "__main__":
    main()
```

### 8.3 tkinter GUI

```python
# gui_tkinter.py
import tkinter as tk
from tkinter import ttk, scrolledtext
from config_manager import ConfigManager

class TranslatorApp(tk.Tk):
    def __init__(self):
        super().__init__()
        self.title("Fordítóprogram")
        self.geometry("900x500")
        self.resizable(True, True)

        self.manager = ConfigManager()
        self.config  = self.manager.load("config.ini")

        self._build_ui()

    def _build_ui(self):
        # Felső keretsor
        top_frame = ttk.Frame(self, padding=10)
        top_frame.pack(fill=tk.X)

        ttk.Label(top_frame, text="Fordítási irány:").pack(side=tk.LEFT)

        # Dinamikus ComboBox a config alapján
        self.lang_var = tk.StringVar()
        lang_names    = [lang.name for lang in self.config.languages]
        self.lang_box = ttk.Combobox(
            top_frame,
            values=lang_names,
            textvariable=self.lang_var,
            state="readonly",
            width=30
        )
        if lang_names:
            self.lang_box.current(0)
        self.lang_box.pack(side=tk.LEFT, padx=10)

        ttk.Button(top_frame, text="⚡ Fordít",
                   command=self._translate).pack(side=tk.LEFT)

        # Szövegterületek
        text_frame = ttk.Frame(self, padding=10)
        text_frame.pack(fill=tk.BOTH, expand=True)

        ttk.Label(text_frame, text="Forrásszöveg:").grid(
            row=0, column=0, sticky=tk.W)
        ttk.Label(text_frame, text="Fordítás:").grid(
            row=0, column=1, sticky=tk.W, padx=(10, 0))

        self.input_area = scrolledtext.ScrolledText(
            text_frame, width=45, height=18, font=("Consolas", 11))
        self.input_area.grid(row=1, column=0, sticky=tk.NSEW)

        self.output_area = scrolledtext.ScrolledText(
            text_frame, width=45, height=18,
            font=("Consolas", 11), state=tk.DISABLED)
        self.output_area.grid(row=1, column=1, sticky=tk.NSEW, padx=(10, 0))

        text_frame.columnconfigure(0, weight=1)
        text_frame.columnconfigure(1, weight=1)
        text_frame.rowconfigure(1, weight=1)

    def _translate(self):
        lang_name = self.lang_var.get()
        selected = next(
            (l for l in self.config.languages if l.name == lang_name), None)
        if not selected:
            return

        text = self.input_area.get("1.0", tk.END).strip()
        if not text:
            return

        # Valós fordítás helyett placeholder
        result = f"(fordítás {lang_name}: {text[:50]}...)"

        self.output_area.config(state=tk.NORMAL)
        self.output_area.delete("1.0", tk.END)
        self.output_area.insert("1.0", result)
        self.output_area.config(state=tk.DISABLED)

    def on_close(self):
        self.manager.save("config.ini", self.config)
        self.destroy()


if __name__ == "__main__":
    app = TranslatorApp()
    app.protocol("WM_DELETE_WINDOW", app.on_close)
    app.mainloop()
```

---

## 9. Moduláris kódszerkezet

### Általános elvek

Bármely programozási nyelven ugyanazokat az elveket érdemes követni a többnyelvű konfigurációs rendszer felépítésekor:

```
┌──────────────────────────────────────────────┐
│                  MODULOK                      │
│                                              │
│  config_module     ← fájl olvasás/írás       │
│  language_module   ← struktúrák, lista       │
│  ui_module         ← menük, ablakok          │
│  translation_module← modell, fordítás        │
│  settings_module   ← beállítások kezelése    │
└──────────────────────────────────────────────┘
```

### Összehasonlítás: modulszerkezet nyelvek szerint

| Nyelv | Modul egység | Fájlok |
|---|---|---|
| C++ | `.h` + `.cpp` fájlpárok | `config.h/cpp`, `settings.h/cpp` |
| C | `.h` + `.c` fájlpárok | `config.h/c`, `menu.h/c` |
| Java | Osztályok, csomagok | `ConfigManager.java`, `LanguageOption.java` |
| Kotlin | `object` + `data class` | `ConfigManager.kt`, `LanguageOption.kt` |
| Python | Modulok (`.py` fájlok) | `config_manager.py`, `cli.py`, `gui.py` |

### A „Lazy Loading" elv

A modellek betöltésére mindig **lazy loading**-ot alkalmazz: csak akkor töltsd be a modellt, amikor ténylegesen szükség van rá.

```
Indítás
  │
  ├── loadConfig() ← csak a config fájlt olvassa be (gyors)
  │
  └── Felhasználó választ
        │
        └── loadModel() ← MOST töltjük be a modellt (lehet lassú, de csak egyszer)
```

Ez szemben áll az **eager loading**-gal, ahol minden modell betöltődik indításkor – ez sok RAM-ot és hosszú indítási időt eredményez.

---

## 10. Platformfüggetlen tippek

### Útvonalak kezelése

Az egyik leggyakoribb hiba: Windows-on `\`, Linux/Mac-en `/` az elválasztó. Használj `/`-t mindenütt – Windows is elfogadja.

**C++ / C:**
```cpp
// ROSSZ (csak Windows):
string path = "en-hu-f32\\source.spm";

// JÓ (minden platformon működik):
string path = "en-hu-f32/source.spm";
```

**Java / Kotlin:**
```java
// Legjobb: File.separator vagy Path API
Path modelPath = Paths.get("en-hu-f32", "source.spm");
```

**Python:**
```python
# Legjobb: pathlib
from pathlib import Path
model_path = Path("en-hu-f32") / "source.spm"
```

### Karakterkódolás

Mindig UTF-8-at használj a konfigurációs fájlokban és a forráskódban!

**C++ (Windows):**
```cpp
// Windows konzolon UTF-8 engedélyezése
#ifdef _WIN32
    system("chcp 65001 > nul");
#endif
```

**Java:**
```java
// Fájlolvasásnál mindig add meg az encoding-ot
new BufferedReader(new InputStreamReader(
    new FileInputStream(file), StandardCharsets.UTF_8))
```

**Python:**
```python
# Fájlolvasásnál
with open(filename, encoding="utf-8") as f:
    ...
```

### Hordozható mappaszerkezet

```
📁 myapp/
├── 🖥️ myapp.exe / myapp      ← futtatható
├── ⚙️ config.ini              ← konfiguráció
├── 📄 translations.txt        ← mentett fordítások
└── 📁 models/
    ├── 📁 en-hu-f32/
    ├── 📁 hu-en-f32/
    └── 📁 de-hu-f32/
```

Az `exe` mindig maga mellett keressen mindent – relatív útvonalakkal. Így a teljes mappát bárhová átmásolhatod.

### Hibakezelés bevált mintái

```cpp
// C++ – try/catch minden modellbetöltésnél
try {
    auto model = loadModel(path);
    runTranslation(model);
} catch (const std::exception& e) {
    std::cerr << "Hiba a betöltésnél: " << e.what() << "\n";
    // → visszatér a menühöz, NEM crashel
}
```

```python
# Python
try:
    model = load_model(path)
except FileNotFoundError:
    print(f"A modell nem található: {path}")
except Exception as e:
    print(f"Váratlan hiba: {e}")
```

---

## 11. Összefoglalás

### A tanulságok egy helyen

A többnyelvű, konfiguráció-vezérelt program tervezésekor öt alapelvet kövess:

**1. Szeparáld a konfigurációt a logikától.** A `config.ini` fájl tartalmazza, *mi* töltsön be. A kód tartalmazza, *hogyan*.

**2. Lazy loading minden esetben.** Ne töltsd be az összes modellt indításkor. Töltsd be azt, amelyiket a felhasználó épp kért.

**3. Relatív útvonalak mindenhol.** Az alkalmazás mindig maga mellett keressen minden fájlt. Ez teszi hordozhatóvá.

**4. UTF-8 mindenhol.** Minden fájlban, minden olvasási/írási műveletnél. Különösen fontos Windows-on.

**5. Moduláris kód.** A konfig, a menü és a fordítás logikája legyen szétválasztva. Így bővíthető, tesztelhető és karbantartható.

### Gyors összehasonlítás – melyik nyelven mi a legjobb megoldás?

| Feladat | C++ | C | Java | Kotlin | Python |
|---|---|---|---|---|---|
| Config betöltés | `ifstream` + szekció parse | `fgets` + `strchr` | `BufferedReader` | `File.forEachLine` | `configparser` / kézi |
| Dinamikus lista | `vector<struct>` | tömb + méret | `ArrayList<>` | `List<data class>` | `list[dataclass]` |
| CLI menü | `cout` + `cin` loop | `printf` + `scanf` | `Scanner` loop | `readLine()` loop | `input()` loop |
| GUI widget | Qt `QComboBox` | GTK `GtkComboBox` | Swing `JComboBox` | JavaFX `ComboBox` | tkinter `Combobox` |
| Fájlírás | `ofstream` | `fopen/fprintf` | `PrintWriter` | `File.printWriter()` | `open("w")` |

### Továbblépési lehetőségek

- **JSON konfig:** `nlohmann/json` (C++), `org.json` (Java), `json` (Python) – strukturáltabb, de bonyolultabb
- **SQLite adatbázis:** ha a nyelvek és beállítások száma nagy mértékben nő
- **Online modellek:** az útvonal helyett URL – a program letölti, ha nem találja lokálisan
- **Plugin rendszer:** a modellek `.dll`/`.so` fájlokba szervezett betölthető modulok
- **GUI konfigurátor:** grafikus felület a `config.ini` szerkesztéséhez, kézzel való szerkesztés nélkül

---

> 💬 *„A legjobb szoftver az, amelyiket egy évvel később is könnyen megérted és bővíted."*

---

*© 2025 – Többnyelvűség a Modern Programozásban*
