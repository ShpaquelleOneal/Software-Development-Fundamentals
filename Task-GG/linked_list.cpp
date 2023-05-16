#include "linked_list.h"

lnkd::lnkd(int d){
    data = d;
    times = 1;
    next = nullptr;
}

// desctructor for all list
lnkd::~lnkd() {
    if (next != nullptr) {
        delete next;
    }
}

// insert new element
void lnkd::insert_node(int d, lnkd* root) {
    lnkd *curr = this;
    while (curr != nullptr) { // iterate through the list, if there is a node with such value, ++times variable
        if (curr->data == d) {
            curr->times++;
            return;
        }
        curr = curr->next; // update the curr pointer to the next node
    }
    // if the data is not encountered in the nodes, create a new node
    lnkd *x = new lnkd(d);
    x->next = root->next;
    root->next = x;
}
void lnkd::print() { // print distinct values of the whole list
    cout << "Number " << data << " encountered " << times << endl;
    if (next != nullptr) next->print();
}

bool lnkd::checkIfAllAtLeastTwice() {

    lnkd *curr = this;
    while (curr != nullptr) { // iterate through the list
        if (curr->times <2) { // if value hasn't been encountered twice, throw an error
            throw "Not all encountered twice.";
            return false;
        }
        curr = curr->next;
    }
    return true;
}
