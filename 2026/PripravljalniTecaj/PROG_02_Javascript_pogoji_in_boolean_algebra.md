# JavaScript: pogoji in Boolean algebra

## Odločanje v programu

Program se lahko glede na podatke odloči, katero pot bo izvedel. Za to uporabimo pogojni stavek `if`.

```javascript
const starost = 19;

if (starost >= 18) {
  console.log("Polnoletna oseba");
} else {
  console.log("Mladoletna oseba");
}
```

Pogoj med oklepajema mora imeti vrednost `true` ali `false`.

## Primerjalni operatorji

| Operator | Pomen |
|---|---|
| `===` | je enako |
| `!==` | ni enako |
| `>` | je večje od |
| `<` | je manjše od |
| `>=` | je večje ali enako |
| `<=` | je manjše ali enako |

Uporabljajmo `===`, ne `==`, ker `===` primerja tudi tip vrednosti.

```javascript
console.log(5 === 5);   // true
console.log(5 === "5"); // false
```

## `if`, `else if` in `else`

```javascript
const ocena = 8;

if (ocena >= 9) {
  console.log("Odlično");
} else if (ocena >= 6) {
  console.log("Opravljeno");
} else {
  console.log("Ni opravljeno");
}
```

Pogoje preverjamo od zgoraj navzdol. Izvede se prva ustrezna veja.

## Boolean vrednosti in operatorji

Boolean vrednost ima samo dve možnosti: `true` ali `false`.

| Operator | Pomen | Primer |
|---|---|---|
| `&&` | in: oba pogoja morata veljati | `starost >= 18 && imaVstopnico` |
| `||` | ali: veljati mora vsaj en pogoj | `jeVikend || jePraznik` |
| `!` | ne: obrne vrednost | `!jeZaprt` |

```javascript
const imaVstopnico = true;
const starost = 17;

if (imaVstopnico && starost >= 15) {
  console.log("Vstop dovoljen");
}
```

## Logična tabela

| A | B | `A && B` | `A \|\| B` |
|---|---|---|---|
| `false` | `false` | `false` | `false` |
| `false` | `true` | `false` | `true` |
| `true` | `false` | `false` | `true` |
| `true` | `true` | `true` | `true` |

## Primer: sodo ali liho število

```javascript
const stevilo = 14;

if (stevilo % 2 === 0) {
  console.log("Število je sodo.");
} else {
  console.log("Število je liho.");
}
```

## Povzetek

- Pogoji omogočajo, da program izbere ustrezno pot.
- Primerjave vrnejo `true` ali `false`.
- `&&` pomeni in, `||` pomeni ali, `!` pa ne.
- Veje pišemo z `if`, `else if` in `else`.

## Naloge

1. Za dano število izpiši, ali je pozitivno, negativno ali enako nič.
2. Za dano starost izpiši, ali je oseba polnoletna.
3. Za dano število izpiši, ali je sodo ali liho.
4. Za dve števili izpiši večje število oziroma sporočilo, da sta enaki.
5. Za oceno od 1 do 10 izpiši `opravljeno`, če je ocena vsaj 6, sicer `ni opravljeno`.
6. Za temperaturo izpiši `mraz`, `prijetno` ali `vroče`; meje določi smiselno sam.
7. Za uporabniško ime in geslo izpiši `prijava uspešna` le, če sta oba pravilna.
8. **Razširitvena naloga:** S `prompt()` preberi starost uporabnika. Poišči, zakaj je potreben `Number(prompt(...))`, nato izpiši, ali je oseba polnoletna.
9. **Razširitvena naloga:** Uporabi pogojni operator `? :` in z njim izpiši, ali je število sodo ali liho.

## Preveri razumevanje

1. Kaj mora vrniti pogoj v stavku `if`?
2. Zakaj je bolje uporabiti `===` kot `==`?
3. Kdaj je izraz z `&&` resničen?
4. Kdaj je izraz z `||` resničen?
5. Kako program izbere vejo `else if`?
