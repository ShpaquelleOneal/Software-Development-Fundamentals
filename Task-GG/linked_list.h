#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED

#include <iostream>
using namespace std;

struct lnkd {

private:
    int data;
    int times; // count how many times data is encountered
    lnkd *next;

public:
    lnkd(int d);
    ~lnkd();
    void insert_node(int d, lnkd* root);
    void print();
    bool checkIfAllAtLeastTwice();
};
#endif // LINKED_LIST_H_INCLUDED
