# JavaScript: zanke in polja

## Zakaj zanke?

Zanko uporabimo, kadar želimo podobno opravilo ponoviti večkrat. Namesto desetih skoraj enakih vrstic napišemo eno zanko.

## Zanka `for`

```javascript
for (let stevec = 1; stevec <= 5; stevec = stevec + 1) {
  console.log(stevec);
}
```

Zanka ima tri dele:

1. začetno vrednost števca: `let stevec = 1`;
2. pogoj nadaljevanja: `stevec <= 5`;
3. spremembo števca: `stevec = stevec + 1`.

Krajši zapis povečanja za ena je `stevec++`.

## Zanka `while`

Zanko `while` uporabimo, kadar želimo ponavljati, dokler pogoj velja.

```javascript
let stevec = 1;

while (stevec <= 3) {
  console.log(stevec);
  stevec++;
}
```

V zanki `while` moramo paziti, da se vrednost v pogoju spreminja. Sicer lahko nastane neskončna zanka.

## Polje

**Polje** (*array*) hrani več vrednosti v določenem vrstnem redu.

```javascript
const barve = ["rdeča", "modra", "zelena"];
```

Elementi imajo indekse. Prvi element ima indeks `0`.

```javascript
console.log(barve[0]); // "rdeča"
console.log(barve[2]); // "zelena"
console.log(barve.length); // 3
```

Nov element dodamo na konec z `push`:

```javascript
barve.push("rumena");
```

## Zanka čez polje

```javascript
const imena = ["Ana", "Bor", "Cene"];

for (let indeks = 0; indeks < imena.length; indeks++) {
  console.log(imena[indeks]);
}
```

Pogoj je `indeks < imena.length`, ne `<=`, ker je zadnji veljavni indeks za polje treh elementov `2`.

## Seštevanje elementov polja

```javascript
const ocene = [6, 8, 9];
let vsota = 0;

for (let indeks = 0; indeks < ocene.length; indeks++) {
  vsota = vsota + ocene[indeks];
}

console.log(vsota); // 23
```

Spremenljivka `vsota` je **akumulator**: med ponavljanjem zbira rezultat.

## Pogoji v zanki

```javascript
const stevila = [3, 10, 7, 12];

for (let indeks = 0; indeks < stevila.length; indeks++) {
  if (stevila[indeks] % 2 === 0) {
    console.log(stevila[indeks]);
  }
}
```

Ta primer izpiše samo soda števila.

## Povzetek

- `for` uporabimo za ponavljanje s števcem.
- `while` ponavlja, dokler je pogoj resničen.
- Polje hrani več vrednosti; prvi indeks je `0`.
- `length` pove število elementov v polju.
- Zanko in pogoj lahko združimo za obdelavo podatkov.

## Naloge

1. Z zanko `for` izpiši števila od 1 do 10.
2. Izpiši števila od 10 do 1.
3. Izpiši vse večkratnike števila 3 med 1 in 30.
4. Izračunaj vsoto števil od 1 do 100.
5. Ustvari polje petih imen in izpiši vsako ime v svoji vrstici.
6. Za polje števil izračunaj vsoto vseh elementov.
7. Za polje števil preštej, koliko elementov je pozitivnih.
8. **Razširitvena naloga:** Za polje števil poišči največje število. Začni z največjim, nastavljenim na prvi element polja.
9. **Razširitvena naloga:** Ugotovi, kako z metodo `reverse()` obrneš polje, in nato izpiši elemente v obrnjenem vrstnem redu.

## Preveri razumevanje

1. Kdaj uporabimo zanko `for`?
2. Zakaj se prvi element polja nahaja na indeksu `0`?
3. Kaj pove lastnost `length`?
4. Zakaj je pri zanki čez polje pravilen pogoj `indeks < polje.length`?
5. Kaj je akumulator?
