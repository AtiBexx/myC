# Reverse Engineering – Parancsok, Eszközök és Védelmek

## Tartalom
- [Disassembly / Dump parancsok](#disassembly--dump-parancsok)
- [Statikus elemzés eszközök](#statikus-elemzés-eszközök)
- [Dinamikus elemzés – Debuggerek](#dinamikus-elemzés--debuggerek)
- [Decompilerek](#decompilerek)
- [Dump eszközök](#dump-eszközök)
- [Védelmek és packerek](#védelmek-és-packerek)
- [Védelemelemzés és unpack eszközök](#védelemelemzés-és-unpack-eszközök)
- [Hasznos egyéb eszközök](#hasznos-egyéb-eszközök)

---

## Disassembly / Dump parancsok

### objdump (Linux)
```bash
# Teljes disassembly
objdump -d binary

# Minden szekció disassembly
objdump -D binary

# Intel szintaxis
objdump -d -M intel binary

# Szimbólumtáblával
objdump -d -t binary

# Adott szekció dump
objdump -d -j .text binary

# Raw hex dump
objdump -s binary

# Szekciólista
objdump -h binary

# Importok/exportok
objdump -p binary
```

### ndisasm (NASM)
```bash
ndisasm -b 32 file.bin          # 32 bites
ndisasm -b 64 file.bin          # 64 bites
ndisasm -b 16 file.bin          # 16 bites (DOS/MBR)
ndisasm -o 0x400000 file.bin    # Origin cím megadása
```

### readelf (ELF fájlok)
```bash
readelf -h binary               # ELF header
readelf -S binary               # Szekciók
readelf -l binary               # Program headerek (szegmensek)
readelf -s binary               # Szimbólumtábla
readelf -r binary               # Relokációk
readelf -d binary               # Dinamikus szekció (importok)
readelf -a binary               # Minden
```

### dumpbin (Windows / MSVC)
```cmd
dumpbin /HEADERS file.exe
dumpbin /IMPORTS file.exe
dumpbin /EXPORTS file.dll
dumpbin /DISASM file.exe
dumpbin /RAWDATA file.exe
dumpbin /SUMMARY file.exe
dumpbin /SYMBOLS file.obj
```

### PE-bear / pecheck (PE elemzés)
```bash
# pecheck (Python)
pecheck file.exe
pecheck -A file.exe             # Minden adat
pecheck -s file.exe             # Szekciók
```

### strings
```bash
strings binary                  # Alapértelmezett (min 4 char)
strings -n 8 binary             # Min 8 karakter
strings -a binary               # Teljes fájl
strings -e l binary             # Little-endian UTF-16
strings -e b binary             # Big-endian UTF-16
```

### xxd / hexdump
```bash
xxd binary | head -50           # Hex dump
xxd -l 256 binary               # Első 256 byte
xxd -s 0x400 binary             # Adott offsettől
hexdump -C binary               # Cannonical hex+ASCII
hexdump -x binary               # 16 bites hex
```

### dd (raw dump)
```bash
dd if=binary of=section.bin bs=1 skip=$((0x1000)) count=$((0x500))
```

---

## Statikus elemzés eszközök

| Eszköz | Platform | Leírás |
|--------|----------|--------|
| **IDA Pro** | Win/Lin/Mac | Ipari standard disassembler/decompiler |
| **IDA Free** | Win/Lin/Mac | Ingyenes verzió (korlátozott decompiler) |
| **Ghidra** | Win/Lin/Mac | NSA által fejlesztett, ingyenes RE suite |
| **Binary Ninja** | Win/Lin/Mac | Modern disassembler, scripting-barát |
| **Cutter** | Win/Lin/Mac | Rizin/Radare2 GUI frontend |
| **Radare2 (r2)** | Win/Lin/Mac | CLI-alapú, szkriptelhető RE framework |
| **PE-bear** | Windows | PE fájl elemző GUI |
| **PEiD** | Windows | Packer/protector azonosító |
| **Detect-It-Easy (DIE)** | Win/Lin/Mac | Packer/compiler azonosítás |
| **ExeinfoPE** | Windows | PE info + packer detect |
| **CFF Explorer** | Windows | PE editor és struktúra néző |
| **HxD** | Windows | Hex editor |
| **010 Editor** | Win/Mac | Hex editor template-ekkel |
| **ImHex** | Win/Lin/Mac | Modern, ingyenes hex editor |
| **pestudio** | Windows | Malware első elemzése |
| **Binwalk** | Lin/Win | Firmware és beágyazott fájlok elemzése |

### Radare2 alapparancsok
```bash
r2 binary                       # Megnyitás
r2 -A binary                    # Auto-analyze megnyitáskor
r2 -d binary                    # Debug módban

# R2 shellben:
aa                              # Analyze all
aaa                             # Deeper analysis
afl                             # Funkciólista
pdf @ main                      # Főfüggvény disassembly
px 64 @ 0x400000                # Hex dump adott címtől
iz                              # Stringek az adatszekciókban
iI                              # Bináris info
ii                              # Importok
ie                              # Exportok
iS                              # Szekciók
```

---

## Dinamikus elemzés – Debuggerek

| Eszköz | Platform | Leírás |
|--------|----------|--------|
| **x64dbg** | Windows | Modern 64/32 bites debugger (open source) |
| **x32dbg** | Windows | x64dbg 32 bites változata |
| **OllyDbg** | Windows | Klasszikus 32 bites debugger |
| **WinDbg** | Windows | Microsoft kernel+user-mode debugger |
| **WinDbg Preview** | Windows | Modernizált WinDbg (Store) |
| **GDB** | Lin/Win/Mac | GNU debugger |
| **PEDA** | Linux | GDB plugin (exploit fejlesztés) |
| **pwndbg** | Linux | GDB plugin CTF/pwn-hoz |
| **GEF** | Linux | GDB Enhanced Features plugin |
| **rr** | Linux | Record & replay debugger (Mozilla) |
| **lldb** | Lin/Mac | LLVM debugger |
| **edb-debugger** | Linux | OllyDbg-like Linux debugger |

### x64dbg hasznos billentyűk / parancsok
```
F2      – Breakpoint toggle
F7      – Step Into
F8      – Step Over
F9      – Run
Ctrl+G  – Adott címre ugrás
Ctrl+F  – Keresés (stringek, bájt szekvenciák)
Alt+B   – Breakpoint lista
Alt+M   – Memory map

# Parancssor:
bp 0x401000          – Breakpoint beállítása
bpc 0x401000         – Breakpoint törlése
bphws 0x403000, r    – Hardware breakpoint (olvasás)
bphws 0x403000, w    – Hardware breakpoint (írás)
dump 0x401000        – Memória dump megnyitása
```

### GDB alapparancsok
```bash
gdb ./binary
gdb -p <PID>                    # Attach futó processhez

# GDB shellben:
run / r                         # Futtatás
break main / b main             # Breakpoint
break *0x400560                 # Cím alapján breakpoint
info break                      # Breakpointok listája
delete 1                        # Breakpoint törlése
step / s                        # Step into
next / n                        # Step over
continue / c                    # Futtatás folytatása
finish                          # Kilépés aktuális függvényből
info registers                  # Regiszterek
x/16xb 0x400000                 # Hex dump (16 byte)
x/s 0x402050                    # String a memóriában
disassemble main                # Disassembly
set disassembly-flavor intel    # Intel szintaxis
backtrace / bt                  # Call stack
info proc mappings              # Memóriatérkép
```

### WinDbg parancsok
```
bp kernel32!CreateFileA         – Breakpoint szimbólum alapján
bp 0x7ff600401000               – Cím alapján breakpoint
bl                              – Breakpoint lista
bc 0                            – Breakpoint törlése
g                               – Go (futtatás)
t                               – Trace (step into)
p                               – Step over
k                               – Call stack
r                               – Regiszterek
dd 0x401000                     – DWORD dump
db 0x401000                     – Byte dump
u 0x401000                      – Disassembly
lm                              – Betöltött modulok
!address 0x401000               – Memória info
!peb                            – Process Environment Block
!teb                            – Thread Environment Block
.logopen c:\debug.log           – Log mentése fájlba
```

---

## Decompilerek

| Eszköz | Platform | Leírás |
|--------|----------|--------|
| **Hex-Rays (IDA)** | Win/Lin/Mac | Legjobb C/C++ decompiler (fizetős) |
| **Ghidra Decompiler** | Win/Lin/Mac | Ingyenes, jó minőségű C decompiler |
| **Binary Ninja** | Win/Lin/Mac | MLIL/HLIL decompiler |
| **RetDec** | Win/Lin/Mac | Avast ingyenes decompiler |
| **Snowman** | Windows | x86/x64 C++ decompiler |
| **dnSpy** | Windows | .NET assembly decompiler+debugger |
| **dotPeek** | Windows | JetBrains .NET decompiler |
| **ILSpy** | Windows | Ingyenes .NET decompiler |
| **jadx** | Win/Lin/Mac | Android APK/DEX → Java decompiler |
| **JD-GUI** | Win/Lin/Mac | Java `.class` decompiler |
| **Procyon** | Win/Lin/Mac | Java decompiler |
| **CFR** | Win/Lin/Mac | Java decompiler (modern class támogatás) |
| **apktool** | Win/Lin/Mac | APK visszafejtés + Smali |

---

## Dump eszközök

| Eszköz | Platform | Leírás |
|--------|----------|--------|
| **Process Hacker** | Windows | Memória dump, process info |
| **Process Explorer** | Windows | Sysinternals process viewer |
| **OllyDump** | Windows | OllyDbg plugin – PE dump packerből |
| **Scylla** | Windows | x64dbg plugin – import rekonstrukció + dump |
| **PE-Sieve** | Windows | Injected/modified code scanner+dump |
| **hollows_hunter** | Windows | PE-Sieve batch verzió |
| **volatility** | Lin/Win | Memory forensics framework |
| **procdump** | Windows | Sysinternals – process dump |

### Scylla (dump csomagolt PE-ből)
```
1. Futtatni a csomagolt exe-t és megállni OEP-nél (Original Entry Point)
2. x64dbg-ben: Plugins → Scylla
3. IAT Autosearch → Get Imports
4. Dump → dump.exe
5. Fix Dump → végleges, javított PE fájl
```

### PE-Sieve parancsok
```bash
pe-sieve.exe /pid 1234
pe-sieve.exe /pid 1234 /imp 3   # Import rekonstrukció
pe-sieve.exe /pid 1234 /out C:\dump\
```

---

## Védelmek és packerek

### Packerek (tömörítők)
| Név | Típus | Megjegyzés |
|-----|-------|------------|
| **UPX** | Tömörítő | Leggyakoribb, könnyen unpackelhető |
| **ASPack** | Tömörítő | Régebbi, exe tömörítés |
| **FSG** | Tömörítő | Fast Small Good |
| **MPRESS** | Tömörítő | .NET és natív |
| **PECompact** | Tömörítő | Kereskedelmi packer |
| **Themida / WinLicense** | Protektor | Erős kereskedelmi védelem |
| **VMProtect** | Protektor+VM | VM-alapú obfuszkáció |
| **Obsidium** | Protektor | Kereskedelmi védelmi rendszer |
| **Enigma Protector** | Protektor | Licenszelés + tömörítés |
| **ExeCryptor** | Protektor | Natív kódvédelem |
| **ConfuserEx** | .NET obfuszkátor | Ingyenes .NET packer |
| **de4dot** | .NET | .NET obfuszkátor eltávolító |

### Anti-debug technikák
| Technika | API / Módszer |
|----------|--------------|
| IsDebuggerPresent | kernel32.dll |
| CheckRemoteDebuggerPresent | kernel32.dll |
| NtQueryInformationProcess | ntdll.dll (ProcessDebugPort) |
| Heap Flags vizsgálata | PEB.NtGlobalFlag |
| Timing attack | RDTSC, GetTickCount |
| Exception handling | INT3, INT 2D |
| TLS callback | Futtatás main() előtt |
| Self-debugging | Folyamat saját magát debugolja |
| Hardware breakpoint detekt | DR regiszterek vizsgálata |
| OutputDebugString trükk | SetLastError + visszatérési érték |

### Anti-VM technikák
| Technika | Leírás |
|----------|--------|
| CPUID ellenőrzés | Hypervisor bit (bit 31 ECX) |
| Registry vizsgálat | VMware/VBox kulcsok |
| Eszközök nevei | `\\.\VBoxGuest`, `\\.\vmci` |
| MAC cím ellenőrzés | VMware: 00:0C:29, VBox: 08:00:27 |
| Folyamat lista | vmtoolsd.exe, vboxservice.exe |
| RDTSC timing | VM lassabb |
| Fájlok megléte | `C:\windows\system32\drivers\vmmouse.sys` |

### Anti-analysis technikák
| Technika | Leírás |
|----------|--------|
| Code obfuscation | Junk code, dead code insertion |
| Control flow flattening | Végrehajtási sorrend elfedése |
| String encryption | XOR, RC4, AES stringek |
| Dynamic API resolving | GetProcAddress runtime |
| Self-modifying code | Önmagát módosítja futás közben |
| Packing | Titkosítás/tömörítés futtatás előtt |
| Virtualization | Saját VM bytecode (VMProtect) |
| Import obfuscation | IAT elrejtése |

---

## Védelemelemzés és unpack eszközök

### UPX unpack
```bash
upx -d packed.exe -o unpacked.exe      # Automatikus unpack
upx -d -o output.exe input.exe
```

### de4dot (.NET deobfuszkátor)
```bash
de4dot.exe obfuscated.exe
de4dot.exe -f obfuscated.exe -o clean.exe
de4dot.exe --detect obfuscated.exe          # Csak azonosítás
```

### apktool (Android APK)
```bash
apktool d app.apk                      # Decode (smali + resources)
apktool d app.apk -o output_dir
apktool b output_dir -o rebuilt.apk    # Újraépítés
```

### jadx (APK/DEX → Java)
```bash
jadx app.apk -d output_dir
jadx-gui app.apk                       # GUI módban
jadx classes.dex
```

### dnSpy / ILSpy (.NET)
```
dnSpy: Fájl megnyitása → Assembly Browser → Decompile → Szerkesztés + újrafordítás
ILSpy: CLI: ilspycmd Assembly.dll -o output_dir
```

---

## Hasznos egyéb eszközök

| Eszköz | Platform | Leírás |
|--------|----------|--------|
| **Wireshark** | Win/Lin/Mac | Hálózati forgalom elemzés |
| **Fiddler** | Win/Mac | HTTP/HTTPS proxy interceptor |
| **Burp Suite** | Win/Lin/Mac | Web app proxy + RE |
| **API Monitor** | Windows | API hívások monitorozása |
| **Frida** | Win/Lin/Mac/Android | Dinamikus instrumentáció (JS) |
| **FLOSS** | Win/Lin/Mac | Obfuszkált stringek kinyerése |
| **YARA** | Win/Lin/Mac | Minta alapú fájlazonosítás |
| **Cuckoo Sandbox** | Linux | Automatizált malware sandbox |
| **Any.run** | Online | Interaktív malware sandbox |
| **VirusTotal** | Online | Multi-AV + statikus elemzés |
| **Hybrid-Analysis** | Online | Ingyenes sandbox |
| **Sysinternals Suite** | Windows | Process Monitor, Autoruns, TCPView stb. |
| **regshot** | Windows | Registry változások követése |
| **Noriben** | Windows | Behavioral analysis sandbox |

### Frida alapparancsok
```bash
frida-ps -U                             # USB (Android) processek
frida-ps -a                             # Futó processek
frida -U -l script.js com.app.package   # Script befecskendezése
frida-trace -U -i "open*" app           # API trace
frida --codeshare user/script -U app    # Codeshare script használata
```

### FLOSS (obfuszkált stringek)
```bash
floss.exe malware.exe
floss.exe -n 6 malware.exe              # Min 6 karakter
floss.exe --no-static malware.exe       # Csak dinamikus stringek
```

---

> **Megjegyzés:** Az eszközök kizárólag legális célokra, saját rendszereken, CTF versenyeken vagy engedélyezett penetrációs tesztelésen alkalmazhatók.
