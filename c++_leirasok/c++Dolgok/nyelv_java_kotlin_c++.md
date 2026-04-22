Igen, ez Kotlinban és Javaban is megoldható, és valójában **szebb is lesz**, mert van **data class** (ami kb a C++ struct modern megfelelője).

A C++ kódod:

```cpp
struct CreateVocab
{
    std::string createVocab;
    std::string createVocab2;
    std::string createVocab3;
    std::string createVocab4;
    std::string createVocab5;
    std::string createVocab6;
    std::string createVocab7;
};

const std::vector<CreateVocab> createVocabTranslations = {
    {
        "Fájl: ",
        " (",
        " szó eddig) ---",
        "Parancsok: 'exit' (mentes es kilepes), 'save' (mentes es folytatas)\n",
        "Angol szo/kifejezes: ",
        "Magyar jelentese (vesszovel elvalasztva ha több van): ",
        "Kiejtes (opcionális): "
    }
};
```

## Kotlin megfelelő:

Kotlinban így nézne ki:

```kotlin
data class CreateVocab(
    val createVocab:String,
    val createVocab2:String,
    val createVocab3:String,
    val createVocab4:String,
    val createVocab5:String,
    val createVocab6:String,
    val createVocab7:String
)

val createVocabTranslations = listOf(
    CreateVocab(
        "Fájl: ",
        " (",
        " szó eddig) ---",
        "Parancsok: 'exit' (mentes es kilepes), 'save' (mentes es folytatas)\n",
        "Angol szo/kifejezes: ",
        "Magyar jelentese (vesszovel elvalasztva ha több van): ",
        "Kiejtes (opcionális): "
    )
)
```

## Mi felel meg minek:

| C++         | Kotlin     |
| ----------- | ---------- |
| struct      | data class |
| std::vector | listOf     |
| const       | val        |
| std::string | String     |

## Miért jobb Kotlin data class?

Automatikusan kapsz:

- toString()
- equals()
- hashCode()
- copy()
- destructuring

C++ structnál ezeket kézzel kell.

## Még szebb Kotlin design (pro tipp)

Ahelyett hogy:

```kotlin
createVocab
createVocab2
createVocab3
```

jobb:

```kotlin
data class CreateVocab(
    val fileLabel:String,
    val countPrefix:String,
    val countSuffix:String,
    val commands:String,
    val englishPrompt:String,
    val hungarianPrompt:String,
    val pronunciationPrompt:String
)
```

Ez már clean architecture.

## Ultra clean Kotlin (még jobb)

Mivel ez translation text → lehet map:

```kotlin
val createVocabTranslations = CreateVocab(
    fileLabel = "Fájl: ",
    countPrefix = " (",
    countSuffix = " szó eddig) ---",
    commands = "Parancsok: exit, save",
    englishPrompt = "Angol:",
    hungarianPrompt = "Magyar:",
    pronunciationPrompt = "Kiejtés:"
)
```

Ez sokkal Kotlinosabb.

## Java megfelelő:

Java verbose:

```java
class CreateVocab {

    String createVocab;
    String createVocab2;
    String createVocab3;
    String createVocab4;
    String createVocab5;
    String createVocab6;
    String createVocab7;

    CreateVocab(
        String createVocab,
        String createVocab2,
        String createVocab3,
        String createVocab4,
        String createVocab5,
        String createVocab6,
        String createVocab7)
    {
        this.createVocab = createVocab;
        this.createVocab2 = createVocab2;
        this.createVocab3 = createVocab3;
        this.createVocab4 = createVocab4;
        this.createVocab5 = createVocab5;
        this.createVocab6 = createVocab6;
        this.createVocab7 = createVocab7;
    }
}
```

Ezért szeretik sokan Kotlin-t.

## Amit te csináltál C++-ban az egyébként jó design 👍

Ez lényegében:
**translation table / resource table**

Ezt használják:

- game engines
- CLI tools
- localization systems

Szóval ez nem beginner ötlet.

------

Jó kérdés 👍 mert ez pont az a dolog ahol jól látszik a nyelvek filozófiája. Ugyanaz a struktúra Java, Python, Rust és C++-ban teljesen más kinézetű.

A Java verziód után így menne a lista:

## Java (teljes példa)

```java
import java.util.List;
import java.util.ArrayList;

class CreateVocab {

    String createVocab;
    String createVocab2;
    String createVocab3;
    String createVocab4;
    String createVocab5;
    String createVocab6;
    String createVocab7;

    CreateVocab(
        String createVocab,
        String createVocab2,
        String createVocab3,
        String createVocab4,
        String createVocab5,
        String createVocab6,
        String createVocab7)
    {
        this.createVocab = createVocab;
        this.createVocab2 = createVocab2;
        this.createVocab3 = createVocab3;
        this.createVocab4 = createVocab4;
        this.createVocab5 = createVocab5;
        this.createVocab6 = createVocab6;
        this.createVocab7 = createVocab7;
    }
}

public class Main {

    public static void main(String[] args) {

        List<CreateVocab> createVocabTranslations = new ArrayList<>();

        createVocabTranslations.add(
            new CreateVocab(
                "Fajl: ",
                " (",
                " szo eddig) ---",
                "Parancsok: exit save",
                "Angol:",
                "Magyar:",
                "Kiejtes:"
            )
        );

    }
}
```

------

# Python megfelelő

Pythonban ez sokkal rövidebb:

## Python (class)

```python
class CreateVocab:

    def __init__(self,
                 createVocab,
                 createVocab2,
                 createVocab3,
                 createVocab4,
                 createVocab5,
                 createVocab6,
                 createVocab7):

        self.createVocab = createVocab
        self.createVocab2 = createVocab2
        self.createVocab3 = createVocab3
        self.createVocab4 = createVocab4
        self.createVocab5 = createVocab5
        self.createVocab6 = createVocab6
        self.createVocab7 = createVocab7


createVocabTranslations = [

    CreateVocab(
        "Fajl:",
        "(",
        "szo eddig",
        "exit save",
        "Angol:",
        "Magyar:",
        "Kiejtes:"
    )

]
```

## Python PRO mód (dataclass) ⭐

Ez a modern megoldás:

```python
from dataclasses import dataclass

@dataclass
class CreateVocab:

    fileLabel:str
    countPrefix:str
    countSuffix:str
    commands:str
    englishPrompt:str
    hungarianPrompt:str
    pronunciationPrompt:str


createVocabTranslations = [

    CreateVocab(
        "Fajl:",
        "(",
        "szo eddig",
        "exit save",
        "Angol:",
        "Magyar:",
        "Kiejtes:"
    )

]
```

Ez kb Python struct.

------

# Rust megfelelő

Rust nagyon hasonlít C++-ra ebben:

## Rust struct:

```rust
struct CreateVocab {

    create_vocab:String,
    create_vocab2:String,
    create_vocab3:String,
    create_vocab4:String,
    create_vocab5:String,
    create_vocab6:String,
    create_vocab7:String
}
```

## Példány:

```rust
let create_vocab_translations = vec![

    CreateVocab{

        create_vocab: "Fajl:".to_string(),
        create_vocab2: "(".to_string(),
        create_vocab3: "szo eddig".to_string(),
        create_vocab4: "exit save".to_string(),
        create_vocab5: "Angol:".to_string(),
        create_vocab6: "Magyar:".to_string(),
        create_vocab7: "Kiejtes:".to_string()

    }

];
```

## Rust miért `.to_string()` ?

Mert:

```rust
"hello"
```

ez:

```rust
&str
```

de struct:

```rust
String
```

Tehát convert kell.

------

# Rövid összehasonlítás:

| Nyelv  | Struct            |
| ------ | ----------------- |
| C++    | struct            |
| Java   | class             |
| Kotlin | data class        |
| Python | class / dataclass |
| Rust   | struct            |

Vector megfelelő:

| C++         | Más nyelv          |
| ----------- | ------------------ |
| std::vector | Java ArrayList     |
| std::vector | Kotlin MutableList |
| std::vector | Python list        |
| std::vector | Rust Vec           |

------

# Amit te csinálsz az egyébként resource table design

Pro C++ projektek így csinálják:

Nem:

```cpp
createVocab1
createVocab2
```

Hanem:

```cpp
struct CreateVocab
{
    std::string fileLabel;
    std::string countPrefix;
    std::string countSuffix;
    std::string commands;
    std::string englishPrompt;
    std::string hungarianPrompt;
    std::string pronunciationPrompt;
};
```

Ez már **clean architecture**.

------

