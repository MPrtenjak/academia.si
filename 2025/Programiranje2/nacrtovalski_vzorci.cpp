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

#ifdef RULE_OF_5_PROBLEM_10

class Buffer {
private:
    int* data;

public:
    Buffer() {
		cout << "Ustvarim prostor za shranjevanje " << sizeof(int) * 10 << " bajtov" << endl;
        data = new int[10];
    }

    ~Buffer() {
        cout << "Uničujem prostor za shranjevanje" << endl;
        delete[] data;
    }
};

int main() {
    cout << "Začetek programa" << endl;
    Buffer buf1;
    Buffer buf2 = buf1;

    cout << "Tik pred koncem programa" << endl;
    return 0;
}

#endif

#ifdef RULE_OF_5_RESITEV_10

class Buffer {
private:
    int* data;

public:
    Buffer() {
        cout << "Ustvarim prostor za shranjevanje " << sizeof(int) * 10 << " bajtov" << endl;
        data = new int[10];
    }

    Buffer(const Buffer& other) {
        cout << "Izvajam copy konstruktor" << endl;
        data = new int[10];
        for (int i = 0; i < 10; i++)
            data[i] = other.data[i];
    }

    ~Buffer() {
        cout << "Uničujem prostor za shranjevanje" << endl;
        delete[] data;
    }
};

int main() {
    cout << "Začetek programa" << endl;
    Buffer buf1;
    Buffer buf2 = buf1;

    cout << "Tik pred koncem programa" << endl;
    return 0;
}

#endif

#ifdef RULE_OF_5_PROBLEM_20

class Buffer {
private:
    int* data;

public:
    Buffer() {
        cout << "Ustvarim prostor za shranjevanje " << sizeof(int) * 10 << " bajtov" << endl;
        data = new int[10];
    }

    ~Buffer() {
        cout << "Uničujem prostor za shranjevanje" << endl;
        delete[] data;
    }
};

int main() {
    cout << "Začetek programa" << endl;
    Buffer buf1;
    Buffer buf2;

    buf1 = buf2;

    cout << "Tik pred koncem programa" << endl;
    return 0;
}

#endif

#ifdef RULE_OF_5_RESITEV_20

class Buffer {
private:
    int* data;

public:
    Buffer() {
        cout << "Ustvarim prostor za shranjevanje " << sizeof(int) * 10 << " bajtov" << endl;
        data = new int[10];
    }

    Buffer(const Buffer& other) {
        cout << "Izvajam copy konstruktor" << endl;
        data = new int[10];
        for (int i = 0; i < 10; i++)
            data[i] = other.data[i];
    }

    Buffer& operator=(const Buffer& other) {
        cout << "Izvajam prireditev!" << endl;
        if (this != &other) {
            delete[] data;
            data = new int[10];
            for (int i = 0; i < 10; i++)
                data[i] = other.data[i];
        }
        return *this;
    }

    ~Buffer() {
        cout << "Uničujem prostor za shranjevanje" << endl;
        delete[] data;
    }
};

int main() {
    cout << "Začetek programa" << endl;
    Buffer buf1;
    Buffer buf2;

    buf1 = buf2;

    cout << "Tik pred koncem programa" << endl;
    return 0;
}

#endif

#ifdef SINGELTON_PROBLEM

class Config {
public:
    int value;
};

int main() {
    Config config1;
    config1.value = 42;
    cout << "Config1 value: " << config1.value << endl;

    Config config2;
    config2.value = 100;
    cout << "Config1 value: " << config1.value << endl;
    cout << "Config2 value: " << config2.value << endl;
    return 0;
}

#endif

#ifdef SINGELTON_RESITEV

class Config {
private:
    static Config* instance;
    Config() {}

public:
    static Config* getInstance() {
        if (instance == 0)
            instance = new Config();
        return instance;
    }

    int value = 0;
};

Config* Config::instance = 0;

int main() {
    Config* config1 = Config::getInstance();
    config1->value = 42;
    cout << "Config1 value: " << config1->value << endl;

    Config* config2 = Config::getInstance();
    config2->value = 100;
    cout << "Config1 value: " << config1->value << endl;
    cout << "Config2 value: " << config2->value << endl;
    return 0;
}

#endif


#ifdef FACTORY_PROBLEM

class Truck {
public:
    void drive() {
        cout << "Dostava s tovornjakom po cesti." << endl;
    }
};

class Ship {
public:
    void sail() {
        cout << "Dostava z ladjo po morju." << endl;
    }
};

class LogisticsApp {
public:
    void planDelivery(int type) {
        cout << "Načrtujem dostavo..." << endl;

        if (type == 1) {
            Truck truck;
			truck.drive();
        }
        else if (type == 2) {
			Ship ship;
			ship.sail();
        }
        else {
            cout << "Napačen tip dostave." << endl;
            return;
        }
    }
};

int main() {
    LogisticsApp app;

    app.planDelivery(1);
    app.planDelivery(2);

    return 0;
}

#endif

#ifdef FACTORY_RESITEV

class Transport {
public:
    virtual void deliver() = 0;
    virtual ~Transport() {}
};

class Truck : public Transport {
public:
    void deliver() {
        cout << "Dostava s tovornjakom po cesti." << endl;
    }
};

class Ship : public Transport {
public:
    void deliver() {
        cout << "Dostava z ladjo po morju." << endl;
    }
};

class Logistics {
public:
    void planDelivery() {
        Transport* transport = createTransport();

        cout << "Načrtujem dostavo..." << endl;
        transport->deliver();

        delete transport;
    }

    virtual Transport* createTransport() = 0;

    virtual ~Logistics() {}
};

class RoadLogistics : public Logistics {
public:
    Transport* createTransport() {
        return new Truck();
    }
};

class SeaLogistics : public Logistics {
public:
    Transport* createTransport() {
        return new Ship();
    }
};

int main() {
    Logistics* logistics = 0;

    logistics = new RoadLogistics();
    logistics->planDelivery();
    delete logistics;

    logistics = new SeaLogistics();
    logistics->planDelivery();
    delete logistics;

    return 0;
}

#endif

#ifdef FACTORY_RESITEV_10

class Transport {
public:
    virtual void deliver() = 0;
    virtual ~Transport() {}
};

class Truck : public Transport {
public:
    void deliver() {
        cout << "Dostava s tovornjakom po cesti." << endl;
    }
};

class Ship : public Transport {
public:
    void deliver() {
        cout << "Dostava z ladjo po morju." << endl;
    }
};

class Plane : public Transport {
public:
    void deliver() {
        cout << "Dostava z letalom po zraku." << endl;
    }
};

class Logistics {
public:
    void planDelivery() {
        Transport* transport = createTransport();

        cout << "Načrtujem dostavo..." << endl;
        transport->deliver();

        delete transport;
    }

    virtual Transport* createTransport() = 0;

    virtual ~Logistics() {}
};

class RoadLogistics : public Logistics {
public:
    Transport* createTransport() {
        return new Truck();
    }
};

class SeaLogistics : public Logistics {
public:
    Transport* createTransport() {
        return new Ship();
    }
};

class AirLogistics : public Logistics {
public:
    Transport* createTransport() {
        return new Plane();
    }
};

int main() {
    Logistics* logistics = 0;

    logistics = new RoadLogistics();
    logistics->planDelivery();
    delete logistics;

    cout << endl;

    logistics = new SeaLogistics();
    logistics->planDelivery();
    delete logistics;

    cout << endl;

    logistics = new AirLogistics();
    logistics->planDelivery();
    delete logistics;

    /*
    cout << endl << endl;
    vector<Logistics*> logisticsOptions = { new RoadLogistics(), new SeaLogistics(), new AirLogistics() };
    for (vector<Logistics*>::iterator i = logisticsOptions.begin(); i != logisticsOptions.end(); i++)
    {
        (*i)->planDelivery();
        cout << endl;
        delete* i;
    }
    */

    /*
    cout << endl << endl;
    vector<Logistics*> logisticsOptions = { new RoadLogistics(), new SeaLogistics(), new AirLogistics() };
    for (Logistics* logisticsOption : logisticsOptions)
    {
        logisticsOption->planDelivery();
        cout << endl;
        delete logisticsOption;
    }
    */

    return 0;
}

#endif

#ifdef BUILDER_PROBLEM

class Computer {
private:
    int ram;
    int disk;
    int hasGraphicsCard;

public:
    Computer(int r, int d, int g) {
        ram = r;
        disk = d;
        hasGraphicsCard = g;
    }

    void show() {
        cout << "Racunalnik:" << endl;
        cout << "RAM: " << ram << " GB" << endl;
        cout << "Disk: " << disk << " GB" << endl;

        if (hasGraphicsCard == 1) {
            cout << "Graficna kartica: DA" << endl;
        }
        else {
            cout << "Graficna kartica: NE" << endl;
        }
    }
};

int main() {
    Computer officeComputer(8, 256, 0);
    Computer gamingComputer(32, 1000, 1);

    officeComputer.show();
    cout << endl;
    gamingComputer.show();

    return 0;
}

#endif

#ifdef BUILDER_RESITEV

class Computer {
private:
    int ram;
    int disk;
    int hasGraphicsCard;

public:
    Computer() {
        ram = 0;
        disk = 0;
        hasGraphicsCard = 0;
    }

    void setRam(int r) {
        ram = r;
    }

    void setDisk(int d) {
        disk = d;
    }

    void setGraphicsCard(int g) {
        hasGraphicsCard = g;
    }

    void show() {
        cout << "Racunalnik:" << endl;
        cout << "RAM: " << ram << " GB" << endl;
        cout << "Disk: " << disk << " GB" << endl;

        if (hasGraphicsCard == 1) {
            cout << "Graficna kartica: DA" << endl;
        }
        else {
            cout << "Graficna kartica: NE" << endl;
        }
    }
};

class ComputerBuilder {
private:
    Computer* computer;

public:
    ComputerBuilder() {
        computer = new Computer();
    }

    void buildRam(int r) {
        computer->setRam(r);
    }

    void buildDisk(int d) {
        computer->setDisk(d);
    }

    void buildGraphicsCard(int g) {
        computer->setGraphicsCard(g);
    }

    Computer* getResult() {
        return computer;
    }
};

int main() {
    ComputerBuilder officeBuilder;
    officeBuilder.buildRam(8);
    officeBuilder.buildDisk(256);
    officeBuilder.buildGraphicsCard(0);

    Computer* officeComputer = officeBuilder.getResult();
    officeComputer->show();
    delete officeComputer;



    ComputerBuilder gamingBuilder;
	gamingBuilder.buildRam(32);
	gamingBuilder.buildDisk(1000);
    gamingBuilder.buildGraphicsCard(1);

    Computer* gamingComputer = gamingBuilder.getResult();
    gamingComputer->show();
    delete gamingComputer;

    return 0;
}

#endif

#ifdef ADAPTER_PROBLEM

class OldPrinter {
public:
    void printOld(const char* text) {
        cout << "Stari tiskalnik tiska: " << text << endl;
    }
};

// reportService je vezan na star tiskalnik, ki ga uporablja za tiskanje poročil
class ReportService {
public:
    void printReport(OldPrinter* printer) {
        printer->printOld("Letno porocilo");
    }
};

int main() {
    OldPrinter oldPrinter;
    ReportService service;

    service.printReport(&oldPrinter);

    return 0;
}

#endif

#ifdef ADAPTER_RESITEV

class Printer {
public:
    virtual void printDocument(const char* text) = 0;

    virtual ~Printer() {}
};

class OldPrinter {
public:
    void printOld(const char* text) {
        cout << "Stari tiskalnik tiska: " << text << endl;
    }
};

class OldPrinterAdapter : public Printer {
private:
    OldPrinter* oldPrinter;

public:
    OldPrinterAdapter(OldPrinter* p) {
        oldPrinter = p;
    }

    void printDocument(const char* text) {
        oldPrinter->printOld(text);
    }
};

class ModernPrinter : public Printer {
public:
    void printDocument(const char* text) {
        cout << "Moderni tiskalnik tiska: " << text << endl;
    }
};

class ReportService {
public:
    void printReport(Printer* printer) {
        printer->printDocument("Letno porocilo");
    }

    void printInvoice(Printer* printer) {
        printer->printDocument("Racun #1001");
    }
};

int main() {
    ReportService service;

    OldPrinter oldPrinter;
    OldPrinterAdapter oldAdapter(&oldPrinter);
    cout << "Uporaba starega tiskalnika preko adapterja:" << endl;
    service.printReport(&oldAdapter);

    cout << endl;

    ModernPrinter modernPrinter;
    cout << "Uporaba modernega tiskalnika brez adapterja:" << endl;
    service.printInvoice(&modernPrinter);

    return 0;
}

#endif

#ifdef DECORATOR_PROBLEM

class Coffee {
public:
    virtual int cost() = 0;
    virtual void description() = 0;
    virtual ~Coffee() {}
};

class SimpleCoffee : public Coffee {
public:
    int cost() {
        return 5;
    }

    void description() {
        cout << "Kava";
    }
};

class CoffeeWithMilk : public Coffee {
public:
    int cost() {
        return 7;
    }

    void description() {
        cout << "Kava + mleko";
    }
};

class CoffeeWithMilkAndSugar : public Coffee {
public:
    int cost() {
        return 8;
    }

    void description() {
        cout << "Kava + mleko + sladkor";
    }
};

int main() {
    Coffee* c1 = new SimpleCoffee();
    c1->description();
    cout << " | Cena: " << c1->cost() << endl;

    Coffee* c2 = new CoffeeWithMilkAndSugar();
    c2->description();
    cout << " | Cena: " << c2->cost() << endl;

    delete c1;
    delete c2;

    return 0;
}

#endif

#ifdef DECORATOR_RESITEV

class Coffee {
public:
    virtual int cost() = 0;
    virtual void description() = 0;
    virtual ~Coffee() {}
};

class SimpleCoffee : public Coffee {
public:
    int cost() {
        return 5;
    }

    void description() {
        cout << "Kava";
    }
};

class CoffeeDecorator : public Coffee {
protected:
    Coffee* coffee;

public:
    CoffeeDecorator(Coffee* c) {
        coffee = c;
    }

    virtual ~CoffeeDecorator() {
        delete coffee;
    }
};

class MilkDecorator : public CoffeeDecorator {
public:
    MilkDecorator(Coffee* c) : CoffeeDecorator(c) {}

    int cost() {
        return coffee->cost() + 2;
    }

    void description() {
        coffee->description();
        cout << " + mleko";
    }
};

class SugarDecorator : public CoffeeDecorator {
public:
    SugarDecorator(Coffee* c) : CoffeeDecorator(c) {}

    int cost() {
        return coffee->cost() + 1;
    }

    void description() {
        coffee->description();
        cout << " + sladkor";
    }
};


/*
* preprosto lahko dodamo še npr. ChocolateDecorator 
*/

int main() {
    Coffee* coffee = new SimpleCoffee();

    coffee = new MilkDecorator(coffee);
    coffee = new SugarDecorator(coffee);

    coffee->description();
    cout << " | Cena: " << coffee->cost() << endl;

    delete coffee;

    return 0;
}

#endif

#ifdef STRATEGY_PROBLEM

class Checkout {
public:
    int finalPrice(int price, int customerType) {
        if (customerType == 1) {
            cout << "Navadna stranka" << endl;
            return price;
        }
        else if (customerType == 2) {
            cout << "Student" << endl;
            return price - (price * 10 / 100);
        }
        else if (customerType == 3) {
            cout << "VIP stranka" << endl;
            return price - (price * 20 / 100);
        }

        return price;
    }
};

int main() {
    Checkout checkout;

    cout << "Cena: " << checkout.finalPrice(100, 1) << endl;
    cout << "Cena: " << checkout.finalPrice(100, 2) << endl;
    cout << "Cena: " << checkout.finalPrice(100, 3) << endl;

    return 0;
}

#endif

#ifdef STRATEGY_RESITEV

class DiscountStrategy {
public:
    virtual int calculate(int price) = 0;

    virtual ~DiscountStrategy() {}
};

class NoDiscount : public DiscountStrategy {
public:
    int calculate(int price) {
        cout << "Navadna stranka" << endl;
        return price;
    }
};

class StudentDiscount : public DiscountStrategy {
public:
    int calculate(int price) {
        cout << "Student" << endl;
        return price - (price * 10 / 100);
    }
};

class VipDiscount : public DiscountStrategy {
public:
    int calculate(int price) {
        cout << "VIP stranka" << endl;
        return price - (price * 20 / 100);
    }
};

class Checkout {
private:
    DiscountStrategy* strategy;

public:
    Checkout(DiscountStrategy* s) {
        strategy = s;
    }

    void setStrategy(DiscountStrategy* s) {
        strategy = s;
    }

    int finalPrice(int price) {
        return strategy->calculate(price);
    }
};

int main() {
    NoDiscount noDiscount;
    StudentDiscount studentDiscount;
    VipDiscount vipDiscount;

    Checkout checkout(&noDiscount);
    cout << "Cena: " << checkout.finalPrice(100) << endl;

    checkout.setStrategy(&studentDiscount);
    cout << "Cena: " << checkout.finalPrice(100) << endl;

    checkout.setStrategy(&vipDiscount);
    cout << "Cena: " << checkout.finalPrice(100) << endl;

    return 0;
}

#endif

#ifdef OBSERVER_PROBLEM

class Display {
public:
    void showTemperature(int value) {
        cout << "Prikazovalnik: temperatura je " << value << " stopinj." << endl;
    }
};

class Alarm {
public:
    void checkTemperature(int value) {
        if (value > 30) {
            cout << "Alarm: temperatura je previsoka!" << endl;
        }
        else {
            cout << "Alarm: temperatura je normalna." << endl;
        }
    }
};

class TemperatureSensor {
private:
    int temperature;
    Display* display;
    Alarm* alarm;

public:
    TemperatureSensor(Display* d, Alarm* a) {
        temperature = 0;
        display = d;
        alarm = a;
    }

    void setTemperature(int value) {
        temperature = value;

        display->showTemperature(temperature);
        alarm->checkTemperature(temperature);
    }
};

int main() {
    Display display;
    Alarm alarm;

    TemperatureSensor sensor(&display, &alarm);

    sensor.setTemperature(25);
    cout << endl;
    sensor.setTemperature(35);

    return 0;
}

#endif

#ifdef OBSERVER_RESITEV

class Observer {
public:
    virtual void update(int value) = 0;

    virtual ~Observer() {}
};

class Display : public Observer {
public:
    void update(int value) {
        cout << "Prikazovalnik: temperatura je " << value << " stopinj." << endl;
    }
};

class Alarm : public Observer {
public:
    void update(int value) {
        if (value > 30) {
            cout << "Alarm: temperatura je previsoka!" << endl;
        }
        else {
            cout << "Alarm: temperatura je normalna." << endl;
        }
    }
};

// preprosto daodamo recimo Logger, ki bo obveščen o spremembi temperature in bo shranil temperaturo v dnevnik

class TemperatureSensor {
private:
    Observer* observers[10];
    int count;
    int temperature;

public:
    TemperatureSensor() {
        count = 0;
        temperature = 0;
    }

    void attach(Observer* observer) {
        if (count < 10) {
            observers[count] = observer;
            count++;
        }
    }

    void detach(Observer* observer) {
        int i;
        int j;

        for (i = 0; i < count; i++) {
            if (observers[i] == observer) {
                for (j = i; j < count - 1; j++) {
                    observers[j] = observers[j + 1];
                }

                count--;
                break;
            }
        }
    }

    void notify() {
        int i;

        for (i = 0; i < count; i++) {
            observers[i]->update(temperature);
        }
    }

    void setTemperature(int value) {
        temperature = value;
        notify();
    }
};

int main() {
    TemperatureSensor sensor;

    Display display;
    Alarm alarm;

    sensor.attach(&display);
    sensor.attach(&alarm);

    sensor.setTemperature(25);
    cout << endl;
    sensor.setTemperature(35);

    return 0;
}

#endif