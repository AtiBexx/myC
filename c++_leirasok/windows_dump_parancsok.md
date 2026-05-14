# Windows Dumpolás – Parancsok és Eszközök

## Tartalom
- [dumpbin (MSVC)](#dumpbin-msvc)
- [CFF Explorer](#cff-explorer)
- [PE-bear](#pe-bear)
- [pefile (Python)](#pefile-python)
- [x64dbg / x32dbg – memória dump](#x64dbg--x32dbg--memória-dump)
- [Scylla – PE dump packerből](#scylla--pe-dump-packerből)
- [PE-Sieve – automatikus dump](#pe-sieve--automatikus-dump)
- [Process Hacker / System Informer](#process-hacker--system-informer)
- [procdump (Sysinternals)](#procdump-sysinternals)
- [WinPmem – RAM dump](#winpmem--ram-dump)
- [Volatility – RAM elemzés](#volatility--ram-elemzés)
- [PowerShell dump parancsok](#powershell-dump-parancsok)
- [Task Manager – gyors dump](#task-manager--gyors-dump)

---

## dumpbin (MSVC)

A Visual Studio részeként települ. Elérhető a **Developer Command Prompt**-ból.

```cmd
:: PE header info
dumpbin /HEADERS file.exe

:: Importált függvények (melyik DLL-ből mit hív)
dumpbin /IMPORTS file.exe

:: Exportált függvények (DLL-eknél)
dumpbin /EXPORTS file.dll

:: Disassembly
dumpbin /DISASM file.exe
dumpbin /DISASM:NOBYTES file.exe        :: Bájtok nélkül (tisztább)

:: Raw hex dump
dumpbin /RAWDATA file.exe
dumpbin /RAWDATA:1 file.exe             :: Csak hex, ASCII nélkül

:: Összefoglaló (szekciók méretei)
dumpbin /SUMMARY file.exe

:: Szekciók listája
dumpbin /SECTION:.text file.exe

:: Szimbólumok (ha van debug info)
dumpbin /SYMBOLS file.obj
dumpbin /SYMBOLS file.pdb

:: Relocations
dumpbin /RELOCATIONS file.exe

:: Dependency (melyik DLL kell)
dumpbin /DEPENDENTS file.exe

:: Verzióinfó
dumpbin /CLRHEADER file.exe             :: .NET assembly esetén

:: Teljes dump fájlba
dumpbin /ALL file.exe > dump.txt
```

---

## CFF Explorer

GUI eszköz, de van parancssori mód is. PE struktúra néző + szerkesztő.

```cmd
:: Megnyitás CLI-ből
CFFExplorer.exe file.exe

:: Nincs gazdag CLI, GUI-ban:
:: File → Open → PE Header / Import Directory / Export Directory
```

**GUI-ban elérhető:**
- PE Header szerkesztés
- Import/Export táblák
- Resource Editor (ikonok, stringek, dialogok)
- Section Editor (szekciók hozzáadása/törlése)
- Rebuilder (PE újraépítés)

---

## PE-bear

GUI + minimális CLI, PE fájlok elemzéséhez.

```cmd
pe-bear.exe file.exe
```

**GUI-ban megmutatja:**
- DOS / NT / Optional Header
- Szekciók (raw/virtual méret, karakterisztikák)
- Import / Export táblák
- TLS callbacks
- Resource-ok
- Rich Header
- Overlay detektálás

---

## pefile (Python)

Programozható PE elemzés Pythonból.

```bash
pip install pefile
```

```python
import pefile

pe = pefile.PE("file.exe")

# Fejléc adatok
print(pe.DOS_HEADER)
print(pe.NT_HEADERS)
print(pe.OPTIONAL_HEADER)

# Szekciók
for section in pe.sections:
    print(section.Name, hex(section.VirtualAddress), section.SizeOfRawData)

# Importok
for entry in pe.DIRECTORY_ENTRY_IMPORT:
    print(entry.dll.decode())
    for imp in entry.imports:
        print("  ", imp.name, hex(imp.address))

# Exportok
for exp in pe.DIRECTORY_ENTRY_EXPORT.symbols:
    print(exp.name, hex(exp.address))

# Raw dump egy szekcióból
section = pe.sections[0]
data = section.get_data()
with open("section_dump.bin", "wb") as f:
    f.write(data)

# Teljes fájl dump
pe.write("modified.exe")
```

```cmd
:: CLI gyorselemzés
python -c "import pefile; pe=pefile.PE('file.exe'); print(pe.dump_info())"
```

---

## x64dbg / x32dbg – memória dump

### Memória dump GUI-ban
```
1. Betölteni az exe-t → futtatni az OEP-ig (Original Entry Point)
2. Memory Map fül (Alt+M)
3. Jobb klikk a kívánt szegmensre → "Dump Memory to File"
4. Mentés .bin fájlba
```

### Parancssor (Command bar)
```
:: Memória kiírása fájlba
savedata C:\dump\mem.bin, 0x400000, 0x5000
    :: savedata <fájl>, <kezdőcím>, <méret>

:: Dump a belépési ponttól
savedata C:\dump\ep.bin, $cip, 0x1000

:: PE dump plugin nélkül – adott cím tartalmának mentése
dump 0x401000

:: Modulok listája
modules

:: Aktuális modul base address
$base

:: Modul mérete
$size
```

### Scylla plugin (x64dbg-ben)
```
Plugins → Scylla
1. IAT Autosearch          :: Import Address Table megkeresése
2. Get Imports             :: Importok feloldása
3. Dump                    :: PE fájl dump memóriából
4. Fix Dump                :: Import tábla javítása a dump-ban
5. PE Rebuild              :: PE header újraépítés
```

---

## Scylla – PE dump packerből

Önálló verzió is elérhető (nem csak plugin).

```
Folyamat:
1. Futtatni a csomagolt exe-t
2. x64dbg-ben megállni az OEP-nél (loop 1-es int3 trick, vagy manuálisan)
3. Scylla megnyitása
4. Process kiválasztása a legördülőből
5. OEP mező kitöltése (pl. 0x456789)
6. IAT Autosearch → Get Imports
7. "Show Invalid" → invalid importok törlése kézzel
8. Dump → dump.exe mentése
9. Fix Dump → dump_SCY.exe (ez a végleges, javított fájl)
```

---

## PE-Sieve – automatikus dump

Futó processekből automatikusan dumpol injected/modified kódot.

```cmd
:: Alap scan és dump
pe-sieve.exe /pid 1234

:: Import rekonstrukcióval
pe-sieve.exe /pid 1234 /imp 3

:: Kimeneti könyvtár megadása
pe-sieve.exe /pid 1234 /out C:\dumps\

:: Minden modul dump (ne csak a módosítottak)
pe-sieve.exe /pid 1234 /dmode 3

:: Shellcode dump is
pe-sieve.exe /pid 1234 /shellc 1

:: Csöndes mód (csak hibák)
pe-sieve.exe /pid 1234 /quiet

:: Rekurzív (child processek is)
pe-sieve.exe /pid 1234 /rec 1

:: Teljes opciólista
pe-sieve.exe /?
```

### hollows_hunter (PE-Sieve batch)
```cmd
:: Minden futó process scanelése
hollows_hunter.exe

:: Kimeneti könyvtár
hollows_hunter.exe /out C:\dumps\

:: Import rekonstrukcióval
hollows_hunter.exe /imp 3

:: Csak injected kód dump
hollows_hunter.exe /hooks
```

---

## Process Hacker / System Informer

```
GUI módban:
1. Process Hacker megnyitása (admin jogosultsággal)
2. Processre jobb klikk → Properties
3. Memory fül → keresés / dump

Memória dump (teljes process):
1. Processre jobb klikk → "Create Dump File"
2. .dmp fájl mentése → WinDbg-gel elemezhető

Egyedi memóriaterület dump:
1. Properties → Memory fül
2. Szegmens kijelölése → jobb klikk → "Dump Memory"
3. Raw .bin fájl mentése
```

---

## procdump (Sysinternals)

```cmd
:: Process dump PID alapján
procdump.exe -ma 1234

:: Process dump név alapján
procdump.exe -ma notepad.exe

:: Mini dump (csak stack és regiszterek)
procdump.exe -mm 1234

:: Crash esetén automatikus dump
procdump.exe -e 1234

:: CPU spike esetén dump (CPU > 80%)
procdump.exe -c 80 1234

:: Több dump egymás után
procdump.exe -ma -n 3 1234

:: Kimeneti fájl neve
procdump.exe -ma 1234 C:\dumps\myapp.dmp

:: Dump indítás + figyelés
procdump.exe -ma -w myapp.exe C:\dumps\

:: Exception esetén dump (access violation stb.)
procdump.exe -ma -e 1 -f "" 1234
```

---

## WinPmem – RAM dump

Teljes fizikai memória dump (kernel driver alapú).

```cmd
:: Teljes RAM dump
winpmem_mini_x64.exe memdump.raw

:: AFF4 formátum
winpmem_mini_x64.exe memdump.aff4

:: Csak adott tartomány
winpmem_mini_x64.exe -start 0x1000 -length 0x10000 output.raw
```

---

## Volatility – RAM elemzés

RAM dump elemzése (Volatility 3).

```cmd
:: OS profil azonosítása
vol.exe -f memdump.raw windows.info

:: Futó processek listája
vol.exe -f memdump.raw windows.pslist
vol.exe -f memdump.raw windows.pstree         :: Fa struktúra

:: Elrejtett processek
vol.exe -f memdump.raw windows.psscan

:: DLL-ek egy processben
vol.exe -f memdump.raw windows.dlllist --pid 1234

:: Process memória dump
vol.exe -f memdump.raw windows.memmap --pid 1234 --dump

:: PE dump processből
vol.exe -f memdump.raw windows.dumpfiles --pid 1234

:: Hálózati kapcsolatok
vol.exe -f memdump.raw windows.netstat

:: Registry kulcsok
vol.exe -f memdump.raw windows.registry.hivelist
vol.exe -f memdump.raw windows.registry.printkey --key "SOFTWARE\Microsoft\Windows\CurrentVersion\Run"

:: Stringek kinyerése
vol.exe -f memdump.raw windows.strings --pid 1234

:: Commandline argumentumok
vol.exe -f memdump.raw windows.cmdline

:: Injected kód keresése
vol.exe -f memdump.raw windows.malfind

:: Handle-ök listája
vol.exe -f memdump.raw windows.handles --pid 1234
```

---

## PowerShell dump parancsok

```powershell
# Process dump PowerShell-ből (MiniDumpWriteDump)
$process = Get-Process -Name "notepad"
$dumpPath = "C:\dumps\notepad.dmp"

Add-Type @"
using System;
using System.Runtime.InteropServices;
public class MiniDump {
    [DllImport("dbghelp.dll")]
    public static extern bool MiniDumpWriteDump(
        IntPtr hProcess, uint ProcessId, IntPtr hFile, uint DumpType,
        IntPtr ExceptionParam, IntPtr UserStreamParam, IntPtr CallbackParam);
}
"@

$fileStream = [System.IO.File]::Create($dumpPath)
[MiniDump]::MiniDumpWriteDump(
    $process.Handle, $process.Id, $fileStream.SafeFileHandle.DangerousGetHandle(),
    2, [IntPtr]::Zero, [IntPtr]::Zero, [IntPtr]::Zero
)
$fileStream.Close()
Write-Host "Dump mentve: $dumpPath"
```

```powershell
# Futó processek listája (PID, név, path)
Get-Process | Select-Object Id, ProcessName, Path | Format-Table

# Process memória info
Get-Process -Id 1234 | Select-Object *Memory*

# DLL-ek egy processben
(Get-Process -Id 1234).Modules | Select-Object ModuleName, FileName
```

---

## Task Manager – gyors dump

```
1. Task Manager megnyitása (Ctrl+Shift+Esc)
2. Details fül
3. Processre jobb klikk → "Create dump file"
4. Automatikusan menti: C:\Users\<user>\AppData\Local\Temp\<process>.dmp
```

---

## Gyors összefoglaló táblázat

| Cél | Legjobb eszköz | Parancs / Módszer |
|-----|---------------|-------------------|
| PE header elemzés | dumpbin | `dumpbin /HEADERS file.exe` |
| Import/Export tábla | dumpbin / pefile | `dumpbin /IMPORTS file.exe` |
| Disassembly | dumpbin / x64dbg | `dumpbin /DISASM file.exe` |
| Csomagolt exe dump | Scylla | OEP → Dump → Fix Dump |
| Injected kód dump | PE-Sieve | `pe-sieve /pid 1234` |
| Process memória dump | procdump | `procdump -ma 1234` |
| Teljes RAM dump | WinPmem | `winpmem memdump.raw` |
| RAM elemzés | Volatility | `vol -f mem.raw windows.pslist` |
| .NET assembly | dnSpy / ILSpy | GUI megnyitás |
| Szekció raw dump | pefile (Python) | `section.get_data()` |

---

> **Megjegyzés:** Ezek az eszközök kizárólag legális célokra, saját rendszereken, CTF versenyeken vagy engedélyezett penetrációs tesztelésen alkalmazhatók.
