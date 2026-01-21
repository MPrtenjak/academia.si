#include "CsvReader.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "FileOpenException.h"
#include "CsvFormatException.h"
#include "InvalidFieldException.h"
#include "AppException.h"

// ------------------ private helper: trim ------------------
std::string CsvReader::trim(const std::string& source) {
    size_t start = source.find_first_not_of(" \t\r\n");
    if (start == std::string::npos) return "";
    size_t end = source.find_last_not_of(" \t\r\n");
    return source.substr(start, end - start + 1);
}

// ------------------ private helper: string->int with validation ------------------
int CsvReader::toIntStrictOrThrow(const std::string& source, int lineNo) {
    std::string t = trim(source);

    if (t.empty())
        throw InvalidFieldException(lineNo, "starost", source, "prazna vrednost");

    size_t idx = 0;
    int value = 0;

    try {
        value = std::stoi(t, &idx);
    }
    catch (const std::exception&) {
        throw InvalidFieldException(lineNo, "starost", source, "ni celo stevilo");
    }

    if (idx != t.size())
        throw InvalidFieldException(lineNo, "starost", source, "vsebuje dodatne znake");

    if (value < 0 || value > 120)
        throw InvalidFieldException(lineNo, "starost", source, "izven obsega 0..120");

    return value;
}

// ------------------ private: parse single CSV line ------------------
Student CsvReader::parseStudentLineOrThrow(const std::string& line, int lineNo) {
    size_t pos = line.find(';');
    if (pos == std::string::npos)
        throw CsvFormatException(lineNo, line);

    std::string ime = trim(line.substr(0, pos));
    std::string starostStr = line.substr(pos + 1);

    if (ime.empty())
        throw InvalidFieldException(lineNo, "ime", ime, "ime ne sme biti prazno");

    int starost = toIntStrictOrThrow(starostStr, lineNo);
    return Student(ime, starost);
}

// ------------------ public: read file ------------------
std::vector<Student> CsvReader::readStudentsCsv(const std::string& filename) {
    std::ifstream in(filename.c_str());
    if (!in)
        throw FileOpenException(filename);

    std::vector<Student> students;
    std::string line;
    int lineNo = 0;

    while (std::getline(in, line)) {
        lineNo++;

        if (trim(line).empty())
            continue;

        // lokalno lovljenje: ena napačna vrstica ne ustavi programa
        try {
            Student s = parseStudentLineOrThrow(line, lineNo);
            students.push_back(s);
        }
        catch (const AppException& e) {
            std::cerr << "OPOZORILO: " << e.what() << std::endl;
        }
    }

    return students;
}
