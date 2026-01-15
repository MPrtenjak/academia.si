#include "Student.h"

Student::Student(const std::string& i, int s) : ime(i), starost(s) {}

const std::string& Student::getIme() const {
    return ime;
}

int Student::getStarost() const {
    return starost;
}

void Student::izpisi() const {
    std::cout << ime << " (" << starost << " let)" << std::endl;
}
