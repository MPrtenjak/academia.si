# Markdown – hitro oblikovanje besedila

## Markdown "editor"-ji

* [dillinger.io](https://dillinger.io) ~ https://dillinger.io
* [stackedit.io](https://stackedit.io/) ~ https://stackedit.io
* [markdownlivepreview.com](https://markdownlivepreview.com/) ~ https://markdownlivepreview.com
* ...

## Kaj je Markdown?

**Markdown** je preprost način zapisa oblikovanega besedila v navadni besedilni datoteki.

Namesto gumbov za krepko besedilo, naslove in sezname uporabimo nekaj znakov s tipkovnice. Besedilo Markdown se pogosto shrani v datoteko s končnico `.md`.

Markdown uporabljajo na primer GitHub, GitLab, dokumentacija za programe, zapiski in spletne strani.

```text
# Moj naslov

To je **pomembna** beseda.
```

Prikazano besedilo se oblikuje kot naslov in odstavek s krepko besedo.

## Osnovno pravilo

Markdown je navadno besedilo, v katerem posebni znaki pomenijo oblikovanje.

| Zapis | Pomen |
|---|---|
| `#` | naslov |
| `*` ali `_` | poudarek |
| `-` | element seznama |
| `[besedilo](naslov)` | povezava |
| `` ` `` | kratek del kode |

## Naslovi

Naslove ustvarimo z znakom `#` na začetku vrstice. Več znakov pomeni nižjo raven naslova.

```markdown
# Glavni naslov
## Poglavje
### Podpoglavje
```

# Glavni naslov

## Poglavje

### Podpoglavje

Za običajne zapiske večinoma zadostujejo ravni `#`, `##` in `###`.

## Odstavki in prelomi vrstic

Odstavke ločimo s prazno vrstico.

```markdown
To je prvi odstavek.

To je drugi odstavek.
```

Če samo pritisnemo Enter, se vrstici v mnogih prikazovalnikih združita v isti odstavek. Prazna vrstica zato pomeni: »začni nov odstavek«.

## Krepko, ležeče in prečrtano besedilo

```markdown
**krepko besedilo**

*ležeče besedilo*

~~prečrtano besedilo~~
```

Prikaz:

- **krepko besedilo**
- *ležeče besedilo*
- ~~prečrtano besedilo~~

Krepko besedilo uporabljamo za pomembne pojme. Poudarkov ne uporabljamo prepogosto, saj potem nič več ne izstopa.

## Seznami

### Neoštevilčen seznam

Pred vsak element dodamo `-` in presledek.

```markdown
- tipkovnica
- miška
- zaslon
```

- tipkovnica
- miška
- zaslon

### Oštevilčen seznam

```markdown
1. Odpri datoteko.
2. Vpiši besedilo.
3. Shrani datoteko.
```

1. Odpri datoteko.
2. Vpiši besedilo.
3. Shrani datoteko.

Za podseznam pred element dodamo zamik, na primer dva ali štiri presledke.

```markdown
- Računalnik
  - strojna oprema
  - programska oprema
```

## Povezave in slike

### Povezava

```markdown
[Obišči Wikipedijo](https://www.wikipedia.org/)
```

Rezultat: [Obišči Wikipedijo](https://www.wikipedia.org/)

Besedilo v oglatih oklepajih je vidno besedilo povezave. Naslov spletne strani je v okroglih oklepajih.

### Slika

Slika ima skoraj enak zapis kot povezava, pred njo pa je klicaj.

```markdown
![Opis slike](slika.jpg)
```

Opis slike pomaga razumeti vsebino, če se slika ne prikaže.

## Koda

Za kratko ime ukaza, datoteke ali programskega izraza uporabimo enojne povratne narekovaje.

```markdown
Datoteko shranimo kot `zapiske.md`.
```

Datoteko shranimo kot `zapiske.md`.

Za več vrstic kode uporabimo tri povratne narekovaje pred in po kodi.

````markdown
```csharp
Console.WriteLine("Pozdrav!");
```
````

Tako lahko prikažemo kodo, ne da bi jo Markdown poskušal oblikovati kot običajno besedilo. Za začetkom treh narekovajev lahko zapišemo tudi jezik, na primer `csharp`, `html` ali `python`.

## Citati in vodoravna črta

### Citat

```markdown
> Najboljši način učenja je vaja.
```

> Najboljši način učenja je vaja.

### Vodoravna črta

Tri vezaje na samostojni vrstici ustvarijo ločilno črto.

```markdown
---
```

---

## Tabele

Tabele so uporabne za kratke primerjave.

```markdown
| Del | Naloga |
|---|---|
| CPU | Izvaja navodila |
| RAM | Hrani trenutno delo |
```

| Del | Naloga |
|---|---|
| CPU | Izvaja navodila |
| RAM | Hrani trenutno delo |

Vrstica z vezaji pod naslovoma je obvezna. Stolpce ločimo z navpično črto `|`.

## Kratek primer celotnega zapisa

```markdown
# Moj računalnik

## Pomembni deli

- **CPU** izvaja navodila.
- **RAM** hrani trenutno delo.

Več o računalnikih: [Wikipedija](https://sl.wikipedia.org/wiki/Ra%C4%8Dunalnik).

> Datoteko shranim kot `zapiske.md`.
```

## Povzetek

Za osnovne zapiske je dovolj, da znamo uporabljati:

- naslove z `#`,
- odstavke in sezname,
- krepko ter ležeče besedilo,
- povezave in slike,
- prikaz kode,
- citate in tabele.

## Preveri razumevanje

1. Katero končnico običajno uporabljajo datoteke Markdown?
2. Kako zapišemo naslov druge ravni?
3. Kako zapišemo krepko besedilo?
4. Kakšna je razlika med povezavo in sliko v Markdownu?
5. Kdaj uporabimo tri povratne narekovaje?
