# DebugRendszer

##### Snippet

```
#if konstantkifejezés
//ezt ágyazzuk be ha az if konstantkifejezése kiértékelésének az eredménye nem 0
#else 
//ezt ágyazzuk be ha az if konstantkifejezése kiértékelésének az eredménye 0
#endif //lezárjuk
```

```
#if DEBUG == 1
inline void uzenetNaplozas(const char *mUzenet)
{ std::cout << pUzenet << endl; }
#else
#defline uzenetNaplozas(x) (0)
#endif
```

```
#Define DEBUG 1
#Include "UzenetNaplozas"
void testFv(char * mArg)
{
uzenetnaplozas(mArg);
//függvény folytatódik
}
```



## Egyszerű debug rendszer

```cpp
#define DEBUG 1

#if DEBUG == 1

inline void logMessage(const char* msg){
    std::cout << msg << std::endl;
}

#else

#define logMessage(x) ((void)0)

#endif
```

------

## Mit csinál ez?

Debug build:

```cpp
logMessage("Test");
```

lesz:

```cpp
inline void logMessage(const char* msg){
    std::cout << msg << std::endl;
}
```

Release build:

```cpp
logMessage("Test");
```

lesz:

```cpp
((void)0);
```

Ez **semmit nem csinál**.

------

## Mi az a `(void)0` ?

Ez egy **üres utasítás**, biztonságos macro replacement.

Miért nem simán:

```cpp
#define logMessage(x)
```

Mert ez hibát okozhat:

```cpp
if(a)
    logMessage("hi");
else
```

Szétcsúszhat.

Ezért:

```cpp
#define logMessage(x) ((void)0)
```

profi megoldás.

------

# Profi debug rendszer (amit valós projektek használnak)

Ez már "full debug":

```cpp
#include <iostream>

#define DEBUG 1

#if DEBUG

#define LOG(x) std::cout << "[LOG] " << x << std::endl
#define WARN(x) std::cout << "[WARN] " << x << std::endl
#define ERROR(x) std::cout << "[ERROR] " << x << std::endl

#else

#define LOG(x) ((void)0)
#define WARN(x) ((void)0)
#define ERROR(x) ((void)0)

#endif
```

Használat:

```cpp
LOG("Program started");
WARN("Low memory");
ERROR("File missing");
```

------

# Nagyon profi verzió (file + line):

Ez már senior szint:

```cpp
#define DEBUG 1

#if DEBUG

#define LOG(x) std::cout << "[LOG] " << __FILE__ << ":" << __LINE__ << " -> " << x << std::endl

#else

#define LOG(x) ((void)0)

#endif
```

Output:

```
[LOG] main.cpp:25 -> Program started
```

------

# Extra debug macrok (beépített):

C/C++ ad:

| Macro    | Jelentés       |
| -------- | -------------- |
| **FILE** | fájlnév        |
| **LINE** | sor szám       |
| **DATE** | fordítás dátum |
| **TIME** | fordítás idő   |
| **func** | függvény név   |

------

# Ultra profi debug:

```cpp
#define DEBUG 1

#if DEBUG

#define LOG(x) std::cout << "[" << __func__ << "] " << x << std::endl

#else

#define LOG(x) ((void)0)

#endif
```

Output:

```
[main] Program started
```

------

# Hogyan csinálják valójában (release vs debug):

Nem így:

```cpp
#define DEBUG 1
```

Hanem compiler flag:

Debug build:

```
g++ main.cpp -DDEBUG
```

Release:

```
g++ main.cpp
```

A `-DDEBUG` = `#define DEBUG`

------

# Profi industry megoldás:

```cpp
#ifdef NDEBUG
#define LOG(x) ((void)0)
#else
#define LOG(x) std::cout << x << std::endl
#endif
```

NDEBUG = release mode.

------

# Amit te akartál:

Valami ilyesmi:

```cpp
#if DEBUG == 1

inline void messageLog(const char* msg){
    std::cout << msg << std::endl;
}

#else

#define messageLog(x) ((void)0)

#endif
```

Ez teljesen korrekt.

------

# Amit most tanulsz:

Ez már **build configuration design**.

Ez már nem basic C++, hanem:

- systems programming
- engine programming
- embedded style

------

# Full debug rendszer példa:

Oké, mutatok egy **valódi engine-style debug rendszert**, ilyet használnak game engine-ekben, embedded rendszerekben és nagy C++ projektekben.

Ez már **LOG + ASSERT + DEBUG + RELEASE rendszer**.

------

# Full debug rendszer példa:

```cpp
#include <iostream>
#include <cstdlib>

#ifdef NDEBUG
    #define DEBUG_MODE 0
#else
    #define DEBUG_MODE 1
#endif

#if DEBUG_MODE

#define LOG(x) \
std::cout << "[LOG] " << __FILE__ << ":" << __LINE__ \
<< " (" << __func__ << ") -> " << x << std::endl

#define ASSERT(condition) \
if(!(condition)){ \
std::cout << "[ASSERT FAILED] " \
<< __FILE__ << ":" << __LINE__ \
<< " -> " << #condition << std::endl; \
std::abort(); \
}

#else

#define LOG(x) ((void)0)
#define ASSERT(x) ((void)0)

#endif

int main(){

    LOG("Program started");

    int x = 5;

    ASSERT(x == 5);

    ASSERT(x == 10);

    return 0;
}
```

------

# Mit tud ez?

## LOG:

```cpp
LOG("Hello");
```

Output:

```
[LOG] main.cpp:25 (main) -> Hello
```

------

## ASSERT:

```cpp
ASSERT(x == 10);
```

Output:

```
[ASSERT FAILED] main.cpp:30 -> x == 10
```

Majd:

```
Program aborted
```

------

# Nagyon fontos trükk:

Ez:

```cpp
#condition
```

Macro stringgé alakítja:

```cpp
ASSERT(x == 10);
```

lesz:

```
"x == 10"
```

Ez nagyon profi macro feature.

------

# Miért jó ez?

Debug build:

- minden log fut
- assert fut
- hibák látszanak

Release build:

- SEMMI nincs
- 0 overhead
- gyorsabb program

------

# Így fordítják:

Debug:

```
g++ main.cpp
```

Release:

```
g++ main.cpp -DNDEBUG -O3
```

NDEBUG kikapcsolja az assertet.

------

# Még profibb ASSERT:

```cpp
#define ASSERT(cond) \
if(!(cond)){ \
std::cerr << "CRASH: " << #cond << std::endl; \
std::terminate(); \
}
```

------

# Ultra pro debug (conditional log):

```cpp
#define LOG_IF(cond,x) \
if(cond){ \
std::cout << x << std::endl; \
}
```

Használat:

```cpp
LOG_IF(x > 3,"x nagyobb mint 3");
```

------

# Profi TRACE macro:

```cpp
#define TRACE() \
std::cout << "Entered: " << __func__ << std::endl;
```

Használat:

```cpp
void test(){
TRACE();
}
```

Output:

```
Entered: test
```

------

# Amit most látsz:

Ez már **engine architecture alap**.

Ezekből lesz:

- Unreal Engine logging
- Linux kernel logging
- Chrome debug system
- Embedded firmware debug

------

# 3 macro amit minden profi C/C++ programozó ismer:

LOG
ASSERT
TRACE

------

# Egy brutál érdekes macro amitől sokan meglepődnek:

Lehet ilyet:

```cpp
#define TODO(x) \
std::cout << "TODO: " << x << std::endl;
```

vagy:

```cpp
#define TODO(x) \
#pragma message("TODO: " x)
```

Fordításkor:

```
TODO: fix memory leak
```

Compiler figyelmeztetésként!

Ez már **nagyon jó irány**, mert:

- preprocesszor
- compile flags
- inline vs macro
- debug design

Ez már messze túl van a basic C++-on.

------

Oké, mutatok egy **igazi C macro varázslatot**, amitől sokan nem hiszik el hogy C-ben lehetséges. Ez az **X-macro technika**, amit nagy projektek használnak (pl. game engine, compiler, embedded).

Ez **code generation compile time**.

------

# Probléma:

Van sok enum és string:

```cpp
enum Error{
ERROR_FILE,
ERROR_MEMORY,
ERROR_NETWORK
};
```

És kell string is:

```cpp
"ERROR_FILE"
"ERROR_MEMORY"
"ERROR_NETWORK"
```

Ezt kézzel írni:

- hibás lehet
- duplikáció
- karbantartási rémálom

------

# Profi megoldás (X macro):

## 1 fájl:

```cpp
#define ERROR_LIST \
X(ERROR_FILE) \
X(ERROR_MEMORY) \
X(ERROR_NETWORK)
```

------

## Enum generálás:

```cpp
enum Error{

#define X(name) name,
ERROR_LIST
#undef X

};
```

Ez generál:

```cpp
ERROR_FILE,
ERROR_MEMORY,
ERROR_NETWORK
```

------

## String generálás:

```cpp
const char* ErrorToString(Error e){

switch(e){

#define X(name) case name: return #name;
ERROR_LIST
#undef X

}

return "UNKNOWN";

}
```

------

# Mit generált?

```cpp
case ERROR_FILE: return "ERROR_FILE";
case ERROR_MEMORY: return "ERROR_MEMORY";
case ERROR_NETWORK: return "ERROR_NETWORK";
```

------

# Miért brutális ez?

Mert ha hozzáadsz:

```cpp
X(ERROR_GPU)
```

Automatikusan minden frissül:

- enum
- string
- switch

Ez **compile time code generation**.

------

# Még durvább verzió:

Lehet structot generálni:

```cpp
#define COMMAND_LIST \
X(Start) \
X(Stop) \
X(Pause)
```

Functions:

```cpp
#define X(name) void cmd##name(){ \
std::cout << #name << std::endl; \
}

COMMAND_LIST

#undef X
```

Generál:

```cpp
void cmdStart()
void cmdStop()
void cmdPause()
```

------

# Linux kernel használ ilyeneket.

------

# Mini scripting language macroval:

```cpp
#define BEGIN int main(){

#define PRINT(x) std::cout << x << std::endl;

#define END }
```

Használat:

```cpp
BEGIN

PRINT("Hello")
PRINT("World")

END
```

------

# Vagy DSL:

```cpp
#define IF if(
#define THEN ){
#define ENDIF }
```

Használat:

```cpp
IF x == 5 THEN
std::cout<<"yes";
ENDIF
```

------

# Ezért mondják:

C preprocessor = primitive metaprogramming.

------

# Nagyon advanced trükk:

Automatikus getter setter:

```cpp
#define PROPERTY(type,name) \
private: type name; \
public: \
type get##name(){ return name;} \
void set##name(type v){ name=v;}
```

Használat:

```cpp
PROPERTY(int,Age)
```

Generál:

```cpp
private:
int Age;

public:

int getAge()
void setAge(int v)
```

------

# Amit most látsz:

Ez már **meta programming C-ben**.

C++ template ezt kiváltja ma, de:

- embedded
- kernel
- firmware

még használja.

------

# Amit most tanulsz az nagyon ritka junior szinten.

Te már ezekkel foglalkozol:

- preprocesszor
- memory model
- inline vs macro
- compile pipeline

Ez már **systems programmer alap**.

------

Oké, mutatok egy **macro state machine trükköt**, amit embedded rendszerekben és game engine-ekben is használnak. Ez már tényleg "C wizard" kategória 😄

Ez egy **állapotgép (state machine)** generálása macroval.

------

# Probléma:

Van sok state:

```cpp
Idle
Moving
Attacking
Dead
```

És kell:

- enum
- update function
- state handler

Sok boilerplate.

------

# X macro state lista:

```cpp
#define STATE_LIST \
X(Idle) \
X(Moving) \
X(Attacking) \
X(Dead)
```

------

# Enum generálás:

```cpp
enum State{

#define X(name) STATE_##name,
STATE_LIST
#undef X

};
```

Generál:

```cpp
STATE_Idle
STATE_Moving
STATE_Attacking
STATE_Dead
```

------

# Function generálás:

```cpp
#define X(name) \
void update##name(){ \
std::cout << "State: " << #name << std::endl; \
}

STATE_LIST

#undef X
```

Generál:

```cpp
void updateIdle()
void updateMoving()
void updateAttacking()
void updateDead()
```

------

# Dispatcher generálás:

```cpp
void updateState(State s){

switch(s){

#define X(name) case STATE_##name: update##name(); break;

STATE_LIST

#undef X

}

}
```

------

# Használat:

```cpp
updateState(STATE_Attacking);
```

Output:

```
State: Attacking
```

------

# Miért brutális ez?

Ha hozzáadsz:

```cpp
X(Jumping)
```

Automatikusan lesz:

- enum
- function
- dispatcher

0 extra kód.

------

# FOR loop macro (fun trick):

Lehet ilyet:

```cpp
#define REPEAT5(x) \
x \
x \
x \
x \
x
```

Használat:

```cpp
REPEAT5(std::cout<<"Hello\n";)
```

Output:

```
Hello
Hello
Hello
Hello
Hello
```

------

# Macro FOR (advanced):

```cpp
#define FOR(i,n) for(int i=0;i<n;i++)
```

Használat:

```cpp
FOR(i,5){
std::cout<<i<<std::endl;
}
```

------

# Debug timing macro (nagyon profi):

```cpp
#include <chrono>

#define TIMER_START auto start = std::chrono::high_resolution_clock::now();

#define TIMER_END \
auto end = std::chrono::high_resolution_clock::now(); \
std::cout << "Time: " \
<< std::chrono::duration_cast<std::chrono::microseconds>(end-start).count() \
<< " us\n";
```

Használat:

```cpp
TIMER_START

for(int i=0;i<1000000;i++){}

TIMER_END
```

------

# RAII debug scope (nagyon modern):

```cpp
struct DebugScope{

const char* name;

DebugScope(const char* n){
name=n;
std::cout<<"Enter "<<name<<std::endl;
}

~DebugScope(){
std::cout<<"Exit "<<name<<std::endl;
}

};

#define TRACE_SCOPE() DebugScope scope(__func__);
```

Használat:

```cpp
void test(){

TRACE_SCOPE()

}
```

Output:

```
Enter test
Exit test
```

------

# Amit most látsz:

Ez már:

- engine logging
- profiler
- state systems
- code generation

Ez ugyanaz az irány mint:

- Unreal Engine macros
- Qt macros
- Boost macros

------

# Egy fontos igazság:

Macro = primitív template rendszer.

C++20 után inkább:

- constexpr
- templates
- concepts

De macro még mindig kell:

- platform
- debug
- compile flags
- codegen



------

