# programQuiz.cpp — mistakeExercise — Részletes magyarázat / Detailed Explanation

---

## A fájl célja / Purpose of the file

Ez a függvény a **hibagyakorló módot** valósítja meg. Beolvassa az előzőleg elrontott szópárokat a `mistakes.data` fájlból, kvízként felteszi őket a felhasználónak, majd a fájlt **felülírja** a még mindig elrontott szavakkal — azok, amiket helyesen megválaszolt, eltűnnek a listáról.

This function implements the **mistake practice mode**. It reads previously incorrect word pairs from the `mistakes.data` file, quizzes the user on them, then **overwrites** the file with only the still-mistaken words — those answered correctly disappear from the list.

---

## Fejlécek / Headers

```cpp
#include "programQuiz.h"
#include "../FileIO/dataFileReading.h"
#include "../Translate/translations.h"
#include "../Common/generalFunctions.h"
#include "../Settings/colors.h"
#include <iostream>
#include <vector>
#include <fstream>
#include "settings.h"
#include "newInput/platformInput.h"
```

| Include | Mit csinál / What it does |
|---|---|
| `<vector>` | `std::vector` dinamikus tömb a szópárok tárolásához. / Dynamic array for storing word pairs. |
| `<fstream>` | `std::ofstream` a fájl felülírásához. / `std::ofstream` for overwriting the file. |
| `"../Settings/colors.h"` | ANSI színkódok (pl. zöld helyes, piros rossz válasznál). / ANSI color codes (e.g. green for correct, red for wrong). |
| `"settings.h"` | Globális beállítások: `showHelp`, `helperUsed`, `resumeIndex`, `useColors`, `useSound` stb. / Global settings. |
| `"newInput/platformInput.h"` | `readLineWithHotkey`: billentyűzet-kezelés Ctrl+C és Ctrl+Y figyeléssel. / Keyboard input with Ctrl+C and Ctrl+Y detection. |

---

## Az útvonal meghatározása / Determining the file path

```cpp
std::string path;
#ifdef _WIN32
    path = "data\\mistakes\\mistakes.data";
#else
    path = "data/mistakes/mistakes.data";
#endif
```

Platform-specifikus elérési út. Windowson `\\` (dupla fordított perjel a stringben, mert az egyszeres `\` escape-karakter lenne), Linuxon `/`. Ez ugyanaz a mintázat, amit az előző fájlokban láttunk.

Platform-specific path. On Windows `\\` (double backslash in the string because a single `\` would be an escape character), on Linux `/`. This is the same pattern seen in previous files.

---

## `loadSettings()` hívás

```cpp
loadSettings();
```

A globális beállításokat tölti be (pl. `resumeIndex`, `showHelp`), mielőtt bármit csinálnánk. Ez biztosítja, hogy ha a felhasználó előző session közben kilépett, onnan folytatjuk, ahol abbahagyta.

Loads global settings (e.g. `resumeIndex`, `showHelp`) before doing anything else. This ensures that if the user exited mid-session previously, we continue from where they left off.

---

## A két vektor / The two vectors

```cpp
std::vector<WordPair> mistakeWords = loadWords(path);
std::vector<WordPair> stillMistakes;
```

- `mistakeWords` — Az összes szópár a fájlból. Ez a **forrás**, nem változik a kvíz közben.
- `stillMistakes` — Ide gyűjtjük azokat a szavakat, amelyeket a felhasználó **nem tudott helyesen megválaszolni**, vagy amelyek elé nem ért (kilépés esetén). A kvíz végén ezt írjuk vissza a fájlba.

- `mistakeWords` — All word pairs from the file. This is the **source** and does not change during the quiz.
- `stillMistakes` — Here we collect words the user **could not answer correctly**, or words not yet reached (on exit). This is written back to the file at the end of the quiz.

---

## `bool realExit = false`

Jelző arra, hogy a felhasználó szándékosan lépett-e ki (`exit` / `e` / Ctrl+C). Ha `true`, a külső `for` ciklus leáll (`!realExit` feltétel miatt). Arra kell, mert egy belső végtelen ciklusból (`for (;;)`) `break`-kel lép ki a kód, és a `break` csak a közvetlen szülő ciklust állítja meg — a külső `for`-t nem. A `realExit` ezt a kommunikációt oldja meg.

A flag indicating whether the user intentionally exited (`exit` / `e` / Ctrl+C). If `true`, the outer `for` loop stops (due to the `!realExit` condition). This is needed because the code exits the inner infinite loop (`for (;;)`) with `break`, and `break` only stops the immediate parent loop — not the outer `for`. `realExit` solves this communication problem.

---

## `resumeIndex` ellenőrzése / checking

```cpp
if (resumeIndex >= mistakeWords.size()) {
    resumeIndex = 0;
}
```

### `size_t` és `.size()`

A `vector::size()` `size_t` típusú értéket ad vissza (előjel nélküli egész). A `resumeIndex` szintén `size_t` (vagy kompatibilis típus). Az összehasonlítás `>=` operátorral biztonságos, mert mindkét oldal előjel nélküli.

`vector::size()` returns a `size_t` value (unsigned integer). `resumeIndex` is also `size_t` (or a compatible type). Comparison with `>=` is safe because both sides are unsigned.

Ha a tárolt index nagyobb vagy egyenlő a lista méreténél (pl. mert azóta csökkent a hibák száma), nullázzuk — nem kísérelnénk meg egy nem létező elem elérését.

If the stored index is greater than or equal to the list size (e.g. because the number of mistakes has decreased since then), it is reset to zero — we would not attempt to access a non-existent element.

---

## A külső ciklus / The outer loop

```cpp
for (size_t i = resumeIndex; i < mistakeWords.size() && !realExit; ++i) {
    const WordPair& word = mistakeWords[i];
    for (;;) {
        ...
    }
}
```

### `size_t i = resumeIndex`

A ciklus nem 0-tól indul, hanem a **mentett pozíciótól**. Ez teszi lehetővé a folytatást.

The loop does not start at 0 but at the **saved position**. This is what enables resuming.

### `i < mistakeWords.size() && !realExit`

Két feltétel egyszerre:
1. `i < mistakeWords.size()` — Ne menjünk túl a vektor végén.
2. `!realExit` — Ha a felhasználó kilépett, azonnal álljon meg a külső ciklus is.

Two conditions at once:
1. `i < mistakeWords.size()` — Do not go past the end of the vector.
2. `!realExit` — If the user exited, the outer loop must also stop immediately.

### `const WordPair& word = mistakeWords[i]`

Az `i`-edik szópárra való **konstans referencia**. Nem másolja le a struktúrát, csak hivatkozik rá. A `const` garantálja, hogy a `word`-ön keresztül nem lehet módosítani az eredeti adatot.

A **constant reference** to the i-th word pair. It does not copy the struct, only refers to it. `const` guarantees that the original data cannot be modified through `word`.

### `for (;;)` — a belső végtelen ciklus / the inner infinite loop

Ez biztosítja, hogy **ugyanazt a szót addig kérdezi**, amíg a felhasználó helyesen nem válaszol, el nem kéri a segítséget, vagy ki nem lép. A ciklusból `break`-kel lép ki helyes válasz esetén, és szintén `break`-kel kilépéskor.

This ensures the same word is asked **until the user answers correctly**, requests help, or exits. The loop exits with `break` on a correct answer, and also with `break` on exit.

---

## Súgó megjelenítése / Showing the hint

```cpp
if (showHelp) {
    std::cout << "CheatSheet: " << colors::GREY << word.targetLangMeaning << colors::RESET << std::endl;
}
```

Ha a `showHelp` globális beállítás igaz, kiírja a helyes választ szürkén. A `colors::GREY` és `colors::RESET` ANSI escape szekvenciák, amelyek a terminál szövegszínét állítják.

If the `showHelp` global setting is true, it prints the correct answer in grey. `colors::GREY` and `colors::RESET` are ANSI escape sequences that set the terminal text color.

---

## `InputResult` és `readLineWithHotkey`

```cpp
InputResult inputResult = readLineWithHotkey(getTranslation("MistakeExercise.answer"));
```

### `InputResult` struktúra

Valószínűleg három mezőt tartalmaz:
- `text` — A begépelt szöveg.
- `exitTriggered` — `true`, ha Ctrl+C-t nyomtak.
- `hotkeyTriggered` — `true`, ha Ctrl+Y-t nyomtak (súgó toggle).

Likely contains three fields:
- `text` — The typed text.
- `exitTriggered` — `true` if Ctrl+C was pressed.
- `hotkeyTriggered` — `true` if Ctrl+Y was pressed (help toggle).

### `readLineWithHotkey`

Egy sort olvas be, de közben figyel speciális billentyűkombinációkra is. Normál `std::getline` ezt nem tudja — az csak szöveget olvas, hotkey-eket nem észlel.

Reads a line while also listening for special key combinations. Normal `std::getline` cannot do this — it only reads text and does not detect hotkeys.

---

## Súgó toggle / Help toggle

```cpp
if (inputResult.hotkeyTriggered) {
    showHelp = !showHelp;
    if (showHelp) helperUsed = true;
    saveSettings();
    continue;
}
```

### `showHelp = !showHelp`

A `!` logikai NEM operátor. Ez az ún. **boolean toggle** minta: ha `showHelp` igaz volt, hamis lesz; ha hamis volt, igaz lesz. Egyetlen sorban megfordítja az értéket.

`!` is the logical NOT operator. This is the **boolean toggle** pattern: if `showHelp` was true it becomes false; if it was false it becomes true. It flips the value in a single line.

### `if (showHelp) helperUsed = true`

A `helperUsed` csak igazzá válhat — sosem állítjuk vissza hamisra itt. Ez azért van, mert ha valaha bekapcsolta a súgót, az tény: igénybe vette a segítséget. A kikapcsolás nem "tünteti el" ezt a tényt.

`helperUsed` can only become true — it is never set back to false here. This is because if the user ever turned on help, it is a fact: they used assistance. Turning it off does not "erase" this fact.

### `saveSettings()`

A megváltozott beállítást azonnal lementi, hogy egy esetleges váratlan kilépés esetén se vesszen el.

The changed setting is saved immediately so it is not lost in case of an unexpected exit.

### `continue`

A belső `for (;;)` ciklus elejére ugrik vissza, hogy a képernyő újrarajzolódjon az új súgó-állapottal — ezért nem kell külön kód a frissítéshez.

Jumps back to the beginning of the inner `for (;;)` loop so the screen redraws with the new help state — no separate refresh code is needed.

---

## Kilépés kezelése / Exit handling

```cpp
if (lowerAnswer == "exit" || lowerAnswer == "e" || inputResult.exitTriggered) {
    stillMistakes.push_back(word);

    for (size_t j = i + 1; j < mistakeWords.size(); ++j) {
        stillMistakes.push_back(mistakeWords[j]);
    }
    resumeIndex = i;
    realExit = true;
    break;
}
```

### Miért kerül bele az aktuális szó és az összes hátralévő? / Why are the current and all remaining words added?

Ha a felhasználó kilép, az aktuális szót (amelyre nem válaszolt) és az összes még nem érintett szót visszaírjuk a fájlba — nehogy elvesszenek. A következő session-ben a `resumeIndex` alapján pontosan innen folytatódik a gyakorlás.

If the user exits, the current word (unanswered) and all not-yet-reached words are written back to the file so they are not lost. In the next session, practice resumes from exactly here based on `resumeIndex`.

### `resumeIndex = i`

Az aktuális indexet elmenti, hogy legközelebb innen induljon a kvíz.

Saves the current index so the quiz starts from here next time.

### `realExit = true` és `break`

A `break` kilép a belső `for (;;)`-ból. A `realExit = true` jelzi a külső `for`-nak, hogy álljon meg — a feltételben `!realExit` áll, ami most hamisra vált.

`break` exits the inner `for (;;)`. `realExit = true` signals the outer `for` to stop — its condition contains `!realExit`, which now becomes false.

---

## Helyes és helytelen válasz / Correct and incorrect answer

```cpp
if (cleanString(answer) == cleanString(word.targetLangMeaning)) {
    if (useColors) std::cout << colors::GREEN;
    std::cout << getTranslation("GoodAnswer1.goodAnswer1");
    if (useColors) std::cout << colors::RESET;
    waitToEnter();
    break;
} else {
    if (useColors) std::cout << colors::RED;
    std::cout << getTranslation("BadlyAnswer.badlyAnswer");
    if (useColors) std::cout << colors::RESET;
    std::cout << "\n" << getTranslation("GoodAnswer2.goodAnswer2") << word.targetLangMeaning << "\n";
    stillMistakes.push_back(word);
    waitToEnter();
}
```

### Helyes válasz / Correct answer

Mindkét oldalt `cleanString`-gel normalizáljuk (kisbetű, trim, írásjelek, ékezetek), hogy az `"  Apple! "` is egyezzen az `"apple"`-lel. Ha egyeznek: zöld szín, visszajelzés, vár az Enterre, majd `break` — kilép a belső ciklusból, a külső ciklus továbblép a következő szóra.

Both sides are normalized with `cleanString` (lowercase, trim, punctuation, accents) so `"  Apple! "` also matches `"apple"`. If they match: green color, feedback, wait for Enter, then `break` — exits the inner loop, the outer loop advances to the next word.

### Helytelen válasz / Incorrect answer

Ha nem egyezik: piros szín, visszajelzés, megmutatja a helyes választ, majd **hozzáadja a szót a `stillMistakes` listához**. A belső ciklus **nem kap `break`-et** — így ugyanazt a szót kérdezi újra. A felhasználónak addig kell próbálkoznia, amíg helyesen nem válaszol (vagy ki nem lép).

If they do not match: red color, feedback, shows the correct answer, then **adds the word to `stillMistakes`**. The inner loop **does not get a `break`** — so it asks the same word again. The user must keep trying until they answer correctly (or exit).

Megjegyendő: ha a felhasználó harmadszorra is elrontja, **megint** bekerül a `stillMistakes`-be. Ez azt jelenti, hogy ugyanaz a szó többször is szerepelhet a fájlban a következő mentésben. Ez egy egyszerű implementáció, nem kezel duplikátumokat.

Note: if the user gets it wrong a third time, it is added to `stillMistakes` **again**. This means the same word may appear multiple times in the file after the next save. This is a simple implementation that does not handle duplicates.

---

## A fájl felülírása / Overwriting the file

```cpp
std::ofstream outFile(path, std::ios::out | std::ios::trunc);
if (outFile.is_open()) {
    for (const WordPair& word : stillMistakes) {
        outFile << word.targetLangMeaning << " -> " << word.motherLangMeaning;
        if (!word.pronunciation.empty()) outFile << " [" << word.pronunciation << "]";
        outFile << "\n";
    }
    outFile.close();
}
```

### `std::ios::out | std::ios::trunc`

Két flag **bitenkénti VAGY** (`|`) operátorral kombinálva:
- `std::ios::out` — A fájlt írásra nyitjuk meg.
- `std::ios::trunc` — A fájl meglévő tartalmát **töröljük** (truncate = csonkítás). Ha ez nem lenne ott, a régi tartalom megmaradna, és az új tartalom mögé fűznénk.

Two flags combined with the **bitwise OR** (`|`) operator:
- `std::ios::out` — Open the file for writing.
- `std::ios::trunc` — **Delete** the existing file contents (truncate). Without this the old content would remain and new content would be appended after it.

### Miért nem `std::ios::app`?

Az előző fájlban (`logMistakeWriteFile`) `app` módot használtunk, mert **hozzá akartunk fűzni**. Most **felülírunk** — csak a még mindig hibás szavakat tartjuk meg. Ezért kell `trunc`.

In the previous file (`logMistakeWriteFile`) we used `app` mode because we wanted to **append**. Now we are **overwriting** — only the still-mistaken words are kept. This is why `trunc` is needed.

### A formátum / The format

```
word.targetLangMeaning << " -> " << word.motherLangMeaning
```

Ugyanabban a formátumban írja vissza a fájlba, amelyben olvasta — így a `loadWords` legközelebb is be tudja olvasni.

It writes back to the file in the same format it was read in — so `loadWords` can read it again next time.

### `if (!word.pronunciation.empty()) outFile << " [" << word.pronunciation << "]"`

A kiejtést csak akkor írja ki, ha nem üres. Ez megőrzi az eredeti adatot — ha volt kiejtés, az visszakerül.

The pronunciation is only written if it is not empty. This preserves the original data — if there was a pronunciation, it is written back.

---

## Végső összefoglalás / Final summary

```cpp
screenWipe();
std::cout << getTranslation("MistakeExercise.exerciseEnd") << stillMistakes.size() << "\n";
saveSettings();
waitToEnter();
```

### `stillMistakes.size()`

Megmutatja, hány szó maradt még a hibalistán. A `.size()` a vektor aktuális elemszámát adja vissza `size_t` típusként.

Shows how many words remain on the mistake list. `.size()` returns the current number of elements in the vector as `size_t`.

### `saveSettings()`

A `resumeIndex` és egyéb beállítások (pl. `helperUsed`) mentése a kvíz végén. Ha a felhasználó végigment az összes szón, `resumeIndex` nem az `i` értéke lesz (mert a kilépési ágban nem állítottuk be), hanem a következő híváskor a 0-ra resetelt érték fog érvényesülni.

Saves `resumeIndex` and other settings (e.g. `helperUsed`) at the end of the quiz.

---

## Az egész folyamat összefoglalva / The whole flow summarized

```
1. Fájl beolvasása → mistakeWords lista
2. Ciklus minden szón:
   a. Kérdés megjelenítése
   b. Bevitel olvasása
      - Ctrl+Y → súgó be/ki, újraindítás
      - exit/e/Ctrl+C → hátralévők → stillMistakes, mentés, kilépés
      - h/help → súgó be
      - Helyes válasz → break (következő szóra)
      - Rossz válasz → stillMistakes, újrakérdezés
3. stillMistakes → fájl felülírása (trunc módban)
4. Statisztika kiírása, beállítások mentése
```

| Fogalom / Concept | Magyarázat / Explanation |
|---|---|
| `realExit` | Kommunikáció belső és külső ciklus között. / Communication between inner and outer loop. |
| `resumeIndex` | A folytatási pont tárolása. / Storing the resume point. |
| `stillMistakes` | Megmaradó hibák gyűjtése. / Collecting remaining mistakes. |
| `ios::trunc` | Fájl tartalmának törlése felülírás előtt. / Deleting file content before overwriting. |
| `boolean toggle` | `x = !x` — értéket megfordít. / Flips a value. |
| `break` | Csak a közvetlen szülő ciklust állítja meg. / Stops only the immediate parent loop. |

