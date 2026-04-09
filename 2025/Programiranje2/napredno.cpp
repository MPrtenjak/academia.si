#include "constants.h"
#include <iostream>
#include <limits>
#include <iomanip>
#include <stdexcept>
using namespace std;

#ifdef VZORCI_10

template <class T>
void swapValues(T& a, T& b) 
{ 
    T tmp = a;
    a = b;
    b = tmp; 
}


int main() {
	int a = 5, b = 10;
	cout << "a: " << a << ", b: " << b << endl;
	swapValues(a, b);
	cout << "a: " << a << ", b: " << b << endl << endl;

	double x = 3.14, y = 2.71;
	cout << "x: " << x << ", y: " << y << endl;
	swapValues(x, y);
	cout << "x: " << x << ", y: " << y << endl << endl;

	string str1 = "Pozdravljen", str2 = "Svet";
	cout << "str1: " << str1 << ", str2: " << str2 << endl;
	swapValues(str1, str2);
	cout << "str1: " << str1 << ", str2: " << str2 << endl << endl;

	return 0;
}
#endif

#ifdef VZORCI_20

template <class T, int SIZE>
class Stack
{

private:
    T   data[SIZE]{};
    int top; 

public:
    Stack() : top(-1) {}

    int push(const T& v)
    {
        if (top >= SIZE - 1) return 0;
        data[++top] = v;
        return 1;
    }

    int pop(T* out)
    {
        if (top < 0) return 0;
        if (out) *out = data[top];
        --top;
        return 1;
    }

    int isEmpty() const { return top < 0; }
    int size() const { return top + 1; }
};

int main() {
    Stack<int, 10> intStack;
    intStack.push(5);
    intStack.push(7);

	while (!intStack.isEmpty()) {
        int data;
        if (intStack.pop(&data)) 
		    cout << data << endl;
    }

	cout << "------------------" << endl;

    Stack<string, 10> stringStack;
    stringStack.push("danes");
    stringStack.push("je");
    stringStack.push("nov");
    stringStack.push("dan");

    while (!stringStack.isEmpty()) {
        string data;
        if (stringStack.pop(&data))
            cout << data << endl;
    }

	return 0;
}
#endif 

#ifdef FUNKCIJE_KOT_ARGUMENTI_10

void applyToArray(int* arr, int len, int (*func)(int))
{
    if (!arr || len <= 0 || !func) return;

    for (int i = 0; i < len; ++i) {
        arr[i] = func(arr[i]); 
    }
}

void printArray(const int* arr, int len)
{
    if (!arr || len <= 0) return;
    for (int i = 0; i < len; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int square(int x) { return x * x; }
int plus10(int x) { return x + 10; }

int main()
{
    int a[] = { 1, -2, 3, 4 };
    int n = (int)(sizeof(a) / sizeof(a[0]));

	printArray(a, n);

	cout << "------------------" << endl;
	cout << "Uporabljam funkcijo kvadriranja na tabeli:" << endl;
    applyToArray(a, n, square);
	printArray(a, n);

    cout << "------------------" << endl;
	cout << "Uporabljam funkcijo plus10 na tabeli:" << endl;
    applyToArray(a, n, plus10);
    printArray(a, n);

    return 0;
}

#endif


#ifdef FUNKCIJE_KOT_ARGUMENTI_20

void bubbleSort(int* arr, int len, int (*shouldSwap)(int a, int b))
{
    if (!arr || len <= 1 || !shouldSwap) return;

    for (int i = 0; i < len - 1; ++i) {
        for (int j = 0; j < len - 1 - i; ++j) {
            if (shouldSwap(arr[j], arr[j + 1])) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

void printArray(const int* arr, int len)
{
    if (!arr || len <= 0) return;
    for (int i = 0; i < len; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// če je levi večji, zamenjaj
int swapAsc(int a, int b) { return a > b; }  

// če je levi manjši, zamenjaj
int swapDesc(int a, int b) { return a < b; }  

// soda števila so manjša od lihih
// sicer sortiraj naraščujoče
int swapEvenAscOddAsc(int a, int b) {
    // zamenjaj, če je levo sodo in desno liho
    if ((a % 2 == 0) && (b % 2 != 0)) return 1; 

    // ne zamenjaj, če je levo liho in desno sodo
    if ((a % 2 != 0) && (b % 2 == 0)) return 0; 

    // sicer sortiraj naraščujoče
    return a > b; 
}

int swapBasedOnLastDigit(int a, int b) 
{
    int lastDigitA = abs(a) % 10;
    int lastDigitB = abs(b) % 10;

    // zamenjaj, če ima levi večjo zadnjo številko
    if (lastDigitA != lastDigitB) {
        return lastDigitA > lastDigitB; 
    }

    // sicer sortiraj naraščujoče
	return a > b; 
}

int main()
{
    int a[] = { -10, -14, 9, -37, -48, -15, 17, 39, 8, 16, -36, 31, -21, 26, 2, -25, 20, -15, -10, -41, 7, -34, 24, 44, 22, -4, -40 };
    int n = (int)(sizeof(a) / sizeof(a[0]));

    printArray(a, n);

    cout << "------------------" << endl;
	cout << "Razvrščanje tabele naraščajoče:" << endl;
    bubbleSort(a, n, swapAsc);
    printArray(a, n);

    cout << "------------------" << endl;
	cout << "Razvrščanje tabele padajoče:" << endl;
	bubbleSort(a, n, swapDesc);
    printArray(a, n);

    cout << "------------------" << endl;
    cout << "Razvrščanje tabele (najprej liha, nato soda števila):" << endl;
    bubbleSort(a, n, swapEvenAscOddAsc);
    printArray(a, n);

    cout << "------------------" << endl;
    cout << "Razvrščanje tabele (glede na zadnjo števko!):" << endl;
    bubbleSort(a, n, swapBasedOnLastDigit);
    printArray(a, n);

    return 0;
}

#endif

#ifdef STATIC_FUNCTIONS_10

class Math {
public:
    static int max(int a, int b) {
        return (a > b) ? a : b;
    }

    static int abs(int x) {
        return (x < 0) ? -x : x;
    }
};

int main() {
    std::cout << Math::max(3, 10) << "\n";   // 10
    std::cout << Math::abs(-7) << "\n";      // 7
}

#endif

#ifdef STATIC_FUNCTIONS_20

class Counter {
private:
    static int created;   // skupno za vse objekte

public:
    Counter() { created++; }

    static int howManyCreated() {  // vezano na razred
        return created;
    }

    // zmanjšaj števec ob uničenju objekta
	~Counter() { created--; }  
};

int Counter::created = 0; // definicija statičnega člana

int main() {
    Counter a, b, c;
    std::cout << Counter::howManyCreated() << "\n"; // 3

    Counter arr[13];
    std::cout << Counter::howManyCreated() << "\n"; // 16

	Counter* p = new Counter();
    std::cout << Counter::howManyCreated() << "\n"; // 17
	delete p;

    std::cout << Counter::howManyCreated() << "\n"; // 16

	return 0;
}

#endif

#ifdef NADGRAJEVANJE_OPERATORJEV_10

struct Vec2 {
    int x, y;

    Vec2(int x_ = 0, int y_ = 0) : x(x_), y(y_) {}

    Vec2 operator+(const Vec2& o) const {
        return Vec2(x + o.x, y + o.y);
    }

    Vec2 operator+(const int offset) const {
        return Vec2(x + offset, y + offset);
    }

    bool operator==(const Vec2& o) const {
        return x == o.x && y == o.y;
    }
};

int main() {
    Vec2 a(2, 3), b(10, -1);
    Vec2 c = a + b;
    std::cout << c.x << "," << c.y << "\n";
    std::cout << (c == Vec2(12, 2)) << "\n";

	Vec2 d = a + 5;
    std::cout << d.x << "," << d.y << "\n";
    std::cout << (d == Vec2(7, 8)) << "\n";
	return 0;
}

#endif

#ifdef NADGRAJEVANJE_OPERATORJEV_20

struct Log {
    Log& operator<<(const char* s) {
        std::cout << "[LOG] " << s << endl;
        return *this;
    }
    Log& operator<<(int x) {
        std::cout << "[LOG] " << x << endl;
        return *this;
    }
};

int main() {
    Log log;
    log << "Rezultat = " << 42 << "Starost = "  << 13;
}

#endif

#ifdef NADGRAJEVANJE_OPERATORJEV_30

struct Tiny3 {
    int a[3];

    int& operator[](int i) {
        if (i < 0 || i >= 3) throw std::out_of_range("indeks");
        return a[i];
    }
    const int& operator[](int i) const {
        if (i < 0 || i >= 3) throw std::out_of_range("indeks");
        return a[i];
    }
};

int main() {
    Tiny3 t;
    t[0] = 7;
    t[1] = 8;
    t[2] = 9;

    std::cout << t[1] << "\n"; // 8
}

#endif
