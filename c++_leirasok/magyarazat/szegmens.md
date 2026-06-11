#### Szegmens jelentése

Amikor a programod elindul, az operációs rendszer **szeletekre osztja a memóriát**. Ezeket hívják szegmenseknek. Minden szeletnek más a célja:

```
+------------------+
|      Stack       |  ← lokális változók, függvényhívások
+------------------+
|       Heap       |  ← dynamic alloc, new/malloc
+------------------+
|      BSS         |  ← inicializálatlan globális változók
+------------------+
|      Data        |  ← inicializált globális változók
+------------------+
|      Text        |  ← maga a kód, az utasítások
+------------------+
```

**Egyszerűen:**

```cpp
int global = 5;        // Data szegmens
int inicializalatlan;  // BSS szegmens

int main() {
    int x = 10;        // Stack
    int* p = new int;  // Heap
}
```

A **Text szegmens** a legérdekesebb — ott van maga a lefordított kód. ASM utasítások sorozata. Ez csak olvasható — ha véletlenül ide írsz, azonnal crash. Ez a **segmentation fault** egyik oka.

**És itt jön az ASM kapcsolat** — assembly szinten te közvetlenül látod ezeket a szegmenseket. Például:

```asm
section .data    ; Data szegmens
section .text    ; Text szegmens
section .bss     ; BSS szegmens
```

ASM-ben te magad mondod meg melyik szegmensbe kerül valami. C++-ban ezt a fordító eldönti helyetted — de most már tudod mi történik a háttérben.

