# Bitwise Operátorok

A bitwise (bitenkénti) operátorok **bináris számok** szintjén működnek, azaz **bitek** (0 és 1) szintjén végzik el a műveleteket. Ezeket gyakran használják alacsony szintű programozásban, optimalizálásban, vagy logikai műveletek során.

---

## 1. Bitwise AND (`&`)

A `&` operátor két bitre alkalmazva a következőképpen működik:

- `1 & 1 = 1`
- `1 & 0 = 0`
- `0 & 1 = 0`
- `0 & 0 = 0`

### Példa:
```python
5 & 3  # Binárisan: 101 & 011 = 001 → 1
```

### Használata:
- Bitek kinyerésére (maszkolás).
- Állapotok ellenőrzésére.

---

## 2. Bitwise OR (`|`)

A `|` operátor két bitre alkalmazva a következőképpen működik:

- `1 | 1 = 1`
- `1 | 0 = 1`
- `0 | 1 = 1`
- `0 | 0 = 0`

### Példa:
```python
5 | 3  # Binárisan: 101 | 011 = 111 → 7
```

### Használata:
- Bitek beállítására.
- Állapotok bekapcsolására.

---

## 3. Bitwise XOR (`^`)

A `^` (kizáró vagy) operátor két bitre alkalmazva a következőképpen működik:

- `1 ^ 1 = 0`
- `1 ^ 0 = 1`
- `0 ^ 1 = 1`
- `0 ^ 0 = 0`

### Példa:
```python
5 ^ 3  # Binárisan: 101 ^ 011 = 110 → 6
```

### Használata:
- Kizáró vagy logikára.
- Titkosításra (pl. egyszerű XOR titkosítás).
- Állapotváltásra (pl. kapcsolók).

---

## 4. Bitwise NOT (`~`)

A `~` operátor egy operandusú, invertálja az összes bitet.

A Pythonban `~x` = `-(x + 1)` (két komplemens miatt).

### Példa:
```python
~5  # Binárisan: -(5 + 1) = -6
```

---

## 5. Logikai operátorok vs Bitwise operátorok

| Operátor | Jelentés | Mire használható? |
|----------|----------|-------------------|
| `and`    | Logikai AND | Igaz/hamis értékekhez |
| `or`     | Logikai OR  | Igaz/hamis értékekhez |
| `not`    | Logikai NOT | Igaz/hamis értékekhez |
| `&`      | Bitwise AND | Bitekhez |
| `\|`     | Bitwise OR  | Bitekhez |
| `^`      | Bitwise XOR | Bitekhez |
| `~`      | Bitwise NOT | Bitekhez |

---

## 6. XOR használata titkosításban

Az XOR titkosítás egy egyszerű, de hatékony módszer, amely két értéket XOR-zol, majd ugyanazzal az értékkel újra XOR-zol, és visszakapod az eredetit.

### Példa:
```python
original = ord('A')  # 65
key = 42
encrypted = original ^ key  # 65 ^ 42 = 107
decrypted = encrypted ^ key  # 107 ^ 42 = 65 ('A')
```

---

## 7. Bit Shift (`<<`, `>>`)

- `<<`: Balra shift (szorzás 2-vel).
- `>>`: Jobbra shift (osztás 2-vel).

### Példa:
```python
5 << 1  # Binárisan: 101 << 1 = 1010 → 10
5 >> 1  # Binárisan: 101 >> 1 = 10 → 2
```

---

## 8. Bitwise NOR

A **NOR** (Not OR) logikai művelet az "OR" tagadása, azaz:

- `A NOR B = NOT (A OR B)`
- `1 NOR 1 = 0`
- `1 NOR 0 = 0`
- `0 NOR 1 = 0`
- `0 NOR 0 = 1`

A Pythonban **nincs beépített NOR operátor**, de megvalósítható így:

```python
def bitwise_nor(a, b):
    return ~(a | b)
```

### Példa:
```python
bitwise_nor(5, 3)  # Binárisan: ~(101 | 011) = ~111 = -8
```

---

## Összefoglalás

| Operátor | Jelentés      | Mire használható? |
|----------|---------------|--------------------|
| `&`      | Bitwise AND   | Maszkolás, bitek kinyerése |
| `\|`     | Bitwise OR    | Bitek beállítása |
| `^`      | Bitwise XOR   | Kizáró vagy, titkosítás, állapotváltás |
| `~`      | Bitwise NOT   | Bitek invertálása |
| `<<`, `>>` | Bit shift   | Szorzás/osztás 2-vel |
| `NOR`    | Not OR        | Logikai művelet (nincs beépítve) |

