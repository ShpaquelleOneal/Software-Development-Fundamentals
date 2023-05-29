#include <iostream>
#include <string>

using namespace std;

class Vehicle {
protected:
    int WheelCount;

public:
    Vehicle(int wheelCount) : WheelCount(wheelCount) {
        cout << "Vehicle constructor called." << endl;
    }

    virtual ~Vehicle() {
        cout << "Vehicle destructor called." << endl;
    }

    virtual void print() {
        cout << "Vehicle - WheelCount: " << WheelCount << endl;
    }
};

class Car : public Vehicle {
private:
    string Brand;

public:
    Car(int wheelCount, string brand) : Vehicle(wheelCount), Brand(brand) {
        cout << "Car constructor called." << endl;
    }

    ~Car() override {
        cout << "Car destructor called." << endl;
    }

    void print() override {
        cout << "Car - WheelCount: " << WheelCount << ", Brand: " << Brand << endl;
    }
};

int main() {
    Vehicle vehicle(4);
    vehicle.print();

    cout << "--------------------------" << endl;

    Car car(4, "Toyota");
    car.print();

    return 0;
}
