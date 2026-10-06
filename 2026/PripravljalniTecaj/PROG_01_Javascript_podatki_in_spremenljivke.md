# JavaScript: podatki in spremenljivke

## Program in rezultat

Program je zaporedje navodil. V JavaScriptu lahko rezultat hitro prikažemo v konzoli:

```javascript
console.log("Pozdrav!");
console.log(2 + 3);
```

## Spremenljivke

Spremenljivka ima ime in vrednost.

```javascript
let starost = 20;
const ime = "Ana";

console.log(ime);
console.log(starost);
```

- `let` uporabimo za vrednost, ki se lahko spremeni.
- `const` uporabimo za vrednost, ki je ne bomo ponovno nastavili.
- Ime naj pove, kaj vrednost pomeni: `cenaIzdelka` je boljše kot `x`.

```javascript
let tocke = 5;
tocke = tocke + 3;
console.log(tocke); // 8
```

## Podatkovni tipi

| Tip | Primer | Pomen |
|---|---|---|
| `number` | `42`, `3.14` | Število. |
| `string` | `"Pozdrav"` | Besedilo. |
| `boolean` | `true`, `false` | Resnično ali neresnično. |
| `null` | `null` | Namenoma ni vrednosti. |
| `undefined` | `undefined` | Vrednost še ni določena. |

```javascript
const cena = 12.5;
const naslov = "Celje";
const jeOdprto = true;
```

Tip vrednosti lahko preverimo z `typeof`:

```javascript
console.log(typeof cena);    // "number"
console.log(typeof naslov);  // "string"
```

## Operatorji

| Operator | Pomen | Primer |
|---|---|---|
| `+` | seštevanje; pri besedilu združevanje | `5 + 3`, `"A" + "na"` |
| `-` | odštevanje | `10 - 4` |
| `*` | množenje | `4 * 6` |
| `/` | deljenje | `10 / 2` |
| `%` | ostanek pri deljenju | `11 % 2` je `1` |

Besedilo lahko sestavimo z `+`:

```javascript
const ime = "Marko";
const pozdrav = "Pozdravljen, " + ime + "!";
console.log(pozdrav);
```

Pri večjih izrazih uporabimo oklepaje:

```javascript
const povprecje = (6 + 8 + 9) / 3;
```

## Pretvorba vrednosti

Besedilo in število nista isto.

```javascript
console.log("2" + "3"); // "23"
console.log(2 + 3);     // 5
```

Za pretvorbo besedila v število lahko uporabimo `Number`:

```javascript
const vpisano = "25";
const starost = Number(vpisano);
console.log(starost + 1); // 26
```

Za zaokrožanje navzdol na celo število uporabimo `Math.floor`:

```javascript
console.log(Math.floor(125 / 60)); // 2
```

## Povzetek

- Vrednosti hranimo v spremenljivkah.
- Najpogostejši tipi so `number`, `string` in `boolean`.
- `const` uporabimo, kadar vrednosti ne nastavljamo znova; sicer `let`.
- Rezultate med učenjem preverjamo s `console.log`.
- `Math.floor` število zaokroži navzdol na celo število.

## Naloge

1. Ustvari spremenljivki `ime` in `kraj` ter izpiši stavek: `Ana živi v Celju.`
2. Ustvari spremenljivki `stevilo1` in `stevilo2` ter izpiši njuno vsoto, razliko, produkt in količnik.
3. Izračunaj obseg pravokotnika s stranicama `sirina` in `visina`.
4. Iz temperature v stopinjah Celzija izračunaj temperaturo v Fahrenheitih: `F = C * 9 / 5 + 32`.
5. Iz števila minut izračunaj število polnih ur in preostalih minut. Pomagaj si z `/` in `%`.
6. Izračunaj povprečje treh ocen in ga izpiši.
7. Izpiši stavek, ki vsebuje ime izdelka, ceno in količino, na primer: `Knjiga stane 15 EUR, količina: 2.`
8. **Razširitvena naloga:** Ugotovi, kako z metodo `toUpperCase()` izpisati ime z velikimi črkami.
9. **Razširitvena naloga:** Ugotovi, kako z `Math.random()` ustvariti naključno decimalno število in ga izpiši.

## Preveri razumevanje

1. Kakšna je razlika med `let` in `const`?
2. Kateri podatkovni tip predstavlja besedilo?
3. Kaj izpiše izraz `"2" + "3"`?
4. Čemu služi operator `%`?
5. Čemu med učenjem služi `console.log()`?
