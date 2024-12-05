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
        cout << "������� �������� ������ ����������: ";
        cin >> name;
        cout << "������� ��� �������: ";
        cin >> toplivo;
        cout << "������� ��� ������ ����������: ";
        cin >> type;
        cout << "������� ��� ������ ����������: ";
        cin >> kg;
    }
    virtual void Print()
    {
        cout << "��������: " << name
            << "\t�������: " << toplivo
            << "\t���: " << type
            << "\t���: " << kg << endl;
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

    cout << "�������� ��� ����������:\n";
    cout << "1. ����������\n2. �������\n3. ��������\n";
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
    cout << "������� ���������� �������� (� ��): ";
    cin >> distance;
    cout << "��������� ��������: " << transport->DeliveryCost(distance) << endl;
}
