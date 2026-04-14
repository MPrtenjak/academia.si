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
    cout << "Vsebina košev:" << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "Koš " << i << ": ";
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

    cout << "Vnesi N: ";
    cin >> N;

    if (N <= 0)
    {
        cout << "N mora biti večji od 0." << endl;
        return 1;
    }

    vector<int>* buckets = new vector<int>[N];

    int number;
    cout << "Vnesi cela števila (0 za konec):" << endl;

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

#ifdef LOOKUP_10

int main()
{
    map<int, string> postOffices;
    
    postOffices[1000] = "Ljubljana";
    postOffices[2000] = "Maribor";
    postOffices[3000] = "Celje";
    postOffices[4000] = "Kranj";
    postOffices[5000] = "Nova Gorica";
    postOffices[6000] = "Koper";
    postOffices[8000] = "Novo mesto";
    postOffices[9000] = "Murska Sobota";
    
    cout << "Seznam vseh poštnih številk:" << endl;
    for (map<int, string>::iterator it = postOffices.begin(); 
         it != postOffices.end(); ++it)
    {
        cout << it->first << " - " << it->second << endl;
    }
    cout << endl;
    
    int postalCode;
    cout << "Vnesi poštno številko za iskanje (0 za konec): ";
    
    while (cin >> postalCode && postalCode != 0)
    {
        map<int, string>::iterator it = postOffices.find(postalCode);
        
        if (it != postOffices.end())
        {
            cout << "Kraj: " << it->second << endl;
        }
        else
        {
            cout << "Poštna številka " << postalCode << " ni bila najdena." << endl;
        }
        
        cout << "Vnesi poštno številko za iskanje (0 za konec): ";
    }
    
    return 0;
}

#endif

#ifdef LOOKUP_20

int main()
{
    map<string, string> peopleSizes;

    peopleSizes["xxs"] = "extra extra small";
    peopleSizes["xs"] = "extra small";
    peopleSizes["s"] = "small";
    peopleSizes["m"] = "middle";
    peopleSizes["l"] = "large";
    peopleSizes["xl"] = "extra large";
    peopleSizes["xxl"] = "extra large large";

    string size;
    cout << "Vnesi velikost (prazno za konec): ";

    while (cin >> size && !size.empty())
    {
        map<string, string>::iterator it = peopleSizes.find(size);

        if (it != peopleSizes.end())
        {
            cout << "Velikost: " << it->second << endl;
        }
        else
        {
            cout << "velikost " << size << " ni bila najdena." << endl;
        }

        cout << "Vnesi velikost (prazno za konec): ";
    }

    return 0;
}

#endif

#ifdef ASSOCIATIVE_CONTAINER_20

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

    usersBySurname.insert(pair<string, User>(u1.name, u1));
    usersBySurname.insert(pair<string, User>(u2.name, u2));
    usersBySurname.insert(pair<string, User>(u3.name, u3));
    usersBySurname.insert(pair<string, User>(u4.name, u4));
    usersBySurname.insert(pair<string, User>(u5.name, u5));

    cout << "Uporabniki, združeni po priimku:" << endl;

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

    cout << "Uporabniki, združeni po priimku, nato po imenu:" << endl;

    map<string, map<string, User> >::iterator itSurname;
    map<string, User>::iterator itName;

    for (itSurname = users.begin(); itSurname != users.end(); ++itSurname)
    {
        cout << "Priimek: " << itSurname->first << endl;

        for (itName = itSurname->second.begin(); itName != itSurname->second.end(); ++itName)
        {
            cout << "  Ime: " << itName->first
                << " -> starost " << itName->second.age << endl;
        }
    }

    return 0;
}

#endif