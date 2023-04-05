/*******************************************

Edgars Spira es22027

Create two programs in C++ to process sequences of values in two ways:
  1) implementing it through a linked list, using dynamic data structures,
  2) using STL::list.
In both implementations, a specific function to process values should be created and presented in action (showing both initial and resulting values).
In the case of linked-list, also auxiliary functions should be created and allocated memory for the structure should be freed.

G4. Write a function to check - are all values in list at least twice.

Program created: 27.03.2023

*******************************************/

#include <iostream>
#include <list>
#include <map>

using namespace std;

void checkIfAllValuesAtLeastTwice(list<int> & lst) {
    map<int, int> check;
    bool all = true;

    //  map how many times the value have been encountered in the list
    for(auto it = lst.begin(); it != lst.end(); ++it) {
        check[*it]++;
    }

    //  print out which values have not been seen twice || print out if all values have been seen twice
    for(auto it : check) {
        if(it.second == 1) {
            cout << "This value is not encountered at least twice in the list: " << it.first << endl;
            all = false;
        }
    }
    if (all) cout << "All values encountered at least twice in the list." << endl;
}

int main() {
    int ok;
    do {
        int elements = 0;
        cout << "How many elements to enter?: ";
        cin >> elements;
        while(elements < 1) {
            cout << "Invalid amount of elements. Enter at least 1:";
            cin >> elements;
        }

        list <int> lst;

        cout << "Enter " << elements << " values: ";
        for(int i = 0; i< elements; i++) {
            int temp = 0;
            cin >> temp;
            lst.push_back(temp);
        }
        checkIfAllValuesAtLeastTwice(lst);


        cout << " Continue (1) or quit (0)?" << endl;
        cin >> ok;
    } while (ok == 1);
}
