#include <iostream>
#include <limits>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

#define ZAPOSLENI_10x

#ifdef OOP_10
struct Student {
    string ime;
    int ocene[5];
};

void izpisiStudenta(const Student& s) {
    cout << "Ime: " << s.ime << endl;
    cout << "Ocene: ";
    for (int i = 0; i < 5; i++) {
        cout << s.ocene[i] << " ";
    }
    cout << endl;
}

Student ustvariStudenta() {
    Student s;
    s.ime = "Ana";
    s.ocene[0] = 6;
    s.ocene[1] = 7;
    s.ocene[2] = 8;
    s.ocene[3] = 9;
    s.ocene[4] = 10;
    return s;
}

Student vnesiStudenta() {
    Student s;
    cout << "Vnesi ime studenta: ";
    cin >> s.ime;
    cout << "Vnesi 5 ocen:\n";
    for (int i = 0; i < 5; i++) {
        cin >> s.ocene[i];
    }
    return s;
}

int main() {
	Student demo = ustvariStudenta();
	cout << "\nDEMO student (ustvarjen v funkciji):\n";
	izpisiStudenta(demo);

	cout << "\nVnesi podatke za novega studenta:\n";
	Student novStudent = vnesiStudenta();
	cout << "\nVneseni student:\n";
	izpisiStudenta(novStudent);

    return 0;
}
#endif

#ifdef OOP_20
struct Student {
    string ime;
    int ocene[5];

    void izpisiStudenta() {
        cout << "Ime: " << ime << endl;
        cout << "Ocene: ";
        for (int i = 0; i < 5; i++) {
            cout << ocene[i] << " ";
        }
        cout << endl;
    }

    void ustvariStudenta() {
        ime = "Ana";
        ocene[0] = 6;
        ocene[1] = 7;
        ocene[2] = 8;
        ocene[3] = 9;
        ocene[4] = 10;
    }

    void vnesiStudenta() {
        cout << "Vnesi ime studenta: ";
        cin >> ime;
        cout << "Vnesi 5 ocen:\n";
        for (int i = 0; i < 5; i++) {
            cin >> ocene[i];
        }
    }
};

int main() {
    Student demo;
	demo.ustvariStudenta();
    demo.izpisiStudenta();

    Student novStudent;
    novStudent.vnesiStudenta();
    novStudent.izpisiStudenta();

    return 0;
}
#endif

#ifdef OOP_30
class Student {
public:
    string ime;
    int ocene[5];

    void izpisiStudenta() {
        cout << "Ime: " << ime << endl;
        cout << "Ocene: ";
        for (int i = 0; i < 5; i++) {
            cout << ocene[i] << " ";
        }
        cout << endl;
    }

    void ustvariStudenta() {
        ime = "Ana";
        ocene[0] = 6;
        ocene[1] = 7;
        ocene[2] = 8;
        ocene[3] = 9;
        ocene[4] = 10;
    }

    void vnesiStudenta() {
        cout << "Vnesi ime studenta: ";
        cin >> ime;
        cout << "Vnesi 5 ocen:\n";
        for (int i = 0; i < 5; i++) {
            cin >> ocene[i];
        }
    }
};

int main() {
    Student demo;
    demo.ustvariStudenta();
    demo.izpisiStudenta();

    Student novStudent;
    novStudent.vnesiStudenta();
    novStudent.izpisiStudenta();

	cout << "----------------------------" << endl;
    novStudent.ime = "Mojca";
	novStudent.ocene[0] = 10;
	demo.ime = "Demo student";
	demo.ocene[0] = 5;

	demo.izpisiStudenta();
	novStudent.izpisiStudenta();

    return 0;
}
#endif

#ifdef ENKAPSULACIJA_10
class Student {
private:
    string ime;
    int ocene[5];

public:
    void izpisiStudenta() {
        cout << "Ime: " << ime << endl;
        cout << "Ocene: ";
        for (int i = 0; i < 5; i++) {
            cout << ocene[i] << " ";
        }
        cout << endl;
    }

    void ustvariStudenta() {
        ime = "Ana";
        ocene[0] = 6;
        ocene[1] = 7;
        ocene[2] = 8;
        ocene[3] = 9;
        ocene[4] = 10;
    }

    void vnesiStudenta() {
        cout << "Vnesi ime studenta: ";
        cin >> ime;
        cout << "Vnesi 5 ocen:\n";
        for (int i = 0; i < 5; i++) {
            cin >> ocene[i];
        }
    }
};

int main() {
    Student demo;
    demo.ustvariStudenta();
    demo.izpisiStudenta();

    Student novStudent;
    novStudent.vnesiStudenta();
    novStudent.izpisiStudenta();

    cout << "----------------------------" << endl;
    novStudent.ime = "Mojca";
    novStudent.ocene[0] = 10;
    demo.ime = "Demo student";
    demo.ocene[0] = 5;

    demo.izpisiStudenta();
    novStudent.izpisiStudenta();

    return 0;
}
#endif


#ifdef KONSTRUKTOR_10
class Student {
private:
    string ime;
    int starost;

public:
    Student(string i, int s) {
        ime = i;
        starost = s;
    }

    void izpisi() {
        cout << ime << " (" << starost << " let)" << endl;
    }
};

int main() {
    // Student demo;
	Student s1("Ana", 20);
	Student s2("Boris", 22);
	s1.izpisi();
	s2.izpisi();

    return 0;
}
#endif

#ifdef PRIVZETNI_KONSTRUKTOR_10
class Student {
private:
    string ime;
    int starost;

public:
    Student() {
        ime = "Neznan";
        starost = 0;
	}

    //Student(string i = "miha", int s = 10) {
    Student(string i, int s) {
        ime = i;
        starost = s;
    }

    void izpisi() {
        cout << ime << " (" << starost << " let)" << endl;
    }
};

int main() {
    Student demo;
    Student s1("Ana", 20);
    Student s2("Boris", 22);

	demo.izpisi();
    s1.izpisi();
    s2.izpisi();

    return 0;
}
#endif

#ifdef DESTRUKTOR_10
class Student {
public:
    Student() {
        cout << "Konstruktor\n";
    }

    ~Student() {
        cout << "Destruktor\n";
    }
};

int main() {
    Student s;
    cout << "KORAK 1\n";

	Student* p = new Student();
	cout << "KORAK 2\n";
	delete p;

	Student studenti[3];
    cout << "KORAK 3\n";

    return 0;
}
#endif


#ifdef DESTRUKTOR_20
class Student {
private:
	string ime;

public:
    Student(string ime) {
		this->ime = ime;
        cout << "Konstruktor za " << ime << "\n";
    }

    ~Student() {
        cout << "Destruktor za " << ime << "\n";
    }
};

int main() {
    Student s("s");
    cout << "KORAK 1\n";

    Student* p = new Student("p");
    cout << "KORAK 2\n";
    delete p;

	Student studenti[3] = { Student("Student1"), Student("Student2"), Student("Student3") };
    cout << "KORAK 3\n";

	cout << "Destruktorji se bodo sedaj poklicali ob izhodu iz main funkcije.\n";
	cout << "Kličejo se v obratnem vrstnem redu kot so bili ustvarjeni!!!!\n";
    return 0;
}
#endif


#ifdef DESTRUKTOR_DINAMICNI_POMNILNIK_10
class Primer {
private:
    int* a;

public:
    Primer() {
        a = new int[5];
        cout << "Pomnilnik alociran\n";
    }

    ~Primer() {
        delete[] a;
        cout << "Pomnilnik sproscen\n";
    }
};

int main() {
    Primer p;

	cout << "uporabljamo p\n";

    cout << "Konec programa\n";
    return 0;
}
#endif


#ifdef GETTER_SETTER_10
class Student {
private:
    string ime;
    int starost;

public:
    // privzeti konstruktor
    Student() {
        ime = "Neznano";
        starost = 0;
    }

    // konstruktor s parametri
    Student(string i, int s) {
        ime = i;
        setStarost(s);
    }

    // setter
    void setStarost(int s) {
		starost = (s >= 0) ? s : 0;
    }

    // getter
    int getStarost() {
        return starost;
    }

    void izpisi() {
        cout << ime << " (" << starost << " let)" << endl;
    }
};

int main() {
    Student a;
    Student b("Ana", 20);
    Student c("Marko", -5); // starost bo 0

    a.izpisi();
    b.izpisi();
    c.izpisi();

    return 0;
}

#endif


#ifdef POLJE_OBJEKTOV_10
class Student {
private:
    string ime;
    int starost;

public:
    Student() {
        ime = "Neznano";
        starost = 0;
    }

    Student(string i, int s) {
        ime = i;
        starost = s;
    }

    void izpisi() {
        cout << ime << " (" << starost << " let)" << endl;
    }
};

int main() {
    Student razred[3];

    razred[0] = Student("Ana", 20);
    razred[1] = Student("Marko", 21);
    razred[2] = Student("Luka", 22);

    for (int i = 0; i < 3; i++) {
        razred[i].izpisi();
    }

    return 0;
}
#endif


#ifdef DINAMICNO_POLJE_OBJEKTOV_10
class Student {
private:
    string ime;
    int starost;

public:
    Student() {
        ime = "Neznano";
        starost = 0;
    }

    void nastavi(string i, int s) {
        ime = i;
        starost = s;
    }

    void izpisi() {
        cout << ime << " (" << starost << " let)" << endl;
    }
};

int main() {
    int n;
    cout << "Koliko studentov? ";
    cin >> n;

    Student* razred = new Student[n];

    for (int i = 0; i < n; i++) {
        string ime;
        int starost;

        cout << "Ime: ";
        cin >> ime;
        cout << "Starost: ";
        cin >> starost;

        razred[i].nastavi(ime, starost);
    }

    cout << "\n--- IZPIS ---\n";
    for (int i = 0; i < n; i++) {
        razred[i].izpisi();
    }

    delete[] razred;
    return 0;
}

#endif

#ifdef DEDOVANJE_10
class Oseba {
protected:
    string ime;
    int starost;

public:
    Oseba(string i, int s) {
        ime = i;
        starost = s;
    }

    void izpisi() {
        cout << ime << " (" << starost << " let)" << endl;
    }
};

class Student : public Oseba {
private:
    int letnik;

public:
    Student(string i, int s, int l)
    : Oseba(i, s) 
    {
        letnik = l;
    }

    void izpisi() {
        Oseba::izpisi();
        cout << "Letnik: " << letnik << endl;
    }
};

int main()
{
    Oseba o("Ana", 20);
    Student s("Marko", 21, 2);
    o.izpisi();
    cout << "-----------------" << endl;
    s.izpisi();
    return 0;
}
#endif

#ifdef POLIMORFIZEM_10
class Oseba {
public:
    void izpisi() {
        cout << "Sem oseba" << endl;
    }
};

class Student : public Oseba {
public:
    void izpisi() {
        cout << "Sem student" << endl;
    }
};


int main()
{
    Oseba o1;
	o1.izpisi();   // izpiše: "Sem oseba"

	Student s1;
	s1.izpisi();   // izpiše: "Sem student"

    Oseba* o2 = new Oseba();
	o2->izpisi();   // izpiše: "Sem oseba"

	Student* s2 = new Student();
	s2->izpisi();   // izpiše: "Sem student"

    Oseba* os1 = new Student();
	os1->izpisi();   // izpiše: "Sem oseba" <--- !!!!!

    return 0;
}
#endif

#ifdef POLIMORFIZEM_20
class Oseba {
public:
	virtual void izpisi() {                 // <-- dodana ključna beseda virtual
        cout << "Sem oseba" << endl;
    }
};

class Student : public Oseba {
public:
    void izpisi() {
        cout << "Sem student" << endl;
    }
};


int main()
{
    Oseba o1;
    o1.izpisi();   // izpiše: "Sem oseba"

    Student s1;
    s1.izpisi();   // izpiše: "Sem student"

    Oseba* o2 = new Oseba();
    o2->izpisi();   // izpiše: "Sem oseba"

    Student* s2 = new Student();
    s2->izpisi();   // izpiše: "Sem student"

    Oseba* os1 = new Student();
    os1->izpisi();   // izpiše: "Sem oseba" <--- !!!!!

    return 0;
}
#endif

#ifdef POLIMORFIZEM_30
class Oseba {
public:
    virtual void izpisi() {
        cout << "Sem oseba" << endl;
    }
};

class Student : public Oseba {
public:
    void izpisi() override {
        cout << "Sem student" << endl;
    }
};

class Profesor : public Oseba {
public:
    void izpisi() override {
        cout << "Sem profesor" << endl;
    }
};

int main() {
    Oseba* seznam[3];
    seznam[0] = new Student();
    seznam[1] = new Profesor();
    seznam[2] = new Oseba();

    for (int i = 0; i < 3; i++) {
        seznam[i]->izpisi();
    }

    // počistimo pomnilnik
    for (int i = 0; i < 3; i++)
        delete seznam[i];

    return 0;
}

#endif


#ifdef ABSTRAKTNI_RAZRED_10
class Oseba {
public:
    virtual void izpisi() = 0;
};

class Student : public Oseba {
public:
    void izpisi() override {
        cout << "Sem student" << endl;
    }
};

class Profesor : public Oseba {
public:
    void izpisi() override {
        cout << "Sem profesor" << endl;
    }
};

int main() {
    Oseba* seznam[3];
    seznam[0] = new Student();
    seznam[1] = new Profesor();
    seznam[2] = new Oseba();

    for (int i = 0; i < 3; i++) {
        seznam[i]->izpisi();
    }

    // počistimo pomnilnik
    for (int i = 0; i < 3; i++)
        delete seznam[i];

    return 0;
}

#endif

#ifdef ABSTRAKTNI_RAZRED_20
class Oseba {
protected:
    string ime;

public:
    Oseba(string i) : ime(i) {}

    virtual void izpisi() = 0;

    void pozdrav() {
        cout << "Pozdravljen, " << ime << endl;
    }

    virtual ~Oseba() {}
};

class Student : public Oseba {
public:
    Student(string i = "") : Oseba(i) {}

    void izpisi() override {
        cout << "Sem student" << endl;
    }
};

class Profesor : public Oseba {
public:
    Profesor(string i = "") : Oseba(i) {}

    void izpisi() override {
        cout << "Sem profesor" << endl;
    }
};

int main() {
    Oseba* seznam[2];
    seznam[0] = new Student();
    seznam[1] = new Profesor();
    //seznam[2] = new Oseba();

    for (int i = 0; i < 2; i++) {
        seznam[i]->izpisi();
    }

    // počistimo pomnilnik
    for (int i = 0; i < 2; i++)
        delete seznam[i];

    return 0;
}

#endif

#ifdef BANCNI_RACUN_10

class BancniRacun {
private:
    double stanje;

public:
    BancniRacun(double zacetno) {
        stanje = zacetno;
    }

    void polog(double znesek) {
        if (znesek > 0)
            stanje += znesek;
    }

    bool dvig(double znesek) {
        if (znesek <= stanje) {
            stanje -= znesek;
            return true;
        }
        return false;
    }

    double getStanje() {
        return stanje;
    }
};

int main() {
    BancniRacun racun(100.0);

    racun.polog(50);
    racun.dvig(30);

    cout << "Stanje: " << racun.getStanje() << endl;
}
#endif

#ifdef GEOMETRIJSKI_LIKI_10

class GeometrijskiLik {
public:
    virtual double povrsina() = 0;
    virtual double obseg() = 0;
    virtual ~GeometrijskiLik() {}
};

class Krog : public GeometrijskiLik {
private:
    double polmer;

public:
    Krog(double r) : polmer(r) {}

    double povrsina() override {
        return 3.14159 * polmer * polmer;
    }

    double obseg() override {
        return 2 * 3.14159 * polmer;
    }
};

class Pravokotnik : public GeometrijskiLik {
private:
    double sirina, visina;

public:
    Pravokotnik(double sirina, double visina) 
        : sirina(sirina), visina(visina) {}

    double povrsina() override {
        return sirina * visina;
    }

    double obseg() override {
        return 2 * (sirina + visina);
    }
};

int main() {
    GeometrijskiLik* oblike[2];
    oblike[0] = new Krog(5);
    oblike[1] = new Pravokotnik(4, 6);

    for (int i = 0; i < 2; i++) {
        cout << "Ploščina: " << oblike[i]->povrsina() << endl;
        cout << "Obseg: " << oblike[i]->obseg() << endl;
    }

    for (int i = 0; i < 2; i++)
        delete oblike[i];
}

#endif

#ifdef ZAPOSLENI_10

enum TipZaposlitve {
    REDNO,
    STUDENTSKO
};

class Zaposleni {
protected:
    string ime;

public:
    Zaposleni(string ime) : ime(ime) {}
    virtual double placa() = 0;
    virtual void izpisi() = 0;
    virtual ~Zaposleni() {}
};

class RednoZaposleni : public Zaposleni {
private:
    double mesecnaPlaca;

public:
    RednoZaposleni(string ime, double placa)
        : Zaposleni(ime), mesecnaPlaca(placa) {
    }

    double placa() override {
        return mesecnaPlaca;
    }

    void izpisi() override {
        cout << ime << " (redno): " << placa() << endl;
    }
};

class StudentskoDelo : public Zaposleni {
private:
    int ure;
    double urnaPostavka;

public:
    StudentskoDelo(string ime, int ure, double urna)
        : Zaposleni(ime), ure(ure), urnaPostavka(urna) {
    }

    double placa() override {
        return ure * urnaPostavka;
    }

    void izpisi() override {
        cout << ime << " (student): " << placa() << endl;
    }
};

int main() {
    Zaposleni* seznam[2];
    seznam[0] = new RednoZaposleni("Ana", 2000);
    seznam[1] = new StudentskoDelo("Luka", 80, 7.5);

    for (int i = 0; i < 2; i++)
        seznam[i]->izpisi();

    for (int i = 0; i < 2; i++)
        delete seznam[i];
}

#endif