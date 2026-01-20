#include "constants.h"
#include <iostream>
#include <limits>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <exception>
#include <sstream>
#include <array>
#include <stack>
#include <queue>
#include <map>
#include <algorithm> 
using namespace std;

#ifdef PODATKOVNE_STRUKTURE_10
// ------------------------------------------------------------
// Isti osnovni podatki za vse primere
// ------------------------------------------------------------
struct Zapis {
    int id;
    std::string ime;
    int tocke;
};

static const std::array<Zapis, 6> skupniPodatki = { {
    {101, "Ana",   88},
    {102, "Boris", 92},
    {103, "Cene",  73},
    {104, "Dora",  92},
    {105, "Eva",   67},
    {106, "Filip", 88}
} };

// Pomožna funkcija: izpiše en zapis
void izpisiZapis(const Zapis& r) {
    std::cout << "  id=" << r.id
        << ", ime=" << std::setw(5) << std::left << r.ime
        << ", tocke=" << std::setw(3) << std::right << r.tocke
        << "\n";
}

// ------------------------------------------------------------
// 1) std::array
//    - ISTI podatki: fiksna velikost, enostavno iteriranje.
//    - PODATKI po meri: histogram (fiksno število predalčkov).
// ------------------------------------------------------------
void primerArray() {
    std::cout << "\n=== primerArray (std::array) ===\n";

    // Isti podatki: iteriranje po fiksno veliki tabeli
    std::cout << "Isti podatki (iteriranje po std::array<Record, N>):\n";
    int vsota = 0;

    std::size_t i;
    for (i = 0; i < skupniPodatki.size(); ++i) {
        izpisiZapis(skupniPodatki[i]);
        vsota += skupniPodatki[i].tocke;
    }

    std::cout << "Povprecje tock = " << (vsota / (int)skupniPodatki.size()) << "\n";

    // Podatki po meri: histogram točk po intervalih 10
    // 0-9, 10-19, ..., 90-100 (100 damo v zadnji predal)
    std::array<int, 10> predali = { {0,0,0,0,0,0,0,0,0,0} };

    for (i = 0; i < skupniPodatki.size(); ++i) {
        int indeks = skupniPodatki[i].tocke / 10;
        if (indeks > 9) indeks = 9;
        predali[indeks]++;
    }

    std::cout << "\nPodatki po meri (histogram tock):\n";
    int p;
    for (p = 0; p < 10; ++p) {
        int spodnja = p * 10;
        int zgornja = (p == 9) ? 100 : (p * 10 + 9);

        std::cout << std::setw(3) << spodnja << "-" << std::setw(3) << zgornja << " : ";

        int zvezdice;
        for (zvezdice = 0; zvezdice < predali[(std::size_t)p]; ++zvezdice) {
            std::cout << "###";
        }
        std::cout << " (" << predali[(std::size_t)p] << ")\n";
    }
}

// ------------------------------------------------------------
// 2) std::vector
//    - ISTI podatki: kopiranje in filtriranje.
//    - PODATKI po meri: dinamična rast (push_back), neznana velikost.
// ------------------------------------------------------------
void primerVector() {
    std::cout << "\n=== primerVector (std::vector) ===\n";

    // Isti podatki: kopiramo iz std::array v std::vector
    std::vector<Zapis> vektroVsehPodatkov(skupniPodatki.begin(), skupniPodatki.end());

    std::cout << "Isti podatki (filtriranje: tocke >= 85):\n";
    std::vector<Zapis> dobri;

    std::size_t i;
    for (i = 0; i < vektroVsehPodatkov.size(); ++i) {
        if (vektroVsehPodatkov[i].tocke >= 85) {
            dobri.push_back(vektroVsehPodatkov[i]);
        }
    }

    for (i = 0; i < dobri.size(); ++i) {
        izpisiZapis(dobri[i]);
    }

    // Podatki po meri: dinamična rast
    std::cout << "\nPodatki po meri (dinamicna rast z push_back):\n";
    std::vector<int> meritve;

    int podatki[] = { 585, 769, 588, 120, 253, 637, 668, 540, 948, 456, 426, 113, 746, 281, 185, 606, 205, 533, 650, 664, 591, 641, 260, 888, 947, 567 };
    int n = (int)(sizeof(podatki) / sizeof(podatki[0]));

    int k;
    for (k = 0; k < n; ++k) {
        meritve.push_back(podatki[k]);
        std::cout << "  dodal " << podatki[k]
            << ", size=" << meritve.size()
            << ", capacity=" << meritve.capacity() << "\n";
    }

    std::cout << "  meritve[3] = " << meritve[3] << " (nakljucni dostop)\n";
}

// ------------------------------------------------------------
// 3) std::stack (LIFO)
//    - ISTI podatki: obdelava v obratnem vrstnem redu.
//    - PODATKI po meri: zgodovina 'undo'.
// ------------------------------------------------------------
void primerStack() {
    std::cout << "\n=== primerStack (std::stack) ===\n";

    // Isti podatki: zadnji dodan gre ven prvi
    std::stack<Zapis> st;

    std::size_t i;
    for (i = 0; i < skupniPodatki.size(); ++i) {
        st.push(skupniPodatki[i]);
    }

    std::cout << "Isti podatki (LIFO: zadnji noter -> prvi ven):\n";
    while (!st.empty()) {
        izpisiZapis(st.top());
        st.pop();
    }

    // Podatki po meri: undo zgodovina
    std::cout << "\nPodatki po meri (Undo zgodovina):\n";
    std::stack<std::string> undo;

    undo.push("Vpisal: Pozdravljen");
    undo.push("Vpisal: Pozdravljen, svet");
    undo.push("Izbrisal: svet");
    undo.push("Vpisal: C++");

    std::cout << "Dejanja izvedena, zdaj razveljavljam:\n";
    while (!undo.empty()) {
        std::cout << "  undo -> " << undo.top() << "\n";
        undo.pop();
    }
}

// ------------------------------------------------------------
// 4) std::queue (FIFO)
//    - ISTI podatki: obdelava v vrstnem redu prihoda.
//    - PODATKI po meri: tiskalniška vrsta.
// ------------------------------------------------------------
void primerQueue() {
    std::cout << "\n=== primerQueue (std::queue) ===\n";

    std::queue<Zapis> q;

    std::size_t i;
    for (i = 0; i < skupniPodatki.size(); ++i) {
        q.push(skupniPodatki[i]);
    }

    std::cout << "Isti podatki (FIFO: prvi noter -> prvi ven):\n";
    while (!q.empty()) {
        izpisiZapis(q.front());
        q.pop();
    }

    // Podatki po meri: tiskalniška opravila
    std::cout << "\nPodatki po meri (Tiskalniska opravila):\n";
    std::queue<std::string> tisk;

    tisk.push("racun.pdf");
    tisk.push("porocilo.docx");
    tisk.push("shema.png");

    int stOpravila = 1;
    while (!tisk.empty()) {
        std::cout << "  tiskam opravilo #" << stOpravila << ": " << tisk.front() << "\n";
        stOpravila++;
        tisk.pop();
    }
}

// ------------------------------------------------------------
// 5) std::map (ključ -> vrednost, urejeno po ključu)
//    - ISTI podatki: indeksiranje po id (hitro iskanje po ključu).
//    - PODATKI po meri: frekvenčna tabela (štetje besed).
// ------------------------------------------------------------
void primerMap() {
    std::cout << "\n=== primerMap (std::map) ===\n";

    // Isti podatki: zgradimo mapo id -> Record
    std::map<int, Zapis> slovarPoID;

    std::size_t i;
    for (i = 0; i < skupniPodatki.size(); ++i) {
        slovarPoID[skupniPodatki[i].id] = skupniPodatki[i];
    }

    std::cout << "Isti podatki (urejeni ključi in izpis):\n";
    std::map<int, Zapis>::const_iterator it;
    for (it = slovarPoID.begin(); it != slovarPoID.end(); ++it) {
        std::cout << "kljuc=" << it->first << " ->\n";
        izpisiZapis(it->second);
    }

    // Iskanje po ključu
    int iskanId = 404;
    std::cout << "Iskanje zapisa z id=" << iskanId << ":\n";
    std::map<int, Zapis>::iterator najden = slovarPoID.find(iskanId);
    if (najden != slovarPoID.end()) {
        izpisiZapis(najden->second);
    }
    else {
        std::cout << "  ni najdeno\n";
    }

    // Podatki po meri: frekvenčna tabela besed
    std::cout << "\nPodatki po meri (frekvenca besed):\n";
    std::map<std::string, int> freq;

    std::string besede[] = { "macka", "pes", "macka", "ptica", "pes", "macka" };
    int n = (int)(sizeof(besede) / sizeof(besede[0]));

    int k;
    for (k = 0; k < n; ++k) {
        freq[besede[k]] = freq[besede[k]] + 1;
    }

    std::map<std::string, int>::const_iterator it2;
    for (it2 = freq.begin(); it2 != freq.end(); ++it2) {
        std::cout << "  " << std::setw(6) << std::left << it2->first
            << " -> " << it2->second << "\n";
    }
}

// ------------------------------------------------------------
// main: samo standardni vhod/izhod
// ------------------------------------------------------------
int main() {
    std::cout << "Demonstracija STL struktur (samo standardni IO)\n";

    primerArray();
    primerVector();
    primerStack();
    primerQueue();
    primerMap();

    std::cout << "\nKonec.\n";
    return 0;
}

#endif

#ifdef ITARATORJI_10

// ------------------------------------------------------------
// Primer 1: iteratorji na std::vector
// ------------------------------------------------------------
void primerVectorIteratorji() {
    std::cout << "=== std::vector + iteratorji ===\n";

    std::vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    // Branje elementov preko iteratorja
    std::cout << "Branje elementov:\n";
    std::vector<int>::const_iterator it;
    for (it = v.begin(); it != v.end(); ++it) {
        std::cout << "  " << *it << "\n";
    }

    // Spreminjanje elementov preko iteratorja
    std::cout << "Spreminjanje (vsak element +5):\n";
    std::vector<int>::iterator it2;
    for (it2 = v.begin(); it2 != v.end(); ++it2) {
        *it2 = *it2 + rand() % 10;
    }

    // Ponovni izpis
    std::cout << "Po spremembi:\n";
    for (it = v.begin(); it != v.end(); ++it) {
        std::cout << "  " << *it << "\n";
    }

    // Brisanje elementov med iteriranjem (primer: odstrani sode)
    std::cout << "Brisanje sodih elementov med iteriranjem:\n";
    std::vector<int>::iterator it3 = v.begin();
    while (it3 != v.end()) {
        if ((*it3 % 2) == 0) {
            // erase vrne iterator na naslednji element
            it3 = v.erase(it3);
        }
        else {
            ++it3;
        }
    }

    std::cout << "Po brisanju sodih:\n";
    for (it = v.begin(); it != v.end(); ++it) {
        std::cout << "  " << *it << "\n";
    }

    std::cout << "\n";
}

// ------------------------------------------------------------
// Primer 2: iteratorji na std::map
// ------------------------------------------------------------
void primerMapIteratorji() {
    std::cout << "=== std::map + iteratorji ===\n";

    // map: kljuc -> vrednost (urejeno po kljucu)
    std::map<std::string, int> ocene;
    ocene["Ana"] = 9;
    ocene["Boris"] = 8;
    ocene["Cene"] = 6;
    ocene["Dora"] = 10;

    // Iteriranje po mapi (it->first je ključ, it->second je vrednost)
    std::cout << "Izpis vseh parov (urejeno po kljucu):\n";
    std::map<std::string, int>::const_iterator it;
    for (it = ocene.begin(); it != ocene.end(); ++it) {
        std::cout << "  " << it->first << " -> " << it->second << "\n";
    }

    // Iskanje z iteratorjem
    std::cout << "Iskanje kljuca 'Cene':\n";
    std::map<std::string, int>::iterator najden = ocene.find("Cene");
    if (najden != ocene.end()) {
        std::cout << "  Najden: " << najden->first << " -> " << najden->second << "\n";
        std::cout << "  Povecam oceno za 1.\n";
        najden->second = najden->second + 1; // spreminjanje vrednosti preko iteratorja
    }
    else {
        std::cout << "  Ni najdeno.\n";
    }

    // Brisanje elementa preko iteratorja
    std::cout << "Brisanje kljuca 'Boris':\n";
    std::map<std::string, int>::iterator itB = ocene.find("Boris");
    if (itB != ocene.end()) {
        ocene.erase(itB); // brisanje z iteratorjem
    }

    // Končni izpis
    std::cout << "Končno stanje mape:\n";
    for (it = ocene.begin(); it != ocene.end(); ++it) {
        std::cout << "  " << it->first << " -> " << it->second << "\n";
    }

    std::cout << "\n";
}

int main() {
    std::cout << "Primeri iteratorjev na std::vector in std::map\n\n";

    primerVectorIteratorji();
    primerMapIteratorji();

    return 0;
}

#endif

#ifdef STD_ALGORITMI_10
#include <algorithm> // sort, find, count_if, transform, remove_if
#include <iterator>  // (ni nujno tukaj, a pogosto pride prav)

bool jeSodo(int x) {
    return (x % 2) == 0;
}

bool jeVecjeOd5(int x) {
    return x > 5;
}

int povecajZa10(int x) {
    return x + 10;
}

void izpisiVektor(const std::vector<int>& v, const std::string& naslov) {
    std::cout << naslov << "\n";
    std::vector<int>::const_iterator it;
    for (it = v.begin(); it != v.end(); ++it) {
        std::cout << "  " << *it << "\n";
    }
}

int main() {
    std::vector<int> v;
    v.push_back(7);
    v.push_back(2);
    v.push_back(9);
    v.push_back(2);
    v.push_back(6);
    v.push_back(1);

    izpisiVektor(v, "Zacetno stanje:");

    // 1) sort
    std::sort(v.begin(), v.end());
    izpisiVektor(v, "\nPo std::sort (urejeno):");

    // 2) find
    std::vector<int>::iterator najden = std::find(v.begin(), v.end(), 6);
    if (najden != v.end()) {
        std::cout << "\nstd::find: vrednost 6 je najdena.\n";
    }
    else {
        std::cout << "\nstd::find: vrednost 6 ni najdena.\n";
    }

    // 3) count_if
    int stSodih = (int)std::count_if(v.begin(), v.end(), jeSodo);
    std::cout << "\nstd::count_if: stevilo sodih = " << stSodih << "\n";

    // 3) count_if
    int vecjih = (int)std::count_if(v.begin(), v.end(), jeVecjeOd5);
    std::cout << "\nstd::count_if: večjih od 5 = " << vecjih << "\n";

    // 4) transform (v nov vektor)
    std::vector<int> vPlus10(v.size());
    std::transform(v.begin(), v.end(), vPlus10.begin(), povecajZa10);
    izpisiVektor(vPlus10, "\nPo std::transform (vsak element +10):");

    // 5) remove_if + erase (dejanski izbris)
    // remove_if premakne "nezelene" elemente na konec in vrne nov konec
    std::vector<int>::iterator novKonec = std::remove_if(v.begin(), v.end(), jeSodo);
    v.erase(novKonec, v.end());
    izpisiVektor(v, "\nPo remove_if+erase (odstranjeni sodi):");

    return 0;
}

#endif

#ifdef PODATKOVNE_STRUKTURE_ARRAY_10

// 1) Najbolj tipičen primer: fiksna velikost je znana vnaprej
//    -> std::array je “prava” tabela (brez dinamične alokacije), velikost je del tipa.
double povprecje3(const std::array<int, 3>& meritve) {
    int vsota = 0;
    std::size_t i;
    for (i = 0; i < meritve.size(); ++i) {
        vsota += meritve[i];
    }
    return vsota / (double)meritve.size();
}

// 2) Tipičen primer: lookup tabela (fiksno število elementov)
//    -> npr. dnevi v tednu ali število dni v mesecu.
int dneviVMesecu(int mesec) {
    // mesec: 1..12
    static const std::array<int, 12> dni = { {31,28,31,30,31,30,31,31,30,31,30,31} };
    if (mesec < 1 || mesec > 12) return -1;
    return dni[(std::size_t)(mesec - 1)];
}

// 3) Tipičen primer: fiksni “buffer” (npr. branje kosov podatkov)
//    -> pokaže, da je velikost stalna in se ne spreminja.
void obdelajVBlokih(const int* podatki, int n) {
    std::array<int, 4> blok; // vedno obdelujemo po 4 elemente
    int i = 0;

    while (i < n) {
        // napolni blok (manjkajoče napolni z 0)
        int j;
        for (j = 0; j < (int)blok.size(); ++j) {
            if (i + j < n) blok[(std::size_t)j] = podatki[i + j];
            else blok[(std::size_t)j] = 0;
        }

        // “obdelava” bloka: samo izpis in vsota
        int vsota = 0;
        std::cout << "Blok: ";
        for (j = 0; j < (int)blok.size(); ++j) {
            std::cout << blok[(std::size_t)j] << " ";
            vsota += blok[(std::size_t)j];
        }
        std::cout << " | vsota=" << vsota << "\n";

        i += (int)blok.size();
    }
}

int main() {
    std::cout << "Primeri, kdaj je std::array dobra izbira\n\n";

    // Case 1: fiksno število meritev (npr. 3 meritve senzorja)
    std::array<int, 3> senzor = { {12, 15, 14} };
    std::cout << "1) Povprecje 3 meritev: " << povprecje3(senzor) << "\n\n";

    // Case 2: lookup tabela (dni v mesecu)
    std::cout << "2) Dnevi v februarju: " << dneviVMesecu(2) << "\n";
    std::cout << "   Dnevi v oktobru:   " << dneviVMesecu(10) << "\n\n";

    // Case 3: fiksni buffer za obdelavo po blokih
    int podatki[] = { 5, 8, 13, 21, 34, 55, 89 };
    int n = (int)(sizeof(podatki) / sizeof(podatki[0]));
    std::cout << "3) Obdelava po blokih (velikost bloka je fiksna):\n";
    obdelajVBlokih(podatki, n);

    return 0;
}

#endif

#ifdef PODATKOVNE_STRUKTURE_VECTOR_10

// 1) Tipičen primer: število elementov ni znano vnaprej (dinamična rast)
void primerDinamicnaRast() {
    std::cout << "=== 1) Dinamicna rast (neznano stevilo elementov) ===\n";

    std::vector<int> v;
    int x;

    std::cout << "Vnesi nekaj celih stevil (0 konca vnos):\n";
    while (true) {
        std::cout << "> ";
        if (!(std::cin >> x)) {
            std::cout << "Napaka pri branju.\n";
            return;
        }
        if (x == 0) break;
        v.push_back(x);
    }

    std::cout << "Vnesel si " << v.size() << " stevil:\n";
    std::size_t i;
    for (i = 0; i < v.size(); ++i) {
        std::cout << "  v[" << i << "] = " << v[i] << "\n";
    }
    std::cout << "\n";
}

// 2) Tipičen primer: delo z algoritmi + iteriranje (sort, filter)
//    (vector je idealen za std::sort, ker ima naključni dostop)
void primerSortInFilter() {
    std::cout << "=== 2) Sort + filter (STL algoritmi) ===\n";

    std::vector<int> v;
    v.push_back(7);
    v.push_back(2);
    v.push_back(9);
    v.push_back(2);
    v.push_back(6);
    v.push_back(1);

    std::cout << "Zacetno:\n";
    std::size_t i;
    for (i = 0; i < v.size(); ++i) std::cout << "  " << v[i] << "\n";

    std::sort(v.begin(), v.end());

    std::cout << "Po std::sort:\n";
    for (i = 0; i < v.size(); ++i) std::cout << "  " << v[i] << "\n";

    // Filter: samo elementi >= 5
    std::vector<int> filtrirano;
    for (i = 0; i < v.size(); ++i) {
        if (v[i] >= 5) filtrirano.push_back(v[i]);
    }

    std::cout << "Filtrirano (>=5):\n";
    for (i = 0; i < filtrirano.size(); ++i) std::cout << "  " << filtrirano[i] << "\n";
    std::cout << "\n";
}

// 3) Tipičen primer: “tabela” objektov (npr. zapisi) + iskanje po podatkih
struct Student {
    std::string ime;
    int ocena;
};

int najdiStudenta(const std::vector<Student>& studenti, const std::string& ime) {
    std::size_t i;
    for (i = 0; i < studenti.size(); ++i) {
        if (studenti[i].ime == ime) return (int)i;
    }
    return -1;
}

void primerSeznamObjektov() {
    std::cout << "=== 3) Seznam objektov (vector kot privzeti seznam) ===\n";

    std::vector<Student> studenti;
    Student s;

    s.ime = "Ana";   s.ocena = 9;  studenti.push_back(s);
    s.ime = "Boris"; s.ocena = 8;  studenti.push_back(s);
    s.ime = "Cene";  s.ocena = 6;  studenti.push_back(s);

    std::cout << "Studenti:\n";
    std::size_t i;
    for (i = 0; i < studenti.size(); ++i) {
        std::cout << "  " << studenti[i].ime << " -> " << studenti[i].ocena << "\n";
    }

    std::string iskano = "Boris";
    int idx = najdiStudenta(studenti, iskano);
    if (idx >= 0) {
        std::cout << "Najden '" << iskano << "' na indeksu " << idx
            << ", ocena=" << studenti[(std::size_t)idx].ocena << "\n";
    }
    else {
        std::cout << "Student '" << iskano << "' ni najden.\n";
    }

    std::cout << "\n";
}

int main() {
    std::cout << "Primeri, kdaj je std::vector dobra izbira\n\n";

    primerDinamicnaRast();   // vnos uporabnika, neznana velikost
    primerSortInFilter();    // algoritmi + sort
    primerSeznamObjektov();  // seznam zapisov/objektov

    return 0;
}

#endif

#ifdef PODATKOVNE_STRUKTURE_STACK_10

// 1) Tipičen primer: razveljavljanje (UNDO) - LIFO
void primerUndo() {
    std::cout << "=== 1) UNDO zgodovina (LIFO) ===\n";

    std::stack<std::string> undo;

    // Uporabnik "naredi" nekaj korakov (push)
    undo.push("Vpisal: Pozdravljen");
    undo.push("Vpisal: Pozdravljen, svet");
    undo.push("Izbrisal: svet");
    undo.push("Vpisal: C++");

    std::cout << "Zgodovina dejanj (zadnje je na vrhu):\n";
    std::cout << "Zdaj razveljavljam:\n";

    // Razveljavljanje gre v obratnem vrstnem redu (pop)
    while (!undo.empty()) {
        std::cout << "  undo -> " << undo.top() << "\n";
        undo.pop();
    }

    std::cout << "\n";
}

// 2) Tipičen primer: preverjanje pravilnih oklepajev ((), [], {})
//    Ideja: ob odprtem oklepaju push, ob zaprtem preveri top in pop.
bool jeOdprtiOklepaj(char c) {
    return (c == '(') || (c == '[') || (c == '{');
}

bool seUjemata(char odprti, char zaprti) {
    if (odprti == '(' && zaprti == ')') return true;
    if (odprti == '[' && zaprti == ']') return true;
    if (odprti == '{' && zaprti == '}') return true;
    return false;
}

bool oklepajiPravilni(const std::string& s) {
    std::stack<char> st;

    std::size_t i;
    for (i = 0; i < s.size(); ++i) {
        char c = s[i];

        if (jeOdprtiOklepaj(c)) {
            st.push(c);
        }
        else if (c == ')' || c == ']' || c == '}') {
            if (st.empty()) return false;           // ni para
            if (!seUjemata(st.top(), c)) return false; // napačen par
            st.pop();
        }
    }

    return st.empty(); // če kaj ostane odprto, ni pravilno
}

void primerOklepaji() {
    std::cout << "=== 2) Preverjanje oklepajev (LIFO) ===\n";

    std::string a = "a*(b+c) - [d/{e+f}]";
    std::string b = "a*(b+c]"; // napaka: ) in ] se ne ujemata

    std::cout << "Niz: " << a << "\n";
    std::cout << "  pravilni oklepaji? " << (oklepajiPravilni(a) ? "DA" : "NE") << "\n";

    std::cout << "Niz: " << b << "\n";
    std::cout << "  pravilni oklepaji? " << (oklepajiPravilni(b) ? "DA" : "NE") << "\n";

    std::cout << "\n";
}

int main() {
    std::cout << "Primeri, kdaj je std::stack dobra izbira\n\n";

    primerUndo();       // LIFO: undo zgodovina
    primerOklepaji();   // LIFO: preverjanje oklepajev

    return 0;
}

#endif

#ifdef PODATKOVNE_STRUKTURE_QUEUE_10

// 1) Tipičen primer: čakalna vrsta opravil (FIFO)
void primerOpravila() {
    std::cout << "=== 1) Cakalna vrsta opravil (FIFO) ===\n";

    std::queue<std::string> opravila;

    // Opravila prihajajo v vrsto
    opravila.push("Natisni racun");
    opravila.push("Poslji e-mail");
    opravila.push("Shrani porocilo");
    opravila.push("Nalozi podatke");

    int st = 1;
    while (!opravila.empty()) {
        std::cout << "  obdelujem #" << st << ": " << opravila.front() << "\n";
        opravila.pop();
        st++;
    }

    std::cout << "\n";
}

// 2) Tipičen primer: simulacija vrste strank (FIFO)
struct Stranka {
    std::string ime;
    int cas; // koliko "sekund" traja obdelava
};

void primerStranke() {
    std::cout << "=== 2) Vrsta strank (FIFO) ===\n";

    std::queue<Stranka> vrsta;

    Stranka s;
    s.ime = "Ana";   s.cas = 3; vrsta.push(s);
    s.ime = "Boris"; s.cas = 2; vrsta.push(s);
    s.ime = "Cene";  s.cas = 4; vrsta.push(s);

    int skupniCas = 0;

    while (!vrsta.empty()) {
        Stranka trenutna = vrsta.front();
        vrsta.pop();

        std::cout << "  obdelujem: " << trenutna.ime
            << " (cas=" << trenutna.cas << ")\n";

        skupniCas += trenutna.cas;
        std::cout << "  skupni porabljeni cas do zdaj: " << skupniCas << "\n";
    }

    std::cout << "Skupni cas: " << skupniCas << "\n\n";
}

int main() {
    std::cout << "Primeri, kdaj je std::queue dobra izbira\n\n";

    primerOpravila(); // FIFO: opravila v vrstnem redu prihoda
    primerStranke();  // FIFO: simulacija vrste strank

    return 0;
}

#endif

#ifdef PODATKOVNE_STRUKTURE_MAP_10

// 1) Tipičen primer: slovar / imenik (kljuc -> vrednost) + hitro iskanje po kljucu
void primerImenik() {
    std::cout << "=== 1) Imenik (kljuc -> vrednost) ===\n";

    // ključ: ime, vrednost: telefonska številka
    std::map<std::string, std::string> imenik;

    imenik["Ana"] = "040-111-222";
    imenik["Boris"] = "031-333-444";
    imenik["Cene"] = "051-555-666";

    // iteriranje (map je urejen po ključu)
    std::cout << "Vsi kontakti (urejeno po imenu):\n";
    std::map<std::string, std::string>::const_iterator it;
    for (it = imenik.begin(); it != imenik.end(); ++it) {
        std::cout << "  " << it->first << " -> " << it->second << "\n";
    }

    // iskanje po ključu
    std::cout << "Iskanje 'Boris':\n";
    std::map<std::string, std::string>::iterator najden = imenik.find("Boris");
    if (najden != imenik.end()) {
        std::cout << "  najden: " << najden->first << " -> " << najden->second << "\n";
    }
    else {
        std::cout << "  ni najden.\n";
    }

    std::cout << "\n";
}

// 2) Tipičen primer: frekvencna tabela (štetje pojavitev)
//    map je super, ker freq[kljuc] privzeto ustvari element z 0, potem povečamo.
void primerFrekvencaBesed() {
    std::cout << "=== 2) Frekvencna tabela (stetje) ===\n";

    std::string besede[] = { "macka", "pes", "macka", "ptica", "pes", "macka" };
    int n = (int)(sizeof(besede) / sizeof(besede[0]));

    std::map<std::string, int> freq;

    int i;
    for (i = 0; i < n; ++i) {
        freq[besede[i]] = freq[besede[i]] + 1;
    }

    std::cout << "Frekvence (urejeno po kljucu):\n";
    std::map<std::string, int>::const_iterator it;
    for (it = freq.begin(); it != freq.end(); ++it) {
        std::cout << "  " << it->first << " -> " << it->second << "\n";
    }

    std::cout << "\n";
}

// 3) Tipičen primer: podatki urejeni po ključu + iskanje po obmocju (range)
//    To je glavna prednost map napram unordered_map: lahko dobiš vse v [od..do].
void primerRangeIskanje() {
    std::cout << "=== 3) Range iskanje (kljuci v obmocju) ===\n";

    // ključ: leto, vrednost: opis dogodka
    std::map<int, std::string> dogodki;
    dogodki[2019] = "Vpis na fakulteto";
    dogodki[2020] = "Prva sluzba";
    dogodki[2022] = "Napredovanje";
    dogodki[2024] = "Selitev";
    dogodki[2025] = "Novi projekt";

    int od = 2020;
    int doVklj = 2024;

    // lower_bound(od) -> prvi ključ >= od
    // upper_bound(doVklj) -> prvi ključ > doVklj
    std::map<int, std::string>::iterator zacetek = dogodki.lower_bound(od);
    std::map<int, std::string>::iterator konec = dogodki.upper_bound(doVklj);

    std::cout << "Dogodki v letih [" << od << ".." << doVklj << "]:\n";

    std::map<int, std::string>::iterator it;
    for (it = zacetek; it != konec; ++it) {
        std::cout << "  " << it->first << " -> " << it->second << "\n";
    }

    std::cout << "\n";
}

int main() {
    std::cout << "Primeri, kdaj je std::map dobra izbira\n\n";

    primerImenik();           // kljuc -> vrednost + find
    primerFrekvencaBesed();   // stetje pojavitev
    primerRangeIskanje();     // range query po kljucih

    return 0;
}

#endif

#ifdef PODATKOVNE_STRUKTURE_ALGORITMI_10

// ---------- pomožne funkcije ----------
void izpisiInt(int x) {
    std::cout << x << " ";
}

bool jeSodo(int x) {
    return (x % 2) == 0;
}

int krat2(int x) {
    return x * 2;
}

// For_each funkcija za map: sprejme par (key,value)
void izpisiPar(const std::pair<const std::string, int>& p) {
    std::cout << p.first << " -> " << p.second << "\n";
}

void izpisiVektor(const std::vector<int>& v, const std::string& naslov) {
    std::cout << naslov << "\n";
    std::for_each(v.begin(), v.end(), izpisiInt);
    std::cout << "\n\n";
}

// ---------- demo ----------
int main() {
    std::cout << "STL algoritmi + kontejnerji (array/vector/map)\n\n";

    // Izhodiščni podatki v std::array (fiksna velikost)
    std::array<int, 10> a = { {7, 2, 9, 2, 6, 1, 8, 3, 2, 5} };

    // -------------------------
    // std::copy (array -> vector)
    // -------------------------
    std::vector<int> v;
    v.resize(a.size()); // pripravimo prostor
    std::copy(a.begin(), a.end(), v.begin());
    izpisiVektor(v, "Po std::copy (array -> vector):");

    // -------------------------
    // std::sort (urejanje: vector ima naključni dostop)
    // -------------------------
    std::sort(v.begin(), v.end());
    izpisiVektor(v, "Po std::sort (urejeno):");

    // -------------------------
    // std::find (prva pojavitev)
    // -------------------------
    std::vector<int>::iterator itNajden = std::find(v.begin(), v.end(), 6);
    if (itNajden != v.end()) {
        std::cout << "std::find: element 6 najden.\n\n";
    }
    else {
        std::cout << "std::find: element 6 ni najden.\n\n";
    }

    // -------------------------
    // std::count_if (štetje po pogoju)
    // -------------------------
    int stSodih = (int)std::count_if(v.begin(), v.end(), jeSodo);
    std::cout << "std::count_if: stevilo sodih elementov = " << stSodih << "\n\n";

    // (Opcijsko: std::count, štetje točne vrednosti)
    int stDvojk = (int)std::count(v.begin(), v.end(), 2);
    std::cout << "std::count: stevilo pojavitev vrednosti 2 = " << stDvojk << "\n\n";

    // -------------------------
    // std::for_each (izvede funkcijo nad vsakim elementom)
    // (Tukaj ga uporabimo samo za izpis v eni vrstici.)
    // -------------------------
    std::cout << "std::for_each: izpis elementov:\n  ";
    std::for_each(v.begin(), v.end(), izpisiInt);
    std::cout << "\n\n";

    // -------------------------
    // std::transform (pretvori elemente)
    // npr. vsak element *2 -> v nov vector
    // -------------------------
    std::vector<int> v2;
    v2.resize(v.size());
    std::transform(v.begin(), v.end(), v2.begin(), krat2);
    izpisiVektor(v2, "std::transform (vsak element *2) -> nov vektor:");

    // -------------------------
    // std::remove_if + erase (dejanski izbris)
    // odstranimo sode elemente iz v
    // -------------------------
    std::vector<int>::iterator novKonec = std::remove_if(v.begin(), v.end(), jeSodo);
    v.erase(novKonec, v.end());
    izpisiVektor(v, "std::remove_if + erase (odstranjeni sodi):");

    // -------------------------
    // std::map + frekvenčna tabela
    // (Pokažemo še algoritem std::for_each na map)
    // -------------------------
    std::map<std::string, int> freq;
    std::string besede[] = { "macka", "pes", "macka", "ptica", "pes", "macka" };
    int n = (int)(sizeof(besede) / sizeof(besede[0]));

    int i;
    for (i = 0; i < n; ++i) {
        freq[besede[i]] = freq[besede[i]] + 1;
    }

    std::cout << "std::map (frekvence besed) + std::for_each (izpis parov):\n";
    std::for_each(freq.begin(), freq.end(), izpisiPar);
    std::cout << "\n";

    return 0;
}

#endif