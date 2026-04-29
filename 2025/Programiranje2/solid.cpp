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

#ifdef SRP_PROBLEM

class GradeReport {
private:
    int grades[10];
    int count;

public:
    GradeReport() {
        count = 0;
    }

    void addGrade(int grade) {
        if (count < 10) {
            grades[count] = grade;
            count++;
        }
    }

    double average() {
        int sum = 0;

        for (int i = 0; i < count; i++) {
            sum += grades[i];
        }

        if (count == 0) {
            return 0;
        }

        return (double)sum / count;
    }

    void printReport() {
        cout << "Grade report" << endl;
        cout << "Average: " << average() << endl;
    }

    void saveReport() {
        cout << "Saving report to file..." << endl;
        cout << "Average saved: " << average() << endl;
    }
};

int main() {
    GradeReport report;

    report.addGrade(8);
    report.addGrade(9);
    report.addGrade(10);

    report.printReport();
    report.saveReport();

    return 0;
}

#endif

#ifdef SRP_RESITEV

class GradeBook {
private:
    int grades[10];
    int count;

public:
    GradeBook() {
        count = 0;
    }

    void addGrade(int grade) {
        if (count < 10) {
            grades[count] = grade;
            count++;
        }
    }

    double average() {
        int sum = 0;

        for (int i = 0; i < count; i++) {
            sum += grades[i];
        }

        if (count == 0) {
            return 0;
        }

        return (double)sum / count;
    }
};

class GradeReportPrinter {
public:
    void print(GradeBook& book) {
        cout << "Grade report" << endl;
        cout << "Average: " << book.average() << endl;
    }
};

class GradeReportSaver {
public:
    void save(GradeBook& book) {
        cout << "Saving report to file..." << endl;
        cout << "Average saved: " << book.average() << endl;
    }
};

int main() {
    GradeBook book;

    book.addGrade(8);
    book.addGrade(9);
    book.addGrade(10);

    GradeReportPrinter printer;
    GradeReportSaver saver;

    printer.print(book);
    saver.save(book);

    return 0;
}

#endif

#ifdef OCP_PROBLEM

class PriceCalculator {
public:
    double finalPrice(double price, int customerType) {
        // 0 = normal customer
        // 1 = student
        // 2 = senior

        if (customerType == 0) {
            return price;
        }
        else if (customerType == 1) {
            return price * 0.90;
        }
        else if (customerType == 2) {
            return price * 0.80;
        }

        return price;
    }
};

int main() {
    PriceCalculator calculator;

    cout << calculator.finalPrice(100, 0) << endl;
    cout << calculator.finalPrice(100, 1) << endl;
    cout << calculator.finalPrice(100, 2) << endl;

    return 0;
}

#endif

#ifdef OCP_RESITEV

class Discount {
public:
    virtual double apply(double price) = 0;
};

class NoDiscount : public Discount {
public:
    double apply(double price) {
        return price;
    }
};

class StudentDiscount : public Discount {
public:
    double apply(double price) {
        return price * 0.90;
    }
};

class SeniorDiscount : public Discount {
public:
    double apply(double price) {
        return price * 0.80;
    }
};

class PriceCalculator {
public:
    double finalPrice(double price, Discount& discount) {
        return discount.apply(price);
    }
};

int main() {
    PriceCalculator calculator;

    NoDiscount noDiscount;
    StudentDiscount studentDiscount;
    SeniorDiscount seniorDiscount;

    cout << calculator.finalPrice(100, noDiscount) << endl;
    cout << calculator.finalPrice(100, studentDiscount) << endl;
    cout << calculator.finalPrice(100, seniorDiscount) << endl;

    return 0;
}

#endif

#ifdef LSP_PROBLEM

class Bird {
public:
    virtual void fly() {
        cout << "Bird is flying." << endl;
    }
};

class Sparrow : public Bird {
public:
    void fly() {
        cout << "Sparrow is flying." << endl;
    }
};

class Penguin : public Bird {
public:
    void fly() {
        cout << "Penguin cannot fly!" << endl;
    }
};

void makeBirdFly(Bird& bird) {
    bird.fly();
}

int main() {
    Sparrow sparrow;
    Penguin penguin;

    makeBirdFly(sparrow);
    makeBirdFly(penguin);

    return 0;
}

#endif

#ifdef LSP_RESITEV

class Bird {
public:
    virtual void showName() = 0;
};

class FlyingBird : public Bird {
public:
    virtual void fly() = 0;
};

class Sparrow : public FlyingBird {
public:
    void showName() {
        cout << "Sparrow" << endl;
    }

    void fly() {
        cout << "Sparrow is flying." << endl;
    }
};

class Penguin : public Bird {
public:
    void showName() {
        cout << "Penguin" << endl;
    }
};

void makeFlyingBirdFly(FlyingBird& bird) {
    bird.fly();
}

int main() {
    Sparrow sparrow;
    Penguin penguin;

    sparrow.showName();
    penguin.showName();

    makeFlyingBirdFly(sparrow);

    // To se ne prevede, kar je dobro:
    // makeFlyingBirdFly(penguin);

    return 0;
}

#endif

#ifdef ISP_PROBLEM

class Worker {
public:
    virtual void work() = 0;
    virtual void eat() = 0;
    virtual void writeCode() = 0;
    virtual void printDocument() = 0;
};

class Programmer : public Worker {
public:
    void work() {
        cout << "Programmer is working." << endl;
    }

    void eat() {
        cout << "Programmer is eating." << endl;
    }

    void writeCode() {
        cout << "Programmer is writing code." << endl;
    }

    void printDocument() {
        cout << "Programmer is printing document." << endl;
    }
};

class Robot : public Worker {
public:
    void work() {
        cout << "Robot is working." << endl;
    }

    void eat() {
        cout << "Robot does not eat." << endl;
    }

    void writeCode() {
        cout << "Robot cannot write code." << endl;
    }

    void printDocument() {
        cout << "Robot cannot print document." << endl;
    }
};

int main() {
    Programmer programmer;
    Robot robot;

    programmer.work();
    robot.work();

	programmer.eat();
	robot.eat();

    return 0;
}

#endif

#ifdef ISP_RESITEV

class Workable {
public:
    virtual void work() = 0;
};

class Eatable {
public:
    virtual void eat() = 0;
};

class CodeWritable {
public:
    virtual void writeCode() = 0;
};

class Printable {
public:
    virtual void printDocument() = 0;
};

class Programmer : public Workable, public Eatable, public CodeWritable, public Printable {
public:
    void work() {
        cout << "Programmer is working." << endl;
    }

    void eat() {
        cout << "Programmer is eating." << endl;
    }

    void writeCode() {
        cout << "Programmer is writing code." << endl;
    }

    void printDocument() {
        cout << "Programmer is printing document." << endl;
    }
};

class Robot : public Workable {
public:
    void work() {
        cout << "Robot is working." << endl;
    }
};

int main() {
    Programmer programmer;
    Robot robot;

    programmer.work();
    programmer.eat();
    programmer.writeCode();
    programmer.printDocument();

    robot.work();

    return 0;
}

#endif

#ifdef DIP_PROBLEM

class LedLamp {
public:
    void turnOn() {
        cout << "LED lamp is on." << endl;
    }

    void turnOff() {
        cout << "LED lamp is off." << endl;
    }
};

class Switch {
private:
    LedLamp lamp;

public:
    void pressOn() {
        lamp.turnOn();
    }

    void pressOff() {
        lamp.turnOff();
    }
};

int main() {
    Switch lightSwitch;

    lightSwitch.pressOn();
    lightSwitch.pressOff();

    return 0;
}

#endif

#ifdef DIP_RESITEV

class Switchable {
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
};

class LedLamp : public Switchable {
public:
    void turnOn() {
        cout << "LED lamp is on." << endl;
    }

    void turnOff() {
        cout << "LED lamp is off." << endl;
    }
};

class Fan : public Switchable {
public:
    void turnOn() {
        cout << "Fan is on." << endl;
    }

    void turnOff() {
        cout << "Fan is off." << endl;
    }
};

class Switch {
private:
    Switchable* device;

public:
    Switch(Switchable* selectedDevice) {
        device = selectedDevice;
    }

    void pressOn() {
        device->turnOn();
    }

    void pressOff() {
        device->turnOff();
    }
};

int main() {
    LedLamp lamp;
    Fan fan;

    Switch lampSwitch(&lamp);
    Switch fanSwitch(&fan);

    lampSwitch.pressOn();
    lampSwitch.pressOff();

    fanSwitch.pressOn();
    fanSwitch.pressOff();

    return 0;
}

#endif