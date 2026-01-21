#ifndef CSV_READER_H
#define CSV_READER_H

#include <string>
#include <vector>
#include "Student.h"

class CsvReader {
public:
    // Prebere CSV in vrne seznam veljavnih studentov
    static std::vector<Student> readStudentsCsv(const std::string& filename);

private:
    // Parsira eno vrstico CSV v Student ali vrže izjemo
    static Student parseStudentLineOrThrow(const std::string& line, int lineNo);

    // Pomožne funkcije (skrite v razredu)
    static std::string trim(const std::string& source);
    static int toIntStrictOrThrow(const std::string& s, int lineNo);
};

#endif
