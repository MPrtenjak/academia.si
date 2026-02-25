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
    int capacity;
    static const int MIN_CAP = 10;

    void resize(int newCap) {
        if (newCap < MIN_CAP) newCap = MIN_CAP;

        int* b = new int[newCap];
        for (int i = 0; i < size; ++i) b[i] = data[i];

        delete[] data;
        data = b;
        capacity = newCap;
    }

    void grow_if_needed() {
        if (size < capacity) return;
        resize(capacity * 2);
    }

    void shrink_if_needed() {
        if (capacity <= MIN_CAP) return;
        if (size <= capacity / 4) resize(capacity / 2);
    }

public:
    IntVector() {
        data = new int[MIN_CAP];
        size = 0;
        capacity = MIN_CAP;
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
        grow_if_needed();
        data[size++] = x;
    }

    void push_front(int x) {
        insert(0, x);
    }

    void insert(int i, int x) {
        if (i < 0 || i > size) throw std::out_of_range("insert");

        grow_if_needed();

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
        shrink_if_needed();
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
        std::cout << "=== Test IntVector ===\n";
        IntVector iv;

        // push_back
        iv.push_back(10);
        iv.push_back(20);
        iv.push_back(30);
        std::cout << "After push_back 10,20,30: ";
        printIntVector(iv, 3);

        // push_front
        iv.push_front(5);
        std::cout << "After push_front 5:      ";
        printIntVector(iv, 4);

        // insert
        iv.insert(2, 15); // [5,10,15,20,30]
        std::cout << "After insert(2,15):      ";
        printIntVector(iv, 5);

        // get
        std::cout << "get(3) = " << iv.get(3) << " (expected 20)\n";

        // set
        iv.set(3, 99); // [5,10,15,99,30]
        std::cout << "After set(3,99):         ";
        printIntVector(iv, 5);

        // find
        std::cout << "find(15) = " << iv.find(15) << " (expected 2)\n";
        std::cout << "find(123) = " << iv.find(123) << " (expected -1)\n";

        // erase
        iv.erase(1); // remove 10 -> [5,15,99,30]
        std::cout << "After erase(1):          ";
        printIntVector(iv, 4);

        std::cout << "\n=== Test SimpleVector<std::string> ===\n";
        SimpleVector<std::string> sv;

        // push_back
        sv.push_back("B");
        sv.push_back("C");
        std::cout << "After push_back B,C:     ";
        printSimpleVector(sv, 2);

        // push_front
        sv.push_front("A");
        std::cout << "After push_front A:      ";
        printSimpleVector(sv, 3);

        // insert
        sv.insert(3, "E"); // append via insert
        sv.insert(3, "D"); // [A,B,C,D,E]
        std::cout << "After insert D,E:        ";
        printSimpleVector(sv, 5);

        // get
        std::cout << "get(4) = " << sv.get(4) << " (expected E)\n";

        // set
        sv.set(2, "X"); // [A,B,X,D,E]
        std::cout << "After set(2,X):          ";
        printSimpleVector(sv, 5);

        // find
        std::cout << "find(D) = " << sv.find("D") << " (expected 3)\n";
        std::cout << "find(Z) = " << sv.find("Z") << " (expected -1)\n";

        // erase
        sv.erase(1); // remove B -> [A,X,D,E]
        std::cout << "After erase(1):          ";
        printSimpleVector(sv, 4);

        std::cout << "\nAll tests done.\n";
    }
    catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << "\n";
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
    int capacity;
    static const int MIN_CAP = 10;

    void resize(int newCap) {
        if (newCap < MIN_CAP) newCap = MIN_CAP;

        T* b = new T[newCap];
        for (int i = 0; i < size; ++i) b[i] = data[i];

        delete[] data;
        data = b;
        capacity = newCap;
    }

    void grow_if_needed() {
        if (size < capacity) return;
        resize(capacity * 2);
    }

    void shrink_if_needed() {
        if (capacity <= MIN_CAP) return;
        if (size <= capacity / 4) resize(capacity / 2);
    }

public:
    SimpleVector() {
        data = new T[MIN_CAP];
        size = 0;
        capacity = MIN_CAP;
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
        grow_if_needed();
        data[size++] = x;
    }

    void push_front(T x) {
        insert(0, x);
    }

    void insert(int i, T x) {
        if (i < 0 || i > size) throw std::out_of_range("insert");

        grow_if_needed();

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
        shrink_if_needed();
    }
};
#endif

#ifdef QUEUE

#include <iostream>
#include <stdexcept>

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
        if (isEmpty()) throw std::out_of_range("dequeue: empty queue");

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
        if (isEmpty()) throw std::out_of_range("front: empty queue");
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

    std::cout << "Empty? " << q.isEmpty() << "\n";
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    std::cout << "Size: " << q.size() << "\n";
    std::cout << "Front: " << q.front() << "\n";

    std::cout << "Dequeue: " << q.dequeue() << "\n";
    std::cout << "Front: " << q.front() << "\n";
    std::cout << "Size: " << q.size() << "\n";

    std::cout << "Dequeue: " << q.dequeue() << "\n";
    std::cout << "Dequeue: " << q.dequeue() << "\n";

    std::cout << "Empty? " << q.isEmpty() << "\n";

    return 0;
}

#endif

#ifdef PRIMER_01

int main()
{
	std::vector<int> v = { 1, 2, 3, 4, 5 };
*/
    // print before
    std::cout << "Before: [ ";
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
    std::cout << "After:  [ ";
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
    std::cout << "Before: [ ";
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
    std::cout << "Before: [ ";
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
        cout << "Enter an expression ('x' to exit): ";
        cin >> inputExpression;

		if (inputExpression == "x") break;

        if (isValid(inputExpression)) {
            cout << "The expression is valid.\n";
        }
        else {
            cout << "The expression is NOT valid.\n";
        }

        cout << endl << endl;
    }

	return 0;
}

#endif

#ifdef RESITEV_01

int main()
{
    // ker vrste ne moremo napolniti tako kot vektorja, C++ ne pozna inicializacije vrst
    vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	queue<int> queue;
    for (int i = 0; i < numbers.size(); ++i)
		queue.push(numbers[i]);

    for (int i = 0; i < 5; ++i)
        queue.pop();

	while (!queue.empty())
    {
        cout << queue.front() << " ";
        queue.pop();
    }

    return 0;
}

#endif

#ifdef RESITEV_02

long long fibonacci(int iN)
{
	if (iN < 0) throw std::invalid_argument("Negative index not allowed");
	if (iN == 0 || iN == 1) return 1;

    vector<long long> fib{ 1, 1 };
    for (int i = 2; i <= iN; ++i)
        fib.push_back(fib[i - 2] + fib[i - 1]);

    return fib[iN];
}

int main()
{
	for (int i = 0; i <= 50; ++i)
        cout << "Fibonacci of " << i << ": " << fibonacci(i) << endl;
}

#endif


#ifdef RESITEV_03

int main()
{
    vector<string> vPhoneNums = {
        "041111000",
        "031111000",
        "051555111",
        "051555000",
        "041111000",
        "031111000",
        "069902333",
        "041111000"
	};

    set<string> set;
    for (int i = 0; i < vPhoneNums.size(); ++i) {
        if (set.find(vPhoneNums[i]) != set.end())
            cout << "Številko [" << vPhoneNums[i] << "] že imamo" << endl;
        else
            cout << "Številke [" << vPhoneNums[i] << "] še nimamo" << endl;

		set.insert(vPhoneNums[i]);
    }
}

#endif


#ifdef RESITEV_04

int main()
{
    // ker sklada ne moremo napolniti tako kot vektorja, C++ ne pozna inicializacije skladov
    vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7 };
    stack<int> stck;
    for (int i = 0; i < numbers.size(); ++i)
        stck.push(numbers[i]);

	stack<int> tmp; 
    int iN = stck.size();
    for (int i = 0; i < iN / 2; ++i)
    {
        tmp.push(stck.top());
        stck.pop();
    }

    stck.pop();

    while (!tmp.empty()) {
        stck.push(tmp.top());
        tmp.pop();
    }

    while (!stck.empty())
    {
        cout << stck.top() << " ";
        stck.pop();
	}
}

#endif


#ifdef RESITEV_05

string readCommand()
{
    std::string in;
    std::cout << "Ukaz: ";

    // preberi ukaz, lahko vsebuje presledke, zato uporabimo getline
    std::getline(std::cin, in); // correct function
	return in;
}

void printCurrentStack(string prefix, const stack<string>& commands)
{
    stack<string> tmp = commands; // kopija, da ne uničimo originala
    cout << prefix <<"[ ";
    while (!tmp.empty()) {
        cout << tmp.top() << " ";
        tmp.pop();
    }
    cout << "]\n";
}

int main(int argc, char* argv[])
{
    stack<string> commands;

    string command = readCommand();
    while (command != "konec") {
        if (command == "undo")
            commands.pop();
        else
            commands.push(command);

		printCurrentStack("SKLAD: ", commands);
        command = readCommand();
    }

	// sedaj moramo ukaze obrniti, da jih bomo izvedli v pravem vrstnem redu
    stack<string> finalCommands;
    while (!commands.empty()) {
        finalCommands.push(commands.top());
        commands.pop();
	}

    printCurrentStack("Ukazi, ki jih bomo izvedli: ", finalCommands);
	return 0;
}



#endif
