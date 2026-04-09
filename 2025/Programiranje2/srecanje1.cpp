#include "constants.h"
#include <iostream>
#include <limits>
#include <iomanip>
#include <stdexcept>
#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <queue>
#include <string>

using namespace std;

#ifdef INT_VECTOR_10

class IntVector {
private:
    int* data;
    int size;
    static const int MAX_CAPACITY = 10;

public:
    IntVector() {
        data = new int[MAX_CAPACITY];
        size = 0;
    }

    ~IntVector() {
        delete[] data;
    }

    int get(int i) const {
        if (i < 0 || i >= size) throw std::out_of_range("get");
        return data[i];
    }

    void set(int i, int x) {
        if (i < 0 || i >= size) throw std::out_of_range("set");
        data[i] = x;
    }

    int find(int x) const {
        for (int i = 0; i < size; ++i)
            if (data[i] == x) return i;
        return -1;
    }

    void push_back(int x) {
		if (size >= MAX_CAPACITY) throw std::out_of_range("push_back");
        data[size++] = x;
    }

    void push_front(int x) {
        insert(0, x);
    }

    void insert(int i, int x) {
        if (i < 0 || i > size || size >= MAX_CAPACITY) throw std::out_of_range("insert");

        for (int k = size; k > i; --k) {
            data[k] = data[k - 1];
        }
        data[i] = x;
        ++size;
    }

    void erase(int i) {
        if (i < 0 || i >= size) throw std::out_of_range("erase");

        for (int k = i; k < size - 1; ++k) {
            data[k] = data[k + 1];
        }
        --size;
    }
};

// ==== helper: print ====
void printIntVector(const IntVector& v, int count) {
    std::cout << "[ ";
    for (int i = 0; i < count; ++i) std::cout << v.get(i) << " ";
    std::cout << "]\n";
}

int main() {
    try {
        std::cout << "=== Preizkus IntVector ===\n";
        IntVector iv;

        // push_back
        iv.push_back(10);
        iv.push_back(20);
        iv.push_back(30);
        std::cout << "Po push_back 10,20,30: ";
        printIntVector(iv, 3);

        // push_front
        iv.push_front(5);
        std::cout << "Po push_front 5:      ";
        printIntVector(iv, 4);

        // insert
        iv.insert(2, 15);
        std::cout << "Po insert(2,15):      ";
        printIntVector(iv, 5);

        // get
        std::cout << "get(3) = " << iv.get(3) << " (pričakovano 20)\n";

        // set
        iv.set(3, 99);
        std::cout << "Po set(3,99):         ";
        printIntVector(iv, 5);

        // find
        std::cout << "find(15) = " << iv.find(15) << " (pričakovano 2)\n";
        std::cout << "find(123) = " << iv.find(123) << " (pričakovano -1)\n";

        // erase
        iv.erase(1);
        std::cout << "Po erase(1):          ";
        printIntVector(iv, 4);

        try
        {
            for (size_t i = 0; i < 12; i++)
            {
                std::cout << "Dodajam 12 na konec, ponovitev " << i << "\n";
                iv.push_back(12);
            }
        }
        catch (const std::exception& e)
        {
            std::cout << "Izjema: " << e.what() << "\n";
        }

        std::cout << "\nVsi testi so zaključeni.\n";
    }
    catch (const std::exception& e) {
        std::cout << "Izjema: " << e.what() << "\n";
    }

    return 0;
}
#endif

#ifdef SIMPLE_VECTOR_20

template <typename T>
class SimpleVector {
private:
    T* data;
    int size;
    static const int MAX_CAPACITY = 10;

public:
    SimpleVector() {
        data = new T[MAX_CAPACITY];
        size = 0;
    }

    ~SimpleVector() {
        delete[] data;
    }

    T get(int i) const {
        if (i < 0 || i >= size) throw std::out_of_range("get");
        return data[i];
    }

    void set(int i, T x) {
        if (i < 0 || i >= size) throw std::out_of_range("set");
        data[i] = x;
    }

    int find(T x) const {
        for (int i = 0; i < size; ++i)
            if (data[i] == x) return i;
        return -1;
    }

    void push_back(T x) {
        if (size >= MAX_CAPACITY) throw std::out_of_range("push_back");
        data[size++] = x;
    }

    void push_front(T x) {
        insert(0, x);
    }

    void insert(int i, T x) {
        if (i < 0 || i > size || size >= MAX_CAPACITY) throw std::out_of_range("insert");

        for (int k = size; k > i; --k) {
            data[k] = data[k - 1];
        }
        data[i] = x;
        ++size;
    }

    void erase(int i) {
        if (i < 0 || i >= size) throw std::out_of_range("erase");

        for (int k = i; k < size - 1; ++k) {
            data[k] = data[k + 1];
        }
        --size;
    }
};

template <typename T>
void printSimpleVector(const SimpleVector<T>& v, int count) {
    std::cout << "[ ";
    for (int i = 0; i < count; ++i) std::cout << v.get(i) << " ";
    std::cout << "]\n";
}

int main() {
    try {
        std::cout << "=== Preizkus SimpleVector<int> ===\n";
        SimpleVector<int> iv;

        // push_back
        iv.push_back(10);
        iv.push_back(20);
        iv.push_back(30);
        std::cout << "Po push_back 10,20,30: ";
        printSimpleVector(iv, 3);

        // push_front
        iv.push_front(5);
        std::cout << "Po push_front 5:      ";
        printSimpleVector(iv, 4);

        // insert
        iv.insert(2, 15); // [5,10,15,20,30]
        std::cout << "Po insert(2,15):      ";
        printSimpleVector(iv, 5);

        // get
        std::cout << "get(3) = " << iv.get(3) << " (pričakovano 20)\n";

        // set
        iv.set(3, 99); // [5,10,15,99,30]
        std::cout << "Po set(3,99):         ";
        printSimpleVector(iv, 5);

        // find
        std::cout << "find(15) = " << iv.find(15) << " (pričakovano 2)\n";
        std::cout << "find(123) = " << iv.find(123) << " (pričakovano -1)\n";

        // erase
        iv.erase(1); // remove 10 -> [5,15,99,30]
        std::cout << "Po erase(1):          ";
        printSimpleVector(iv, 4);

        std::cout << "\nVsi testi so zaključeni.\n";

        std::cout << "\n=== Preizkus SimpleVector<std::string> ===\n";
        SimpleVector<std::string> sv;

        // push_back
        sv.push_back("B");
        sv.push_back("C");
        std::cout << "Po push_back B,C:     ";
        printSimpleVector(sv, 2);

        // push_front
        sv.push_front("A");
        std::cout << "Po push_front A:      ";
        printSimpleVector(sv, 3);

        // insert
        sv.insert(3, "E"); // append via insert
        sv.insert(3, "D"); // [A,B,C,D,E]
        std::cout << "Po insert D,E:        ";
        printSimpleVector(sv, 5);

        // get
        std::cout << "get(4) = " << sv.get(4) << " (pričakovano E)\n";

        // set
        sv.set(2, "X"); // [A,B,X,D,E]
        std::cout << "Po set(2,X):          ";
        printSimpleVector(sv, 5);

        // find
        std::cout << "find(D) = " << sv.find("D") << " (pričakovano 3)\n";
        std::cout << "find(Z) = " << sv.find("Z") << " (pričakovano -1)\n";

        // erase
        sv.erase(1); // remove B -> [A,X,D,E]
        std::cout << "Po erase(1):          ";
        printSimpleVector(sv, 4);

        std::cout << "\nVsi testi so zaključeni.\n";
    }
    catch (const std::exception& e) {
        std::cout << "Izjema: " << e.what() << "\n";
    }

    return 0;
}

#endif

#ifdef QUEUE

struct Element {
    int value;
    Element* next;
};

class Queue {
private:
    Element* head;
    Element* tail;
    int count;

public:
    Queue() : head(0), tail(0), count(0) {}

    ~Queue() {
        // pobriše vse elemente
        while (!isEmpty()) 
            dequeue(); 
    }

    void enqueue(int x) {
        Element* e = new Element;
        e->value = x;
        e->next = NULL;

        if (head == NULL) {
            head = tail = e;
        }
        else {
            tail->next = e;
            tail = e;
        }

        ++count;
    }

    int dequeue() {
        if (isEmpty()) throw std::out_of_range("dequeue: prazna vrsta");

        Element* old = head;
        int v = old->value;

        head = head->next;

        // če je bil zadnji element
        if (head == NULL) tail = NULL;  

        delete old;
        --count;
        return v;
    }

    int front() const { // peek
        if (isEmpty()) throw std::out_of_range("front: prazna vrsta");
        return head->value;
    }

    bool isEmpty() const {
        return head == NULL; // ali count==0
    }

    int size() const {
        return count;
    }
};

int main() {
    Queue q;

    std::cout << "Prazna? " << q.isEmpty() << "\n";
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    std::cout << "Velikost: " << q.size() << "\n";
    std::cout << "Začetek: " << q.front() << "\n";

    std::cout << "Odstrani iz vrste: " << q.dequeue() << "\n";
    std::cout << "Začetek: " << q.front() << "\n";
    std::cout << "Velikost: " << q.size() << "\n";

    std::cout << "Odstrani iz vrste: " << q.dequeue() << "\n";
    std::cout << "Odstrani iz vrste: " << q.dequeue() << "\n";

    std::cout << "Prazna? " << q.isEmpty() << "\n";

    return 0;
}

#endif

#ifdef PRIMER_01

int main()
{
	std::vector<int> v = { 1, 2, 3, 4, 5 };

    // print before
    std::cout << "Pred: [ ";
    for (int i = 0; i < (int)v.size(); ++i) std::cout << v[i] << " ";
    std::cout << "]\n";

    // reverse using stack
    std::stack<int> s;

    for (int i = 0; i < (int)v.size(); ++i) {
        s.push(v[i]);
    }

    for (int i = 0; i < (int)v.size(); ++i) {
        v[i] = s.top();
        s.pop();
    }

    // print after
    std::cout << "Po:    [ ";
    for (int i = 0; i < (int)v.size(); ++i) std::cout << v[i] << " ";
    std::cout << "]\n";

    return 0;
}

#endif


#ifdef PRIMER_02

int main()
{
    std::vector<int> v = { 1, 2, 1, 2, 2, 1, 3, 4, 1, 4 };

    // print before
    std::cout << "Pred: [ ";
    for (int i = 0; i < (int)v.size(); ++i) std::cout << v[i] << " ";
    std::cout << "]\n";

    std::set<int> allNumbers;
    std::cout << "After: [ ";
    for (int i = 0; i < (int)v.size(); ++i)
    {
		int value = v[i];
		if (allNumbers.find(value) != allNumbers.end()) continue; // že smo videli, preskočimo

		std::cout << value << " ";
		allNumbers.insert(value);
    }
    std::cout << "]\n";


    return 0;
}

#endif

#ifdef PRIMER_03

int main()
{
	std::vector<int> v = { 1, 2, 1, 2, 2, 1, 3, 4, 1, 4 };

    // print before
    std::cout << "Pred: [ ";
    for (int i = 0; i < (int)v.size(); ++i) std::cout << v[i] << " ";
    std::cout << "]\n";

    std::set<int> allNumbers;
    std::cout << "After: [ ";
    for (int i = 0; i < (int)v.size(); ++i)
    {
        int value = v[i];
        if (allNumbers.find(value) != allNumbers.end()) 
            std::cout << value << " ";

        allNumbers.insert(value);
    }
    std::cout << "]\n";


    return 0;
}

#endif


#ifdef PRIMER_04

bool isValid(string expression)
{
	stack<char> stack;
    for (int c = 0; c < (int)expression.size(); ++c)
    {
        char ch = expression[c];
        if (ch == '(' || ch == '{' || ch == '[') {
            stack.push(ch);
        }

        if (ch == ')' || ch == '}' || ch == ']') {
            if (stack.empty()) return false;
			char pair = stack.top();
            stack.pop();

            if ((ch == ')' && pair != '(') ||
                (ch == '}' && pair != '{') ||
                (ch == ']' && pair != '[')) {
                    return false;
			}
        }
    }

    return stack.empty();
}

int main()
{
    string inputExpression;

    while (true) {
        cout << "Vnesi izraz ('x' za izhod): ";
        cin >> inputExpression;

		if (inputExpression == "x") break;

        if (isValid(inputExpression)) {
            cout << "Izraz je veljaven.\n";
        }
        else {
            cout << "Izraz NI veljaven.\n";
        }

        cout << endl << endl;
    }

	return 0;
}

#endif

