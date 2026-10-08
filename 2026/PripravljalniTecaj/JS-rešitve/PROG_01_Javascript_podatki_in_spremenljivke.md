# Rešitve nalog – osnove JavaScripta

Spodnje primere lahko kopiramo v JavaScriptovo okolje in jih zaženemo. V primerih uporabljamo `console.log()` za izpis v konzolo.

## 1. Ime in kraj

```javascript
const ime = "Ana";
const kraj = "Celju";

console.log(`${ime} živi v ${kraj}.`);
```

## 2. Osnovne računske operacije

```javascript
const stevilo1 = 12;
const stevilo2 = 4;

console.log("Vsota:", stevilo1 + stevilo2);
console.log("Razlika:", stevilo1 - stevilo2);
console.log("Produkt:", stevilo1 * stevilo2);
console.log("Količnik:", stevilo1 / stevilo2);
```

## 3. Obseg pravokotnika

Obseg pravokotnika izračunamo po formuli `2 × (širina + višina)`.

```javascript
const sirina = 5;
const visina = 3;
const obseg = 2 * (sirina + visina);

console.log("Obseg pravokotnika je:", obseg);
```

## 4. Pretvorba Celzijevih stopinj v Fahrenheitove

```javascript
const celsius = 20;
const fahrenheit = celsius * 9 / 5 + 32;

console.log(`${celsius} °C je ${fahrenheit} °F.`);
```

## 5. Pretvorba minut v polne ure in preostale minute

Operator `/` pri deljenju vrne količnik, operator `%` pa ostanek. Za polno število ur uporabimo `Math.floor()`.

```javascript
const minute = 135;
const ure = Math.floor(minute / 60);
const preostaleMinute = minute % 60;

console.log(`${minute} minut je ${ure} ur in ${preostaleMinute} minut.`);
```

## 6. Povprečje treh ocen

```javascript
const ocena1 = 8;
const ocena2 = 9;
const ocena3 = 7;
const povprecje = (ocena1 + ocena2 + ocena3) / 3;

console.log("Povprečje ocen je:", povprecje);
```

## 7. Stavek o izdelku

```javascript
const izdelek = "Knjiga";
const cena = 15;
const kolicina = 2;

console.log(`${izdelek} stane ${cena} EUR, količina: ${kolicina}.`);
```

## 8. Ime z velikimi črkami

Metoda `toUpperCase()` vrne besedilo z velikimi črkami.

```javascript
const ime = "Ana";

console.log(ime.toUpperCase());
```

Izpis:

```text
ANA
```

## 9. Naključno decimalno število

`Math.random()` vrne naključno decimalno število, ki je večje ali enako `0` in manjše od `1`.

```javascript
const nakljucnoStevilo = Math.random();

console.log(nakljucnoStevilo);
```

Za naključno decimalno število med `0` in `10` lahko rezultat pomnožimo z `10`:

```javascript
const nakljucnoStevilo = Math.random() * 10;

console.log(nakljucnoStevilo);
```
