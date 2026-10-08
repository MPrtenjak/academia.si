# Rešitve nalog – funkcije in objekti v JavaScriptu

Primere lahko kopiramo v JavaScriptovo okolje in jih zaženemo. Za izpis uporabljamo `console.log()`.

## 1. Funkcija `izpisiPozdrav()`

```javascript
function izpisiPozdrav() {
  console.log("Pozdravljeni!");
}

izpisiPozdrav();
```

## 2. Funkcija `pozdravi(ime)`

```javascript
function pozdravi(ime) {
  console.log(`Živjo, ${ime}!`);
}

pozdravi("Ana");
```

## 3. Funkcija `kvadrat(stevilo)`

Funkcija vrne rezultat z ukazom `return`.

```javascript
function kvadrat(stevilo) {
  return stevilo * stevilo;
}

const rezultat = kvadrat(5);
console.log(rezultat);
```

## 4. Funkcija `jePolnoleten(starost)`

```javascript
function jePolnoleten(starost) {
  return starost >= 18;
}

console.log(jePolnoleten(20)); // true
console.log(jePolnoleten(16)); // false
```

Primerjava `starost >= 18` že vrne logično vrednost `true` ali `false`.

## 5. Funkcija `izracunajPovprecje(stevila)`

```javascript
function izracunajPovprecje(stevila) {
  let vsota = 0;

  for (let i = 0; i < stevila.length; i++) {
    vsota += stevila[i];
  }

  return vsota / stevila.length;
}

console.log(izracunajPovprecje([6, 8, 10])); // 8
```

Ta rešitev predpostavlja, da polje vsebuje vsaj eno število.

## 6. Objekt `knjiga`

```javascript
const knjiga = {
  naslov: "Martin Krpan",
  avtor: "Fran Levstik",
  leto: 1858
};

console.log("Naslov:", knjiga.naslov);
console.log("Avtor:", knjiga.avtor);
console.log("Leto izdaje:", knjiga.leto);
```

Do lastnosti objekta dostopamo s piko, na primer `knjiga.naslov`.

## 7. Izpis imen polnoletnih oseb

```javascript
const osebe = [
  { ime: "Ana", starost: 22 },
  { ime: "Boris", starost: 16 },
  { ime: "Cene", starost: 35 }
];

for (let i = 0; i < osebe.length; i++) {
  if (osebe[i].starost >= 18) {
    console.log(osebe[i].ime);
  }
}
```

## 8. Funkcija `najdiNajstarejso(osebe)`

```javascript
function najdiNajstarejso(osebe) {
  if (osebe.length === 0) {
    return null;
  }

  let najstarejsa = osebe[0];

  for (let i = 1; i < osebe.length; i++) {
    if (osebe[i].starost > najstarejsa.starost) {
      najstarejsa = osebe[i];
    }
  }

  return najstarejsa;
}

const osebe = [
  { ime: "Ana", starost: 22 },
  { ime: "Boris", starost: 16 },
  { ime: "Cene", starost: 35 }
];

const najstarejsaOseba = najdiNajstarejso(osebe);
console.log(najstarejsaOseba);
```

Če je polje prazno, funkcija vrne `null`, ker v njem ni osebe, ki bi jo lahko vrnila.

## 9. Uporaba metode `filter()`

Metoda `filter()` ustvari novo polje z elementi, za katere podani pogoj velja.

```javascript
const osebe = [
  { ime: "Ana", starost: 22 },
  { ime: "Boris", starost: 16 },
  { ime: "Cene", starost: 35 }
];

const polnoletneOsebe = osebe.filter(oseba => oseba.starost >= 18);

console.log(polnoletneOsebe);
```

Za izpis samo imen polnoletnih oseb lahko uporabimo še zanko:

```javascript
for (let i = 0; i < polnoletneOsebe.length; i++) {
  console.log(polnoletneOsebe[i].ime);
}
```
