## Videó Leszedése oldalakról

Chrome lépj be az oldalra <br>

**Nyomj egy F-12 (Developer tools) majd keresd a hálózatokat**

**Indíts el a videót**

![image-20260204143305506](E:\projects\Books\kepek\image-20260204143305506.png)

**KERESD AZ .MP4 vagy M3U vagy M3U8 feliratok ha meg van **

**OPEN IN NEW TAB**

![image-20260204143536789](E:\projects\Books\kepek\image-20260204143536789.png)

Majd a következő ablakban mentés másként.

![image-20260204143633958](E:\projects\Books\kepek\image-20260204143633958.png)

Lehet külön fájlba van az Audio is erre van a Bash_Script .....

Windowson `.bat ` Linuxon .`sh`

**win** (a fájl neve akármi lehet mondjuk video.bat [LINUXON video.sh])

```
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

**Linux**

```
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

**Bekérős változat**(Ami bekéri a fájlok nevét )

**WIN**

```
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

**Linux**

```
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

**DRAG AND DROP VERZIÓ**(Csak a Scriptre húzod a fájlokat és ennyi)

**WIN**

```
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

**LINUX**

```
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

