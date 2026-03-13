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

#ifdef ASSOCIATIVE_CONTAINER_10

using namespace std;

void printoutBuckets(vector<int>* buckets, int N)
{
	system("cls");
    cout << endl;
    cout << "Contents of buckets:" << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "Bucket " << i << ": ";
        for (int j = 0; j < (int)buckets[i].size(); j++)
        {
            cout << buckets[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int N;

    cout << "Enter N: ";
    cin >> N;

    if (N <= 0)
    {
        cout << "N must be greater than 0." << endl;
        return 1;
    }

    vector<int>* buckets = new vector<int>[N];

    int number;
    cout << "Enter integers (0 to stop):" << endl;

    while (true)
    {
        cin >> number;

        if (number == 0)
            break;

        int index = number % N;

        if (index < 0)
            index = index + N;   // handles negative numbers

        buckets[index].push_back(number);
        printoutBuckets(buckets, N);
    }

	printoutBuckets(buckets, N);

    delete[] buckets;

    return 0;
}

#endif

#ifdef ASSOCIATIVE_CONTAINER_20


using namespace std;

struct User
{
    string name;
    string surname;
    int age;
};

int main()
{
    User u1 = { "Ana", "Novak", 22 };
    User u2 = { "Boris", "Kovac", 30 };
    User u3 = { "Cene", "Novak", 27 };
    User u4 = { "Dora", "Horvat", 25 };
    User u5 = { "Eva", "Kovac", 19 };

    multimap<string, User> usersBySurname;

    usersBySurname.insert(pair<string, User>(u1.surname, u1));
    usersBySurname.insert(pair<string, User>(u2.surname, u2));
    usersBySurname.insert(pair<string, User>(u3.surname, u3));
    usersBySurname.insert(pair<string, User>(u4.surname, u4));
    usersBySurname.insert(pair<string, User>(u5.surname, u5));

    cout << "Users grouped by surname:" << endl;

    multimap<string, User>::iterator it;
    for (it = usersBySurname.begin(); it != usersBySurname.end(); ++it)
    {
        cout << it->first << " -> "
            << it->second.name << " "
            << it->second.surname << ", age "
            << it->second.age << endl;
    }

    return 0;
}

#endif

#ifdef ASSOCIATIVE_CONTAINER_30

using namespace std;

struct User
{
    string name;
    string surname;
    int age;
};

int main()
{
    User u1 = { "Ana", "Novak", 22 };
    User u2 = { "Boris", "Kovac", 30 };
    User u3 = { "Cene", "Novak", 27 };
    User u4 = { "Dora", "Horvat", 25 };
    User u5 = { "Eva", "Kovac", 19 };

    map<string, map<string, User> > users;

    users[u1.surname][u1.name] = u1;
    users[u2.surname][u2.name] = u2;
    users[u3.surname][u3.name] = u3;
    users[u4.surname][u4.name] = u4;
    users[u5.surname][u5.name] = u5;

    cout << "Users grouped by surname, then by name:" << endl;

    map<string, map<string, User> >::iterator itSurname;
    map<string, User>::iterator itName;

    for (itSurname = users.begin(); itSurname != users.end(); ++itSurname)
    {
        cout << "Surname: " << itSurname->first << endl;

        for (itName = itSurname->second.begin(); itName != itSurname->second.end(); ++itName)
        {
            cout << "  Name: " << itName->first
                << " -> age " << itName->second.age << endl;
        }
    }

    return 0;
}

#endif