#include <iostream>
#include <vector>
#include "../linked_list.h"


using namespace std;

int main()
{
    int arrElements;
    vector<int> test;
    lnkd* root = nullptr;

    // Test case #1, {0, 0, 0}, result - true (all elements encountered at least twice)
    arrElements = 3;
    test = {0, 0, 0};
    root = new lnkd(test[0]);
    for (int i = 1; i < arrElements; i++) {
        root->insert_node(test[i], root);
    }
    //root->print();
    try {
        if(root->checkIfAllAtLeastTwice()) {
            cout << "Test #1 passed..." << endl;
        }
    } catch (const  char * msg) {
        cout << "Test #1 failed..." << endl;
    }
    delete root;

    // Test case #2, {5, 5, 10, 10}, result - true
    arrElements = 4;
    test = {5, 5, 10, 10};
    root = new lnkd(test[0]);
    for (int i = 1; i < arrElements; i++) {
        root->insert_node(test[i], root);
    }
    //root->print();
    try {
        if(root->checkIfAllAtLeastTwice()) {
            cout << "Test #2 passed..." << endl;
        }
    } catch (const  char * msg) {
        cout << "Test #2 failed..." << endl;
    }
    delete root;

    // Test case #3, {-10, 5, 5, 2, 2, 10, 11}, result - false (one or more elements not encountered at least twice)
    arrElements = 7;
    test = {-10, 5, 5, 2, 2, 10, 11};
    root = new lnkd(test[0]);
    for (int i = 1; i < arrElements; i++) {
        root->insert_node(test[i], root);
    }
    //root->print();
    try {
        if(root->checkIfAllAtLeastTwice()) {
            cout << "Test #3 failed..." << endl;
        }
    } catch (const  char * msg) {
        cout << "Test #3 passed..." << endl;
    }
    delete root;

    // Test case #4, {-5, -1, -5, -1}, result - true
    arrElements = 4;
    test = {-5, -1, -5, -1};
    root = new lnkd(test[0]);
    for (int i = 1; i < arrElements; i++) {
        root->insert_node(test[i], root);
    }
    //root->print();
    try {
        if(root->checkIfAllAtLeastTwice()) {
            cout << "Test #4 passed..." << endl;
        }
    } catch (const  char * msg) {
        cout << "Test #4 failed..." << endl;
    }
    delete root;

}
