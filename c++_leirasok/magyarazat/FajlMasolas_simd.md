#### FájlMásolás

----

```cpp
// FájlMásolás
//Biztonsági másolatot készít egy fájlról
//
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <limits>
#include <string>
#include <iostream>
int main(int argc, char** argv)
{
//minden átadot fájlnál megismételjük a folyamatot
    for (int n = 1; n < argc; n++)
    {
        // létrehozunk egy fájlnevet és egy biztonsági nevet
        std::string szForras(argv[n]);
        std::string szCel = szForras + ".bMasolat";
        //most megnyitjuk a fájlt olvasásra a célt pedig írásra
        std::ifstream bemenet(szForras.c_str(),
                              std::ios_base::in|std::ios_base::binary);
        std::ofstream kimenet(szCel.c_str(),
                              std::ios_base::out|std::ios_base::binary|std::ios_base::trunc);
        if(bemenet.good() && kimenet.good())
        {
            std::cout << szForras <<"Biztonsági Mentése..." <<"...";
            //addig olvassuk be a 4 kb blokokat amíg el nem érjük a fájl végét EOF
            while(!bemenet.eof() && bemenet.good())
            {
                char puffer[4096];
                bemenet.read(puffer, 4096);
                kimenet.write(puffer,bemenet.gcount());
            }
            std::cout <<"kész"<<std::endl;

        }
        else
        {
            std::cerr <<szForras<< " "<<"másolása nem sikerült...." <<std::endl;
        }
    }
    //kilépünk
    std::cout <<"A Folytatáshoz nyomd meg az ENTER kétszer...." <<std::flush<<'\n';
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
    std::cin.get();


    return 0;
}

```

**OUTPUT**

//ARGUMENTUMMAL KELL HASZNÁLNI

```cpp

E:\projects\cpp\FajlMasolas\bin\Debug>FajlMasolas.exe t.txt
t.txtBiztonsági Mentése......kész
A Folytatáshoz nyomd meg az ENTER kétszer....



E:\projects\cpp\FajlMasolas\bin\Debug>
E:\projects\cpp\FajlMasolas\bin\Debug>
```

Persze Ati, menjünk végig rajta szépen sorban. Ez egy klasszikus fájlmásoló program, és szinte minden sorában van valami érdekes C++ fogalom.

## 1. Mi az?

```cpp
std::ios_base::out | std::ios_base::binary | std::ios_base::trunc
```

Ezek fájlmegnyitási módok.

### out

```cpp
std::ios_base::out
```

Írásra nyitja meg a fájlt.

### binary

```cpp
std::ios_base::binary
```

Bináris módban nyitja meg.

Például egy JPG vagy MP3 másolásánál fontos.

Szöveges módban egyes rendszerek módosíthatják a sortöréseket.

### trunc

```cpp
std::ios_base::trunc
```

Ha a fájl már létezik, törli a tartalmát.

Például:

```text
teszt.txt.bMasolat
```

létezik és 100 MB.

A megnyitás után:

```text
0 byte
```

lesz.

------

## 2. Mi az a good()?

```cpp
bemenet.good()
```

Azt kérdezi:

> minden rendben van a fájllal?

Ha igen:

```cpp
true
```

Ha valami hiba történt:

```cpp
false
```

Például:

```cpp
ifstream f("nemletezik.txt");
```

akkor:

```cpp
f.good()
```

hamis lesz.

------

## 3. Mi az eof()?

```cpp
bemenet.eof()
```

EOF = End Of File

Azt jelenti:

> elértem a fájl végét?

Példa:

```text
alma
körte
szilva
```

Miután az utolsó karaktert is beolvastad:

```cpp
eof() == true
```

------

## 4. Mi ez?

```cpp
char puffer[4096];
```

Létrehoz egy memóriaterületet.

```text
4096 byte
```

méretben.

A puffer ideiglenes tároló.

Például:

```text
Fájl
 ↓
Puffer
 ↓
Új fájl
```

------

## 5. Miért pont 4096?

Ez csak egy választott méret.

Lehetne:

```cpp
char puffer[100];
```

vagy

```cpp
char puffer[8192];
```

is.

4096 byte = 4 KB

Ez hagyományosan jó kompromisszum.

------

## 6. Mi az a read()?

```cpp
bemenet.read(puffer, 4096);
```

A jelentése:

> olvass be legfeljebb 4096 byte-ot a fájlból a pufferbe

Példa:

```text
Fájl:
ABCDEFGHIJ
```

ha:

```cpp
read(puffer, 5);
```

akkor a puffer:

```text
ABCDE
```

lesz.

------

## 7. Mi az a write()?

```cpp
kimenet.write(puffer, bemenet.gcount());
```

A jelentése:

> írd ki a puffer tartalmát a fájlba

Tehát:

```text
Puffer
 ↓
Kimeneti fájl
```

------

## 8. Mi az a gcount()?

Ez nagyon fontos.

```cpp
bemenet.gcount()
```

megmondja:

> az előző read() hány byte-ot olvasott be valójában

Példa:

Van egy fájl:

```text
5000 byte
```

Első olvasás:

```cpp
read(puffer,4096);
```

beolvas:

```text
4096 byte
```

gcount():

```cpp
4096
```

Második olvasás:

már csak:

```text
904 byte
```

maradt.

Ezért:

```cpp
gcount()
```

értéke:

```cpp
904
```

lesz.

Ezért kell:

```cpp
write(puffer,bemenet.gcount());
```

különben a végén szemetet is kiírhatnánk.

------

## 9. Mi az a c_str()?

Példa:

```cpp
std::string nev = "teszt.txt";
```

A string egy C++ objektum.

Régebbi függvények viszont C stílusú karaktertömböt várnak.

A

```cpp
nev.c_str()
```

visszaadja:

```cpp
const char*
```

alakban.

Példa:

```cpp
std::string nev = "alma";
```

A

```cpp
nev.c_str()
```

nagyjából ezt adja:

```cpp
'a'
'l'
'm'
'a'
'\0'
```

A végén a:

```cpp
'\0'
```

jelzi a szöveg végét.

------

Összefoglalva a másolás folyamata:

```text
Forrás fájl
      ↓
read()
      ↓
char puffer[4096]
      ↓
gcount() megmondja mennyi adat érkezett
      ↓
write()
      ↓
Cél fájl
```

Ez az egyik legklasszikusabb fájlmásoló algoritmus C++-ban, mert ugyanúgy működik egy 10 bájtos TXT fájllal, mint egy 4 GB-os videóval.

Általában **igen, de csak egy bizonyos pontig**.

Ha nagyon kicsi a puffer:

```cpp
char puffer[1];
```

akkor a program 1 bájtonként olvas és ír. Ez nagyon lassú, mert rengeteg `read()` és `write()` hívás történik.

Például egy 100 MB-os fájlnál:

- 1 bájtos puffer → ~100 millió olvasás
- 4096 bájtos puffer → ~25 ezer olvasás

Ezért a nagyobb puffer általában gyorsabb.

Viszont egy idő után már nincs nagy nyereség:

```cpp
char puffer[4096];      // 4 KB
char puffer[65536];     // 64 KB
char puffer[1048576];   // 1 MB
```

A 64 KB gyakran valamivel gyorsabb lehet, mint a 4 KB, de a 100 MB-os puffer általában nem lesz 100-szor gyorsabb. Sőt, túl nagy puffer esetén:

- több memóriát foglal
- rosszabb lehet a cache-használat
- a gyorsulás szinte eltűnik

Ezért a gyakorlatban gyakran használnak:

- 4 KB
- 8 KB
- 16 KB
- 64 KB

méretű puffereket.

Érdekesség: a modern `ifstream` és `ofstream` osztályok **maguk is használnak belső puffert**, tehát a te 4096 bájtos puffered mellett a fájlfolyamnak is van saját pufferelése.

A 4096 bájt nem véletlen szám: sok operációs rendszerben a memóriaoldal (memory page) mérete 4 KB, ezért ez hagyományosan egy jó választás.

Jó kérdés, itt jön a lényeg: **nem az számít, mennyit tudsz egyszerre beolvasni, hanem mennyire hatékonyan működik a teljes rendszer (RAM + cache + OS + fájlrendszer)**.

## Miért nem lesz sokkal gyorsabb 100 MB pufferrel?

### 1. A gyorsulást nem az `read()` hívások száma korlátozza csak

Igen, kevesebb `read()` hívás lenne, de a szűk keresztmetszet általában:

- a **lemez (SSD/HDD) sebessége**
- az **operációs rendszer fájlkezelése**
- a **kernel bufferelése**

Ezek már amúgy is nagy blokkokban dolgoznak.

------

### 2. Az OS már eleve pufferez (nagyon fontos!)

Amikor ezt hívod:

```cpp
bemenet.read(...)
```

akkor nem a program “nyers” lemezről olvas.

A valóság:

```text
SSD → OS cache (pl. 1-16 MB blokkok) → te puffered
```

Tehát a rendszer már optimalizálja a nagy olvasásokat.

 Ezért a te 100 MB puffered sokszor csak “ráül” egy már létező OS cache-re.

------

### 3. RAM vs cache probléma

Egy 100 MB puffer:

- elfoglal sok RAM-ot
- gyakran kilöki a CPU cache-t (L1/L2/L3)

Ez rossz hatás:

```text
CPU gyors cache → kiesik
RAM → lassabb elérés
```

 Ezért paradox módon lassulhat is.

------

### 4. Nem tudja a lemez sem “varázssebességgel” adni

Egy SSD mondjuk:

- 500 MB/s – 3000 MB/s

de:

- van latency (késleltetés)
- van vezérlő overhead

Hiába kérsz 100 MB-ot egyszerre:

- nem fog 10× gyorsabban reagálni
- csak nagyobb “csomagot” kapsz ugyanannyi idő alatt

------

### 5. diminishing returns (csökkenő hozadék)

Ez a kulcs:

| Puffer | Hatás          |
| ------ | -------------- |
| 1 KB   | nagyon lassú   |
| 4 KB   | jó             |
| 64 KB  | kicsit jobb    |
| 1 MB   | alig jobb      |
| 100 MB | szinte ugyanaz |

------

## Egyszerű analógia

Képzeld el:

- 4 KB puffer = vödör
- 1 MB puffer = nagy kanna
- 100 MB puffer = víztartály

A csap (SSD) sebessége ugyanaz.

 Hiába viszel nagyobb tartályt, a csap nem fog gyorsabban folyni.

------

## Valós válasz

 Igen, egy bizonyos méretig gyorsul
 100 MB-nál már nem
 sőt akár lassabb is lehet

------

## Profi gyakorlat

A legtöbb fájlmásoló (pl. Windows, Linux cp):

- 64 KB – 1 MB közötti bufferrel dolgozik
- és az OS cache-re bízza a többit

------

### SIMD esetleg?

>  SIMD nem attól gyorsít, hogy “nagyobb buffert használsz”, hanem attól, hogy **egy CPU utasítás egyszerre több byte-ot dolgoz fel**.

------

#  1. Mi a SIMD itt?

SIMD = *Single Instruction Multiple Data*

CPU utasítások:

- 1 művelet → 16 / 32 / 64 byte egyszerre

Pl. SSE / AVX / AVX2:

- AVX2 = 256 bit = **32 byte egyszerre**
- AVX-512 = **64 byte egyszerre**

------

#  2. Fontos meglepetés

 Fájlmásolásnál:

- a bottleneck = SSD / RAM / OS
- nem a CPU

Ezért:

> SIMD csak akkor segít, ha a CPU lett volna a szűk keresztmetszet (ritka)

De: nagy buffer + SIMD = optimális kombináció

------

#  3. Egyszerű SIMD memcpy-szerű másoló (AVX2)

Ez egy **memcpy jellegű gyors másoló**:

```cpp
#include <immintrin.h>
#include <fstream>
#include <iostream>

void simd_copy(const char* src, char* dst, size_t size)
{
    size_t i = 0;

    for (; i + 32 <= size; i += 32)
    {
        __m256i data = _mm256_loadu_si256((__m256i*)(src + i));
        _mm256_storeu_si256((__m256i*)(dst + i), data);
    }

    // maradék byte-ok
    for (; i < size; i++)
    {
        dst[i] = src[i];
    }
}
```

------

#  4. Fájlmásolás SIMD + nagy bufferrel

```cpp
#include <fstream>
#include <iostream>
#include <vector>
#include <immintrin.h>

int main()
{
    std::ifstream in("input.bin", std::ios::binary);
    std::ofstream out("output.bin", std::ios::binary);

    const size_t SIZE = 1024 * 1024; // 1 MB buffer
    std::vector<char> buffer(SIZE);

    while (in)
    {
        in.read(buffer.data(), buffer.size());
        std::streamsize bytes = in.gcount();

        char* src = buffer.data();
        char* dst = buffer.data(); // ugyanaz a buffer itt, egyszerű példa

        size_t i = 0;

        // SIMD rész (AVX2 = 32 byte)
        for (; i + 32 <= (size_t)bytes; i += 32)
        {
            __m256i v = _mm256_loadu_si256((__m256i*)(src + i));
            _mm256_storeu_si256((__m256i*)(dst + i));
        }

        // maradék
        for (; i < (size_t)bytes; i++)
            dst[i] = src[i];

        out.write(buffer.data(), bytes);
    }

    std::cout << "kész\n";
}
```

------

#  5. De most jön a REALITÁS (nagyon fontos)

SIMD itt:

###  nem lesz 10× gyorsabb

###  sokszor semmi különbség

###  néha lassabb is

------

#  6. Mi a valódi gyorsítás fájlmásolásnál?

Rangsor:

##  1. OS cache + async IO

##  2. nagy buffer (64KB – 1MB)

##  3. thread / overlapped IO

##  SIMD (nagyon kis hatás)

------

#  7. Mikor hasznos SIMD?

SIMD akkor üt:

- audio processing (VST, FFT)
- video decoding
- image processing
- crypto
- compression

 nem sima file copy

------

#  Összefoglalás

- SIMD = több byte egyszerre CPU-n
- fájlmásolás = I/O bound (nem CPU bound)
- ezért:
  - nagy buffer = fontos
  - SIMD = minimális extra

------

Ez nagyon jó kérdés, Ati — mert itt látszik igazán, hogy **hova “illene” a SIMD**, és miért mondtam korábban, hogy fájlmásolásnál szinte nem nyersz vele.

##  Rövid válasz

 **a SIMD-et a `read()` és `write()` KÖZÉ tennéd, a puffer feldolgozásába**

De…

> ❗ itt a te kódodban nincs semmilyen feldolgozás → ezért a SIMD-nek nincs mit gyorsítani

------

#  Hol lenne a SIMD helye?

Ez a részed:

```cpp
bemenet.read(puffer, 4096);
kimenet.write(puffer, bemenet.gcount());
```

##  Ide “logikailag” ez történne:

```text
disk → read → buffer → SIMD feldolgozás → write → disk
```

------

#  De most jön a lényeg

## SIMD csak akkor kell, ha ezt csinálod:

- adatot módosítasz
- számolsz rajta
- transzformálsz

Pl:

- titkosítás
- tömörítés
- hangfeldolgozás
- képfeldolgozás

------

#  A te kódod mit csinál?

 csak másol:

```text
A byte → A byte
B byte → B byte
```

Ez **memcpy feladat**

------

#  Hol lenne mégis SIMD a te kódodban?

Ha erőltetjük, akkor itt:

```cpp
char puffer[4096];
bemenet.read(puffer, 4096);
```

 UTÁNA

```cpp
// SIMD copy (puffer → másik buffer)
```

de…

##  ez teljesen felesleges

mert:

 `ofstream.write()` már optimalizált
 `memcpy()` már SIMD-es
 OS is bufferel

------

#  Ha mégis “helyesen” SIMD-et akarsz

Akkor ki kell venni a `write(puffer)` részt és így nézne ki:

## SIMD memcpy jelleg:

```cpp
#include <immintrin.h>

void simd_copy(char* dst, const char* src, size_t size)
{
    size_t i = 0;

    for (; i + 32 <= size; i += 32)
    {
        __m256i v = _mm256_loadu_si256((__m256i*)(src + i));
        _mm256_storeu_si256((__m256i*)(dst + i));
    }

    for (; i < size; i++)
        dst[i] = src[i];
}
```

de ezt csak akkor használod, ha:

 saját memóriát kezelsz
 nem fájlstreamet

------

#  A fontos felismerés

A te programod:

```text
FILE COPY PROGRAM
```

SIMD-et akkor használnál, ha ez lenne:

```text
FILE → DEKÓDOLÁS / TRANSZFORMÁCIÓ → FILE
```

------

#  Összefoglalás

## Hova tennéd SIMD-et?

👉 ide:

```
read() után
write() előtt
```

## De miért nem érdemes?

- nincs számítás
- csak másolás
- `std::ifstream/ofstream` + OS már SIMD-szintű optimalizált

------

#  Egy mondatban

> SIMD-et nem a fájlmásolás gyorsítására tesszük, hanem az adat feldolgozására — nálad pedig nincs feldolgozás, csak átvitel.

------

```cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <immintrin.h>
#include <cstring>

// AVX2 gyors memmásolás (32 byte egyszerre)
static void simd_copy(void* dst, const void* src, size_t size)
{
    size_t i = 0;

    char* d = (char*)dst;
    const char* s = (const char*)src;

    // 32 byte-os SIMD blokkok
    for (; i + 32 <= size; i += 32)
    {
        __m256i data = _mm256_loadu_si256((__m256i*)(s + i));
        _mm256_storeu_si256((__m256i*)(d + i), data);
    }

    // maradék byte-ok
    for (; i < size; i++)
    {
        d[i] = s[i];
    }
}

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cout << "Hasznalat: program file1 file2 ...\n";
        return 0;
    }

    const size_t BUFFER_SIZE = 1024 * 1024; // 1 MB buffer

    std::vector<char> buffer(BUFFER_SIZE);

    for (int n = 1; n < argc; n++)
    {
        std::string srcName = argv[n];
        std::string dstName = srcName + ".bMasolat";

        std::ifstream in(srcName, std::ios::binary);
        std::ofstream out(dstName, std::ios::binary | std::ios::trunc);

        if (!in || !out)
        {
            std::cerr << "Hiba: " << srcName << "\n";
            continue;
        }

        std::cout << srcName << " masolasa...\n";

        while (in)
        {
            in.read(buffer.data(), buffer.size());
            std::streamsize bytes = in.gcount();

            if (bytes <= 0)
                break;

            // SIMD copy (itt történik a "gyorsítás")
            simd_copy(buffer.data(), buffer.data(), (size_t)bytes);

            out.write(buffer.data(), bytes);
        }

        std::cout << "kesz: " << dstName << "\n";
    }

    std::cout << "ENTER...\n";
    std::cin.get();

    return 0;
}
```

---------

 Fontos: stream + SIMD együtt csak “demó jellegű”, mert itt nem lesz nagy gyorsulás, de technikailag így néz ki helyesen.

------

#  A TE KÓDOD + SIMD BEÉPÍTVE

```cpp
// FájlMásolás
//Biztonsági másolatot készít egy fájlról
//
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <limits>
#include <string>
#include <iostream>
#include <immintrin.h>   // SIMD

int main(int argc, char** argv)
{
//minden átadot fájlnál megismételjük a folyamatot
    for (int n = 1; n < argc; n++)
    {
        // létrehozunk egy fájlnevet és egy biztonsági nevet
        std::string szForras(argv[n]);
        std::string szCel = szForras + ".bMasolat";

        //most megnyitjuk a fájlt olvasásra a célt pedig írásra
        std::ifstream bemenet(szForras.c_str(),
                              std::ios_base::in|std::ios_base::binary);

        std::ofstream kimenet(szCel.c_str(),
                              std::ios_base::out|std::ios_base::binary|std::ios_base::trunc);

        if(bemenet.good() && kimenet.good())
        {
            std::cout << szForras << " Biztonsági Mentése..." << "...";

            while(!bemenet.eof() && bemenet.good())
            {
                char puffer[4096];
                bemenet.read(puffer, 4096);

                std::streamsize bytes = bemenet.gcount();

                // ============================
                // SIMD MÁSOLÁS (AVX2 32 byte)
                // ============================
                size_t i = 0;

                for (; i + 32 <= (size_t)bytes; i += 32)
                {
                    __m256i v = _mm256_loadu_si256((__m256i*)(puffer + i));
                    _mm256_storeu_si256((__m256i*)(puffer + i), v);
                }

                for (; i < (size_t)bytes; i++)
                {
                    puffer[i] = puffer[i];
                }
                // ============================

                kimenet.write(puffer, bytes);
            }

            std::cout <<" kész"<<std::endl;
        }
        else
        {
            std::cerr <<szForras<< " másolása nem sikerült...." <<std::endl;
        }
    }

    //kilépünk
    std::cout <<"A Folytatáshoz nyomd meg az ENTER kétszer...." <<std::flush<<'\n';
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
    std::cin.get();

    return 0;
}
```

------

#  ŐSZINTE MEGJEGYZÉS (nagyon fontos)

Ez a rész:

```cpp
puffer[i] = puffer[i];
```

 valójában SEMMIT nem csinál.

Ez azért van így, mert:

- nincs adatfeldolgozás
- csak másolás történik

------

#  MIT KELLENE VALÓJÁBAN SIMD-EL CSINÁLNI?

SIMD akkor lenne “igazi”, ha pl.:

- titkosítás (XOR, AES)
- hang erősítés
- kép feldolgozás
- tömörítés

------

#  VALÓS TUNING SORREND

Ha ezt a programot gyorsítani akarod:

1.  1 MB buffer
2.  `read()` / `write()` optimalizálás
3.  OS cache
4.  SIMD (itt gyakorlatilag semmi)

------

#  Ha akarod a következő szintet

Meg tudom mutatni:

 “valódi SIMD program” (WAV audio amplifier, hallható különbséggel)
 “memcpy reimplementáció AVX2 vs std::memcpy benchmark”
 “Windows copy engine hogyan működik belül”

Ez már tényleg profi rendszerszint 