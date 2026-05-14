# Fájlkezelés különböző nyelveken

Műveletek: **listázás, belépés, visszalépés (..), másolás, áthelyezés, törlés** — fájlokra és mappákra.

---

## 1. C++ — `std::filesystem` (C++17)

```cpp
#include <filesystem>
#include <iostream>
#include <string>
#include <algorithm>

namespace fs = std::filesystem;

const std::string ROOT_DIR = "./data";

// Listázás
void listFiles(const fs::path& path) {
    std::cout << "--- " << fs::absolute(path).string() << " ---\n";
    for (const auto& entry : fs::directory_iterator(path)) {
        std::string name = entry.path().filename().string();
        if (entry.is_directory())
            std::cout << "[DIR]  " << name << "\n";
        else
            std::cout << "       " << name << "\n";
    }
}

// Másolás
void copyEntry(const fs::path& src, const fs::path& dest) {
    try {
        fs::copy(src, dest, fs::copy_options::recursive | fs::copy_options::overwrite_existing);
        std::cout << "Másolva: " << src << " -> " << dest << "\n";
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Hiba: " << e.what() << "\n";
    }
}

// Áthelyezés / átnevezés
void moveEntry(const fs::path& src, const fs::path& dest) {
    try {
        fs::rename(src, dest);
        std::cout << "Áthelyezve: " << src << " -> " << dest << "\n";
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Hiba: " << e.what() << "\n";
    }
}

// Törlés
void deleteEntry(const fs::path& path) {
    try {
        if (fs::is_directory(path))
            fs::remove_all(path);
        else
            fs::remove(path);
        std::cout << "Törölve: " << path << "\n";
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Hiba: " << e.what() << "\n";
    }
}

// Navigáció
void navigate() {
    fs::path current = ROOT_DIR;
    for (;;) {
        listFiles(current);
        std::cout << "Parancs (cd <mappa> | .. | cp <src> <dest> | mv <src> <dest> | del <nev> | exit): ";
        std::string input;
        std::getline(std::cin, input);

        if (input == "exit") return;

        if (input == "..") {
            if (current != ROOT_DIR)
                current = current.parent_path();
            continue;
        }

        if (input.rfind("cd ", 0) == 0) {
            fs::path next = current / input.substr(3);
            if (fs::exists(next) && fs::is_directory(next))
                current = next;
            else
                std::cout << "Nem létező mappa!\n";
            continue;
        }

        if (input.rfind("del ", 0) == 0) {
            deleteEntry(current / input.substr(4));
            continue;
        }

        if (input.rfind("cp ", 0) == 0) {
            std::string args = input.substr(3);
            size_t sp = args.find(' ');
            if (sp != std::string::npos)
                copyEntry(current / args.substr(0, sp), args.substr(sp + 1));
            continue;
        }

        if (input.rfind("mv ", 0) == 0) {
            std::string args = input.substr(3);
            size_t sp = args.find(' ');
            if (sp != std::string::npos)
                moveEntry(current / args.substr(0, sp), args.substr(sp + 1));
            continue;
        }

        // Enter = belépés mappába
        fs::path chosen = current / input;
        if (fs::exists(chosen) && fs::is_directory(chosen))
            current = chosen;
        else
            std::cout << "Ismeretlen parancs vagy nem létező mappa.\n";
    }
}

int main() {
    navigate();
}
```

---

## 2. C++ — `std::filesystem` nélkül (POSIX / Windows)

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#ifdef _WIN32
  #include <windows.h>
#else
  #include <dirent.h>
  #include <sys/stat.h>
  #include <unistd.h>
#endif

const std::string ROOT_DIR = "./data";

struct FileEntry {
    std::string name;
    bool isDirectory;
};

bool isDir(const std::string& path) {
    struct stat s{};
    return (stat(path.c_str(), &s) == 0) && S_ISDIR(s.st_mode);
}

// Listázás
std::vector<FileEntry> listFiles(const std::string& directory) {
    std::vector<FileEntry> entries;
#ifdef _WIN32
    WIN32_FIND_DATA fd;
    HANDLE hFind = FindFirstFile((directory + "\\*").c_str(), &fd);
    if (hFind != INVALID_HANDLE_VALUE) {
        do {
            std::string name = fd.cFileName;
            if (name != "." && name != "..") {
                bool dir = (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0;
                entries.push_back({name, dir});
            }
        } while (FindNextFile(hFind, &fd));
        FindClose(hFind);
    }
#else
    DIR* dir = opendir(directory.c_str());
    if (dir) {
        struct dirent* ent;
        while ((ent = readdir(dir)) != nullptr) {
            std::string name = ent->d_name;
            if (name != "." && name != "..") {
                std::string fullPath = directory + "/" + name;
                entries.push_back({name, isDir(fullPath)});
            }
        }
        closedir(dir);
    }
#endif
    return entries;
}

// Másolás
void copyEntry(const std::string& src, const std::string& dest) {
#ifdef _WIN32
    std::string cmd = isDir(src)
        ? "xcopy /E /I /H /Y \"" + src + "\" \"" + dest + "\""
        : "copy /Y \"" + src + "\" \"" + dest + "\"";
#else
    std::string cmd = "cp -rp \"" + src + "\" \"" + dest + "\"";
#endif
    system(cmd.c_str());
}

// Áthelyezés
void moveEntry(const std::string& src, const std::string& dest) {
#ifdef _WIN32
    std::string cmd = "move /Y \"" + src + "\" \"" + dest + "\"";
#else
    std::string cmd = "mv -f \"" + src + "\" \"" + dest + "\"";
#endif
    system(cmd.c_str());
}

// Törlés
void deleteEntry(const std::string& path) {
#ifdef _WIN32
    std::string cmd = isDir(path)
        ? "rd /s /q \"" + path + "\""
        : "del /f /q \"" + path + "\"";
#else
    std::string cmd = isDir(path)
        ? "rm -rf \"" + path + "\""
        : "rm -f \"" + path + "\"";
#endif
    system(cmd.c_str());
}

// Navigáció
void navigate() {
    std::string current = ROOT_DIR;
    for (;;) {
        std::cout << "--- " << current << " ---\n";
        auto entries = listFiles(current);
        for (const auto& e : entries)
            std::cout << (e.isDirectory ? "[DIR]  " : "       ") << e.name << "\n";

        std::cout << "Parancs: ";
        std::string input;
        std::getline(std::cin, input);

        if (input == "exit") return;

        if (input == "..") {
            if (current.length() > ROOT_DIR.length()) {
                size_t pos = current.find_last_of("/\\");
                if (pos != std::string::npos) current = current.substr(0, pos);
            }
            continue;
        }

        if (input.rfind("del ", 0) == 0) { deleteEntry(current + "/" + input.substr(4)); continue; }
        if (input.rfind("cp ", 0) == 0) {
            std::string args = input.substr(3);
            size_t sp = args.find(' ');
            if (sp != std::string::npos) copyEntry(current + "/" + args.substr(0, sp), args.substr(sp + 1));
            continue;
        }
        if (input.rfind("mv ", 0) == 0) {
            std::string args = input.substr(3);
            size_t sp = args.find(' ');
            if (sp != std::string::npos) moveEntry(current + "/" + args.substr(0, sp), args.substr(sp + 1));
            continue;
        }

        // Enter = belépés mappába
        std::string chosen = current + "/" + input;
        if (isDir(chosen)) current = chosen;
        else std::cout << "Ismeretlen parancs vagy mappa.\n";
    }
}

int main() {
    navigate();
}
```

---

## 3. C — POSIX / Windows

```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef _WIN32
  #include <windows.h>
#else
  #include <dirent.h>
  #include <sys/stat.h>
#endif

#define ROOT_DIR "./data"
#define MAX_PATH_LEN 1024

int isDir(const char* path) {
    struct stat s;
    return (stat(path, &s) == 0) && S_ISDIR(s.st_mode);
}

// Listázás
void listFiles(const char* directory) {
    printf("--- %s ---\n", directory);
#ifdef _WIN32
    char searchPath[MAX_PATH_LEN];
    snprintf(searchPath, sizeof(searchPath), "%s\\*", directory);
    WIN32_FIND_DATA fd;
    HANDLE hFind = FindFirstFile(searchPath, &fd);
    if (hFind != INVALID_HANDLE_VALUE) {
        do {
            if (strcmp(fd.cFileName, ".") && strcmp(fd.cFileName, "..")) {
                int dir = (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0;
                printf("%s %s\n", dir ? "[DIR] " : "      ", fd.cFileName);
            }
        } while (FindNextFile(hFind, &fd));
        FindClose(hFind);
    }
#else
    DIR* dir = opendir(directory);
    if (!dir) { perror("opendir"); return; }
    struct dirent* ent;
    while ((ent = readdir(dir)) != NULL) {
        if (strcmp(ent->d_name, ".") && strcmp(ent->d_name, "..")) {
            char fullPath[MAX_PATH_LEN];
            snprintf(fullPath, sizeof(fullPath), "%s/%s", directory, ent->d_name);
            printf("%s %s\n", isDir(fullPath) ? "[DIR] " : "      ", ent->d_name);
        }
    }
    closedir(dir);
#endif
}

// Másolás
void copyEntry(const char* src, const char* dest) {
    char cmd[MAX_PATH_LEN * 2 + 32];
#ifdef _WIN32
    snprintf(cmd, sizeof(cmd), isDir(src)
        ? "xcopy /E /I /H /Y \"%s\" \"%s\""
        : "copy /Y \"%s\" \"%s\"", src, dest);
#else
    snprintf(cmd, sizeof(cmd), "cp -rp \"%s\" \"%s\"", src, dest);
#endif
    system(cmd);
}

// Áthelyezés
void moveEntry(const char* src, const char* dest) {
    char cmd[MAX_PATH_LEN * 2 + 16];
#ifdef _WIN32
    snprintf(cmd, sizeof(cmd), "move /Y \"%s\" \"%s\"", src, dest);
#else
    snprintf(cmd, sizeof(cmd), "mv -f \"%s\" \"%s\"", src, dest);
#endif
    system(cmd);
}

// Törlés
void deleteEntry(const char* path) {
    char cmd[MAX_PATH_LEN + 16];
#ifdef _WIN32
    snprintf(cmd, sizeof(cmd), isDir(path)
        ? "rd /s /q \"%s\""
        : "del /f /q \"%s\"", path);
#else
    snprintf(cmd, sizeof(cmd), isDir(path)
        ? "rm -rf \"%s\""
        : "rm -f \"%s\"", path);
#endif
    system(cmd);
}

// Navigáció
void navigate() {
    char current[MAX_PATH_LEN];
    strncpy(current, ROOT_DIR, MAX_PATH_LEN);
    char input[256];

    for (;;) {
        listFiles(current);
        printf("Parancs (cd <mappa> | .. | cp <src> <dest> | mv <src> <dest> | del <nev> | exit): ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0; // newline levágás

        if (strcmp(input, "exit") == 0) return;

        if (strcmp(input, "..") == 0) {
            if (strlen(current) > strlen(ROOT_DIR)) {
                char* last = strrchr(current, '/');
                if (!last) last = strrchr(current, '\\');
                if (last) *last = '\0';
            }
            continue;
        }

        if (strncmp(input, "del ", 4) == 0) {
            char full[MAX_PATH_LEN];
            snprintf(full, sizeof(full), "%s/%s", current, input + 4);
            deleteEntry(full);
            continue;
        }

        if (strncmp(input, "cp ", 3) == 0) {
            char src[MAX_PATH_LEN], dest[MAX_PATH_LEN];
            char* space = strchr(input + 3, ' ');
            if (space) {
                *space = '\0';
                snprintf(src, sizeof(src), "%s/%s", current, input + 3);
                strncpy(dest, space + 1, MAX_PATH_LEN);
                copyEntry(src, dest);
            }
            continue;
        }

        if (strncmp(input, "mv ", 3) == 0) {
            char src[MAX_PATH_LEN], dest[MAX_PATH_LEN];
            char* space = strchr(input + 3, ' ');
            if (space) {
                *space = '\0';
                snprintf(src, sizeof(src), "%s/%s", current, input + 3);
                strncpy(dest, space + 1, MAX_PATH_LEN);
                moveEntry(src, dest);
            }
            continue;
        }

        // Enter = belépés mappába
        char chosen[MAX_PATH_LEN];
        snprintf(chosen, sizeof(chosen), "%s/%s", current, input);
        if (isDir(chosen))
            strncpy(current, chosen, MAX_PATH_LEN);
        else
            printf("Ismeretlen parancs vagy mappa.\n");
    }
}

int main() {
    navigate();
    return 0;
}
```

---

## 4. Java — `java.nio.file`

```java
import java.io.*;
import java.nio.file.*;
import java.nio.file.attribute.BasicFileAttributes;
import java.util.*;

public class FileManager {

    static final Path ROOT_DIR = Paths.get("./data");

    // Listázás
    static void listFiles(Path directory) throws IOException {
        System.out.println("--- " + directory.toAbsolutePath() + " ---");
        try (DirectoryStream<Path> stream = Files.newDirectoryStream(directory)) {
            for (Path entry : stream) {
                String prefix = Files.isDirectory(entry) ? "[DIR]  " : "       ";
                System.out.println(prefix + entry.getFileName());
            }
        }
    }

    // Másolás
    static void copyEntry(Path src, Path dest) throws IOException {
        if (Files.isDirectory(src)) {
            Files.walkFileTree(src, new SimpleFileVisitor<>() {
                public FileVisitResult preVisitDirectory(Path dir, BasicFileAttributes attrs) throws IOException {
                    Files.createDirectories(dest.resolve(src.relativize(dir)));
                    return FileVisitResult.CONTINUE;
                }
                public FileVisitResult visitFile(Path file, BasicFileAttributes attrs) throws IOException {
                    Files.copy(file, dest.resolve(src.relativize(file)), StandardCopyOption.REPLACE_EXISTING);
                    return FileVisitResult.CONTINUE;
                }
            });
        } else {
            Files.copy(src, dest, StandardCopyOption.REPLACE_EXISTING);
        }
        System.out.println("Másolva: " + src + " -> " + dest);
    }

    // Áthelyezés
    static void moveEntry(Path src, Path dest) throws IOException {
        Files.move(src, dest, StandardCopyOption.REPLACE_EXISTING);
        System.out.println("Áthelyezve: " + src + " -> " + dest);
    }

    // Törlés
    static void deleteEntry(Path path) throws IOException {
        if (Files.isDirectory(path)) {
            Files.walkFileTree(path, new SimpleFileVisitor<>() {
                public FileVisitResult visitFile(Path file, BasicFileAttributes attrs) throws IOException {
                    Files.delete(file); return FileVisitResult.CONTINUE;
                }
                public FileVisitResult postVisitDirectory(Path dir, IOException exc) throws IOException {
                    Files.delete(dir); return FileVisitResult.CONTINUE;
                }
            });
        } else {
            Files.delete(path);
        }
        System.out.println("Törölve: " + path);
    }

    // Navigáció
    static void navigate() throws IOException {
        Path current = ROOT_DIR;
        Scanner scanner = new Scanner(System.in);

        while (true) {
            listFiles(current);
            System.out.print("Parancs (cd <mappa> | .. | cp <src> <dest> | mv <src> <dest> | del <nev> | exit): ");
            String input = scanner.nextLine().trim();

            if (input.equals("exit")) return;

            if (input.equals("..")) {
                if (!current.equals(ROOT_DIR)) current = current.getParent();
                continue;
            }

            if (input.startsWith("del ")) {
                deleteEntry(current.resolve(input.substring(4)));
                continue;
            }

            if (input.startsWith("cp ")) {
                String[] parts = input.substring(3).split(" ", 2);
                if (parts.length == 2) copyEntry(current.resolve(parts[0]), Paths.get(parts[1]));
                continue;
            }

            if (input.startsWith("mv ")) {
                String[] parts = input.substring(3).split(" ", 2);
                if (parts.length == 2) moveEntry(current.resolve(parts[0]), Paths.get(parts[1]));
                continue;
            }

            // Enter = belépés mappába
            Path chosen = current.resolve(input);
            if (Files.isDirectory(chosen)) current = chosen;
            else System.out.println("Ismeretlen parancs vagy mappa.");
        }
    }

    public static void main(String[] args) throws IOException {
        navigate();
    }
}
```

---

## 5. Kotlin — `java.nio.file`

```kotlin
import java.nio.file.*
import java.nio.file.attribute.BasicFileAttributes

val ROOT_DIR: Path = Paths.get("./data")

// Listázás
fun listFiles(directory: Path) {
    println("--- ${directory.toAbsolutePath()} ---")
    Files.newDirectoryStream(directory).use { stream ->
        for (entry in stream) {
            val prefix = if (Files.isDirectory(entry)) "[DIR]  " else "       "
            println("$prefix${entry.fileName}")
        }
    }
}

// Másolás
fun copyEntry(src: Path, dest: Path) {
    if (Files.isDirectory(src)) {
        Files.walkFileTree(src, object : SimpleFileVisitor<Path>() {
            override fun preVisitDirectory(dir: Path, attrs: BasicFileAttributes): FileVisitResult {
                Files.createDirectories(dest.resolve(src.relativize(dir)))
                return FileVisitResult.CONTINUE
            }
            override fun visitFile(file: Path, attrs: BasicFileAttributes): FileVisitResult {
                Files.copy(file, dest.resolve(src.relativize(file)), StandardCopyOption.REPLACE_EXISTING)
                return FileVisitResult.CONTINUE
            }
        })
    } else {
        Files.copy(src, dest, StandardCopyOption.REPLACE_EXISTING)
    }
    println("Másolva: $src -> $dest")
}

// Áthelyezés
fun moveEntry(src: Path, dest: Path) {
    Files.move(src, dest, StandardCopyOption.REPLACE_EXISTING)
    println("Áthelyezve: $src -> $dest")
}

// Törlés
fun deleteEntry(path: Path) {
    if (Files.isDirectory(path)) {
        Files.walkFileTree(path, object : SimpleFileVisitor<Path>() {
            override fun visitFile(file: Path, attrs: BasicFileAttributes): FileVisitResult {
                Files.delete(file); return FileVisitResult.CONTINUE
            }
            override fun postVisitDirectory(dir: Path, exc: IOException?): FileVisitResult {
                Files.delete(dir); return FileVisitResult.CONTINUE
            }
        })
    } else {
        Files.delete(path)
    }
    println("Törölve: $path")
}

// Navigáció
fun navigate() {
    var current = ROOT_DIR
    val reader = System.`in`.bufferedReader()

    while (true) {
        listFiles(current)
        print("Parancs (cd <mappa> | .. | cp <src> <dest> | mv <src> <dest> | del <nev> | exit): ")
        val input = reader.readLine()?.trim() ?: return

        if (input == "exit") return

        if (input == "..") {
            if (current != ROOT_DIR) current = current.parent
            continue
        }

        if (input.startsWith("del ")) {
            deleteEntry(current.resolve(input.substring(4))); continue
        }

        if (input.startsWith("cp ")) {
            val parts = input.substring(3).split(" ", limit = 2)
            if (parts.size == 2) copyEntry(current.resolve(parts[0]), Paths.get(parts[1]))
            continue
        }

        if (input.startsWith("mv ")) {
            val parts = input.substring(3).split(" ", limit = 2)
            if (parts.size == 2) moveEntry(current.resolve(parts[0]), Paths.get(parts[1]))
            continue
        }

        // Enter = belépés mappába
        val chosen = current.resolve(input)
        if (Files.isDirectory(chosen)) current = chosen
        else println("Ismeretlen parancs vagy mappa.")
    }
}

fun main() {
    navigate()
}
```

---

## 6. Python — `pathlib` + `shutil`

```python
import shutil
from pathlib import Path

ROOT_DIR = Path("./data")

# Listázás
def list_files(directory: Path):
    print(f"--- {directory.resolve()} ---")
    for entry in sorted(directory.iterdir()):
        prefix = "[DIR]  " if entry.is_dir() else "       "
        print(f"{prefix}{entry.name}")

# Másolás
def copy_entry(src: Path, dest: Path):
    if src.is_dir():
        shutil.copytree(src, dest, dirs_exist_ok=True)
    else:
        shutil.copy2(src, dest)
    print(f"Másolva: {src} -> {dest}")

# Áthelyezés
def move_entry(src: Path, dest: Path):
    shutil.move(str(src), str(dest))
    print(f"Áthelyezve: {src} -> {dest}")

# Törlés
def delete_entry(path: Path):
    if path.is_dir():
        shutil.rmtree(path)
    else:
        path.unlink()
    print(f"Törölve: {path}")

# Navigáció
def navigate():
    current = ROOT_DIR

    while True:
        list_files(current)
        user_input = input("Parancs (cd <mappa> | .. | cp <src> <dest> | mv <src> <dest> | del <nev> | exit): ").strip()

        if user_input == "exit":
            return

        if user_input == "..":
            if current != ROOT_DIR:
                current = current.parent
            continue

        if user_input.startswith("del "):
            delete_entry(current / user_input[4:])
            continue

        if user_input.startswith("cp "):
            parts = user_input[3:].split(" ", 1)
            if len(parts) == 2:
                copy_entry(current / parts[0], Path(parts[1]))
            continue

        if user_input.startswith("mv "):
            parts = user_input[3:].split(" ", 1)
            if len(parts) == 2:
                move_entry(current / parts[0], Path(parts[1]))
            continue

        # Enter = belépés mappába
        chosen = current / user_input
        if chosen.is_dir():
            current = chosen
        else:
            print("Ismeretlen parancs vagy mappa.")

if __name__ == "__main__":
    navigate()
```

---

## Összefoglalás

| Művelet       | C++ filesystem      | C++ (no fs)       | C                  | Java                  | Kotlin                | Python               |
|---------------|---------------------|-------------------|--------------------|-----------------------|-----------------------|----------------------|
| Listázás      | `directory_iterator`| `opendir/readdir` | `opendir/readdir`  | `DirectoryStream`     | `DirectoryStream`     | `Path.iterdir()`     |
| Belépés       | `current /= mappa`  | `strcat`          | `strcat`           | `resolve()`           | `resolve()`           | `Path / mappa`       |
| Visszalépés   | `parent_path()`     | `find_last_of`    | `strrchr`          | `getParent()`         | `.parent`             | `.parent`            |
| Másolás       | `fs::copy`          | `system(cp/xcopy)`| `system(cp/xcopy)` | `Files.copy`          | `Files.copy`          | `shutil.copy2`       |
| Áthelyezés    | `fs::rename`        | `system(mv/move)` | `system(mv/move)`  | `Files.move`          | `Files.move`          | `shutil.move`        |
| Törlés        | `fs::remove_all`    | `system(rm/rd)`   | `system(rm/rd)`    | `Files.walkFileTree`  | `Files.walkFileTree`  | `shutil.rmtree`      |
