#include <iostream>
#include <string>
using namespace std;

template<typename T>
class Vehicle {
private:
    T WheelCount;

public:
    Vehicle(T wheels);
    void print() const;
};

// Constructor implementation outside the class
template<typename T>
Vehicle<T>::Vehicle(T wheels) : WheelCount(wheels) {}

// Print method implementation outside the class
template<typename T>
void Vehicle<T>::print() const {
    cout << "Wheel Count: " << WheelCount << endl;
}

int main() {
    // Creating objects of the template class with int and string types
    Vehicle<int> vehicle1(4);
    vehicle1.print();  // Output: Wheel Count: 4

    Vehicle<string> vehicle2("Two");
    vehicle2.print();  // Output: Wheel Count: Two

    return 0;
}
