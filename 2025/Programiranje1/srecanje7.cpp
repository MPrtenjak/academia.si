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
using namespace std;

#ifdef PODATKOVNE_STRUKTURE_10
// ------------------------------------------------------------
// Isti osnovni podatki za vse primere
// ------------------------------------------------------------
struct Record {
    int id;
    std::string ime;
    int tocke;
};

static const std::array<Record, 6> skupniPodatki = { {
    {101, "Ana",   88},
    {102, "Boris", 92},
    {103, "Cene",  73},
    {104, "Dora",  92},
    {105, "Eva",   67},
    {106, "Filip", 88}
} };

// Pomožna funkcija: izpiše en zapis
void izpisiRecord(const Record& r) {
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
        izpisiRecord(skupniPodatki[i]);
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
            std::cout << '*';
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
    std::vector<Record> v(skupniPodatki.begin(), skupniPodatki.end());

    std::cout << "Isti podatki (filtriranje: tocke >= 85):\n";
    std::vector<Record> dobri;

    std::size_t i;
    for (i = 0; i < v.size(); ++i) {
        if (v[i].tocke >= 85) {
            dobri.push_back(v[i]);
        }
    }

    for (i = 0; i < dobri.size(); ++i) {
        izpisiRecord(dobri[i]);
    }

    // Podatki po meri: dinamična rast
    std::cout << "\nPodatki po meri (dinamicna rast z push_back):\n";
    std::vector<int> meritve;

    int podatki[] = { 585, 769, 588, 120, 253, 637, 668, 540, 948, 456, 426, 113, 746, 281, 185, 606, 205, 533, 650, 664, 591, 641, 260 };
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
    std::stack<Record> st;

    std::size_t i;
    for (i = 0; i < skupniPodatki.size(); ++i) {
        st.push(skupniPodatki[i]);
    }

    std::cout << "Isti podatki (LIFO: zadnji noter -> prvi ven):\n";
    while (!st.empty()) {
        izpisiRecord(st.top());
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

    std::queue<Record> q;

    std::size_t i;
    for (i = 0; i < skupniPodatki.size(); ++i) {
        q.push(skupniPodatki[i]);
    }

    std::cout << "Isti podatki (FIFO: prvi noter -> prvi ven):\n";
    while (!q.empty()) {
        izpisiRecord(q.front());
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
    std::map<int, Record> poId;

    std::size_t i;
    for (i = 0; i < skupniPodatki.size(); ++i) {
        poId[skupniPodatki[i].id] = skupniPodatki[i];
    }

    std::cout << "Isti podatki (urejeni ključi in izpis):\n";
    std::map<int, Record>::const_iterator it;
    for (it = poId.begin(); it != poId.end(); ++it) {
        std::cout << "kljuc=" << it->first << " ->\n";
        izpisiRecord(it->second);
    }

    // Iskanje po ključu
    int iskanId = 104;
    std::cout << "Iskanje zapisa z id=" << iskanId << ":\n";
    std::map<int, Record>::iterator najden = poId.find(iskanId);
    if (najden != poId.end()) {
        izpisiRecord(najden->second);
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
        *it2 = *it2 + 5;
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