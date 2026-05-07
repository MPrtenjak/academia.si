#include "constants.h"

#ifdef SOLID_BAD

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

class CsvStudentProgram {
private:
    string inputFileName;
    string outputFileName;
    char delimiter;
    int reportType;

    vector<int> ids;
    vector<string> names;
    vector<double> grade1;
    vector<double> grade2;
    vector<double> averages;
    vector<int> passed;

public:
    CsvStudentProgram() {
        inputFileName = "students.csv";
        outputFileName = "report.csv";
        delimiter = ',';

        // 1 = samo zaslon
        // 2 = samo datoteka
        // 3 = zaslon in datoteka
        reportType = 3;
    }

    vector<string> splitLine(string line) {
        vector<string> parts;
        string current = "";

        for (int i = 0; i < (int)line.length(); i++) {
            if (line[i] == delimiter) {
                parts.push_back(current);
                current = "";
            }
            else {
                current += line[i];
            }
        }

        parts.push_back(current);

        return parts;
    }

    void run() {
        ifstream input(inputFileName.c_str());

        if (!input) {
            cout << "Napaka: datoteke ni mogoce odpreti." << endl;
            return;
        }

        string line;
        int lineNumber = 0;

        while (getline(input, line)) {
            lineNumber++;

            if (line == "") {
                continue;
            }

            vector<string> parts = splitLine(line);

            if ((int)parts.size() != 4) {
                cout << "Napaka v vrstici " << lineNumber << ": napacno stevilo stolpcev." << endl;
                continue;
            }

            int id = atoi(parts[0].c_str());
            string name = parts[1];
            double g1 = atof(parts[2].c_str());
            double g2 = atof(parts[3].c_str());

            if (id <= 0) {
                cout << "Napaka v vrstici " << lineNumber << ": neveljaven id." << endl;
                continue;
            }

            if (name == "") {
                cout << "Napaka v vrstici " << lineNumber << ": prazno ime." << endl;
                continue;
            }

            if (g1 < 1 || g1 > 10 || g2 < 1 || g2 > 10) {
                cout << "Napaka v vrstici " << lineNumber << ": ocena ni med 1 in 10." << endl;
                continue;
            }

            double average = (g1 + g2) / 2.0;

            int didPass = 0;

            if (average >= 6.0 && g1 >= 5.0 && g2 >= 5.0) {
                didPass = 1;
            }

            ids.push_back(id);
            names.push_back(name);
            grade1.push_back(g1);
            grade2.push_back(g2);
            averages.push_back(average);
            passed.push_back(didPass);
        }

        input.close();

        int passedCount = 0;
        double totalAverage = 0;

        for (int i = 0; i < (int)averages.size(); i++) {
            totalAverage += averages[i];

            if (passed[i] == 1) {
                passedCount++;
            }
        }

        double classAverage = 0;

        if ((int)averages.size() > 0) {
            classAverage = totalAverage / averages.size();
        }

        if (reportType == 1 || reportType == 3) {
            cout << "POROCILO O STUDENTIH" << endl;
            cout << "--------------------" << endl;

            for (int i = 0; i < (int)ids.size(); i++) {
                cout << ids[i] << " ";
                cout << names[i] << " ";
                cout << grade1[i] << " ";
                cout << grade2[i] << " ";
                cout << "povprecje: " << averages[i] << " ";

                if (passed[i] == 1) {
                    cout << "opravil";
                }
                else {
                    cout << "ni opravil";
                }

                cout << endl;
            }

            cout << "--------------------" << endl;
            cout << "Stevilo studentov: " << ids.size() << endl;
            cout << "Opravilo: " << passedCount << endl;
            cout << "Povprecje razreda: " << classAverage << endl;
        }

        if (reportType == 2 || reportType == 3) {
            ofstream output(outputFileName.c_str());

            if (!output) {
                cout << "Napaka: izhodne datoteke ni mogoce odpreti." << endl;
                return;
            }

            output << "id,name,grade1,grade2,average,status" << endl;

            for (int i = 0; i < (int)ids.size(); i++) {
                output << ids[i] << ",";
                output << names[i] << ",";
                output << grade1[i] << ",";
                output << grade2[i] << ",";
                output << averages[i] << ",";

                if (passed[i] == 1) {
                    output << "passed";
                }
                else {
                    output << "failed";
                }

                output << endl;
            }

            output << "students," << ids.size() << endl;
            output << "passed," << passedCount << endl;
            output << "class_average," << classAverage << endl;

            output.close();
        }
    }

    void setInputFileName(string fileName) {
        inputFileName = fileName;
    }

    void setOutputFileName(string fileName) {
        outputFileName = fileName;
    }

    void setDelimiter(char selectedDelimiter) {
        delimiter = selectedDelimiter;
    }

    void setReportType(int selectedReportType) {
        reportType = selectedReportType;
    }
};

int main() {
    CsvStudentProgram program;

    program.setInputFileName("c:\\temp\\studenti.csv");
    program.setOutputFileName("c:\\temp\\rezultat.csv");
    program.setReportType(3);

    program.run();

    return 0;
}

#endif