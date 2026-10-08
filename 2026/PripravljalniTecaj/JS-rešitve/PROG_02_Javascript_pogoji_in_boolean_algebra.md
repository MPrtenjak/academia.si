# Rešitve nalog – pogoji v JavaScriptu

Primere lahko kopiramo v JavaScriptovo okolje in jih zaženemo. Za izpis v konzolo uporabljamo `console.log()`.

## 1. Pozitivno, negativno ali nič

```javascript
const stevilo = -3;

if (stevilo > 0) {
  console.log("Število je pozitivno.");
} else if (stevilo < 0) {
  console.log("Število je negativno.");
} else {
  console.log("Število je enako nič.");
}
```

## 2. Polnoletnost

Predpostavimo, da je oseba polnoletna pri 18 letih ali več.

```javascript
const starost = 20;

if (starost >= 18) {
  console.log("Oseba je polnoletna.");
} else {
  console.log("Oseba ni polnoletna.");
}
```

## 3. Sodo ali liho število

Ostanek pri deljenju z 2 je pri sodem številu enak 0.

```javascript
const stevilo = 7;

if (stevilo % 2 === 0) {
  console.log("Število je sodo.");
} else {
  console.log("Število je liho.");
}
```

## 4. Večje od dveh števil ali enaki števili

```javascript
const stevilo1 = 12;
const stevilo2 = 9;

if (stevilo1 > stevilo2) {
  console.log("Večje število je:", stevilo1);
} else if (stevilo2 > stevilo1) {
  console.log("Večje število je:", stevilo2);
} else {
  console.log("Števili sta enaki.");
}
```

## 5. Opravljeno ali ni opravljeno

```javascript
const ocena = 7;

if (ocena >= 6) {
  console.log("opravljeno");
} else {
  console.log("ni opravljeno");
}
```

## 6. Opis temperature

Meje so izbrane za primer: pod 10 °C je mraz, od 10 °C do vključno 25 °C je prijetno, nad 25 °C je vroče.

```javascript
const temperatura = 18;

if (temperatura < 10) {
  console.log("mraz");
} else if (temperatura <= 25) {
  console.log("prijetno");
} else {
  console.log("vroče");
}
```

## 7. Preverjanje uporabniškega imena in gesla

```javascript
const pravilnoUporabniskoIme = "Ana";
const pravilnoGeslo = "skrivnost";

const uporabniskoIme = "Ana";
const geslo = "skrivnost";

if (uporabniskoIme === pravilnoUporabniskoIme && geslo === pravilnoGeslo) {
  console.log("prijava uspešna");
} else {
  console.log("prijava neuspešna");
}
```

Operator `&&` pomeni, da morata biti izpolnjena oba pogoja.

## 8. Starost, prebrana s `prompt()`

`prompt()` vrne vneseno vrednost kot besedilo. Zato jo pretvorimo v število z `Number()` in šele nato primerjamo s številom 18.

```javascript
const starost = Number(prompt("Koliko ste stari?"));

if (starost >= 18) {
  console.log("Oseba je polnoletna.");
} else {
  console.log("Oseba ni polnoletna.");
}
```

## 9. Sodo ali liho s pogojnim operatorjem

Pogojni operator ima obliko `pogoj ? vrednostČeDrži : vrednostČeNeDrži`.

```javascript
const stevilo = 7;
const rezultat = stevilo % 2 === 0 ? "sodo" : "liho";

console.log(`Število je ${rezultat}.`);
```
