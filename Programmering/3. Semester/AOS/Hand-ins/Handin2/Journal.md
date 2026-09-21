
# Journal – Aflevering Uge 3-4 (Algoritmer og datastrukturer)

2026-09-18 · @Someone

Status: opgave 1, 2, 3, 5 og 6 er færdige og testede. Opgave 4 og 7 mangler en rettelse af quadratic probing-rehashing.

## Opgave 1 — List ADT (linket liste)


Vi bygger List'en op fra bunden: en `Node`-struct med `value` og `next`, derefter en generisk `List<Object>`-klasse. Undervejs implementerede vi hver operation enkeltvis og testede den for sig, før den blev sat sammen med de andre:

- Indsættelse: `push_front`, `push_back`, `insert_at(pos, value)`
- Sletning: `delete_front`, `delete_end`, `delete_at(pos)`
- `contains(value)` — traversal med korrekt håndtering af tom liste og manglende værdi
- `reverse()` — tre-pointer-teknik (`prev`, `current`, `next`), returnerer den nye head

Et centralt gennemgående princip var altid at gemme den værdi, man er ved at overskrive (fx `Node* rest = current->next;`, _før_ man kobler en ny node ind), for at undgå at miste resten af kæden eller ende med dangling pointers.

**Vigtigt for gruppens aflevering:** vi endte med at have to versioner af List — min egen (simpel `nullptr`-afsluttet kæde) og min gruppemakkers (`list.h` + `linked_list.h`, sentinel head/tail-noder, med `push_middle`/`pop_middle`/`find` i stedet for `insert_at`/`delete_at`/`contains`). Efter gennemgang valgte vi at bruge **hans version** som den fælles List til resten af afleveringen (Set i opgave 5 bygger på den) — den var allerede komplet og testet med alle krævede operationer. Min egen version står som del af læringsprocessen.

```cpp
void reverse() {
    Node* prev = nullptr;
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}
```

## Opgave 2 — Stack med array


`Stack<Object>` er bygget oven på et dynamisk allokeret array (`Object* arr`). Standardkonstruktøren giver en startkapacitet på 100 (opgavens krav), og en overloadet konstruktør tillader en angivet startstørrelse (brugt til at teste resize-logikken med en lille kapacitet).

`push` fordobler kapaciteten, når arrayet er fuldt: et nyt, dobbelt så stort array allokeres, det gamle indhold kopieres over, og det gamle array frigives med `delete[]`.

```cpp
void push(const Object x) {
    if (topIndex == capacity - 1) {
        int newCapacity = capacity * 2;
        Object* newArray = new Object[newCapacity];
        for (int i = 0; i <= topIndex; i++) newArray[i] = arr[i];
        delete[] arr;
        arr = newArray;
        capacity = newCapacity;
    }
    arr[++topIndex] = x;
}
```

Interfacet matcher `stack_class.h`: `empty()`, `top()`, `pop()`, `push(const Object x)`.

**Tidskompleksitet:** `push` er O(1) amortiseret — de fleste kald er O(1) (ingen resize), og de sjældne resize-kald (O(n)) fordeles over mange indsættelser, så gennemsnittet forbliver konstant. `pop` er altid O(1), da den kun justerer et indeks.

Testet med en lille startkapacitet (2) for eksplicit at trigge en resize midt i en serie af `push`-kald, og verificeret at `pop` derefter leverer værdierne i korrekt LIFO-rækkefølge.

## Opgave 3 — Queue via Stack (to stacks)



`Queue<Object>` er bygget udelukkende ved hjælp af to `Stack<Object>`-medlemmer, `inStack` og `outStack` — ingen brug af Stackens interne struktur eller en iterator, som opgaven kræver.

Princippet: `put(x)` lægger altid nye elementer i `inStack`. Når man skal hente (`front`/`get`), og `outStack` er tom, flyttes **alt** fra `inStack` over på `outStack`, ét element ad gangen (`outStack.push(inStack.pop())`) — det vender rækkefølgen om, så det ældste element (først puttet ind) ender øverst på `outStack`, klar til at hentes i korrekt FIFO-rækkefølge. Er der allerede noget i `outStack`, flyttes der ikke igen (ellers ville rækkefølgen blive blandet).

```cpp
Object get() {
    if (outStack.empty()) {
        while (!inStack.empty()) outStack.push(inStack.pop());
    }
    return outStack.pop();
}
```

Testet med en blanding af `put`- og `get`-kald (inklusiv et `put` midt i en serie af `get`-kald), som bekræftede at "flyt kun når outStack er tom"-reglen holder rækkefølgen korrekt uanset rækkefølgen af operationer.

## Opgave 4 — Hash-tabel (chaining, linear probing, quadratic probing) IKKE FÆRDIG


Nøglerne 5, 28, 19, 15, 20, 33, 12, 17, 33, 10 skal indsættes i en tabel af størrelse 7 med `h(x) = x mod 7`, for chaining, linear probing og quadratic probing.

- **Chaining**: korrekt og komplet. Load factor `10/7 ≈ 1,43`.
- **Linear probing**: korrekt, men ufærdig — tabellen bliver helt fuld (load factor 1) efter kun 7 af de 10 nøgler. De resterende tre (17, 33, 10) mangler stadig at blive indsat efter en rehash.
- **Quadratic probing**: indeholder en reel fejl. Nøglen 12 (`12 mod 7 = 5`) blev placeret på index 4 — men det er matematisk umuligt: probe-sekvensen `(5 + i²) mod 7` kan for et primtal som 7 kun ramme indeksene `{5, 6, 0, 2}` (kvadratresterne mod 7), aldrig 4, uanset hvor mange forsøg man gør.

Dette er netop det problem, pensum bruger som eksempel på, hvorfor man **skal** rehashe, før belastningen (`ρ`) kommer over 0,5, i stedet for at vente til tabellen "sidder fast". Med de givne nøgler når `ρ = 4/7 ≈ 0,57` allerede efter 4. indsættelse (5, 28, 19, 15) — så rehashing skulle være sket, før nøgle nummer 5 (20) blev indsat, til en ny tabelstørrelse (`nextPrime(2 × 7) = 17`).

**Næste skridt:** genopbygge quadratic probing-tabellen korrekt med rehash ved `ρ ≥ 0,5`, og færdiggøre linear probing-tabellen med de resterende tre nøgler efter rehash.

## Opgave 5 — Set via List

`Set<Object>` er bygget oven på min gruppemakkers `Linkedlist<Object>` (fra opgave 1) — uden at røre dens interne struktur eller bruge en iterator.

**`insert(x)`** tjekker først, om `x` allerede findes (via `contains`), og tilføjer kun, hvis den ikke gør — det sikrer, at et Set aldrig indeholder dubletter.

**`contains(x)`** udnytter, at `Linkedlist::find(x)` kaster en `std::out_of_range`, hvis værdien ikke findes, i stedet for at returnere en bool. Løst med `try`/`catch`:

```cpp
bool contains(const Object x) {
    try { list.find(x); return true; }
    catch (const std::out_of_range&) { return false; }
}
```

**`remove(x)`** var den svære del: `Linkedlist` har ingen "find position af værdi"-funktion, kun `pop_middle(pos)` — så man kan ikke slette direkte ved værdi. Løsningen bruger to lister (samme grundidé som `Queue` fra opgave 3, bare uden rækkefølge-vending): tøm hele `list` element for element, og læg alt undtagen `x` over i en midlertidig `temp`-liste — flyt derefter alt fra `temp` tilbage til `list`.

```cpp
void remove(const Object x) {
    Linkedlist<Object> temp;
    while (!list.empty()) {
        Object val = list.pop_front();
        if (val == x) continue;      // dropper netop denne værdi
        temp.push_back(val);
    }
    while (!temp.empty()) list.push_back(temp.pop_front());
}
```

Testet med indsættelse af dubletter (ingen effekt på anden gang), samt `remove` efterfulgt af `contains`-tjek på de resterende værdier.

## Opgave 6 — Dictionary/Map via STL vector


`Vector_map<Key, Value>` er bygget oven på `std::vector<std::pair<Key, Value>>`, som opgaven kræver.

`insert(key, value)` gennemsøger vektoren lineært; findes nøglen allerede, opdateres værdien i stedet for at oprette en dublet-post:

```cpp
void insert(Key key, Value value) {
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i].first == key) { vec[i].second = value; return; }
    }
    vec.emplace_back(key, value);
}
```

`find(key)` returnerer den tilhørende værdi (kaster `std::out_of_range`, hvis nøglen ikke findes), `contains(key)` returnerer en bool, og `remove(key)` fjerner posten med `vec.erase`.

Testet med `std::string`-nøgler (alder pr. navn), inklusiv opdatering af en eksisterende nøgle (bekræftet ingen dublet, korrekt `size()`), samt med en anden nøgle/værdi-kombination (`int`/`std::string`) for at bekræfte, at klassen faktisk er generisk.

## Opgave 7 - An old exam question

Tabel:

| Index | Value |
| ----- | ----- |
| 0     | 22    |
| 1     |       |
| 2     |       |
| 3     |       |
| 4     |       |
| 5     | 5     |
| 6     | 16    |
| 7     |       |
| 8     |       |
| 9     | 27    |
| 10    |       |
Først beregner vi ρ:
$$ρ=\frac{4}{11}=0.364$$
Så længe $\rho$ er under 0.5 behøver der ikke at rehashes, og vi kan bare indsætte værdier direkte.

Vi starter med at finde $h(1)$:
1 mod 11 = 1

Eftersom index 1 er ledig, smider vi den ind

| Index | Value |
| ----- | ----- |
| 0     | 22    |
| 1     | 1     |
| 2     |       |
| 3     |       |
| 4     |       |
| 5     | 5     |
| 6     | 16    |
| 7     |       |
| 8     |       |
| 9     | 27    |
| 10    |       |
Vi beregner $\rho$ igen:
$$\rho=\frac{5}{11}=0.454$$
Da den stadig er under 0.5, skal vi ikke rehashe.
Vi finder nu $h(12)$:
12 mod 11 = 1

Index 1 er ikke ledig. Derfor bliver vi nødt til at bruge metoden:
$h(x)+i^2$ mod 11

Altså:
$12+1^2=13$
13 mod 11 = 2

Da index 2 er ledig placeres 12 der.

Vi beregner $\rho$ igen:
$$\rho=\frac{6}{11}=0.545$$
Da $\rho$ er over 0.5, skal tabellen rehashes
Først laver vi en ny tabelstørrelse. Det er altså næste primtal efter det dobbelte af den nuværende tabelstørrelse. 

Tabelstørrelsen er 11, det dobbelte er 22. Det næste primtal er 23. Så den nye tabelstørrelse bliver 23.

Vi skal nu genindsætte alle værdierne i den nye tabel, og finde $h(x)=x$ mod 23.

| h(x) | mod 23 | index |
| ---- | ------ | ----- |
| 22   | 22     | 22    |
| 1    | 1      | 1     |
| 12   | 12     | 12    |
| 5    | 3      | 3     |
| 16   | 7      | 7     |
| 27   | 4      | 4     |
Så vi får tabellen:

| Index | Value |
| ----- | ----- |
| 0     |       |
| 1     | 1     |
| 2     |       |
| 3     | 5     |
| 4     | 27    |
| 5     |       |
| 6     |       |
| 7     | 16    |
| 8     |       |
| 9     |       |
| 10    |       |
| 11    |       |
| 12    | 12    |
| 13    |       |
| 14    |       |
| 15    |       |
| 16    |       |
| 17    |       |
| 18    |       |
| 19    |       |
| 20    |       |
| 21    |       |
| 22    | 22    |

Vi kan nu se vores $\rho$ er faldet gevaldigt og vi kan fortsætte:
$$\rho=\frac{6}{23}=0.261$$
Jeg er 22 år gammel. Vi indsætter nu min alder
22 mod 23 = 22
Index 22 er optaget så vi bruger metoden fra før
$22 + 1^2=23$
23 mod 23 = 0
Index 0 er ledigt, og kan derfor indsættes i tabellen.


Vi skal nu indsætte mit studienummer: 202411378
$$\rho=\frac{7}{23}=0.304$$
Stadig under 0.5.
$$\frac{202411378}{23}=8800494.696$$
Vi er kun interesseret i heltallet, så vi fjerne decimalerne og ganger heltallet tilbage med 23:
$$8800494\cdot23=202411362$$
Det trækker vi fra vores oprindelige tal:
$$202411378-202411362=16$$
Index 16 er ledigt og 202411378 bliver nu indsat på index 16 og vores endelige tabel bliver:

| Index | Value     |
| ----- | --------- |
| 0     | 22        |
| 1     | 1         |
| 2     |           |
| 3     | 5         |
| 4     | 27        |
| 5     |           |
| 6     |           |
| 7     | 16        |
| 8     |           |
| 9     |           |
| 10    |           |
| 11    |           |
| 12    | 12        |
| 13    |           |
| 14    |           |
| 15    |           |
| 16    | 202411378 |
| 17    |           |
| 18    |           |
| 19    |           |
| 20    |           |
| 21    |           |
| 22    | 22        |

C:\Users\rober\Obsidian Vault-20260324T083224Z-1-001\Obsidian Vault\3. semester\Algoritmer og datastrukturer\Handin week 3-4.md
