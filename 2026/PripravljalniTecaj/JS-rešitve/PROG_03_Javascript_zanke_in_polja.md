# Rešitve nalog – zanke in polja v JavaScriptu

Primere lahko kopiramo v JavaScriptovo okolje in jih zaženemo. Za izpis v konzolo uporabljamo `console.log()`.

## 1. Izpis števil od 1 do 10

```javascript
for (let i = 1; i <= 10; i++) {
  console.log(i);
}
```

Spremenljivka `i` začne pri 1. Po vsakem ponavljanju se poveča za 1, zanka pa se izvaja, dokler je `i` manjši ali enak 10.

## 2. Izpis števil od 10 do 1

```javascript
for (let i = 10; i >= 1; i--) {
  console.log(i);
}
```

Spremenljivka `i` se po vsakem ponavljanju zmanjša za 1.

## 3. Večkratniki števila 3 med 1 in 30

```javascript
for (let i = 3; i <= 30; i += 3) {
  console.log(i);
}
```

Zanka začne pri 3 in pri vsakem ponavljanju prišteje 3.

## 4. Vsota števil od 1 do 100

```javascript
let vsota = 0;

for (let i = 1; i <= 100; i++) {
  vsota += i;
}

console.log("Vsota je:", vsota);
```

Po koncu zanke je vrednost spremenljivke `vsota` enaka 5050.

## 5. Izpis petih imen

```javascript
const imena = ["Ana", "Boris", "Cene", "Dora", "Eva"];

for (let i = 0; i < imena.length; i++) {
  console.log(imena[i]);
}
```

Indeksi polja se začnejo z 0, zato so indeksi petih elementov od 0 do 4. Lastnost `length` pove število elementov v polju.

## 6. Vsota vseh elementov polja

```javascript
const stevila = [4, 7, 2, 9];
let vsota = 0;

for (let i = 0; i < stevila.length; i++) {
  vsota += stevila[i];
}

console.log("Vsota elementov je:", vsota);
```

## 7. Štetje pozitivnih elementov

```javascript
const stevila = [-3, 5, 0, 8, -1, 2];
let steviloPozitivnih = 0;

for (let i = 0; i < stevila.length; i++) {
  if (stevila[i] > 0) {
    steviloPozitivnih++;
  }
}

console.log("Pozitivnih elementov je:", steviloPozitivnih);
```

Število 0 ni pozitivno, zato pogoj uporablja `> 0`.

## 8. Iskanje največjega števila v polju

Največje število najprej nastavimo na prvi element polja. Nato pregledamo preostale elemente in vrednost posodobimo, kadar najdemo večje število.

```javascript
const stevila = [4, 12, -3, 8, 6];
let najvecje = stevila[0];

for (let i = 1; i < stevila.length; i++) {
  if (stevila[i] > najvecje) {
    najvecje = stevila[i];
  }
}

console.log("Največje število je:", najvecje);
```

Ta rešitev predpostavlja, da polje vsebuje vsaj en element.

## 9. Obrnitev polja z metodo `reverse()`

Metoda `reverse()` obrne vrstni red elementov v polju.

```javascript
const imena = ["Ana", "Boris", "Cene", "Dora", "Eva"];
imena.reverse();

for (let i = 0; i < imena.length; i++) {
  console.log(imena[i]);
}
```

Metoda `reverse()` spremeni vrstni red elementov v samem polju. Po klicu metode se bodo imena izpisala v obratnem vrstnem redu.
