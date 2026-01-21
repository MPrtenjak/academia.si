#include "Student.h"

Student::Student(const std::string& ime, int starost) : ime(ime), starost(starost) {}

const std::string& Student::getIme() const {
    return ime;
}

int Student::getStarost() const {
    return starost;
}

void Student::izpisi() const {
    std::cout << ime << " (" << starost << " let)" << std::endl;
}
