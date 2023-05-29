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
    char* Brand;  // Pointer to dynamically allocated character array

public:
    Car(int wheelCount, const char* brand) : Vehicle(wheelCount) {
        int length = 0;
        while (brand[length] != '\0') {
            length++;
        }

        Brand = new char[length + 1];  // Allocate memory for the brand name

        for (int i = 0; i <= length; i++) {
            Brand[i] = brand[i];  // Copy characters one by one
        }

        cout << "Car constructor called." << endl;
    }

    Car(const Car& other) : Vehicle(other.WheelCount) {
        int length = 0;
        while (other.Brand[length] != '\0') {
            length++;
        }

        Brand = new char[length + 1];  // Allocate memory for the brand name

        for (int i = 0; i <= length; i++) {
            Brand[i] = other.Brand[i];  // Copy characters one by one
        }

        cout << "Car copy constructor called." << endl;
    }

    ~Car() override {
        cout << "Car destructor called." << endl;
        delete[] Brand;  // Release the dynamically allocated memory
    }

    Car& operator=(const Car& other) {
        if (this != &other) {
            // Release the existing memory
            delete[] Brand;

            // Copy the wheel count
            WheelCount = other.WheelCount;

            // Calculate the length of the brand name
            int length = 0;
            while (other.Brand[length] != '\0') {
                length++;
            }

            // Allocate memory for the new brand name
            Brand = new char[length + 1];

            // Copy the brand name
            for (int i = 0; i <= length; i++) {
                Brand[i] = other.Brand[i];
            }
        }

        cout << "Car assignment operator called." << endl;
        return *this;
    }

    void print() override {
        cout << "Car - WheelCount: " << WheelCount << ", Brand: " << Brand << endl;
    }
};

int main() {
    Vehicle vehicle(4);
    vehicle.print();

    cout << "--------------------------" << endl;

    Car car1(4, "Toyota");
    car1.print();

    cout << "--------------------------" << endl;

    Car car2 = car1;  // Copy constructor called
    car2.print();

    cout << "--------------------------" << endl;

    Car car3(4, "BMW");
    car3.print();

    cout << "--------------------------" << endl;

    car2 = car3;  // Assignment operator called
    car2.print();


    return 0;
}
