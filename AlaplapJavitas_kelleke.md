

------

#  0 → Laptop alaplap javítás útvonal

#  1. szint – Alap elektronika (0–2 hét)

##  Cél:

Értsd mi történik az áramkörben.

## Tanuld:

- feszültség (V)
- áram (A)
- ellenállás (Ω)
- Ohm törvény (U = I × R)
- rövidzár (short)
- szakadás (open circuit)

## Gyakorlat:

- elem + LED + ellenállás
- multiméterrel mérés

## Eszköz:

- multiméter (olcsó is jó)

------

#  2. szint – Forrasztás alapok (2–4 hét)

##  Cél:

tudd megfogni a pákát stabilan

## Tanuld:

- ón felvitele
- flux használata
- alkatrész le- és felrakás
- SMD vs THT

## Gyakorlat:

- régi router / rádió szétszedése
- alkatrészek leforrasztása

## Eszköz:

- forrasztóállomás (állítható hőfokkal)
- flux
- csipesz

------

#  3. szint – PC alaplap alapok (1–2 hónap)

##  Cél:

érts egy PC alaplap működést

## Tanuld:

- VRM (tápellátás)
- CPU power rail
- BIOS szerepe
- POST folyamat

## Gyakorlat:

- régi PC alaplap vizsgálat
- POST kártya használata

## Eszköz:

- POST kártya
- multiméter

------

#  4. szint – Hibakeresés alap (2–3 hónap)

##  Cél:

tudd meg mi halt meg a lapon

## Tanuld:

- rövidzár keresés
- tápágak (3.3V / 5V / 12V)
- MOSFET alapok
- kondenzátor hibák

## Gyakorlat:

- „nem induló” alaplap vizsgálata
- feszültségmérés pontokon

## Eszköz:

- labortáp (nagyon fontos!)
- multiméter

------

#  5. szint – Laptop alaplap belépő (3–6 hónap)

##  Cél:

megérteni laptop boardokat

## Tanuld:

- laptop tápágak (always-on 3.3V / 5V)
- power sequence
- EC (Embedded Controller)
- BIOS szerep laptopban

## Gyakorlat:

- bontott laptop alaplap vizsgálata
- feszültségek mérés sorrendben

## Eszköz:

- labortáp
- mikroszkóp (itt már kell)

------

#  6. szint – Laptop javítás (haladó)

##  Cél:

hibát megtalálni és javítani

## Tanuld:

- rövidzár lokalizálás
- alkatrész csere (SMD)
- BIOS újraírás
- schematics olvasás
- boardview használat

## Gyakorlat:

- nem induló laptop javítás
- USB nem működik hibák
- töltés hiba (charging IC)

## Eszköz:

- hot air állomás
- mikroszkóp
- labortáp
- BIOS programmer (CH341A)

------

#  Profi szint (6–12 hónap)

- GPU/CPU táp hibák
- BGA hibák (reballing)
- multilayer hibák
- komplett diagnosztika szerviz szinten

------

#  FULL ESZKÖZ LIST (amit végül kelleni fog)

## Alap:

- multiméter
- forrasztóállomás

## Közép:

- labortáp
- POST kártya
- flux + SMD készlet

## Haladó:

- mikroszkóp
- hot air station
- BIOS programmer (CH341A)

------

#  Fontos igazság

 laptop alaplap javítás = nem „forrasztás”
 hanem:

- mérés
- logika
- tápvonal követés
- hibakeresés

------

#  Reális idő

- alap szint: 1 hónap
- PC hibakeresés: 2–3 hónap
- laptop belépő: 3–6 hónap
- jó szint: 1 év+

------

A labortáp (laboratóriumi tápegység) abban más, hogy **nem csak “adja az áramot”, hanem kontrolláltan és biztonságosan adagolja**.

------

#  Labortáp vs sima adapter

##  1. Sima töltő / adapter

- fix feszültség (pl. 19V laptop töltő)
- nem látod az áramot
- ha zárlat van → csak leáll vagy tönkremegy

 „bután adja az energiát”

------

##  2. Labortáp

- állítható feszültség (pl. 0–30V)
- állítható áramkorlát (pl. 0–5A)
- kijelzi:
  - feszültség (V)
  - áram (A)

 „okosan adagolja az energiát”

------

#  A legfontosabb különbség: ÁRAMKORLÁT

Ez a kulcs laptop javításnál.

## Ha rövidzár van:

### Sima töltő:

- túl sok áram
- leéghet alkatrész

### Labortáp:

- beállítod pl. 1V / 1A
- és ha zárlat van:
  - nem ég el semmi
  - csak “megáll az áram”

 ez a **biztonsági funkció**

------

#  Hogyan segít hibakeresésnél?

Laptop alaplapon:

## Normál eset:

- 19V bemegy
- kis áram (0.02–0.1A standby)

## Hiba eset (rövidzár):

- labortáp:
  - feszültség leesik
  - áram felmegy limitig

 ebből tudod:

- VAN zárlat a lapon

------

#  Extra trükk (profi használat)

## „Freeze / hőkeresés”

- labortáp ráad kis feszültséget
- zárlatos alkatrész melegszik
- megtalálod hőkamerával / alkohollal

------

#  Összefoglalás

| Eszköz       | Mit tud                   |
| ------------ | ------------------------- |
| sima adapter | fix 19V                   |
| labortáp     | állítható V + A + védelem |

------

#  Egyszerű mondatban:

 **A labortáp azért kell, hogy ne tudd tönkretenni a hibás alaplapot, és lásd mi történik benne.**

------

Ha akarod, megmutatom:
hogyan néz ki egy tipikus laptop rövidzár labortápos tesztje lépésről lépésre.