#include <iostream>
#include <string>
using namespace std;

class Transport {
protected:
    string name;
    string toplivo;
    string type;
    double kg;
public:
    Transport() {}
    Transport(string nm, string topl, string tp, double k) {
        name = nm;
        toplivo = topl;
        type = tp;
        kg = k;
    }

    virtual ~Transport() {}

    virtual void Input()
    {
        cout << "Введите название вашего транспорта: ";
        cin >> name;
        cout << "Введите тип топлива: ";
        cin >> toplivo;
        cout << "Введите тип вашего транспорта: ";
        cin >> type;
        cout << "Введите вес вашего транспорта: ";
        cin >> kg;
    }
    virtual void Print()
    {
        cout << "Название: " << name
            << "\tТопливо: " << toplivo
            << "\tТип: " << type
            << "\tВес: " << kg << endl;
    }

    virtual double DeliveryC(double distance) = 0;
};

class Car : public Transport {
public:
    Car() {}
    Car(string nm, string topl, string tp, double k)
        : Transport(nm, topl, tp, k) {}

    void Input()
    {
        Transport::Input();
    }

    void Print()
    {
        Transport::Print();
    }

    double DeliveryC(double distance)
    {
        return kg * 0.5 * distance;
    }
};

class Airplane : public Transport {
public:
    Airplane() {}
    Airplane(string nm, string topl, string tp, double k)
        : Transport(nm, topl, tp, k) {}

    void Input()
    {
        Transport::Input();
    }

    void Print()
    {
        Transport::Print();
    }

    double DeliveryCost(double distance)
    {
        return kg * 2.0 * distance;
    }
};

class Lorry : public Transport {
public:
    Lorry() {}
    Lorry(string nm, string topl, string tp, double k)
        : Transport(nm, topl, tp, k) {}

    void Input()
    {
        Transport::Input();
    }

    void Print()
    {
        Transport::Print();
    }

    double DeliveryCost(double distance)
    {
        return kg * 1.2 * distance;
    }
};

int main() {
    Transport* transport = nullptr;
    int choice;

    cout << "Выберите тип транспорта:\n";
    cout << "1. Автомобиль\n2. Самолет\n3. Грузовик\n";
    cin >> choice;

    switch (choice)
    {
    case 1:
        transport = new Car();
        break;
    case 2:
        transport = new Airplane();
        break;
    case 3:
        transport = new Lorry();
        break;
    }

    transport->Input();
    transport->Print();
    double distance;
    cout << "Введите расстояние доставки (в км): ";
    cin >> distance;
    cout << "Стоимость доставки: " << transport->DeliveryCost(distance) << endl;
}
