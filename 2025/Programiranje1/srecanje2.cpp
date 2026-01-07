#include <iostream>
#include <limits>
#include <iomanip>
using namespace std;

#define funkcije_x

#ifdef S2_1
int main() {
    int i = numeric_limits<int>::max();

    cout << "vrednost: " << i << endl;
    i = i + 1;
    cout << "vrednost + 1: " << i << endl;
}
#endif

#ifdef S2_2
int main() {
    int i = numeric_limits<int>::min();

    cout << "vrednost: " << i << endl;
    i = i - 1;
    cout << "vrednost - 1: " << i << endl;
}
#endif

#ifdef S2_3
int main() {
    char c = 'A';

    cout << "vrednost: " << c << endl;
    cout << "(int) vrednost: " << (int)c << endl;
}
#endif

#ifdef S2_4
int main() {
    char c = numeric_limits<char>::max();

    cout << "vrednost: " << (int)c << endl;
    c = c + 1;
    cout << "vrednost + 1: " << (int)c << endl;
}
#endif

#ifdef S2_5
int main() {
    char c = numeric_limits<char>::min();

    cout << "vrednost: " << (int)c << endl;
    c = c - 1;
    cout << "vrednost - 1: " << (int)c << endl;
}
#endif

#ifdef S2_6
int main() {
    char c1 = 'M';
    char c2 = 'A';
    char c3 = 'R';
    char c4 = 'K';
    char c5 = 'O';

	cout << c1 << c2 << c3 << c4 << c5 << endl;

	c1 = c1 + 32;
	c2 += 32;
	c3 = 94;
    c4 = '\'';
	c5 += 32;
    cout << c1 << c2 << c3 << c4 << c5 << endl;
}
#endif

#ifdef S2_7
int main() {
    double a = 0.1;
    double b = 0.2;
    double c = a + b;

	if (c > 0.29999 && c < 0.300001)
    //if (c == 0.3)
        cout << "Enako" << endl;
    else
        cout << "Ni enako" << endl;

    cout << "Koliko je c == " << c << endl;
}
#endif

#ifdef S2_8
int main() {
    double a = 0.1;
    double b = 0.2;
    double c = a + b;

    if (c == 0.3)
        cout << "Enako" << endl;
    else
        cout << "Ni enako" << endl;

    cout << setprecision(numeric_limits<double>::max_digits10);
    cout << "a == " << a << endl;
    cout << "b == " << b << endl;
    cout << "c == " << c << endl;
}
#endif

#ifdef S2_9
int main() {
    float a = 1.0;
    float b = 0.0000001;

    float c = a - b; 

    cout << setprecision(numeric_limits<double>::max_digits10);
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
}
#endif

#ifdef S2_10
int main() {
    double a, b, c;

    cout << "Vnesi tri stranice trikotnika: ";
    cin >> a >> b >> c;

    // 1. Najprej preverimo, ali sploh lahko tvorijo trikotnik
    if (a + b > c && a + c > b && b + c > a) {
        // 2. Ker tvorijo trikotnik, preverjamo vrsto
        if (a == b && b == c) {
            cout << "Trikotnik je enakostranični." << endl;
        }
        else {
            // Tu vemo, da niso vse tri stranice enake
            if (a == b || a == c || b == c) {
                cout << "Trikotnik je enakokraki." << endl;
            }
            else {
                cout << "Trikotnik je raznostranični." << endl;
            }
        }
    }
    else {
        cout << "Podane stranice NE tvorijo trikotnika." << endl;
    }

    return 0;
}
#endif

#ifdef S2_10_1
int main() {
    double a, b, c;

    cout << "Vnesi tri stranice trikotnika: ";
    cin >> a >> b >> c;

    if (!(a + b > c && a + c > b && b + c > a))
        cout << "Podane stranice NE tvorijo trikotnika." << endl;

	//if (a + b <= c || a + c <= b || b + c <= a) 
    //    cout << "Podane stranice NE tvorijo trikotnika." << endl;

    if (a == b && b == c) {
        cout << "Trikotnik je enakostranični." << endl;
        return 0;
    }

    if (a == b || a == c || b == c) 
        cout << ((a == b || a == c || b == c)
                 ? "Trikotnik je enakokraki."
		         : "Trikotnik je raznostranični.") 
             << endl;

    return 0;
}
#endif

#ifdef S2_11
int main() {
    int ocena;

    cout << "Vnesi oceno (1–5): ";
    cin >> ocena;

    switch (ocena) {
        case 1:
            cout << "Nedzadostno" << endl;
            break;

        case 2:
            cout << "Zadostno" << endl;
            break;

        case 3:
            cout << "Dobro" << endl;
            break;

        case 4:
            cout << "Prav dobro" << endl;
            break;

        case 5:
            cout << "Odlično" << endl;
            break;

        default:
            cout << "Neveljavna ocena." << endl;
    }

    // ddd

    return 0;
}
#endif

#ifdef S2_12
int main() {
    int stevecPozitivnih = 0;
    int vnesenoStevilo;

    while (true) {
        cout << "Vnesi celo število (0 za konec): ";
        cin >> vnesenoStevilo;

        if (vnesenoStevilo == 0) 
            break;

        if (vnesenoStevilo > 0) 
            stevecPozitivnih = stevecPozitivnih + 1;
    }

    cout << "Pozitivnih stevil: " << stevecPozitivnih << endl;
    return 0;
}
#endif

#ifdef S2_13
int main() {
    int n;
    cout << "Vnesi n: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        if (i % 2 != 0) {
            continue; 
        }

        cout << i << " ";
    }

    cout << endl;
    return 0;
}
#endif

#ifdef S2_13_1
int main() {
    int n;
    cout << "Vnesi n: ";
    cin >> n;

    for (int i = 2; i <= n; i+=2) 
        cout << i << " ";

    cout << endl;
    return 0;
}
#endif

#ifdef S2_14
int main() {
    int n;
    cout << "Vnesi n (>= 0): ";
    cin >> n;

    unsigned long long fakulteta = 1;

    for (int i = 1; i <= n; i++) 
        fakulteta = fakulteta * i;

    cout << n << "! = " << fakulteta << endl;
    return 0;
}
#endif


#ifdef S2_15
int main() {
    int n;
    cout << "Vnesi ne-negativno celo število: ";
    cin >> n;

    int vsota = 0;

    while (n > 0) {
        int zadnjaStevka = n % 10;   // vzamemo zadnjo števko
        vsota = vsota + zadnjaStevka;
        n = n / 10;                  // odstranimo zadnjo števko
    }

    cout << "Vsota števk je: " << vsota << endl;
    return 0;
}
#endif

#ifdef while1
int main() {
    unsigned char i = 5;

    while (i > 0)
    {
		cout << "pozdravljen svet [" << (int)i << "]" << endl;
		i = i + 1;
    }
}
#endif



#ifdef postevanka
int main() {
    for (int i = 1; i <= 10; ++i) {
        for (int j = 1; j <= 10; ++j) {
            // cout << i << " * " << j << " = " << (i * j) << " | ";
            cout << setw(3) << (i * j) << " | ";
        }

        cout << endl;
    }
    return 0;
}
#endif




#ifdef funkcije
int kvadrat(int x) {
    return x * x;
}

double PovrsinaKroga(int r) {
    return 2 * 3.14 * r;
}

void pozdrav(int n) {
    for (int i = 0; i < n; i++)
    {
        cout << "Pozdravljen svet!" << endl;
    }

	// return 103;
}

int sedemkratnik(int n)
{
    return 7 * n;
}

int main() {
    int stranica;

    pozdrav(10);

	cout << "Vnesi stranico kvadrata: ";
	cin >> stranica;

	cout << "Površina kvadrata s stranico " << stranica << " je " << kvadrat(stranica) << endl;

    int polmer;
    cout << "Vnesi polmer kroga: ";
    cin >> polmer;

    cout << "Površina kroga s polmerom " << polmer << " je " << PovrsinaKroga(polmer) << endl;


    return 0;
}
#endif




