------

#  C++ STREAM + FILE CHEATSHEET

------

#  1. Formázási jelölők (cout / cin)

##  boolalpha

```cpp
std::cout << std::boolalpha << true;
```

 true/false szövegként (nem 1/0)

------

##  dec

```cpp
std::cout << std::dec << 255;
```

 decimális (10-es számrendszer)

------

##  hex

```cpp
std::cout << std::hex << 255;
```

 hex: ff

------

##  oct

```cpp
std::cout << std::oct << 255;
```

 oktális

------

##  fixed

```cpp
std::cout << std::fixed << 3.14;
```

 fix tizedes formátum

------

##  scientific

```cpp
std::cout << std::scientific << 12345.6;
```

 1.234e+04

------

##  left / right

```cpp
std::cout << std::left;
std::cout << std::right;
```

 igazítás

------

##  showbase

```cpp
std::cout << std::showbase << std::hex << 255;
```

 0xff

------

##  showpoint

```cpp
std::cout << std::showpoint << 10.0;
```

 10.0000

------

##  skipws

```cpp
std::cin >> std::skipws;
```

 szóközök kihagyása

------

##  unitbuf

```cpp
std::cout << std::unitbuf;
```

 minden kiírás azonnal flush

------

##  uppercase

```cpp
std::cout << std::uppercase << std::hex << 255;
```

 FF

------

#  2. Fájl megnyitási módok

##  app (append)

```cpp
std::ofstream f("a.txt", std::ios::app);
```

 hozzáfűz

------

##  trunc

```cpp
std::ofstream f("a.txt", std::ios::trunc);
```

 törli a fájlt

------

##  in

```cpp
std::ifstream f("a.txt", std::ios::in);
```

 olvasás

------

##  out

```cpp
std::ofstream f("a.txt", std::ios::out);
```

 írás

------

##  binary

```cpp
std::ifstream f("a.bin", std::ios::binary);
```

 bináris mód

------

#  3. formázás (fill / width / flags)

##  fill

```cpp
std::cout.fill('*');
```

 kitöltő karakter

------

##  width

```cpp
std::cout.width(10);
std::cout << 42;
```

 minimum szélesség

------

##  flags mentés

```cpp
std::ios_base::fmtflags f = std::cout.flags();
```

 formátum elmentése

------

#  4. fontos stream metódusok

##  open

```cpp
file.open("a.txt");
```

------

##  close

```cpp
file.close();
```

------

##  good / fail / bad / eof

```cpp
if(file.good())
if(file.fail())
if(file.bad())
if(file.eof())
```

------

##  gcount

```cpp
file.read(buf, 100);
std::cout << file.gcount();
```

 hány byte-ot olvasott

------

##  get

```cpp
char c = std::cin.get();
```

------

##  getline

```cpp
char buf[100];
std::cin.getline(buf, 100);
```

------

##  seekg / seekp

### eleje

```cpp
file.seekg(10, std::ios::beg);
```

### aktuális

```cpp
file.seekg(10, std::ios::cur);
```

### vége

```cpp
file.seekg(-5, std::ios::end);
```

------

##  tellg / tellp

```cpp
file.tellg();
file.tellp();
```

aktuális pozíció

------

##  write / read

```cpp
file.write(data, size);
file.read(buffer, size);
```

------

#  5. endl

```cpp
std::cout << std::endl;
```

 új sor + flush (kiüríti a buffert)

------

#  EXTRA FONTOS LÉNYEG

 `cout` = képernyő
 `fstream` = ugyanaz, csak fájl

```cpp
std::cout << "hello";
file << "hello";
```

------

