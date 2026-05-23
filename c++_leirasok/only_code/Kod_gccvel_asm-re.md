```
g++ -S main.cpp
```

ha több fájl van 

Ha több fájlod van, akkor a `g++ -S main.cpp` csak **egy fájlt fordít assemblyvé**, tehát nem elég egy nagy projekthez.

------

# 1. Több fájl esetén (egyszerű g++)

## Minden fájlt külön kell fordítani:

```bash
g++ -S main.cpp
g++ -S linkedList.cpp
g++ -S utils.cpp
```

 eredmény:

```text
main.s
linkedList.s
utils.s
```

------

# 2. Fontos: ez még NEM linkel

Ez csak assembly generálás.

------

# 3. Ha teljes build + assembly kell

Akkor:

```bash
g++ -S -O0 *.cpp
```

vagy Windows-on:

```bash
g++ -S -O0 main.cpp linkedList.cpp utils.cpp
```

------

# 4. CMake esetén (PROFI MÓD)

## A legegyszerűbb:

```bash
cmake -DCMAKE_CXX_FLAGS="-S -O0" ..
make
```

DE ez nem mindig ad tiszta `.s` fájlokat.

------

## JOBB CMake megoldás (target szinten)

CMakeLists.txt:

```cmake
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -S -O0 -masm=intel")
```

------

## PROFIBB: külön assembly build target

```cmake
add_custom_target(asm ALL
    COMMAND ${CMAKE_CXX_COMPILER} -S -O0 ${CMAKE_SOURCE_DIR}/main.cpp
)
```

------

# 5. Legjobb módszer (amit fejlesztők is használnak)

 nem CMake hack

hanem:

```bash
cmake --build . --verbose
```

és a compile parancsot kimásolod, majd:

```bash
g++ -S <ugyanaz a compile parancs>
```

------

# 6. Ha igazán tiszta ASM kell

Mindig használd:

```bash
g++ -S -O0 -fno-omit-frame-pointer main.cpp
```

------

# 7. Röviden

| eset           | megoldás                |
| -------------- | ----------------------- |
| 1 fájl         | `g++ -S main.cpp`       |
| több fájl      | mindegyiket külön `-S`  |
| CMake          | flag vagy custom target |
| tiszta tanulás | `-O0 -S`                |

------

# + fontos gondolat

A linked list pointeres kódodnál:

 az assembly csak akkor lesz érthető, ha `-O0`-t használsz

mert optimalizálásnál:

- eltűnnek változók
- átnevezések lesznek
- pointerek “összeolvadnak”

------

Ha akarod, következő lépésben megmutatom:

hogyan néz ki a te `kovetkezoTag = listaFej` sorod assemblyben (ez nagyon jó pointer-tanító példa).