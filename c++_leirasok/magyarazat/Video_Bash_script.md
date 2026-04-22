# Videó újrakódolo Videó +Audio(Egyberakása)

Ez egy **Windows .bat script**, ahol a `set`-ekkel **változókat** adsz meg, a végén pedig lefuttatod az ffmpeg parancsot.

------

## A script felépítése – mit csinál mi?

```bat
@echo off
```

Kikapcsolja, hogy minden parancs kiíródjon.
Szebb, letisztult futás.

------

```bat
set VIDEO=video.mp4
```

 Létrehoz egy **VIDEO nevű változót**

- a **literál értéke**: `video.mp4`
- később így hivatkozol rá: `%VIDEO%`

------

```bat
set AUDIO=audio.mp4
```

 Ugyanez, csak a **hang forrás**

------

```bat
set OUT=final.mp4
```

Ez az **output fájl neve**

- igen: **`OUT` a változó**
- **`final.mp4` a literál érték**

------

```bat
ffmpeg -i "%VIDEO%" -i "%AUDIO%" -c copy -shortest "%OUT%"
```

👉 Ez a „motor”:

- bemenet: `%VIDEO%` (kép)
- bemenet: `%AUDIO%` (hang)
- `-c copy` → nincs újrakódolás
- `-shortest` → a rövidebb végén áll meg
- kimenet: `%OUT%`

------

```bat
echo.
```

Üres sor (olvashatóbb)

------

```bat
echo Kész: %OUT%
```

Kiírja:

```
Kész: final.mp4
```

Itt **a %OUT% behelyettesítődik** a literál értékre.

------

```bat
pause
```

 Megáll a végén:

```
Press any key to continue...
```

Ne záródjon be az ablak.

------

## Teljes, helyes script (készre összerakva)

```bat
@echo off
echo Indítás...

set VIDEO=video.mp4
set AUDIO=audio.mp4
set OUT=final.mp4

ffmpeg -i "%VIDEO%" -i "%AUDIO%" -c copy -shortest "%OUT%"

echo.
echo Kész: %OUT%
pause
```

------

## Gyors mentális modell

- `set` = változó létrehozás
- `%OUT%` = változó **értékének behelyettesítése**
- `echo` = kiírás
- `pause` = vége / várakozás

Teljesen jól látod, **ez már script-gondolkodás** 
Ha akarod, a következő lépés:

- automatikus fájlnév-felismerés
- drag & drop-os .bat
- vagy feliratot is belerakó verzió

## Linuxon

### Windows `.bat`

```bat
set VIDEO=video.mp4
```

### Linux `.sh`

```sh
VIDEO="video.mp4"
```

**Mi történik itt?**

- `VIDEO` = változó neve
- `"video.mp4"` = érték
- Linuxban **nincs `set`**, csak `=`-t használunk
- **Ne legyen szóköz `=` előtt vagy után**

------

### Windows `.bat`

```bat
ffmpeg -i "%VIDEO%" -i "%AUDIO%" -c copy -shortest "%OUT%"
```

### Linux `.sh`

```sh
ffmpeg -i "$VIDEO" -i "$AUDIO" -c copy -shortest "$OUT"
```

**Mi történik?**

- `$VIDEO` → változó értékét helyettesíti be
- `"` használata azért fontos, hogy ha a fájlnévben van szóköz, ne akadjon meg
- Egyéb paraméterek ugyanazok (`-c copy`, `-shortest`)

------

### Windows `.bat`

```bat
echo Kész: %OUT%
pause
```

### Linux `.sh`

```sh
echo "Kész: $OUT"
read -n1 -r -p "Nyomj egy gombot a kilépéshez..."
```

**Mi történik?**

- `echo` ugyanaz, csak `$OUT`-tal
- `read -n1 -r -p` → Linuxban ez vár egy gombnyomásra (`pause` helyett)

------

### Teljes Linuxos script példa

```sh
#!/bin/bash
echo "Indítás..."

VIDEO="video.mp4"
AUDIO="audio.mp4"
OUT="final.mp4"

ffmpeg -i "$VIDEO" -i "$AUDIO" -c copy -shortest "$OUT"

echo
echo "Kész: $OUT"
read -n1 -r -p "Nyomj egy gombot a kilépéshez..."
```

**Megjegyzések:**

- `#!/bin/bash` → a script elején, megmondja a rendszernek, hogy Bash futtassa
- `.sh` fájl → futtatás: `chmod +x script.sh` majd `./script.sh`
- Ha Linuxon szeretnéd, hogy **drag & drop működjön**, kicsit bonyolultabb, de simán lehet

------

## Bekérős Script

- Kéri a **videó fájl helyét + nevét**
- Kéri az **audio fájl helyét + nevét**
- Összeilleszti `ffmpeg`-pel
- Kiírja, kész, majd **vár egy gombnyomásra**

------

## **Windows `.bat` verzió**

```bat
@echo off
echo Indítás...

:: Videó fájl megadása
set /p VIDEO=Add meg a video fájl teljes elérési útját és nevét: 

:: Audio fájl megadása
set /p AUDIO=Add meg az audio fájl teljes elérési útját és nevét: 

:: Kimeneti fájl
set /p OUT=Add meg a kimeneti fájl nevét (pl. final.mp4): 

:: FFMPEG futtatása
ffmpeg -i "%VIDEO%" -i "%AUDIO%" -c copy -shortest "%OUT%"

echo.
echo Kész: %OUT%
pause
```

**Használat:**

1. Mentés pl. `merge.bat` néven
2. Dupla kattintás → megkérdezi a videó, audio és a kimeneti fájl nevét
3. Összekapcsolja, majd vár a gombnyomásra

------

## **Linux `.sh` verzió**

```sh
#!/bin/bash
echo "Indítás..."

# Videó fájl
read -p "Add meg a video fájl teljes elérési útját és nevét: " VIDEO

# Audio fájl
read -p "Add meg az audio fájl teljes elérési útját és nevét: " AUDIO

# Kimeneti fájl
read -p "Add meg a kimeneti fájl nevét (pl. final.mp4): " OUT

# FFMPEG futtatása
ffmpeg -i "$VIDEO" -i "$AUDIO" -c copy -shortest "$OUT"

echo
echo "Kész: $OUT"
read -n1 -r -p "Nyomj egy gombot a kilépéshez..."
echo
```

**Használat:**

1. Mentés pl. `merge.sh`
2. Futás előtt: `chmod +x merge.sh`
3. `./merge.sh` → megkérdezi a fájlokat, összekapcsolja, majd vár

------

## Drag and Drop Verzió

## **Windows `.bat` drag & drop verzió**

```bat
@echo off
echo Indítás...

:: Ellenőrizzük, hogy kaptunk-e fájlokat
if "%~1"=="" (
    echo Húzz ra egy videó fájlt a scriptre!
    pause
    exit /b
)
if "%~2"=="" (
    echo Húzz ra egy audio fájlt is a scriptre!
    pause
    exit /b
)

:: Paraméterek: %1 = videó, %2 = audio
set "VIDEO=%~1"
set "AUDIO=%~2"

:: Kimeneti fájl
set "OUT=final.mp4"

:: FFMPEG futtatása
ffmpeg -i "%VIDEO%" -i "%AUDIO%" -c copy -shortest "%OUT%"

echo.
echo Kész: %OUT%
pause
```

**Használat:**

1. Mentés pl. `merge_drag.bat` néven
2. Ráhúzol egy **videó fájlt**, majd **egy audio fájlt** a scriptre
3. Kész a `final.mp4`

------

## **Linux `.sh` drag & drop verzió**

```sh
#!/bin/bash
echo "Indítás..."

# Ellenőrzés
if [ -z "$1" ] || [ -z "$2" ]; then
    echo "Használat: húzd rá a videót és az audio-t a scriptre."
    exit 1
fi

VIDEO="$1"
AUDIO="$2"
OUT="final.mp4"

ffmpeg -i "$VIDEO" -i "$AUDIO" -c copy -shortest "$OUT"

echo
echo "Kész: $OUT"
read -n1 -r -p "Nyomj egy gombot a kilépéshez..."
echo
```

**Használat:**

1. Mentés `merge_drag.sh` néven
2. Futás előtt: `chmod +x merge_drag.sh`
3. Ráhúzol egy **videót és egy audio-t** → kész a `final.mp4`

------

