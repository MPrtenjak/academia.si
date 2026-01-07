#include <iostream>
#include <limits>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <exception>
#include <sstream>
using namespace std;

#define TOKOVI_10

#ifdef TOKOVI_10

int main()
{
	ofstream izhodniTok("c:\\temp\\izhod.txt");

	if (!izhodniTok) {
		cerr << "Napaka pri odpiranju datoteke za pisanje!" << endl;
		return 1;
	}

	izhodniTok << "To je prvi zapis v datoteko." << endl;
	izhodniTok << "To je drugi zapis v datoteko." << endl;

	izhodniTok.close();

	return 0;
}

#endif

#ifdef TOKOVI_20

int main()
{
	ofstream izhodniTok("c:\\temp\\izhod.txt", ios::app);

	if (!izhodniTok) {
		cerr << "Napaka pri odpiranju datoteke za pisanje!" << endl;
		return 1;
	}

	izhodniTok << "To je dodatni zapis v datoteko." << endl;

	izhodniTok.close();

	return 0;
}

#endif

#ifdef TOKOVI_30

int main()
{
	ifstream vhodniTok("c:\\temp\\izhod.txt");

	if (!vhodniTok) {
		cerr << "Napaka pri odpiranju datoteke za pisanje!" << endl;
		return 1;
	}

	while (!vhodniTok.eof())
	{
		string vrstica;
		getline(vhodniTok, vrstica);
		cout << vrstica << endl;
	}

	vhodniTok.close();

	return 0;
}

#endif

#ifdef TOKOVI_40

int main()
{
	ifstream vhodniTok("c:\\temp\\izhod.txt");

	if (!vhodniTok) {
		cerr << "Napaka pri odpiranju datoteke za pisanje!" << endl;
		return 1;
	}

	string vrstica;
	while (getline(vhodniTok, vrstica)) {
		cout << vrstica << endl;
	}

	vhodniTok.close();

	return 0;
}

#endif


#ifdef BRANJE_EXCELOVE_DATOTEKE_10

int main()
{
	ifstream vhodniTok("c:\\temp\\excel.csv");

	if (!vhodniTok) {
		cerr << "Napaka pri odpiranju datoteke za pisanje!" << endl;
		return 1;
	}

	string vrstica;
	while (getline(vhodniTok, vrstica)) {
		cout << vrstica << endl;
	}

	vhodniTok.close();

	return 0;
}

#endif


#ifdef BRANJE_EXCELOVE_DATOTEKE_20

int main()
{
	ifstream vhodniTok("c:\\temp\\excel.csv");

	if (!vhodniTok) {
		cerr << "Napaka pri odpiranju datoteke za pisanje!" << endl;
		return 1;
	}

	string vrstica;
	int skupenZnesek = 0;
	while (getline(vhodniTok, vrstica)) {
		int pos = vrstica.find(';');
		if (pos != string::npos) {
			string ime = vrstica.substr(0, pos);
			string vrednost = vrstica.substr(pos + 1);

			int ivrednost = 0;
			try {
				ivrednost = stoi(vrednost);
			}
			catch (const invalid_argument& ia) {
				cerr << "Neveljavna vrednost za " << ime << ": " << vrednost << endl;
				continue;
			}
			catch (const out_of_range& oor) {
				cerr << "Vrednost izven obsega za " << ime << ": " << vrednost << endl;
				continue;
			}

			skupenZnesek += ivrednost;
		}
	}

	cout << "Skupen znesek: " << skupenZnesek << endl;

	vhodniTok.close();

	return 0;
}

#endif

#ifdef IZJEME_10

int main() {
	try {
		throw 5;   // namerno sprožimo izjemo
	}
	catch (int e) {
		cout << "Ujeta izjema: " << e << endl;
	}
}

#endif

#ifdef IZJEME_20

int main() {
	string nizi[] = {"123", "abc", "456"};

	for (int i = 0; i < size(nizi); i++)
	{
		string niz = nizi[i];

		try {
			int i = stoi(niz);
			cout << "niz [" << niz << "] sem pretvoril v celo stevilo " << i << endl;
		}
		catch (...) {	// to je slabo saj ujememo vse napke, tudi tiste ki jih ne zelimo
			cout << "niza [" << niz << "] ne morem pretvoriti v celo stevilo" << endl;
		}
	}
}

#endif

#ifdef IZJEME_30

int pretvoriVSteviloAli0(const string& s) {
	try {
		return stoi(s);
	}
	catch (const invalid_argument& e) {
		return 0; // -4
	}
	catch (const out_of_range& e) {
		return 0; // -5
	}
}

int main() {
	string nizi[] = { "123", "abc", "456", "999999999999999999" };

	for (int i = 0; i < size(nizi); i++)
	{
		string niz = nizi[i];
		int stevilo = pretvoriVSteviloAli0(niz);
		//
		// kaj če ne ulovimo napake
		// 
		// int stevilo = stoi(niz);
		//
		cout << "niz [" << niz << "] sem pretvoril v celo stevilo " << stevilo << endl;
	}
}

#endif

#ifdef BRANJE_CSV_DATOTEKE_10

class Prodaja {
private:
	string mesec;
	int vrednost;

public:
	Prodaja(string mesec, int vrednost) {
		this->mesec = mesec;
		this->vrednost = vrednost;
	}

	void izpisi() const {
		cout << mesec << " (" << vrednost << " EUR)" << endl;
	}
};

int pretvoriVSteviloAli0(const string& s) {
	try {
		return stoi(s);
	}
	catch (const invalid_argument& e) {
		return 0; // -4
	}
	catch (const out_of_range& e) {
		return 0; // -5
	}
}

void preberiDatoteko(const string& imeDatoteke) {
	ifstream in(imeDatoteke);

	if (!in)
		throw "Datoteke ni mogoce odpreti";

	string vrstica;

	while (getline(in, vrstica)) {
		size_t pos = vrstica.find(';');
		if (pos == string::npos)
			continue;

		string mesec = vrstica.substr(0, pos);
		string vrednost = vrstica.substr(pos + 1);

		int iVrednost = pretvoriVSteviloAli0(vrednost);
		Prodaja s(mesec, iVrednost);
		s.izpisi();
	}

	in.close();
}

int main() {
	preberiDatoteko("c:\\temp\\excel.csv");

	return 0;
}

#endif