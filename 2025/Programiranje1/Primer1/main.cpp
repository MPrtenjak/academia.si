#define PRIMER1

#ifdef PRIMER1

#include <iostream>
#include <vector>

#include "CsvReader.h"
#include "AppException.h"

/* primer za datoteko studenti.csv:
Ana;20
Marko;abc
Eva;25
Luka;-3
;18
Tina;
Peter;120
Maja;121
Gregor; 30
Nina;15abc
Boris;45
Nejc;0
Sara;19
NapacnaVrsticaBrezLocila
*/

int main() {
    try {
        std::vector<Student> students = CsvReader::readStudentsCsv("c:\\temp\\studenti.csv");

        std::cout << "\n--- USPEŠNO PREBRANI ŠTUDENTI ---\n";
        for (size_t i = 0; i < students.size(); i++)
            students[i].izpisi();

        if (!students.empty()) {
            int sum = 0;
            int minAge = students[0].getStarost();
            int maxAge = students[0].getStarost();

            for (size_t i = 0; i < students.size(); i++) {
                int age = students[i].getStarost();
                sum += age;
                if (age < minAge) minAge = age;
                if (age > maxAge) maxAge = age;
            }

            double avg = (double)sum / students.size();

            std::cout << "\nStatistika:\n";
            std::cout << "Stevilo studentov: " << students.size() << "\n";
            std::cout << "Min starost: " << minAge << "\n";
            std::cout << "Max starost: " << maxAge << "\n";
            std::cout << "Povprecje: " << avg << "\n";
        }
        else {
            std::cout << "\nNi veljavnih studentov v datoteki.\n";
        }

    }
    catch (const AppException& e) {
        std::cerr << "KRITIČNA NAPAKA: " << e.what() << std::endl;
        return 1;
    }
    catch (const std::exception& e) {
        std::cerr << "NEPRIČAKOVANA NAPAKA (std): " << e.what() << std::endl;
        return 2;
    }
    catch (...) {
        std::cerr << "NEPRIČAKOVANA NAPAKA (neznana)." << std::endl;
        return 3;
    }

    return 0;
}
#endif