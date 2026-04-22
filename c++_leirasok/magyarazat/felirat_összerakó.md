## Subtiltle merged programming

## C++

```cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

double parseTime(const string& t) {
    int h, m, s, ms;
    sscanf(t.c_str(), "%d:%d:%d,%d", &h, &m, &s, &ms);
    return h * 3600 + m * 60 + s + ms / 1000.0;
}

string formatTime(double t) {
    int h = (int)t / 3600;
    int m = ((int)t % 3600) / 60;
    int s = (int)t % 60;
    int ms = (int)round((t - (int)t) * 1000);
    char buf[32];
    sprintf(buf, "%02d:%02d:%02d,%03d", h, m, s, ms);
    return string(buf);
}

map<pair<double,double>, string> readBlocks(const string& filename) {
    ifstream f(filename);
    map<pair<double,double>, string> result;
    string line, block;
    while (getline(f, line)) {
        // Normalize \r\n
        if (!line.empty() && line.back() == '\r') line.pop_back();
        if (!line.empty()) {
            block += line + "\n";
        } else if (!block.empty()) {
            istringstream ss(block);
            string numLine, timeLine, text, tl;
            getline(ss, numLine);
            getline(ss, timeLine);
            string textBlock;
            while (getline(ss, tl)) textBlock += tl + "\n";
            if (!textBlock.empty() && textBlock.back() == '\n')
                textBlock.pop_back();

            size_t sep = timeLine.find(" --> ");
            if (sep != string::npos) {
                double start = parseTime(timeLine.substr(0, sep));
                double end   = parseTime(timeLine.substr(sep + 5));
                result[{start, end}] = textBlock;
            }
            block.clear();
        }
    }
    return result;
}

int main() {
    string file1   = "A_Powerful_Ancient_Symbol.srt";
    string file2   = "A_Powerful_Ancient_Symbol_hu.srt";
    string outFile = "A_Powerful_Ancient_Symbol_merged.srt";

    auto eng = readBlocks(file1);
    auto hun = readBlocks(file2);

    // Összes kulcs összegyűjtése
    map<pair<double,double>, int> allKeys;
    for (auto& e : eng) allKeys[e.first] = 0;
    for (auto& h : hun) allKeys[h.first] = 0;

    ofstream out(outFile);
    int i = 1;
    for (auto& kv : allKeys) {
        auto key = kv.first;
        string engText = eng.count(key) ? eng[key] : "";
        string hunText = hun.count(key) ? hun[key] : "";
        string combined = (engText.empty() || hunText.empty())
            ? engText + hunText
            : engText + "\n" + hunText;

        out << i++ << "\n"
            << formatTime(key.first) << " --> " << formatTime(key.second) << "\n"
            << combined << "\n\n";
    }

    cout << "Kész! Párhuzamos felirat: " << outFile << endl;
    return 0;
}
```

------

## C

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_BLOCKS 5000
#define MAX_TEXT   1024

typedef struct {
    double start, end;
    char text[MAX_TEXT];
} Block;

int parseTime(const char* t, double* out) {
    int h, m, s, ms;
    if (sscanf(t, "%d:%d:%d,%d", &h, &m, &s, &ms) != 4) return 0;
    *out = h * 3600 + m * 60 + s + ms / 1000.0;
    return 1;
}

void formatTime(double t, char* buf) {
    int h  = (int)t / 3600;
    int m  = ((int)t % 3600) / 60;
    int s  = (int)t % 60;
    int ms = (int)round((t - (int)t) * 1000);
    sprintf(buf, "%02d:%02d:%02d,%03d", h, m, s, ms);
}

int readBlocks(const char* filename, Block* blocks) {
    FILE* f = fopen(filename, "r");
    if (!f) { fprintf(stderr, "Nem nyitható meg: %s\n", filename); return 0; }

    char line[512];
    int count = 0, state = 0;  // 0=szám, 1=idő, 2=szöveg
    Block cur = {0};

    while (fgets(line, sizeof(line), f)) {
        // \r\n kezelés
        int len = strlen(line);
        while (len > 0 && (line[len-1] == '\n' || line[len-1] == '\r'))
            line[--len] = '\0';

        if (state == 0 && len > 0) {
            state = 1;  // következő sor az időbélyeg
        } else if (state == 1) {
            char s1[32], s2[32];
            if (sscanf(line, "%31s --> %31s", s1, s2) == 2) {
                parseTime(s1, &cur.start);
                parseTime(s2, &cur.end);
                cur.text[0] = '\0';
                state = 2;
            }
        } else if (state == 2) {
            if (len == 0) {
                blocks[count++] = cur;
                state = 0;
            } else {
                if (strlen(cur.text) > 0) strncat(cur.text, "\n", MAX_TEXT - strlen(cur.text) - 1);
                strncat(cur.text, line, MAX_TEXT - strlen(cur.text) - 1);
            }
        }
    }
    if (state == 2) blocks[count++] = cur;  // utolsó blokk
    fclose(f);
    return count;
}

int cmpBlocks(const void* a, const void* b) {
    double d = ((Block*)a)->start - ((Block*)b)->start;
    return d < 0 ? -1 : d > 0 ? 1 : 0;
}

int main() {
    Block eng[MAX_BLOCKS], hun[MAX_BLOCKS];
    int engN = readBlocks("A_Powerful_Ancient_Symbol.srt", eng);
    int hunN = readBlocks("A_Powerful_Ancient_Symbol_hu.srt", hun);

    FILE* out = fopen("A_Powerful_Ancient_Symbol_merged.srt", "w");
    int i = 1;
    for (int e = 0; e < engN; e++) {
        char t1[32], t2[32];
        formatTime(eng[e].start, t1);
        formatTime(eng[e].end,   t2);

        // Magyar pár keresése azonos időbélyeggel
        char* hunText = NULL;
        for (int h = 0; h < hunN; h++) {
            if (fabs(hun[h].start - eng[e].start) < 0.001 &&
                fabs(hun[h].end   - eng[e].end)   < 0.001) {
                hunText = hun[h].text;
                break;
            }
        }

        fprintf(out, "%d\n%s --> %s\n%s\n", i++, t1, t2, eng[e].text);
        if (hunText) fprintf(out, "%s\n", hunText);
        fprintf(out, "\n");
    }

    fclose(out);
    printf("Kész! Párhuzamos felirat: A_Powerful_Ancient_Symbol_merged.srt\n");
    return 0;
}
```

------

## Java

```java
import java.io.*;
import java.util.*;

public class SrtMerger {

    record TimeKey(double start, double end) implements Comparable<TimeKey> {
        public int compareTo(TimeKey o) {
            return Double.compare(this.start, o.start);
        }
    }

    static double parseTime(String t) {
        String[] parts = t.trim().split("[:，,]");
        // "00:00:06,860" → h=0,m=0,s=6,ms=860
        int h  = Integer.parseInt(parts[0]);
        int m  = Integer.parseInt(parts[1]);
        int s  = Integer.parseInt(parts[2]);
        int ms = Integer.parseInt(parts[3]);
        return h * 3600 + m * 60 + s + ms / 1000.0;
    }

    static String formatTime(double t) {
        int h  = (int) t / 3600;
        int m  = ((int) t % 3600) / 60;
        int s  = (int) t % 60;
        int ms = (int) Math.round((t - (int) t) * 1000);
        return String.format("%02d:%02d:%02d,%03d", h, m, s, ms);
    }

    static Map<TimeKey, String> readBlocks(String filename) throws IOException {
        Map<TimeKey, String> result = new TreeMap<>();
        List<String> lines = new BufferedReader(
            new InputStreamReader(new FileInputStream(filename), "UTF-8"))
            .lines().toList();

        int i = 0;
        while (i < lines.size()) {
            // Üres sor kihagyása
            if (lines.get(i).isBlank()) { i++; continue; }
            // Sorszám
            i++;
            if (i >= lines.size()) break;
            // Időbélyeg
            String timeLine = lines.get(i++).trim();
            if (!timeLine.contains("-->")) continue;
            String[] parts = timeLine.split("-->");
            double start = parseTime(parts[0]);
            double end   = parseTime(parts[1]);
            // Szöveg
            StringBuilder text = new StringBuilder();
            while (i < lines.size() && !lines.get(i).isBlank()) {
                if (text.length() > 0) text.append("\n");
                text.append(lines.get(i++).stripTrailing());
            }
            result.put(new TimeKey(start, end), text.toString());
        }
        return result;
    }

    public static void main(String[] args) throws IOException {
        String file1 = "A_Powerful_Ancient_Symbol.srt";
        String file2 = "A_Powerful_Ancient_Symbol_hu.srt";
        String outFile = "A_Powerful_Ancient_Symbol_merged.srt";

        Map<TimeKey, String> eng = readBlocks(file1);
        Map<TimeKey, String> hun = readBlocks(file2);

        Set<TimeKey> allKeys = new TreeSet<>();
        allKeys.addAll(eng.keySet());
        allKeys.addAll(hun.keySet());

        try (PrintWriter out = new PrintWriter(new OutputStreamWriter(
                new FileOutputStream(outFile), "UTF-8"))) {
            int i = 1;
            for (TimeKey key : allKeys) {
                String engText = eng.getOrDefault(key, "");
                String hunText = hun.getOrDefault(key, "");
                String combined = (!engText.isEmpty() && !hunText.isEmpty())
                    ? engText + "\n" + hunText
                    : engText + hunText;

                out.printf("%d%n%s --> %s%n%s%n%n",
                    i++,
                    formatTime(key.start()), formatTime(key.end()),
                    combined);
            }
        }
        System.out.println("Kész! Párhuzamos felirat: " + outFile);
    }
}
```

------

## Kotlin

```kotlin
import java.io.File
import kotlin.math.roundToInt

data class TimeKey(val start: Double, val end: Double) : Comparable<TimeKey> {
    override fun compareTo(other: TimeKey) = compareValuesBy(this, other, { it.start }, { it.end })
}

fun parseTime(t: String): Double {
    val (hm, msStr) = t.trim().split(",")
    val parts = hm.split(":")
    val ms = msStr.toInt()
    return parts[0].toInt() * 3600 + parts[1].toInt() * 60 + parts[2].toInt() + ms / 1000.0
}

fun formatTime(t: Double): String {
    val h  = t.toInt() / 3600
    val m  = (t.toInt() % 3600) / 60
    val s  = t.toInt() % 60
    val ms = ((t - t.toInt()) * 1000).roundToInt()
    return "%02d:%02d:%02d,%03d".format(h, m, s, ms)
}

fun readBlocks(filename: String): Map<TimeKey, String> {
    val result = sortedMapOf<TimeKey, String>()
    val lines = File(filename).readLines(Charsets.UTF_8)

    var i = 0
    while (i < lines.size) {
        if (lines[i].isBlank()) { i++; continue }
        i++ // sorszám
        if (i >= lines.size) break
        val timeLine = lines[i++].trim()
        if (!timeLine.contains("-->")) continue
        val (startStr, endStr) = timeLine.split("-->")
        val start = parseTime(startStr)
        val end   = parseTime(endStr)
        val textLines = mutableListOf<String>()
        while (i < lines.size && lines[i].isNotBlank()) {
            textLines.add(lines[i++].trimEnd())
        }
        result[TimeKey(start, end)] = textLines.joinToString("\n")
    }
    return result
}

fun main() {
    val file1   = "A_Powerful_Ancient_Symbol.srt"
    val file2   = "A_Powerful_Ancient_Symbol_hu.srt"
    val outFile = "A_Powerful_Ancient_Symbol_merged.srt"

    val eng = readBlocks(file1)
    val hun = readBlocks(file2)

    val allKeys = (eng.keys + hun.keys).toSortedSet()

    File(outFile).bufferedWriter(Charsets.UTF_8).use { out ->
        allKeys.forEachIndexed { idx, key ->
            val engText = eng[key] ?: ""
            val hunText = hun[key] ?: ""
            val combined = if (engText.isNotEmpty() && hunText.isNotEmpty())
                "$engText\n$hunText" else engText + hunText

            out.write("${idx + 1}\n${formatTime(key.start)} --> ${formatTime(key.end)}\n$combined\n\n")
        }
    }
    println("Kész! Párhuzamos felirat: $outFile")
}
```

------

**Összefoglalás — mi változik nyelvenként:**

|            | Fájlkezelés      | Map/Dict                | Stringformázás  |
| ---------- | ---------------- | ----------------------- | --------------- |
| **Python** | `open()`         | `dict`                  | f-string        |
| **C++**    | `ifstream`       | `std::map`              | `sprintf`       |
| **C**      | `fopen`          | tömb + lineáris keresés | `fprintf`       |
| **Java**   | `BufferedReader` | `TreeMap`               | `String.format` |
| **Kotlin** | `File.readLines` | `sortedMapOf`           | `.format`       |

#### Python eredeti 

```
import re

file1 = r"E:\videos\SubtiltlesGenerator-master\kexx\A Powerful Ancient Symbol.srt"
file2 = r"E:\videos\SubtiltlesGenerator-master\kexx\A Powerful Ancient Symbol_hu.srt"
merged_file = r"E:\videos\SubtiltlesGenerator-master\kexx\A_Powerful_Ancient_Symbol_merged.srt"

def parse_time(t):
    t = t.strip()
    h, m, s_ms = t.split(":")
    s, ms = s_ms.split(",")
    return int(h)*3600 + int(m)*60 + int(s) + int(ms)/1000

def format_time(t):
    h = int(t) // 3600
    m = (int(t) % 3600) // 60
    s = int(t) % 60
    ms = int(round((t - int(t)) * 1000))
    return f"{h:02}:{m:02}:{s:02},{ms:03}"

def read_blocks(filename):
    with open(filename, "r", encoding="utf-8-sig") as f:
        content = f.read().strip()
    content = content.replace('\r\n', '\n').replace('\r', '\n')
    blocks = content.split("\n\n")
    parsed = {}
    for block in blocks:
        lines = block.strip().splitlines()
        if len(lines) >= 3:
            times = lines[1].split(" --> ")
            start = parse_time(times[0])
            end = parse_time(times[1])
            text = "\n".join(lines[2:]).strip()
            parsed[(start, end)] = text
    return parsed

eng = read_blocks(file1)
hun = read_blocks(file2)

all_keys = sorted(set(list(eng.keys()) + list(hun.keys())))

with open(merged_file, "w", encoding="utf-8") as f:
    for i, key in enumerate(all_keys, start=1):
        start, end = key
        eng_text = eng.get(key, "")
        hun_text = hun.get(key, "")

        if eng_text and hun_text:
            combined = f"{eng_text}\n{hun_text}"
        else:
            combined = eng_text or hun_text

        time_str = f"{format_time(start)} --> {format_time(end)}"
        f.write(f"{i}\n{time_str}\n{combined}\n\n")

print(f"Kész! Párhuzamos felirat: {merged_file}")
```

