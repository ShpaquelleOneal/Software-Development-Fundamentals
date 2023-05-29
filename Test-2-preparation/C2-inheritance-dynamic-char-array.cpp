#include <iostream>

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
    char * Brand;

public:
    Car(int wheelCount, const char * brand) : Vehicle(wheelCount) {
        int length = 0;
        while (brand[length] != '\0') {
            length++;
        }

        Brand = new char [length+1];
        for (int i = 0; i< length + 1; i++) {
            Brand[i] = brand[i];
        }
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
