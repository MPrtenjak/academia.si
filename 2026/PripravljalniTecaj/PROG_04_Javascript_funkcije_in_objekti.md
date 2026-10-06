# JavaScript: funkcije in objekti

## Funkcije

**Funkcija** je poimenovan del programa, ki opravi določeno nalogo. Funkcije pomagajo, da kode ne ponavljamo in jo lažje razumemo.

```javascript
function pozdravi() {
  console.log("Pozdrav!");
}

pozdravi();
```

Funkcijo najprej definiramo, nato jo pokličemo.

## Parametri in rezultat

Funkcija lahko prejme podatke kot **parametre**:

```javascript
function pozdraviOsebo(ime) {
  console.log("Pozdrav, " + ime + "!");
}

pozdraviOsebo("Ana");
```

Funkcija lahko z `return` vrne rezultat:

```javascript
function sestej(prvoStevilo, drugoStevilo) {
  return prvoStevilo + drugoStevilo;
}

const rezultat = sestej(4, 7);
console.log(rezultat); // 11
```

`console.log` rezultat le izpiše, `return` pa vrednost vrne tja, kjer smo funkcijo poklicali.

## Lokalna spremenljivka

Spremenljivka, ustvarjena znotraj funkcije, je praviloma dostopna le v tej funkciji.

```javascript
function izracunaj() {
  const rezultat = 5 + 3;
  return rezultat;
}
```

## Objekti

**Objekt** združi podatke, ki opisujejo isto stvar.

```javascript
const oseba = {
  ime: "Ana",
  starost: 25,
  kraj: "Celje"
};
```

Podatek v objektu imenujemo **lastnost**. Do lastnosti dostopamo s piko:

```javascript
console.log(oseba.ime);
console.log(oseba.starost);
```

Lastnost lahko spremenimo ali dodamo:

```javascript
oseba.starost = 26;
oseba.poklic = "učiteljica";
```

## Polje objektov

Polje lahko vsebuje tudi objekte:

```javascript
const osebe = [
  { ime: "Ana", starost: 25 },
  { ime: "Bor", starost: 17 },
  { ime: "Cene", starost: 30 }
];
```

Objekte v polju obdelamo z zanko:

```javascript
for (let indeks = 0; indeks < osebe.length; indeks++) {
  const oseba = osebe[indeks];
  console.log(oseba.ime + ": " + oseba.starost);
}
```

## Povezovanje znanja

Funkcija lahko prejme polje in ga obdela:

```javascript
function izracunajVsoto(stevila) {
  let vsota = 0;

  for (let indeks = 0; indeks < stevila.length; indeks++) {
    vsota = vsota + stevila[indeks];
  }

  return vsota;
}
```

## Povzetek

- Funkcija združi kodo za eno nalogo.
- Parametri so vhodni podatki funkcije.
- `return` vrne rezultat funkcije.
- Objekt združi povezane lastnosti ene stvari.
- Polje objektov omogoča obdelavo več podobnih stvari.

## Naloge

1. Napiši funkcijo `izpisiPozdrav()`, ki izpiše kratek pozdrav.
2. Napiši funkcijo `pozdravi(ime)`, ki izpiše pozdrav z danim imenom.
3. Napiši funkcijo `kvadrat(stevilo)`, ki vrne kvadrat števila.
4. Napiši funkcijo `jePolnoleten(starost)`, ki vrne `true` ali `false`.
5. Napiši funkcijo `izracunajPovprecje(stevila)`, ki za polje števil vrne povprečje.
6. Ustvari objekt `knjiga` z lastnostmi `naslov`, `avtor` in `leto`, nato jih izpiši.
7. Ustvari polje treh objektov oseb z lastnostma `ime` in `starost`; izpiši imena polnoletnih oseb.
8. **Razširitvena naloga:** Napiši funkcijo `najdiNajstarejso(osebe)`, ki iz polja oseb vrne objekt najstarejše osebe.
9. **Razširitvena naloga:** Poišči metodo `filter()` in z njo ustvari novo polje samo polnoletnih oseb.

## Preveri razumevanje

1. Zakaj uporabljamo funkcije?
2. Kakšna je razlika med parametrom in vrednostjo, ki jo funkcija vrne z `return`?
3. Kaj je lokalna spremenljivka?
4. Kaj je objekt v JavaScriptu?
5. Kako dostopamo do lastnosti `ime` v objektu `oseba`?
