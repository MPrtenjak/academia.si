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
#include <map>
#include <algorithm>

#ifdef _WIN32
#include <windows.h>
#include <io.h>
#include <fcntl.h>
#endif

using namespace std;

#ifdef RESITEV_SRECANJE_3_NALOGA_1_2

int main()
{
	const int NUM_BUCKETS = 12;

	vector<double> numbers = { 0.35, 1.163, 1.312, 0.493, 0.478, 0.9913, 0.95112, 0.4, 1.2356, 0.6 };
	for (vector<double>::iterator i = numbers.begin(); i != numbers.end(); ++i)
	{
		double number = *i;
		long value = std::round(number * 100);
		double bucket = value % NUM_BUCKETS;

		cout << "Število " << number << " gre v košaro številka #" << bucket << endl;
	}

	return 0;
}

#endif

#ifdef RESITEV_SRECANJE_3_NALOGA_3_4_5

struct Owner
{
	string name;
	string surname;
	string telephonNumber;
};

std::vector<Owner> getRandomData()
{
	return {
		{"Matej", "Novak", "031-456-789"},
		{"Ana", "Horvat", "041-234-567"},
		{"Janez", "Kovačič", "051-678-234"},
		{"Nina", "Krajnc", "040-987-654"},
		{"Luka", "Zupan", "031-555-123"},
		{"Eva", "Potočnik", "041-876-543"},
		{"Marko", "Vidmar", "051-234-876"},
		{"Sara", "Mlakar", "040-765-432"},
		{"Tomaž", "Pavlič", "031-321-654"},
		{"Petra", "Golob", "041-147-258"}
	};
}

Owner GetOwner(const string& telephonNumber)
{
	Owner owner;
	owner.telephonNumber = telephonNumber;

	cout << "Vnesite ime: ";
	cin >> owner.name;

	cout << "Vnesite priimek: ";
	cin >> owner.surname;

	return owner;
}

void AskForNewOwner(std::string& telephonNumber, std::map<std::string, Owner>& telephonNumberLookup)
{
	cout << "Želite dodati novo osebo? (D/N): ";
	char choice;
	cin >> choice;
	if (choice == 'd' || choice == 'D') {
		Owner newOwner = GetOwner(telephonNumber);
		telephonNumberLookup[telephonNumber] = newOwner;
		cout << "Oseba dodana: " << newOwner.name << " " << newOwner.surname << endl;
	}
}

int main()
{
	vector<Owner> owners = getRandomData();

	map<string, Owner> telephonNumberLookup;
	for (vector<Owner>::iterator i = owners.begin(); i != owners.end(); ++i)
	{
		cout << "Lastnik: " << i->name << " " << i->surname
			<< ", telefon: " << i->telephonNumber << endl;

		telephonNumberLookup.insert(pair(i->telephonNumber, *i));
	}

	cout << endl << endl;
	do {
		cout << "Vpišite telefonsko številko ('q' za prekinitev): ";

		string telephonNumber;
		cin >> telephonNumber;

		if (telephonNumber == "q")
			break;

		auto it = telephonNumberLookup.find(telephonNumber);
		if (it != telephonNumberLookup.end()) {
			Owner& owner = it->second;
			cout << "Oseba: " << owner.name << " " << owner.surname << endl;
		}
		else {
			cout << "Osebe s telefonsko številko " << telephonNumber << " ne najdem" << endl;
			AskForNewOwner(telephonNumber, telephonNumberLookup);
		}
	} while (true);

	return 0;
}

#endif

#ifdef RESITEV_SRECANJE_3_NALOGA_6

int main()
{
	string data;
	cout << "vnestite besedilo ";
	getline(cin, data);


	cout << "Urejeno po črkah" << endl;

	map<char, int> charCount;
	for (char c : data)
	{
		charCount[c]++;
	}

	for (auto cc : charCount)
	{
		cout << "črka " << cc.first << " se pojavi " << cc.second << endl;
	}
}
#endif

#ifdef RESITEV_SRECANJE_3_NALOGA_6a

int main()
{
#ifdef _WIN32
	// Set console to UTF-16 on Windows for proper Unicode support
	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);
#endif

	wstring data;
	wcout << L"vnestite besedilo ";
	getline(wcin, data);

	wcout << L"Urejeno po črkah" << endl;

	map<wchar_t, int> charCount;
	for (wchar_t c : data)
	{
		charCount[c]++;
	}

	for (auto cc : charCount)
	{
		wcout << L"črka '" << cc.first << L"' se pojavi " << cc.second << endl;
	}

	return 0;
}

#endif

#ifdef RESITEV_SRECANJE_3_NALOGA_7_8

struct Student
{
	string ime;
	string priimek;
	int ocena;
	string predmet;
};

struct StudentKey
{
	string ime;
	string priimek;
	string predmet;

	StudentKey(const string& i, const string& p, const string& pr)
		: ime(i), priimek(p), predmet(pr) {}

	bool operator<(const StudentKey& other) const
	{
		if (ime != other.ime)
			return ime < other.ime;
		if (priimek != other.priimek)
			return priimek < other.priimek;
		return predmet < other.predmet;
	}
};

std::vector<Student> getRandomStudents()
{
	return {
		{"Anja", "Novak", 6, "Matematika"},
		{"Luka", "Horvat", 7, "Fizika"},
		{"Nina", "Kovačič", 8, "Zbirke podatkov 1"},
		{"Matej", "Krajnc", 9, "Zbirke podatkov 1"},
		{"Eva", "Zupan", 6, "Zbirke podatkov 1"},
		{"Jan", "Potočnik", 8, "Zbirke podatkov 1"},
		{"Sara", "Vidmar", 6, "Zbirke podatkov 1"},
		{"Gašper", "Mlakar", 9, "Zbirke podatkov 1"},
		{"Maja", "Pavlič", 10, "Informatika"},
		{"Tim", "Golob", 6, "Zbirke podatkov 1"}
	};
}

std::map<StudentKey, int> createStudentMap(const std::vector<Student>& students)
{
	std::map<StudentKey, int> studentMap;

	for (size_t i = 0; i < students.size(); ++i)
	{
		StudentKey key(students[i].ime, students[i].priimek, students[i].predmet);
		studentMap[key] = students[i].ocena;
	}

	return studentMap;
}

int main()
{
	vector<Student> students = getRandomStudents();

	cout << "Seznam študentov:" << endl << endl;

	for (size_t i = 0; i < students.size(); ++i)
	{
		cout << "Študent: " << students[i].ime << " " << students[i].priimek
			<< ", predmet: " << students[i].predmet
			<< ", ocena: " << students[i].ocena << endl;
	}

	cout << endl << "Uporaba mape:" << endl << endl;

	std::map<StudentKey, int> studentMap = createStudentMap(students);

	for (std::map<StudentKey, int>::iterator it = studentMap.begin(); it != studentMap.end(); ++it)
	{
		cout << "Študent: " << it->first.ime << " " << it->first.priimek
			<< ", predmet: " << it->first.predmet
			<< ", ocena: " << it->second << endl;
	}

	for (;;)
	{
		cout << endl << "Iskanje ocene študenta:" << endl;
		cout << "Vnesite ime 'q' za konec: ";
		string ime;
		getline(cin, ime);

		if (ime == "q")
			break;

		cout << "Vnesite priimek: ";
		string priimek;
		getline(cin, priimek);

		cout << "Vnesite predmet: ";
		string predmet;
		getline(cin, predmet);

		StudentKey searchKey(ime, priimek, predmet);
		auto it = studentMap.find(searchKey);

		if (it != studentMap.end()) {
			cout << "Ocena: " << it->second << endl;
		}
		else {
			cout << "ne najdem" << endl;
		}
	}

	cout << endl << "Študenti predmeta 'Zbirke podatkov 1':" << endl << endl;

	for (const auto& entry : studentMap) {
		if (entry.first.predmet == "Zbirke podatkov 1") {
			cout << "Študent: " << entry.first.ime << " " << entry.first.priimek
				<< ", ocena: " << entry.second << endl;
		}
	}

	return 0;
}

#endif