#include "constants.h"
#include <iostream>
#include <limits>
#include <iomanip>
#include <stdexcept>
#include <vector>
#include <stack>
#include <set>
#include <queue>
#include <string>
#include <map>

using namespace std;

#ifdef BUBBLE_SORT_10

void bubbleSort(int a[], int n)
{
    int i, j, temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int a[] = { 42, 7, 19, 3, 25, 10 };
    int n = sizeof(a) / sizeof(a[0]);
    int i;

    cout << "Pred razvrščanjem:" << endl;
    for (i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    bubbleSort(a, n);

    cout << "Po razvrščanju:" << endl;
    for (i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}

#endif


#ifdef BUBBLE_SORT_20

struct User
{
    string name;
    string surname;
    int age;
};

void bubbleSortUsersBySurname(User users[], int n)
{
    int i, j;
    User temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (users[j].surname > users[j + 1].surname)
            {
                temp = users[j];
                users[j] = users[j + 1];
                users[j + 1] = temp;
            }
        }
    }
}

int main()
{
    User users[] =
    {
        {"Ana", "Novak", 22},
        {"Boris", "Kovac", 30},
        {"Cene", "Horvat", 27},
        {"Dora", "Zupan", 25},
        {"Eva", "Bizjak", 19}
    };

    int n = sizeof(users) / sizeof(users[0]);
    int i;

    cout << "Pred razvrščanjem:" << endl;
    for (i = 0; i < n; i++)
    {
        cout << users[i].name << " "
            << users[i].surname << " "
            << users[i].age << endl;
    }

    bubbleSortUsersBySurname(users, n);

    cout << endl;
    cout << "Po razvrščanju po priimku:" << endl;
    for (i = 0; i < n; i++)
    {
        cout << users[i].name << " "
            << users[i].surname << " "
            << users[i].age << endl;
    }

    return 0;
}

#endif


#ifdef BUBBLE_SORT_30

#include <iostream>
#include <string>

using namespace std;

struct User
{
    string name;
    string surname;
    int age;
};

template <class T>
void bubbleSort(T data[], int N, bool (*compare)(const T&, const T&))
{
    int i, j;
    T temp;

    for (i = 0; i < N - 1; i++)
    {
        for (j = 0; j < N - 1 - i; j++)
        {
            if (compare(data[j], data[j + 1]))
            {
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

bool compareInt(const int& a, const int& b)
{
    return a > b;
}

bool compareUserBySurname(const User& a, const User& b)
{
    return a.surname > b.surname;
}

bool compareUserByName(const User& a, const User& b)
{
    return a.name > b.name;
}

void printInts(int data[], int N)
{
    int i;

    for (i = 0; i < N; i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}

void printUsers(User data[], int N)
{
    int i;

    for (i = 0; i < N; i++)
    {
        cout << data[i].name << " "
            << data[i].surname << " "
            << data[i].age << endl;
    }
}

int main()
{
    int numbers[] = { 42, 7, 19, 3, 25, 10 };
    int nNumbers = sizeof(numbers) / sizeof(numbers[0]);

    User users[] =
    {
        {"Ana", "Novak", 22},
        {"Boris", "Kovac", 30},
        {"Cene", "Horvat", 27},
        {"Dora", "Zupan", 25},
        {"Eva", "Bizjak", 19}
    };
    int nUsers = sizeof(users) / sizeof(users[0]);

    cout << "Cela števila pred razvrščanjem:" << endl;
    printInts(numbers, nNumbers);

    bubbleSort(numbers, nNumbers, compareInt);

    cout << "Cela števila po razvrščanju:" << endl;
    printInts(numbers, nNumbers);

    cout << endl;

    cout << "Uporabniki pred razvrščanjem:" << endl;
    printUsers(users, nUsers);

    bubbleSort(users, nUsers, compareUserBySurname);

    cout << endl;
    cout << "Uporabniki po razvrščanju po priimku:" << endl;
    printUsers(users, nUsers);


    bubbleSort(users, nUsers, compareUserByName);

    cout << endl;
    cout << "Uporabniki po razvrščanju po imenu:" << endl;
    printUsers(users, nUsers);

    return 0;
}

#endif
