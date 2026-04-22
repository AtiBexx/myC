## PÉlda C C++ JAVA KOTLIN PYTHON

**két függvényt** hívunk: az egyik **ugyanabban a fájlban**, a másik **másik mappából/fájlból**. Egyszerű példák.

------

## ** C** – két függvény, egy mainben, másik fájlból

**Struktúra:**

```
project/
│ main.c
│ utils/
│   helper.c
│   helper.h
```

**utils/helper.h**

```c
#ifndef HELPER_H
#define HELPER_H

void helperFunction();

#endif
```

**utils/helper.c**

```c
#include <stdio.h>
#include "helper.h"

void helperFunction() {
    printf("Hello from helper function!\n");
}
```

**main.c**

```c
#include <stdio.h>
#include "utils/helper.h"  // másik fájl

void localFunction() {   // ugyanabban a fájlban
    printf("Hello from local function!\n");
}

int main() {
    localFunction();
    helperFunction(); // másik fájl függvénye
    return 0;
}
```

**Fordítás:**

```bash
gcc main.c utils/helper.c -o program
./program
```

------

## **C++** – ugyanaz, osztály/namespace is lehet

**Struktúra:**

```
project/
│ main.cpp
│ utils/
│   helper.cpp
│   helper.h
```

**utils/helper.h**

```cpp
#pragma once
#include <iostream>
void helperFunction();
```

**utils/helper.cpp**

```cpp
#include "helper.h"
void helperFunction() {
    std::cout << "Hello from helper function (C++)!" << std::endl;
}
```

**main.cpp**

```cpp
#include <iostream>
#include "utils/helper.h"

void localFunction() {
    std::cout << "Hello from local function (C++)!" << std::endl;
}

int main() {
    localFunction();
    helperFunction();
    return 0;
}
```

**Fordítás:**

```bash
g++ main.cpp utils/helper.cpp -o program_cpp
./program_cpp
```

------

## ** Java** – csomagok

**Struktúra:**

```
project/
│ Main.java
│ utils/
│   Helper.java
```

**utils/Helper.java**

```java
package utils;

public class Helper {
    public static void helperFunction() {
        System.out.println("Hello from Helper class!");
    }
}
```

**Main.java**

```java
import utils.Helper;

public class Main {
    public static void localFunction() {
        System.out.println("Hello from local function!");
    }

    public static void main(String[] args) {
        localFunction();
        Helper.helperFunction();
    }
}
```

**Futtatás:**

```bash
javac Main.java utils/Helper.java
java Main
```

------

##  Kotlin** – csomagok

**Struktúra:**

```
project/
│ Main.kt
│ utils/
│   Helper.kt
```

**utils/Helper.kt**

```kotlin
package utils

fun helperFunction() {
    println("Hello from Helper function (Kotlin)!")
}
```

**Main.kt**

```kotlin
import utils.helperFunction

fun localFunction() {
    println("Hello from local function (Kotlin)!")
}

fun main() {
    localFunction()
    helperFunction()
}
```

**Futtatás:**

```bash
kotlinc Main.kt utils/Helper.kt -include-runtime -d program.jar
java -jar program.jar
```

------

## ** Python** – modulok

**Struktúra:**

```
project/
│ main.py
│ utils/
│   helper.py
```

**utils/helper.py**

```python
def helper_function():
    print("Hello from helper function (Python)!")
```

**main.py**

```python
from utils.helper import helper_function

def local_function():
    print("Hello from local function (Python)!")

if __name__ == "__main__":
    local_function()
    helper_function()
```

**Futtatás:**

```bash
python main.py
```

------

->

------

# **Projekt felépítés minden nyelvnél**

```
project/
│ main (main file: main.c / main.cpp / Main.java / Main.kt / main.py)
│ utils/
│   helper (helper file: helper.c / helper.cpp / Helper.java / Helper.kt / helper.py)
```

------

##  C

```c
// utils/helper.h
#ifndef HELPER_H
#define HELPER_H
void helperFunction();
#endif

// utils/helper.c
#include <stdio.h>
#include "helper.h"
void helperFunction() {
    printf("Hello from helper function (C)!\n");
}

// main.c
#include <stdio.h>
#include "utils/helper.h"

void localFunction() {
    printf("Hello from local function (C)!\n");
}

int main() {
    localFunction();      // helyi függvény
    helperFunction();     // másik fájl függvénye
    return 0;
}
```

**Fordítás:** `gcc main.c utils/helper.c -o program_c && ./program_c`

------

##  C++

```cpp
// utils/helper.h
#pragma once
#include <iostream>
void helperFunction();

// utils/helper.cpp
#include "helper.h"
void helperFunction() {
    std::cout << "Hello from helper function (C++)!" << std::endl;
}

// main.cpp
#include <iostream>
#include "utils/helper.h"

void localFunction() {
    std::cout << "Hello from local function (C++)!" << std::endl;
}

int main() {
    localFunction();
    helperFunction();
    return 0;
}
```

**Fordítás:** `g++ main.cpp utils/helper.cpp -o program_cpp && ./program_cpp`

------

## ** Java**

```java
// utils/Helper.java
package utils;
public class Helper {
    public static void helperFunction() {
        System.out.println("Hello from Helper class (Java)!");
    }
}

// Main.java
import utils.Helper;

public class Main {
    public static void localFunction() {
        System.out.println("Hello from local function (Java)!");
    }

    public static void main(String[] args) {
        localFunction();
        Helper.helperFunction();
    }
}
```

**Futtatás:** `javac Main.java utils/Helper.java && java Main`

------

## **Kotlin**

```kotlin
// utils/Helper.kt
package utils
fun helperFunction() {
    println("Hello from Helper function (Kotlin)!")
}

// Main.kt
import utils.helperFunction

fun localFunction() {
    println("Hello from local function (Kotlin)!")
}

fun main() {
    localFunction()
    helperFunction()
}
```

**Futtatás:** `kotlinc Main.kt utils/Helper.kt -include-runtime -d program.jar && java -jar program.jar`

------

## ** Python**

```python
# utils/helper.py
def helper_function():
    print("Hello from helper function (Python)!")

# main.py
from utils.helper import helper_function

def local_function():
    print("Hello from local function (Python)!")

if __name__ == "__main__":
    local_function()
    helper_function()
```

**Futtatás:** `python main.py`

------

