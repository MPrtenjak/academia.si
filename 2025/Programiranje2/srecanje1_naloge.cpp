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

#ifdef RESITEV_SRECANJE_1_NALOGA_1

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

#ifdef RESITEV_SRECANJE_1_NALOGA_2

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


#ifdef RESITEV_SRECANJE_1_NALOGA_3

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


#ifdef RESITEV_SRECANJE_1_NALOGA_4

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


#ifdef RESITEV_SRECANJE_1_NALOGA_5

string readCommand()
{
    std::string in;
    std::cout << "Ukaz: ";

    // preberi ukaz, lahko vsebuje presledke, zato uporabimo getline
    std::getline(std::cin, in);
    return in;
}

void printCurrentStack(string prefix, const stack<string>& commands)
{
    stack<string> tmp = commands; // kopija, da ne uničimo originala
    cout << prefix << "[ ";
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
