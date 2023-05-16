#include <iostream>
#include "linked_list.h"

using namespace std;

int main() {
    int ok;
    do {
        // user friendly input system
        int elements = 0;
        cout << "How many elements to enter?: ";
        cin >> elements;

        while (elements < 1) {
            cout << "Invalid amount of elements. Enter at least 1:";
            cin >> elements;
        }

        cout << "Enter " << elements << " values: ";
        int temp = 0;
        cin >> temp;
        lnkd* root = new lnkd(temp);
        for (int i = 0; i < elements - 1; i++) {
            cin >> temp;
            root->insert_node(temp, root);
        }

        root->print();
        cout << endl;

        try {
            if(root->checkIfAllAtLeastTwice()) {
                cout << "All elements encountered at least twice." << endl;
            }
        } catch (const char * msg) {
            cout << msg << endl;
        }


        // clear the linked list
        delete root;

        cout << endl;
        cout << "Continue (1) or quit (0)?" << endl;
        cin >> ok;
    } while (ok == 1);
}
