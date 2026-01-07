
#include <iostream>
#include <cmath>
using namespace std;

#define E66_x

#ifdef E7
int main()
{
    int m, n;

    cin >> m >> n;

    //cout << "7 / 2 = 3 ots. 1"
    cout << m << " / " << n << " = " << (m / n) << " ost. " << (m % n);

    return 0;
}
#endif

#ifdef E7_1
int main()
{
    int m, n;

    cin >> m >> n;

    /*
    if (m % n == 0)
        cout << m << " \ " << n << " = " << (m / n);
    else
        cout << m << " / " << n << " = " << (m / n) << " ost. " << (m % n);
    */

    cout << m << " \ " << n << " = " << (m / n);
    if (m % n != 0)
		cout << " ost. " << (m % n);

    return 0;
}
#endif

#ifdef E7_2
int main()
{
    int m, n;

    cin >> m >> n;

    cout << m << " / " << n << " = " << (m / n);
    if (m % n != 0)
        cout << " ost. " << (m % n);

    return 0;
}
#endif

#ifdef E10
int main()
{
    int a, b, c;

    cin >> a >> b >> c;

    if (a > b && a > c)
        cout << a;
    else if (b > a && b > c)
        cout << b;
    else
        cout << c;

    return 0;
}
#endif

#ifdef E10_1
int main()
{
    int a, b, c;

    cin >> a >> b >> c;

    if (a > b)
        if (a > c)
            cout << a;
        else
            cout << c;
    else
        if (b > c)
            cout << b;
        else
            cout << c;

    return 0;
}
#endif

#ifdef E10_2
int main()
{
    int a, b, c;

    cin >> a >> b >> c;

    if (a > b)
        cout << (a > c ? a : c);
    else
        cout << (b > c ? b : c);

    return 0;
}
#endif

#ifdef E13
int main()
{
    int a;

    cin >> a;

    if (a < 1000 || a > 9999) {
        cout << "število ne ustreza";
        return 1;
    }

    cout << a % 10 << " E "
        << (a / 10) % 10 << " D "
        << (a / 100) % 10 << " S "
        << (a / 1000) % 10 << " T ";

    return 0;
}
#endif

#ifdef E13_1
int main()
{
    int stevilo;

    cout << "Vnesite stevilo" << endl;
    cin >> stevilo;

    int enice = stevilo % 10;
    cout << "Vasa stevilka vsebuje " << enice << " enic" << endl;

    int desetice = stevilo / 10 % 10;
    cout << "Vasa stevilka vsebuje " << desetice << " desetic" << endl;

    int stotice = stevilo / 100 % 10;
    cout << "Vasa stevilka vsebuje " << stotice << " stotic" << endl;

    int tisocice = stevilo / 1000 % 10;
    cout << "Vasa stevilka vsebuje " << tisocice << " tisocic" << endl;

    cout << endl << "Vasa stevilka vsebuje: " << enice << " E " << desetice << " D " << stotice << " S " << tisocice << " T " << endl;

    return 0;
}
#endif

#ifdef E14
int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    if (a > b)
        if (a > c)
            if (b > c)
                cout << a << " " << b << " " << c;
            else
                cout << a << " " << c << " " << b;
        else
            cout << c << " " << a << " " << b;
    else
        if (b > c)
            if (a > c)
                cout << b << " " << a << " " << c;
            else
                cout << b << " " << c << " " << a;
        else
            cout << c << " " << b << " " << a;

    return 0;
}
#endif

#ifdef OBRNI
int main()
{
    int a = 10, b = 33;

	cout << "Pred zamenjavo: a = " << a << ", b = " << b << endl;
	int t = a; 
	a = b;
	b = t;
    cout << "Po zamenjavi: a = " << a << ", b = " << b << endl;
	return 0;
}

#endif

#ifdef E14_1
int main()
{
    unsigned int a, b, c;
    cin >> a >> b >> c;

    int t;
    if (b > a) { t = a; a = b; b = t; }
    if (c > b) { t = b; b = c; c = t; }
    if (b > a) { t = a; a = b; b = t; }

    cout << a << " " << b << " " << c;

    return 0;
}
#endif

#ifdef BOOL_TEST
int main()
{
    int a;
	cout << "Vnesi celo število: ";
	cin >> a;

    if (a)
        cout << "TRUE";
    else
        cout << "FALSE";

    return 0;
}
#endif


#ifdef E26
void izpisiVseStevke(long long n)
{
    if (n < 0)
    {
        cout << "- ";
        n = -n;
	}

    while (n > 0)
    {
		cout << (n % 10) << " ";
		n = n / 10;
    }
}

int main()
{
    long long stevilo;
    cout << "vnesi vecmestno stevilo: ";
    cin >> stevilo;

	izpisiVseStevke(stevilo);

    return 0;
}
#endif


#ifdef E31
long long vsotaSodihDoN(long n)
{
    long long vsota = 0;
    for (int i = 2; i < n; i += 2)
        vsota += i;

    return vsota;
}

int main()
{
    long stevilo;
    cout << "Vnesi stevilo: ";
    cin >> stevilo;

	cout << "Vsota sodih stevk do " << stevilo << " je " << vsotaSodihDoN(stevilo) << endl;

    return 0;
}
#endif

#ifdef E37
void izpisiDeljitelje(unsigned int n)
{
    if (n < 1) return;

    cout << "Deljitelji stevilke " << n << " so: 1 ";
    for (unsigned int i = 2; i <= n; i++)
    {
        if (n % i == 0)
            cout << i << " ";
	} 
    cout << endl;

    cout << "Deljitelji stevilke " << n << " so: 1 " << n << " ";
    for (unsigned int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            cout << i << " " << (n / i) << " ";
    }
    cout << endl;

    cout << "koren stevila (" << n << ") je " << sqrt(n) << endl;
}

int main()
{
    do {
        long stevilo;
        cout << "Vnesi stevilo (ali 0 za konec): ";
        cin >> stevilo;

        if (stevilo <= 0)
            break;

        izpisiDeljitelje(stevilo);
    } while (true);

    return 0;
}
#endif

#ifdef E38
unsigned int najmanjsiSkupniVeckratnik(unsigned int a, unsigned int b)
{
    unsigned int i = 1;
    
    if (b > a)
    {
        unsigned int t = a;
        a = b;
        b = t;
	}

    while (i < b)
    {
        if ((i * a) % b == 0)
            return i * a;

        ++i;
	}

    return a * b;
}

int main()
{
    do {
        unsigned int stevilo1, stevilo2;
        cout << "Vnesi dve stevili (ali 0 za konec): ";
		cin >> stevilo1 >> stevilo2;

		if ((stevilo1 == 0) || (stevilo2 == 0))
            break;

		cout << "Najmanjsi skupni veckratnik stevil " 
             << stevilo1 << " in " << stevilo2 << " je " 
             << najmanjsiSkupniVeckratnik(stevilo1, stevilo2) << endl;
    } while (true);

    return 0;
}
#endif


#ifdef E39
unsigned int najvecjiSkupniDeljitelj(unsigned int a, unsigned int b)
{
	unsigned int min = (a < b) ? a : b;

    for (unsigned int i = min; i >= 1; --i)
    {
        if ((a % i == 0) && (b % i == 0))
            return i;
    }

	return 1;
}

/*

Če imamo dve števili a in b, velja:

    NSD(a, b) = NSD(b, a  mod  b)

To pomeni, da lahko problem zmanjšujemo tako, da večje število nadomestimo z ostankom pri deljenju.

Postopek

1. Vzemi dve pozitivni števili a in b.
2. Dokler b ≠ 0:
  2.1. Izračunaj ostanek r = a  mod  b
  2.2. Zamenjaj a in b
3. Ko b = 0, je NSD enak a.

*/
unsigned int euklid(unsigned int a, unsigned int b)
{
    while (b != 0)
    {
        unsigned int t = b;
        b = a % b;
        a = t;
    }

    return a;
}

int main()
{
    do {
        unsigned int stevilo1, stevilo2;
        cout << "Vnesi dve stevili (ali 0 za konec): ";
        cin >> stevilo1 >> stevilo2;

        if ((stevilo1 == 0) || (stevilo2 == 0))
            break;

        cout << "Najvecji skupni deljitelj stevil "
            << stevilo1 << " in " << stevilo2 << " je "
            << najvecjiSkupniDeljitelj(stevilo1, stevilo2) << endl;

        cout << "Najvecji skupni deljitelj stevil (euklid) "
            << stevilo1 << " in " << stevilo2 << " je "
            << euklid(stevilo1, stevilo2) << endl;
    } while (true);

    return 0;
}
#endif

#ifdef E40
void pretvoriV2(unsigned int a)
{
    int temp = a;

    while (temp > 0)
    {
		cout << (temp % 2);
        temp = temp / 2;
    }
}

void pretvoriV2_pravilno(unsigned int a)
{
    int temp = a;

	std::string binarno = "";
    while (temp > 0)
    {
		char ch = '0' + (temp % 2);
		binarno.insert(0, 1, ch);
        temp = temp / 2;
	}

    cout << binarno;
}

int main()
{
    do {
        unsigned int stevilo;
        cout << "Vnesi stevilo (ali 0 za konec): ";
        cin >> stevilo;

        if (stevilo == 0)
            break;

        cout << "Obrnjeno stevilo " << stevilo << " v dvojsnem sistemu je: ";
		pretvoriV2(stevilo);
		cout << endl;

        cout << "Pravilno stevilo " << stevilo << " v dvojsnem sistemu je: ";
        pretvoriV2_pravilno(stevilo);
        cout << endl;
    } while (true);

    return 0;
}
#endif


#ifdef E62

enum Pariteta {
    STEVILO_NI_DVOJISKO,
    STEVILO_JE_PREKRATKO,
    PARITETA_USTREZA,
    PARITETA_NE_USTREZA
};

Pariteta PreveriPariteto(unsigned long long a)
{
    if (a < 10)
		return STEVILO_JE_PREKRATKO;

    int pariteta = a % 10;
    if ((pariteta != 0) && (pariteta != 1))
        return STEVILO_NI_DVOJISKO;

    a /= 10;

    int stevecEnic = 0;
    while (a > 0)
    {
        unsigned int cifra = a % 10;
        if ((cifra != 0) && (cifra != 1))
            return STEVILO_NI_DVOJISKO;

		stevecEnic += (cifra == 1) ? 1 : 0;

        a /= 10;
    }

    if (pariteta == 0)
		return (stevecEnic % 2 == 0) ? PARITETA_USTREZA : PARITETA_NE_USTREZA;
    else
        return (stevecEnic % 2 == 1) ? PARITETA_USTREZA : PARITETA_NE_USTREZA;
}

int main()
{
    do {
        unsigned long long stevilo;
        cout << "Vnesi dvojisko stevilo (ali 0 za konec): ";
        cin >> stevilo;

        if (stevilo == 0)
            break;

		Pariteta rezultat = PreveriPariteto(stevilo);

        switch (rezultat)
        {
            case STEVILO_NI_DVOJISKO:
                cout << "Stevilo ni dvojisko!" << endl;
                break;
            case STEVILO_JE_PREKRATKO:
                cout << "Stevilo je prekratko!" << endl;
                break;
            case PARITETA_USTREZA:
                cout << "Pariteta ustreza!" << endl;
                break;
            case PARITETA_NE_USTREZA:
                cout << "Pariteta ne ustreza!" << endl;
                break;
		}
    } while (true);

    return 0;
}
#endif


#ifdef E63
unsigned long long Fibbonaci(unsigned int n)
{
    unsigned long long a = 0;
    unsigned long long b = 1;
    for (unsigned int i = 0; i < n; ++i)
    {
        unsigned long long t = a;
        a = b;
        b = t + b;
    }

    return a;
}

int main()
{
    do {
        unsigned int stevilo;
        cout << "Vnesi stevilo (ali 0 za konec): ";
        cin >> stevilo;

        if (stevilo == 0)
            break;

		cout << stevilo << ". Fibbonaccijevo stevilo je " << Fibbonaci(stevilo) << endl;
    } while (true);

    return 0;
}
#endif

#ifdef E66
long sestejStevke(long n)
{
    long vsota = 0;
    while (n > 0)
    {
        vsota += n % 10;
        n = n / 10;
    }
	return vsota;
}

int main()
{
    do {
        unsigned int stevilo;
        cout << "Vnesi stevilo (ali 0 za konec): ";
        cin >> stevilo;

        if (stevilo == 0)
            break;

        cout << stevilo;
        while (stevilo > 10)
        {
            stevilo = sestejStevke(stevilo);
            cout << " -> " << stevilo;
		}

        cout << endl;
    } while (true);

    return 0;
}
#endif