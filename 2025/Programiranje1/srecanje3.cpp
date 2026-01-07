#include <iostream>
#include <limits>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

#define REKURZIVNE_FUNKCIJE_3x

#ifdef POLJA_1
int main() {
    int a[5];

	a[0] = 10;
	a[1] = 234;
	a[2] = 456;
	a[3] = 567;
	a[4] = 678;

    cout << "Stevila v polju a so :\n";
    for (int i = 0; i < 5; i++) {
        cout "a[" << i << "] : " << a[i] << " ";
    }

	int b[5] = { 22, 5, 66, 7, 8, 33 };

    cout << "Stevila v polju b so :\n";
    for (int i = 0; i < 5; i++) {
        cout "b[" << i << "] : " << b[i] << " ";
    }


    int c[] = { 4, 5, 67, 567, 8 };

    cout << "Stevila v polju b so :\n";
    for (int i = 0; i < 5; i++) {
        cout "c[" << i << "] : " << c[i] << " ";
    }

    return 0;
}
#endif

#ifdef POLJA_2
int main() {
    int a[5];

    cout << "Vnesi 5 stevil:\n";
    for (int i = 0; i < 5; i++)
        cin >> a[i];

    cout << "Vnesena stevila so:\n";
    for (int i = 0; i < 5; i++) {
        cout << a[i] << " ";
    }

    int max = a[0];
    for (int i = 1; i < 5; i++) {
        if (a[i] > max)
            max = a[i];
    }

    cout << "Najvecje stevilo je: " << max << endl;
    return 0;
}
#endif

#ifdef POLJA_3
int main() {
    int a[5] = { 1, 2, 3, 4, 5 };

    for (int i = 4; i >= 0; i--) {
        cout << a[i] << " ";
    }

    return 0;
}
#endif


#ifdef POMNILNIK_1
int main() {
    int i, pi[5];
	char c, pc[5];
	float f, pf[5];
	double d, pd[5];


	cout << "velikost zasedenega pomnilnika za int: " << sizeof(i) << " bajtov" << endl;
	cout << "velikost zasedenega pomnilnika za char: " << sizeof(c) << " bajtov" << endl;
	cout << "velikost zasedenega pomnilnika za float: " << sizeof(f) << " bajtov" << endl;
	cout << "velikost zasedenega pomnilnika za double: " << sizeof(d) << " bajtov" << endl;

    cout << "---------------------------------" << endl;
    cout << "velikost zasedenega pomnilnika za int[5]: " << sizeof(pi) << " bajtov" << endl;
	cout << "velikost zasedenega pomnilnika za char[5]: " << sizeof(pc) << " bajtov" << endl;
	cout << "velikost zasedenega pomnilnika za float[5]: " << sizeof(pf) << " bajtov" << endl;
	cout << "velikost zasedenega pomnilnika za double[5]: " << sizeof(pd) << " bajtov" << endl;

	cout << "---------------------------------" << endl;
	cout << "Število podatkov v int[5]: " << sizeof(pi) / sizeof(int) << endl;
	cout << "Število podatkov v char[5]: " << sizeof(pc) / sizeof(char) << endl;
	cout << "Število podatkov v float[5]: " << sizeof(pf) / sizeof(float) << endl;
	cout << "Število podatkov v double[5]: " << sizeof(pd) / sizeof(double) << endl;

    return 0;
}
#endif

#ifdef DVO_DIMENZIJSKA_POLJA_1
int main() {
    int m[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    for (int i = 0; i < 2; i++) {        // vrstice
        for (int j = 0; j < 3; j++) {    // stolpci
            cout << m[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
#endif

#ifdef NIZI_1
int main() {
    string s = "Programiranje";
    cout << s.length() << endl;;   // ali s.size()

    for (size_t i = 0; i < s.length(); i++)
		cout << "znak " << i << " == s[" << i << "] == " << s[i] << endl;

    // Združevanje nizov
    string ime = "Ana";
    string pozdrav = "Pozdrav, " + ime + "!";

    // Primerjanje nizov
    if (ime == "Ana") {
        cout << "ime je 'Ana'";
    }
    if (ime == "ana") {
        cout << "ime je 'ana'";
    }

    // iskanje v nizu
    int poz = s.find("gram");
    if (poz != string::npos) {
        cout << "Niz 'gram' najden na poziciji " << poz << endl;
    } else {
        cout << "Niz 'gram' ni najden" << endl;
	}

    // podnizi
    string s = "programiranje";
	cout << s.substr(3, 2) << endl; // izpiše "gr"

    return 0;
}
#endif

#ifdef PODATKOVNI_TIPI_1
int main() {
    int i;
    char c;
    string s;
    long l;

	cout << "Vnesi int, char, string in long: ";
	cin >> i >> c >> s >> l;

    cout << "int: " << i << endl;
    cout << "char: " << c << endl;
    cout << "string: " << s << endl;
    cout << "long: " << l << endl;
	return 0;
}
#endif

#ifdef PODATKOVNI_TIPI_2
int main() {
    int i;
    char c;
    string s;
    long l;

    cout << "Vnesi int, char, string in long: ";
    cin >> i >> c;
	getline(cin, s); // Preberi preostali del vrstice vključno s presledki
    cin >> l;

    cout << "int: " << i << endl;
    cout << "char: " << c << endl;
    cout << "string: " << s << endl;
    cout << "long: " << l << endl;
    return 0;
}
#endif

#ifdef NIZI_2
int main() {
    string s;

    cout << "Vnesi miz znalov s ciframi: ";
    getline(cin, s);

    int sum = 0;
    for (size_t i = 0; i < s.length(); i++) {
        if (isdigit(s[i])) {
            sum += s[i] - '0';
			cout << "Cifra: " << s[i] << ", vsota: " << sum << endl;
        }
	}

	cout << "Vsota cifr v nizu je: " << sum << endl;

    return 0;
}
#endif

#ifdef STRUKTURE_1
struct Student {
    string ime;
    int starost;
    int letnik;
};

int main() {
    Student s;

    s.ime = "Ana";
    s.starost = 20;
    s.letnik = 2;

    cout << "Ime: " << s.ime << endl;
    cout << "Starost: " << s.starost << endl;
    cout << "Letnik: " << s.letnik << endl;

    return 0;
}
#endif

#ifdef STRUKTURE_IN_NASTEVANJE_1
enum Letnik {
    PRVI,
    DRUGI,
    TRETJI
};

struct Student {
    string ime;
    int starost;
    Letnik letnik;
};

int main() {
    Student s;

    s.ime = "Marko";
    s.starost = 21;
    s.letnik = DRUGI;

    cout << "Ime: " << s.ime << endl;
    cout << "Starost: " << s.starost << endl;
    cout << "Letnik (direktno): " << s.letnik << endl;

    cout << "Letnik (inirektno): ";
    if (s.letnik == PRVI)  cout << "1. letnik";
    if (s.letnik == DRUGI) cout << "2. letnik";
    if (s.letnik == TRETJI) cout << "3. letnik";

    return 0;
}
#endif

#ifdef REFERENCE_1
int main() {
    int a = 5;
	cout << "Pred spremembo: a = " << a << endl;

    int& r = a;
	cout << "Referenca r na a: r = " << r << endl;

    r = 10;
	cout << "Po spremembi preko reference r: a = " << a << ", r = " << r << endl;

    a = 33;
    cout << "Po spremembi preko vrednosti a: a = " << a << ", r = " << r << endl;

	return 0;
}
#endif

#ifdef REFERENCE_IN_FUNKCIJE_1
void povecaj(int x) {
	cout << "V funkciji povecaj pred povecanjem: x = " << x << endl;
    x++;
	cout << "V funkciji povecaj po povecanjem: x = " << x << endl;
}

void povecaj1(int a) {
    cout << "V funkciji povecaj pred povecanjem: x = " << a << endl;
    a++;
    cout << "V funkciji povecaj po povecanjem: x = " << a << endl;
}

int main() {
    int a = 5;

	cout << "Pred klicem funkcije povecaj: a = " << a << endl;
    povecaj(a);
	cout << "Po klicu funkcije povecaj: a = " << a << endl;

    cout << "Pred klicem funkcije povecaj1: a = " << a << endl;
    povecaj(a);
    cout << "Po klicu funkcije povecaj1: a = " << a << endl;

	return 0;
}
#endif

#ifdef REFERENCE_IN_FUNKCIJE_2
void povecaj(int &x) {
    cout << "V funkciji povecaj pred povecanjem: x = " << x << endl;
    x++;
    cout << "V funkciji povecaj po povecanjem: x = " << x << endl;
}

void povecaj1(int &a) {
    cout << "V funkciji povecaj pred povecanjem: a = " << a << endl;
    a++;
    cout << "V funkciji povecaj po povecanjem: a = " << a << endl;
}

int main() {
    int a = 5;

    cout << "Pred klicem funkcije povecaj: a = " << a << endl;
    povecaj(a);
    cout << "Po klicu funkcije povecaj: a = " << a << endl;

    cout << "Pred klicem funkcije povecaj1: a = " << a << endl;
    povecaj1(a);
    cout << "Po klicu funkcije povecaj1: a = " << a << endl;

    return 0;
}
#endif

#ifdef REFERENCE_IN_FUNKCIJE_3
void swap_ne_deluje(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

void swap_deluje(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
	int vrednost1 = 10;
	int vrednost2 = 20;

	cout << "Pred klicem swap_ne_deluje: vrednost1 = " << vrednost1 << ", vrednost2 = " << vrednost2 << endl;
	swap_ne_deluje(vrednost1, vrednost2);
	cout << "Po klicu swap_ne_deluje: vrednost1 = " << vrednost1 << ", vrednost2 = " << vrednost2 << endl;

	cout << "Pred klicem swap_deluje: vrednost1 = " << vrednost1 << ", vrednost2 = " << vrednost2 << endl;
	swap_deluje(vrednost1, vrednost2);
	cout << "Po klicu swap_deluje: vrednost1 = " << vrednost1 << ", vrednost2 = " << vrednost2 << endl;

    return 0;
}
#endif


#ifdef REFERENCE_IN_FUNKCIJE_4
void minMax(int a, int b, int& min, int& max) {
    if (a < b) {
        min = a;
        max = b;
    }
    else {
        min = b;
        max = a;
    }
}

int main() {
    int vrednost1 = 33, vrednost2 = 105;
	int manjsa, vecja;

	minMax(vrednost1, vrednost2, manjsa, vecja);
	cout << "Manjsa: " << manjsa << ", Vecja: " << vecja << endl;

    return 0;
}
#endif

#ifdef REFERENCE_IN_FUNKCIJE_5
struct Oseba {
    string ime;
    int starost;
};

// kopiranje
void predaja_po_vrednosti(Oseba o) {
    o.starost++;
}

// ni kopiranja
void predaja_po_referenci(Oseba& o) {
    o.starost++;
}

void predaja_po_referenci_2(const Oseba& o) {
    // o.ime = "Spremenjeno ime";

    cout << o.ime << " (" << o.starost << ")";
}

int main() {
	Oseba oseba;
	oseba.ime = "Luka";
	oseba.starost = 25;

	cout << "Pred klicem funkcije predaja_po_vrednosti: " << oseba.ime << ", starost: " << oseba.starost << endl;
	predaja_po_vrednosti(oseba);
	cout << "Po klicu funkcije predaja_po_vrednosti: " << oseba.ime << ", starost: " << oseba.starost << endl;

	cout << "Pred klicem funkcije predaja_po_referenci: " << oseba.ime << ", starost: " << oseba.starost << endl;
	predaja_po_referenci(oseba);
	cout << "Po klicu funkcije predaja_po_referenci: " << oseba.ime << ", starost: " << oseba.starost << endl;


	cout << "Klic funkcije predaja_po_referenci_2: ";
	predaja_po_referenci_2(oseba);

    return 0;
}
#endif

#ifdef REFERENCE_IN_FUNKCIJE_6
struct Oseba {
    string ime;
    int starost;
};

void povecajStarost(Oseba s[], int n) {
    for (int i = 0; i < n; i++)
        s[i].starost++;
}

void izpisiOsebo(const Oseba& o) {
    cout << o.ime << " (" << o.starost << " let)" << endl;
}

int main() {
    Oseba osebe[3] = {
        {"Ana", 20},
        {"Boris", 22},
        {"Cilka", 19}
    };

    cout << "Pred povecanjem starosti:\n";
    for (int i = 0; i < 3; i++) 
		izpisiOsebo(osebe[i]);

    povecajStarost(osebe, 3);

    cout << "Po povecanjem starosti:\n";
    for (int i = 0; i < 3; i++)
        izpisiOsebo(osebe[i]);

    return 0;
}
#endif

#ifdef REFERENCE_IN_FUNKCIJE_7
struct Oseba {
    string ime;
    int starost;
};

//void povecajStarost(Oseba& s[], int n) {
void povecajStarost(Oseba (&s)[], int n) {
    for (int i = 0; i < n; i++)
        s[i].starost++;
}

void izpisiOsebo(const Oseba& o) {
    cout << o.ime << " (" << o.starost << " let)" << endl;
}

int main() {
    Oseba osebe[3] = {
        {"Ana", 20},
        {"Boris", 22},
        {"Cilka", 19}
    };

    cout << "Pred povecanjem starosti:\n";
    for (int i = 0; i < 3; i++)
        izpisiOsebo(osebe[i]);

    povecajStarost(osebe, 3);

    cout << "Po povecanjem starosti:\n";
    for (int i = 0; i < 3; i++)
        izpisiOsebo(osebe[i]);

    return 0;
}
#endif

#ifdef KAZALCI_1
int main() {
	int vrednost = 42;
	int* kazalec = &vrednost;

	cout << "Vrednost: " << vrednost << endl;
	cout << "Kazalec: " << kazalec << endl;
	cout << "Vrednost preko kazalca: " << *kazalec << endl;

    return 0;
}
#endif

#ifdef KAZALCI_IN_FUNKCIJE_1
void povecaj(int *x) {
    cout << "V funkciji povecaj pred povecanjem: x = " << *x << endl;
    (*x)++;
    cout << "V funkciji povecaj po povecanjem: x = " << *x << endl;
}

void povecaj1(int *a) {
    cout << "V funkciji povecaj pred povecanjem: a = " << *a << endl;
    (*a)++;
    cout << "V funkciji povecaj po povecanjem: a = " << *a << endl;
}

void povecaj2(int* b) {
    cout << "V funkciji povecaj pred povecanjem: b = " << b << endl;
    b++;
    cout << "V funkciji povecaj po povecanjem: b = " << b << endl;
}

int main() {
    int a = 5;

    cout << "Pred klicem funkcije povecaj: a = " << a << endl;
	povecaj(&a);    // podati moramo referenco na a
    cout << "Po klicu funkcije povecaj: a = " << a << endl;

    cout << "Pred klicem funkcije povecaj1: a = " << a << endl;
	povecaj1(&a);    // podati moramo referenco na a
    cout << "Po klicu funkcije povecaj1: a = " << a << endl;

    cout << "Pred klicem funkcije povecaj1: a = " << a << endl;
    povecaj2(&a);    // podati moramo referenco na a
    cout << "Po klicu funkcije povecaj1: a = " << a << endl;

    return 0;
}
#endif

#ifdef KAZALCI_IN_FUNKCIJE_2
void swap_ne_deluje(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

void swap_deluje(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int vrednost1 = 10;
    int vrednost2 = 20;

    cout << "Pred klicem swap_ne_deluje: vrednost1 = " << vrednost1 << ", vrednost2 = " << vrednost2 << endl;
    swap_ne_deluje(vrednost1, vrednost2);
    cout << "Po klicu swap_ne_deluje: vrednost1 = " << vrednost1 << ", vrednost2 = " << vrednost2 << endl;

    cout << "Pred klicem swap_deluje: vrednost1 = " << vrednost1 << ", vrednost2 = " << vrednost2 << endl;
    swap_deluje(&vrednost1, &vrednost2);
    cout << "Po klicu swap_deluje: vrednost1 = " << vrednost1 << ", vrednost2 = " << vrednost2 << endl;

    return 0;
}
#endif

#ifdef KAZALCI_IN_FUNKCIJE_3
struct Oseba {
    string ime;
    int starost;
};

void postaraj(Oseba *o) {
    o->starost++;

    (*o).starost++;
}

int main() {
	Oseba oseba;
	oseba.ime = "Luka";
	oseba.starost = 25;

	cout << "Pred klicem funkcije postaraj: " << oseba.ime << ", starost: " << oseba.starost << endl;
	postaraj(&oseba);
	cout << "Po klicu funkcije postaraj: " << oseba.ime << ", starost: " << oseba.starost << endl;

    return 0;
}
#endif

#ifdef KAZALCI_IN_POLJA_1
int main() {
	int a[5] = { 10, 20, 30, 40, 50 };
	int* p = a; // ali int* p = &a[0];

	for (int i = 0; i < 5; i++) 
		cout << "a[" << i << "] = " << *(p + i) << endl;

	cout << "---------------------------------" << endl;

	int* q = a;
    cout << "a[3] = " << *(p + 3) << endl;

    return 0;
}
#endif

#ifdef DINAMICNA_POLJA_1
int main() {
    int* stevila;
    int velikost;

	cout << "Vnesi velikost polja: ";
	cin >> velikost;

	stevila = new int[velikost];

	cout << "Vnesi " << velikost << " stevil:\n";
	for (int i = 0; i < velikost; i++)
		cin >> stevila[i];

	cout << "Vnesena stevila so:\n";
	for (int i = 0; i < velikost; i++)
		cout << stevila[i] << " ";

	delete[] stevila;

    return 0;
}
#endif

#ifdef DINAMICNA_POLJA_2
int* ustvariTabelo(int n) {
    int *tabela = new int[n];

    for (int i = 0; i < n; i++)
		tabela[i] = rand() % 100; // nakljucno stevilo med 0 in 99

    return tabela;
}

int main() {
    int* stevila;
    int velikost;

    cout << "Vnesi velikost tabele: ";
    cin >> velikost;

	stevila = ustvariTabelo(velikost);

    cout << "Generirana stevila so:\n";
    for (int i = 0; i < velikost; i++)
        cout << stevila[i] << " ";

    delete[] stevila;   // NE POZABI!!!!!

    return 0;
}
#endif

#ifdef DINAMICNE_STRUKTURE_1
struct Oseba {
    string ime;
    int starost;
};

int main() {
	Oseba* oseba = new Oseba;
	oseba->ime = "Maja";
	oseba->starost = 28;

	cout << "Ime: " << oseba->ime << endl;
	cout << "Starost: " << oseba->starost << endl;

	delete oseba;

    return 0;
}
#endif


#ifdef DINAMICNE_STRUKTURE_2
struct Oseba {
    string ime;
    int starost;
};

int main() {
    int n = 3;
    Oseba* osebe = new Oseba[n];

	osebe[0].ime = "Ana";
	osebe[0].starost = 20;
	osebe[1].ime = "Boris";
	osebe[1].starost = 22;
	osebe[2].ime = "Cilka";
	osebe[2].starost = 19;

    for (int i = 0; i < n; i++) {
        cout << "Ime: " << osebe[i].ime << ", Starost: " << osebe[i].starost << endl;
	}

	delete[] osebe;

    return 0;
}
#endif

#ifdef DINAMICNE_STRUKTURE_3
struct Oseba {
    string ime;
    int starost;
};

int main() {
	vector<Oseba> osebe;

    int n;
    cout << "Vnesi stevilo oseb: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        Oseba o;
        cout << "Vnesi ime osebe: ";
        cin >> o.ime;
        cout << "Vnesi starost osebe: ";
        cin >> o.starost;
        osebe.push_back(o);
    }

	cout << "-----------------------" << endl;
    cout << "Vnesene osebe so:\n";
    for (const Oseba& o : osebe) {
        cout << "Ime: " << o.ime << ", Starost: " << o.starost << endl;
    }

    cout << "-----------------------" << endl;
    cout << "Vnesene osebe so:\n";
    for (size_t i = 0; i < osebe.size(); i++)
    {
        cout << "Ime: " << osebe[i].ime << ", Starost: " << osebe[i].starost << endl;
    }


	return 0;
}
#endif

#ifdef FUNKCIJE_1
// 1. Brez parametrov, brez vračila
void pozdrav() {
    cout << "Pozdravljen uporabnik!" << endl;
}

// 2. S parametri in vračilom
int vsota(int a, int b) {
    return a + b;
}

// 3. S privzetimi parametri
int zmnozi(int a, int b = 2) {
    return a * b;
}

// 4. Z referencami
void povecaj(int& x) {
    x++;
}

int main() {
    // 1
    pozdrav();

    // 2
    int r = vsota(3, 5);
    cout << "Vsota = " << r << endl;

    // 3
    cout << "Zmnozi(5) = " << zmnozi(5) << endl;
    cout << "Zmnozi(5, 3) = " << zmnozi(5, 3) << endl;

    // 4
    int a = 10;
    povecaj(a);
    cout << "Povecana vrednost = " << a << endl;

    return 0;
}

#endif

#ifdef FUNKCIJE_2
const int ST_OCEN = 5;

// -------------------- STRUKTURA --------------------
struct Student {
    string ime;
    int ocene[ST_OCEN];
};

// -------------------- FUNKCIJE ZA POLJE --------------------
double povprecjePolja(const int a[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
    return (double)sum / n;
}

// -------------------- FUNKCIJE ZA STRUKTURO --------------------
Student ustvariStudentaDemo() {
    Student s;
    s.ime = "Ana";
    for (int i = 0; i < ST_OCEN; i++)
        s.ocene[i] = 6 + i; // 6,7,8,9,10
    return s;
}

void izpisiStudenta(const Student& s) {
    cout << "Ime: " << s.ime << endl;
    cout << "Ocene: ";
    for (int i = 0; i < ST_OCEN; i++)
        cout << s.ocene[i] << " ";
    cout << endl;
}

double povprecjeStudenta(const Student& s) {
    return povprecjePolja(s.ocene, ST_OCEN);
}

void dodajBonus(Student& s, int bonus) {
    for (int i = 0; i < ST_OCEN; i++) {
        s.ocene[i] += bonus;
        if (s.ocene[i] > 10) s.ocene[i] = 10;
    }
}

// -------------------- FUNKCIJE ZA TABELO STRUKTUR --------------------
void vnesiStudente(Student razred[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "\nStudent " << (i + 1) << ":\n";
        cout << "Ime: ";
        cin >> razred[i].ime;

        cout << "Vnesi " << ST_OCEN << " ocen: ";
        for (int j = 0; j < ST_OCEN; j++)
            cin >> razred[i].ocene[j];
    }
}

void izpisiRazred(const Student razred[], int n) {
    cout << "\n--- IZPIS RAZREDA ---\n";
    for (int i = 0; i < n; i++) {
        cout << "\n[" << (i + 1) << "]\n";
        izpisiStudenta(razred[i]);
        cout << "Povprecje: " << povprecjeStudenta(razred[i]) << endl;
    }
}

int indeksNajboljsega(const Student razred[], int n) {
    int best = 0;
    double bestAvg = povprecjeStudenta(razred[0]);

    for (int i = 1; i < n; i++) {
        double avg = povprecjeStudenta(razred[i]);
        if (avg > bestAvg) {
            bestAvg = avg;
            best = i;
        }
    }
    return best;
}

double povprecjeRazreda(const Student razred[], int n) {
    double sum = 0;
    for (int i = 0; i < n; i++)
        sum += povprecjeStudenta(razred[i]);
    return sum / n;
}

void dodajBonusVsem(Student razred[], int n, int bonus) {
    for (int i = 0; i < n; i++)
        dodajBonus(razred[i], bonus);
}

// -------------------- MAIN --------------------
int main() {
    cout << "=== DEMO: STRUKTURE + POLJA + FUNKCIJE ===\n";

    // 1) Demo: funkcija vrne strukturo
    Student demo = ustvariStudentaDemo();
    cout << "\nDEMO student (ustvarjen v funkciji):\n";
    izpisiStudenta(demo);
    cout << "Povprecje demo studenta: " << povprecjeStudenta(demo) << endl;

    // 2) Dodamo bonus demo studentu (referenca)
    dodajBonus(demo, 1);
    cout << "\nDEMO po bonu (+1):\n";
    izpisiStudenta(demo);
    cout << "Novo povprecje: " << povprecjeStudenta(demo) << endl;

    // 3) Logično nadaljevanje: tabela struktur (razred)
    const int N = 3;
    Student razred[N];

    cout << "\n\n=== VNESI PODATKE ZA " << N << " STUDENTE ===\n";
    vnesiStudente(razred, N);

    // 4) Izpis razreda
    izpisiRazred(razred, N);

    // 5) Najboljši študent
    int best = indeksNajboljsega(razred, N);
    cout << "\n--- NAJBOLJSI STUDENT ---\n";
    izpisiStudenta(razred[best]);
    cout << "Povprecje: " << povprecjeStudenta(razred[best]) << endl;

    // 6) Povprečje razreda
    cout << "\nPovprecje razreda: " << povprecjeRazreda(razred, N) << endl;

    // 7) Bonus vsem
    cout << "\nDodajam bonus +1 vsem studentom...\n";
    dodajBonusVsem(razred, N, 1);

    // 8) Ponovni izpis
    izpisiRazred(razred, N);

    return 0;
}

#endif

#ifdef FUNKCIJE_3

int sestej(int a, int b) {
    return a + b;
}

double sestej(double a, double b) {
    return a + b;
}

float sestej(float a, float b) {
    return a + b;
}

int main() {
	int int1 = 5, int2 = 10;
	double double1 = 5.5, double2 = 10.2;
	float float1 = 3.3f, float2 = 4.4f;

	cout << "Sestevek int: " << sestej(int1, int2) << endl;
	cout << "Sestevek double: " << sestej(double1, double2) << endl;
	cout << "Sestevek float: " << sestej(float1, float2) << endl;

    return 0;
}

#endif

#ifdef REKURZIVNE_FUNKCIJE_1
void odstevaj(int n) {
    if (n == 0)          // osnovni primer
        return;

    cout << n << endl;
    odstevaj(n - 1);     // rekurzivni klic
}


int main() {
    int stevilo;
    cout << "Vnesi stevilo: ";
    cin >> stevilo;

    cout << "Odstevanje od " << stevilo << " do 1:\n";
    odstevaj(stevilo);
	return 0;
}

#endif


#ifdef REKURZIVNE_FUNKCIJE_2

// n! = n * (n-1) * (n-2) * ... * 1
// 
// 0! = 1
// Rekurzivno: n! = n * (n-1)!

int fakulteta(int n) {
    if (n == 0)
        return 1;               // osnovni primer

    return n * fakulteta(n - 1);
}

int main() {
	int stevilo;
	cout << "Vnesi stevilo: ";
	cin >> stevilo;

	cout << stevilo << "! = " << fakulteta(stevilo) << endl;

    return 0;
}

#endif

#ifdef REKURZIVNE_FUNKCIJE_3

bool palindrom(const string& s, int zacetek, int konec) {
    if (zacetek >= konec)
        return true;

    if (s[zacetek] != s[konec])
        return false;

    return palindrom(s, zacetek + 1, konec - 1);
}

bool palindrom_nerekurzivno(const string& s, int zacetek, int konec) {
    while (zacetek < konec) {
        if (s[zacetek] != s[konec])
            return false;

        zacetek++;
        konec--;
    }

    return true;
}

bool palindrom_nerekurzivno1(const string& s, int zacetek, int konec) {
	const char* k_zacetek = &s[zacetek];
	const char* k_konec = &s[konec];

    while (k_zacetek < k_konec) {
        if (*k_zacetek != *k_konec)
            return false;

        k_zacetek++;
        k_konec--;
    }

    return true;
}

int main() {
    string s = "ana";
	cout << palindrom(s, 0, s.length() - 1) << endl;

	cout << "-------------------------------" << endl;

    do {
        string s1;
        cout << "Vnesi niz ali prazno za konec : ";
        getline(cin, s1);

        if (s1.empty())
			break;

        if (palindrom(s1, 0, s1.length() - 1))
            cout << "Niz je palindrom." << endl;
        else
            cout << "Niz ni palindrom." << endl;

        if (palindrom_nerekurzivno(s1, 0, s1.length() - 1))
            cout << "Niz je palindrom." << endl;
        else
            cout << "Niz ni palindrom." << endl;

        if (palindrom_nerekurzivno1(s1, 0, s1.length() - 1))
            cout << "Niz je palindrom." << endl;
        else
            cout << "Niz ni palindrom." << endl;
    } while (true);

    return 0;
}

#endif