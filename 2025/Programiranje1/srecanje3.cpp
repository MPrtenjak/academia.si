#include "constants.h"
#include <iostream>
#include <limits>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

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
        cout << "a[" << i << "] : " << a[i] << " " << endl;
    }

	int b[5] = { 22, 5, 66, 7, 8 };

    cout << "Stevila v polju b so :\n";
    for (int i = 0; i < 5; i++) {
        cout << "b[" << i << "] : " << b[i] << " " << endl;
    }


    int c[] = { 4, 5, 67, 567, 8 };

    cout << "Stevila v polju b so :\n";
    for (int i = 0; i < 5; i++) {
        cout << "c[" << i << "] : " << c[i] << " " << endl;
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
