#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>

class Student {
private:
    std::string ime;
    int starost;

public:
    Student(const std::string& ime, int starost);

    const std::string& getIme() const;
    int getStarost() const;

    void izpisi() const;
};

#endif
