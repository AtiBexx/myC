# C és C++ – Teljes Fájlkezelő Parancsok

## Tartalom
- [C – stdio.h (fopen/fclose)](#c--stdioh)
- [C – Alacsony szintű (unistd.h / fcntl.h)](#c--alacsony-szintű-unistdh--fcntlh)
- [C – sys/stat.h (fájl info)](#c--sysstat)
- [C++ – fstream](#c--fstream)
- [C++ – std::filesystem (C++17)](#c--stdfilesystem-c17)
- [C++ – stdio.h C-stílusban](#c--stdioh-c-stílusban)
- [Windows API – fájlkezelés](#windows-api--fájlkezelés)
- [C++ – stringstream / memória buffer](#c--stringstream--memória-buffer)
- [Bináris fájlok](#bináris-fájlok)
- [Temp fájlok](#temp-fájlok)
- [Hibakezelés](#hibakezelés)
- [Gyors összefoglaló táblázat](#gyors-összefoglaló-táblázat)

---

## C – stdio.h

A legklasszikusabb C fájlkezelés.

### Megnyitás / Bezárás
```c
#include <stdio.h>

FILE *f = fopen("file.txt", "r");   // Olvasás
FILE *f = fopen("file.txt", "w");   // Írás (felülírja ha létezik)
FILE *f = fopen("file.txt", "a");   // Hozzáfűzés
FILE *f = fopen("file.txt", "rb");  // Bináris olvasás
FILE *f = fopen("file.txt", "wb");  // Bináris írás
FILE *f = fopen("file.txt", "ab");  // Bináris hozzáfűzés
FILE *f = fopen("file.txt", "r+");  // Olvasás + írás (fájl kell hogy létezzen)
FILE *f = fopen("file.txt", "w+");  // Olvasás + írás (felülír vagy létrehoz)
FILE *f = fopen("file.txt", "a+");  // Olvasás + hozzáfűzés

if (f == NULL) {
    perror("Hiba");   // Kiírja a hibát
    return 1;
}

fclose(f);           // Bezárás (mindig hívd meg!)
```

### Szöveges olvasás
```c
#include <stdio.h>

// Karakterenként
int ch;
while ((ch = fgetc(f)) != EOF) {
    printf("%c", ch);
}

// Soronként
char buf[256];
while (fgets(buf, sizeof(buf), f) != NULL) {
    printf("%s", buf);
}

// Formázott olvasás (scanf-szerű)
int n;
float x;
fscanf(f, "%d %f", &n, &x);

// Teljes fájl beolvasása
fseek(f, 0, SEEK_END);
long size = ftell(f);
rewind(f);                          // vagy: fseek(f, 0, SEEK_SET);

char *buf = malloc(size + 1);
fread(buf, 1, size, f);
buf[size] = '\0';
```

### Szöveges írás
```c
// Egyetlen karakter
fputc('A', f);

// Sor írása
fputs("Hello, World!\n", f);

// Formázott írás (printf-szerű)
fprintf(f, "Szám: %d, Float: %.2f\n", 42, 3.14);
fprintf(f, "String: %s\n", "valami");
```

### Bináris olvasás / írás
```c
// Írás
int data[] = {1, 2, 3, 4, 5};
fwrite(data, sizeof(int), 5, f);
//     ^ptr  ^elemméret  ^db ^fájl

// Olvasás
int result[5];
size_t olvasott = fread(result, sizeof(int), 5, f);
printf("Olvasott elemek: %zu\n", olvasott);

// Struct írása/olvasása
typedef struct {
    int id;
    char name[64];
    float value;
} Record;

Record r = {1, "alma", 3.14f};
fwrite(&r, sizeof(Record), 1, f);

Record r2;
fread(&r2, sizeof(Record), 1, f);
```

### Pozíció kezelés
```c
// Aktuális pozíció lekérdezése
long pos = ftell(f);

// Pozíció beállítása
fseek(f, 0, SEEK_SET);      // Fájl elejére
fseek(f, 0, SEEK_END);      // Fájl végére
fseek(f, 10, SEEK_SET);     // 10. byte-ra
fseek(f, -5, SEEK_CUR);     // 5-tel visszább az aktuálistól
fseek(f, 100, SEEK_CUR);    // 100-zal előre az aktuálistól

// Vissza az elejére
rewind(f);

// Pozíció mentése / visszaállítása
fpos_t pos;
fgetpos(f, &pos);           // Mentés
fsetpos(f, &pos);           // Visszaállítás

// Fájlméret lekérése
fseek(f, 0, SEEK_END);
long size = ftell(f);
fseek(f, 0, SEEK_SET);
```

### Puffer és flush
```c
fflush(f);                  // Puffer kiürítése (fájlba írás erőltetése)
fflush(stdout);             // stdout kiürítése

// Puffer beállítása
setvbuf(f, NULL, _IOFBF, 4096);  // Full buffering, 4KB puffer
setvbuf(f, NULL, _IOLBF, 0);     // Line buffering
setvbuf(f, NULL, _IONBF, 0);     // Nincs puffer
```

### EOF és hibák
```c
feof(f);        // 1 ha elértük a fájl végét
ferror(f);      // 1 ha hiba történt
clearerr(f);    // Hiba és EOF flag törlése
```

---

## C – Alacsony szintű (unistd.h / fcntl.h)

POSIX API (Linux/Mac; Windows-on `_open`, `_read` stb. van).

```c
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

// Megnyitás
int fd = open("file.txt", O_RDONLY);
int fd = open("file.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
int fd = open("file.txt", O_RDWR);
int fd = open("file.txt", O_WRONLY | O_APPEND);
int fd = open("file.txt", O_WRONLY | O_CREAT | O_EXCL, 0644);  // Hiba ha létezik

// Flagek:
// O_RDONLY  – csak olvasás
// O_WRONLY  – csak írás
// O_RDWR    – olvasás+írás
// O_CREAT   – létrehozás ha nem létezik
// O_TRUNC   – felülírás (0 byte-ra csonkítás)
// O_APPEND  – hozzáfűzés
// O_EXCL    – hiba ha már létezik (O_CREAT-tel)
// O_NONBLOCK – non-blocking mód

// Bezárás
close(fd);

// Olvasás
char buf[1024];
ssize_t n = read(fd, buf, sizeof(buf));
// n > 0: olvasott bájtok száma
// n == 0: EOF
// n < 0: hiba

// Írás
ssize_t w = write(fd, "Hello\n", 6);

// Pozíció
off_t pos = lseek(fd, 0, SEEK_SET);    // Elejére
off_t pos = lseek(fd, 0, SEEK_END);    // Végére
off_t pos = lseek(fd, 100, SEEK_CUR);  // Relatív
off_t size = lseek(fd, 0, SEEK_END);   // Fájlméret

// Fájl csonkítása (méret beállítása)
ftruncate(fd, 1024);        // fd-re
truncate("file.txt", 1024); // Névvel

// Duplikálás (fd másolása)
int fd2 = dup(fd);
int fd2 = dup2(fd, 5);      // Adott fd számra

// Szinkronizálás (kernel cache → lemez)
fsync(fd);
fdatasync(fd);              // Csak adat, metadata nélkül
```

### Fájl törlése / átnevezése (C, POSIX)
```c
#include <stdio.h>
#include <unistd.h>

remove("file.txt");         // stdio.h – törlés
unlink("file.txt");         // unistd.h – törlés (POSIX)
rename("old.txt", "new.txt");  // Átnevezés / áthelyezés

// Könyvtár műveletek
#include <sys/stat.h>
#include <dirent.h>

mkdir("newdir", 0755);      // Könyvtár létrehozása
rmdir("emptydir");          // Üres könyvtár törlése

// Könyvtár bejárása
DIR *dir = opendir(".");
struct dirent *entry;
while ((entry = readdir(dir)) != NULL) {
    printf("%s\n", entry->d_name);
}
closedir(dir);
```

---

## C – sys/stat.h

Fájl információk lekérése.

```c
#include <sys/stat.h>
#include <sys/types.h>

struct stat st;

// Fájl info lekérése
stat("file.txt", &st);          // Útvonalon keresztül (symlinket követ)
lstat("link.txt", &st);         // Symlink saját infója
fstat(fd, &st);                 // Fájlleíró alapján

// Elérhető mezők:
st.st_size;         // Fájlméret byte-ban
st.st_mode;         // Fájltípus + jogosultságok
st.st_uid;          // Tulajdonos UID
st.st_gid;          // Tulajdonos GID
st.st_atime;        // Utolsó hozzáférés ideje
st.st_mtime;        // Utolsó módosítás ideje
st.st_ctime;        // Utolsó státuszváltozás ideje
st.st_nlink;        // Hard linkek száma
st.st_ino;          // Inode szám
st.st_dev;          // Eszközazonosító
st.st_blksize;      // Optimális blokk méret
st.st_blocks;       // Lefoglalt blokkok száma (512 byte-os egységek)

// Fájltípus ellenőrzés (makrók)
S_ISREG(st.st_mode)     // Normál fájl?
S_ISDIR(st.st_mode)     // Könyvtár?
S_ISLNK(st.st_mode)     // Szimbolikus link?
S_ISFIFO(st.st_mode)    // Named pipe?
S_ISSOCK(st.st_mode)    // Socket?
S_ISBLK(st.st_mode)     // Blokk eszköz?
S_ISCHR(st.st_mode)     // Karakter eszköz?

// Jogosultság bitjei
st.st_mode & S_IRUSR    // Tulajdonos olvashat
st.st_mode & S_IWUSR    // Tulajdonos írhat
st.st_mode & S_IXUSR    // Tulajdonos futtathat
st.st_mode & S_IRGRP    // Csoport olvashat
st.st_mode & S_IROTH    // Mások olvashatnak

// Jogosultság beállítása
chmod("file.txt", 0644);
fchmod(fd, 0755);

// Létezik-e a fájl?
access("file.txt", F_OK);   // 0 = létezik
access("file.txt", R_OK);   // 0 = olvasható
access("file.txt", W_OK);   // 0 = írható
access("file.txt", X_OK);   // 0 = futtatható

// Példa:
struct stat st;
if (stat("file.txt", &st) == 0) {
    printf("Méret: %ld byte\n", st.st_size);
    printf("Könyvtár: %s\n", S_ISDIR(st.st_mode) ? "igen" : "nem");
}
```

---

## C++ – fstream

```cpp
#include <fstream>
#include <string>
#include <sstream>

// ---- Szöveges olvasás ----

std::ifstream fin("file.txt");

// Soronként
std::string line;
while (std::getline(fin, line)) {
    std::cout << line << "\n";
}

// Szavanként
std::string word;
while (fin >> word) {
    std::cout << word << "\n";
}

// Karakterenként
char ch;
while (fin.get(ch)) {
    std::cout << ch;
}

// Egész fájl egyszerre
std::ifstream fin("file.txt");
std::stringstream ss;
ss << fin.rdbuf();
std::string content = ss.str();

// Egész fájl (C++11 iterator módszer)
std::ifstream fin("file.txt");
std::string content(
    (std::istreambuf_iterator<char>(fin)),
    std::istreambuf_iterator<char>()
);

// ---- Szöveges írás ----

std::ofstream fout("file.txt");
fout << "Hello, World!\n";
fout << "Szám: " << 42 << "\n";
fout << "Float: " << std::fixed << std::setprecision(2) << 3.14 << "\n";

// Hozzáfűzés
std::ofstream fout("file.txt", std::ios::app);
fout << "Új sor\n";

// ---- Olvasás + Írás ----

std::fstream f("file.txt", std::ios::in | std::ios::out);
std::fstream f("file.txt", std::ios::in | std::ios::out | std::ios::trunc);  // Felülír

// ---- Megnyitási módok ----
std::ios::in        // Olvasás
std::ios::out       // Írás
std::ios::app       // Hozzáfűzés
std::ios::trunc     // Felülírás (tartalom törlése)
std::ios::binary    // Bináris mód
std::ios::ate       // Megnyitás után rögtön a végére ugrik

// ---- Pozíció kezelés ----

// Olvasási pozíció
fin.seekg(0, std::ios::beg);    // Elejére
fin.seekg(0, std::ios::end);    // Végére
fin.seekg(100, std::ios::beg);  // 100. byte
fin.seekg(-10, std::ios::cur);  // 10-zel visszább
std::streampos pos = fin.tellg();  // Aktuális pozíció

// Írási pozíció
fout.seekp(0, std::ios::beg);
fout.seekp(0, std::ios::end);
std::streampos pos = fout.tellp();

// Fájlméret lekérése
fin.seekg(0, std::ios::end);
std::streamsize size = fin.tellg();
fin.seekg(0, std::ios::beg);

// ---- Állapot ellenőrzés ----
fin.is_open()   // Megnyílt-e?
fin.good()      // Minden ok?
fin.eof()       // Fájl vége?
fin.fail()      // Hiba (nem fatális)?
fin.bad()       // Kritikus hiba?
fin.clear()     // Hibaflagek törlése

// ---- Flush / Sync ----
fout.flush();
fout << std::flush;
fout << std::endl;  // '\n' + flush

// ---- Bezárás ----
fin.close();
// Destruktorban automatikusan bezáródik (RAII)
```

### fstream bináris
```cpp
#include <fstream>

// Struct kiírása binárisban
struct Point { int x, y; float z; };

Point p = {10, 20, 3.14f};
std::ofstream fout("data.bin", std::ios::binary);
fout.write(reinterpret_cast<const char*>(&p), sizeof(Point));

// Struct beolvasása binárisból
Point p2;
std::ifstream fin("data.bin", std::ios::binary);
fin.read(reinterpret_cast<char*>(&p2), sizeof(Point));

// Vektor kiírása
std::vector<int> v = {1, 2, 3, 4, 5};
fout.write(reinterpret_cast<const char*>(v.data()), v.size() * sizeof(int));

// Vektor beolvasása
std::vector<int> v2(5);
fin.read(reinterpret_cast<char*>(v2.data()), v2.size() * sizeof(int));
```

---

## C++ – std::filesystem (C++17)

```cpp
#include <filesystem>
namespace fs = std::filesystem;

// ---- Útvonalak ----

fs::path p = "C:/Users/alma/file.txt";
fs::path p = fs::current_path();        // Aktuális könyvtár
fs::path p = fs::temp_directory_path(); // Temp könyvtár

p.string()          // std::string
p.filename()        // "file.txt"
p.stem()            // "file"
p.extension()       // ".txt"
p.parent_path()     // "C:/Users/alma"
p.root_name()       // "C:"
p.root_path()       // "C:/"
p.is_absolute()     // true
p.is_relative()     // false

// Útvonalak kombinálása
fs::path full = fs::path("C:/Users") / "alma" / "file.txt";
p /= "subdir";      // Hozzáfűzés operator

// Normalizálás
fs::path clean = fs::canonical(p);      // Symlinket felold, '..' eltávolít
fs::path norm  = fs::weakly_canonical(p); // Nem kell hogy létezzen
fs::path abs   = fs::absolute(p);       // Abszolút útvonal

// ---- Fájl / könyvtár létrehozás ----

fs::create_directory("newdir");
fs::create_directories("a/b/c/d");     // Rekurzív (szülőket is létrehozza)

// Fájl másolása
fs::copy_file("src.txt", "dst.txt");
fs::copy_file("src.txt", "dst.txt", fs::copy_options::overwrite_existing);
fs::copy_file("src.txt", "dst.txt", fs::copy_options::skip_existing);

// Könyvtár másolása (rekurzív)
fs::copy("srcdir", "dstdir", fs::copy_options::recursive);

// Átnevezés / áthelyezés
fs::rename("old.txt", "new.txt");
fs::rename("file.txt", "subdir/file.txt");

// Törlés
fs::remove("file.txt");                 // Fájl vagy üres könyvtár
fs::remove_all("directory");            // Könyvtár rekurzívan (rm -rf)

// Szimbolikus link
fs::create_symlink("target.txt", "link.txt");
fs::create_directory_symlink("targetdir", "linkdir");
fs::read_symlink("link.txt");           // Célpont lekérése

// Hard link
fs::create_hard_link("target.txt", "hardlink.txt");

// ---- Fájl info ----

fs::exists("file.txt")                  // Létezik?
fs::is_regular_file("file.txt")         // Normál fájl?
fs::is_directory("dir")                 // Könyvtár?
fs::is_symlink("link.txt")              // Szimbolikus link?
fs::is_empty("file.txt")                // Üres fájl vagy könyvtár?

fs::file_size("file.txt")               // Méret byte-ban
fs::last_write_time("file.txt")         // Utolsó módosítás (file_time_type)

// Méret beállítása
fs::resize_file("file.txt", 1024);

// Jogosultságok
fs::perms p = fs::status("file.txt").permissions();
fs::permissions("file.txt",
    fs::perms::owner_read | fs::perms::owner_write,
    fs::perm_options::replace);

// ---- Könyvtár bejárás ----

// Nem rekurzív
for (const auto& entry : fs::directory_iterator("mydir")) {
    std::cout << entry.path() << "\n";
    std::cout << entry.file_size() << " byte\n";
    std::cout << (entry.is_directory() ? "dir" : "file") << "\n";
}

// Rekurzív
for (const auto& entry : fs::recursive_directory_iterator("mydir")) {
    std::cout << entry.path() << "\n";
}

// Szűrés kiterjesztés szerint
for (const auto& entry : fs::recursive_directory_iterator("mydir")) {
    if (entry.path().extension() == ".cpp") {
        std::cout << entry.path() << "\n";
    }
}

// Összes fájl mérete egy könyvtárban
uintmax_t total = 0;
for (const auto& entry : fs::recursive_directory_iterator("mydir")) {
    if (entry.is_regular_file()) {
        total += entry.file_size();
    }
}

// ---- Aktuális könyvtár ----

fs::current_path()                      // Lekérés
fs::current_path("C:/Users/alma")       // Beállítás (cd)

// ---- Szabad hely a lemezen ----

fs::space_info si = fs::space("C:/");
si.capacity    // Teljes kapacitás
si.free        // Szabad hely (root számára)
si.available   // Szabad hely (felhasználó számára)

// ---- Hibakezelés (exception nélkül) ----

std::error_code ec;
fs::create_directory("newdir", ec);
if (ec) {
    std::cerr << "Hiba: " << ec.message() << "\n";
}

fs::copy_file("src.txt", "dst.txt", ec);
fs::remove("file.txt", ec);
```

---

## C++ – stdio.h C-stílusban

C++ kódban is használható a C stdio.h teljesen:

```cpp
#include <cstdio>

FILE* f = std::fopen("file.txt", "r");
std::fprintf(f, "Szám: %d\n", 42);
std::fclose(f);
// Minden fopen/fread/fwrite/fseek stb. elérhető std:: prefixszel
```

---

## Windows API – fájlkezelés

```cpp
#include <windows.h>

// ---- Fájl létrehozása / megnyitása ----

HANDLE hFile = CreateFile(
    "file.txt",                  // Fájlnév
    GENERIC_READ | GENERIC_WRITE,// Hozzáférés
    0,                           // Megosztás (0 = exkluzív)
    NULL,                        // Biztonsági leíró
    OPEN_EXISTING,               // Megnyitási mód
    FILE_ATTRIBUTE_NORMAL,       // Attribútumok
    NULL                         // Sablon
);

// Megnyitási módok:
// CREATE_NEW        – Csak ha nem létezik
// CREATE_ALWAYS     – Mindig létrehozza (felülír)
// OPEN_EXISTING     – Csak ha létezik
// OPEN_ALWAYS       – Megnyitja vagy létrehozza
// TRUNCATE_EXISTING – Megnyitja és 0 méretűre vágja

// Hozzáférési flagek:
// GENERIC_READ    – Olvasás
// GENERIC_WRITE   – Írás
// GENERIC_ALL     – Minden

if (hFile == INVALID_HANDLE_VALUE) {
    DWORD err = GetLastError();
    // Hibakezelés
}

// ---- Olvasás ----

char buf[1024];
DWORD bytesRead;
ReadFile(hFile, buf, sizeof(buf), &bytesRead, NULL);

// ---- Írás ----

const char* data = "Hello, Windows!\n";
DWORD bytesWritten;
WriteFile(hFile, data, strlen(data), &bytesWritten, NULL);

// ---- Pozíció ----

// Elejére
SetFilePointer(hFile, 0, NULL, FILE_BEGIN);
// Végére
SetFilePointer(hFile, 0, NULL, FILE_END);
// Relatív
SetFilePointer(hFile, 100, NULL, FILE_CURRENT);

// 64 bites pozíció
LARGE_INTEGER pos;
pos.QuadPart = 0;
SetFilePointerEx(hFile, pos, NULL, FILE_BEGIN);

// Aktuális pozíció lekérése
LARGE_INTEGER cur;
SetFilePointerEx(hFile, {0}, &cur, FILE_CURRENT);

// ---- Fájlméret ----

LARGE_INTEGER size;
GetFileSizeEx(hFile, &size);
printf("Méret: %lld byte\n", size.QuadPart);

// ---- Flush / Bezárás ----

FlushFileBuffers(hFile);
CloseHandle(hFile);

// ---- Fájl műveletek ----

CopyFile("src.txt", "dst.txt", FALSE);         // FALSE = felülír
MoveFile("old.txt", "new.txt");                // Átnevezés
MoveFileEx("old.txt", "new.txt", MOVEFILE_REPLACE_EXISTING);
DeleteFile("file.txt");                        // Törlés

// ---- Könyvtár műveletek ----

CreateDirectory("newdir", NULL);
RemoveDirectory("emptydir");                   // Csak üres könyvtár
GetCurrentDirectory(MAX_PATH, buf);            // Aktuális könyvtár
SetCurrentDirectory("C:\\Users\\alma");

// ---- Könyvtár bejárás (Windows) ----

WIN32_FIND_DATA ffd;
HANDLE hFind = FindFirstFile("mydir\\*", &ffd);
if (hFind != INVALID_HANDLE_VALUE) {
    do {
        if (ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            printf("[DIR] %s\n", ffd.cFileName);
        } else {
            printf("[FILE] %s\n", ffd.cFileName);
        }
    } while (FindNextFile(hFind, &ffd));
    FindClose(hFind);
}

// ---- Fájl attribútumok ----

DWORD attr = GetFileAttributes("file.txt");
attr & FILE_ATTRIBUTE_READONLY    // Csak olvasható?
attr & FILE_ATTRIBUTE_HIDDEN      // Rejtett?
attr & FILE_ATTRIBUTE_DIRECTORY   // Könyvtár?
attr & FILE_ATTRIBUTE_SYSTEM      // Rendszerfájl?

SetFileAttributes("file.txt", FILE_ATTRIBUTE_HIDDEN);

// ---- Memory-mapped fájl ----

HANDLE hMap = CreateFileMapping(hFile, NULL, PAGE_READWRITE, 0, 0, NULL);
LPVOID pView = MapViewOfFile(hMap, FILE_MAP_ALL_ACCESS, 0, 0, 0);

// pView-on keresztül közvetlenül olvasható/írható a fájl
char* data = (char*)pView;
printf("%s\n", data);

UnmapViewOfFile(pView);
CloseHandle(hMap);
CloseHandle(hFile);
```

---

## C++ – stringstream / memória buffer

```cpp
#include <sstream>
#include <iostream>

// Szöveg összerakása
std::ostringstream oss;
oss << "Szám: " << 42 << ", Float: " << 3.14;
std::string result = oss.str();

// Szöveg bontása
std::istringstream iss("10 20 30.5 hello");
int a, b; float c; std::string s;
iss >> a >> b >> c >> s;

// Egész fájl memóriába olvasása
std::ifstream fin("file.txt");
std::ostringstream oss;
oss << fin.rdbuf();
std::string content = oss.str();

// Memóriában lévő adat "fájlként" kezelése
std::string data = "sor1\nsor2\nsor3\n";
std::istringstream stream(data);
std::string line;
while (std::getline(stream, line)) {
    std::cout << line << "\n";
}
```

---

## Bináris fájlok

```cpp
#include <fstream>
#include <vector>
#include <cstdint>

// ---- Raw byte-ok írása/olvasása ----

// Fájl teljes tartalmának beolvasása
std::vector<uint8_t> readFile(const std::string& path) {
    std::ifstream fin(path, std::ios::binary | std::ios::ate);
    std::streamsize size = fin.tellg();
    fin.seekg(0, std::ios::beg);

    std::vector<uint8_t> buf(size);
    fin.read(reinterpret_cast<char*>(buf.data()), size);
    return buf;
}

// Byte-ok kiírása fájlba
void writeFile(const std::string& path, const std::vector<uint8_t>& data) {
    std::ofstream fout(path, std::ios::binary);
    fout.write(reinterpret_cast<const char*>(data.data()), data.size());
}

// Adott offset-en lévő érték beolvasása
uint32_t readU32(const std::vector<uint8_t>& data, size_t offset) {
    return *reinterpret_cast<const uint32_t*>(&data[offset]);
}

// Big-endian → little-endian csere
uint32_t swapEndian32(uint32_t val) {
    return ((val & 0xFF) << 24) | ((val >> 8 & 0xFF) << 16) |
           ((val >> 16 & 0xFF) << 8) | (val >> 24);
}
```

---

## Temp fájlok

```c
// C stílus
char tmp_name[] = "/tmp/tmpXXXXXX";
int fd = mkstemp(tmp_name);         // Létrehozza és visszaadja az fd-t
// ... használat ...
close(fd);
unlink(tmp_name);                   // Törlés

// stdio.h
FILE* f = tmpfile();                // Automatikusan törlődik bezáráskor
char* name = tmpnam(NULL);          // Csak nevet generál (deprecated, ne használd)
```

```cpp
// C++17 – tmp könyvtár
#include <filesystem>
fs::path tmp = fs::temp_directory_path() / "myapp_tmpXXXXXX";

// C++17 temp fájl generáláshoz maradj a C mkstemp-nél
// vagy használj library-t (boost::filesystem::unique_path)
```

---

## Hibakezelés

### C stílus
```c
#include <errno.h>
#include <string.h>

FILE* f = fopen("file.txt", "r");
if (!f) {
    fprintf(stderr, "Hiba: %s\n", strerror(errno));
    // errno értékek: ENOENT (nem létezik), EACCES (nincs jog), EISDIR stb.
}

// POSIX
int fd = open("file.txt", O_RDONLY);
if (fd < 0) {
    perror("open");     // "open: No such file or directory"
}
```

### C++ stílus – exception
```cpp
#include <fstream>
#include <stdexcept>

std::ifstream fin;
fin.exceptions(std::ios::failbit | std::ios::badbit);
try {
    fin.open("file.txt");
    // ...
} catch (const std::ios_base::failure& e) {
    std::cerr << "I/O hiba: " << e.what() << "\n";
}
```

### C++17 filesystem – error_code
```cpp
#include <filesystem>
namespace fs = std::filesystem;

std::error_code ec;
fs::copy_file("src.txt", "dst.txt", ec);
if (ec) {
    std::cerr << "Hiba: " << ec.message()
              << " (kod: " << ec.value() << ")\n";
}

// Exception-t dob ha nincs error_code paraméter:
try {
    fs::copy_file("src.txt", "dst.txt");
} catch (const fs::filesystem_error& e) {
    std::cerr << e.what() << "\n";
    std::cerr << "Path1: " << e.path1() << "\n";
    std::cerr << "Path2: " << e.path2() << "\n";
}
```

---

## Gyors összefoglaló táblázat

| Feladat | C | C++ fstream | C++17 filesystem | Windows API |
|---------|---|-------------|-----------------|-------------|
| Megnyitás | `fopen` | `ifstream/ofstream` | – | `CreateFile` |
| Szöveges olvasás | `fgets`, `fscanf` | `getline`, `>>` | – | `ReadFile` |
| Szöveges írás | `fprintf`, `fputs` | `<<` | – | `WriteFile` |
| Bináris olvasás | `fread` | `.read()` | – | `ReadFile` |
| Bináris írás | `fwrite` | `.write()` | – | `WriteFile` |
| Pozíció | `fseek/ftell` | `seekg/tellg` | – | `SetFilePointer` |
| Bezárás | `fclose` | destruktor | – | `CloseHandle` |
| Létezik? | `access` / `stat` | `fin.is_open()` | `fs::exists` | `GetFileAttributes` |
| Méret | `stat.st_size` | `seekg(end)+tellg` | `fs::file_size` | `GetFileSizeEx` |
| Másolás | – | – | `fs::copy_file` | `CopyFile` |
| Törlés | `remove` / `unlink` | – | `fs::remove` | `DeleteFile` |
| Átnevezés | `rename` | – | `fs::rename` | `MoveFile` |
| Könyvtár létrehozás | `mkdir` | – | `fs::create_directories` | `CreateDirectory` |
| Könyvtár bejárás | `opendir/readdir` | – | `fs::directory_iterator` | `FindFirstFile` |
| Jogosultság | `chmod` / `stat` | – | `fs::permissions` | `SetFileAttributes` |

---

> **Fordítási flagek:**
> ```bash
> # C++17 filesystem
> g++ -std=c++17 main.cpp -o app
>
> # Linux-on régebbi GCC esetén
> g++ -std=c++17 main.cpp -lstdc++fs -o app
> ```
