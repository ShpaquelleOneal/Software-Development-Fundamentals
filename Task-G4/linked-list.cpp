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
#include <map>

using namespace std;

struct lnkd {
    int data;
    lnkd *next;

public:
    lnkd(int d) : data(d), next(NULL) {} // constructor
    ~lnkd() {
        //cout << data << ": deleted." << endl;
        if(next != NULL) {
            delete next;
        }
    }

    int value() {
        return data;
    }

    lnkd* iter() {
        return next;
    }

    void insert(int d) {
        lnkd *x = new lnkd(d);
        x -> next = next;
        next = x;
    }

    lnkd* insert_first (int d) {
        lnkd *x = new lnkd(d);
        x -> next = this;
        return x;
    }

    lnkd* insert_ordered (int d) {
        if(d <= data) return insert_first(d);
        else {
            if(next != NULL) {
                if(d <= next -> data) insert(d);
                else next -> insert_ordered(d);
            } else {
                insert(d);
            }
            return this;
        }
    }

    void print() {
        cout << data << " ";
        if(next != NULL) next -> print();
    }

    //  function that checks if all linked list elements encounters at least twice
    //  take pointer to the first element as input
    void checkIfAllAlteastTwice() {

        lnkd * curr = this;
        map<int, int> cnt; //   use map for convenient processing
        bool all = true;

        //  map how many times the value have been encountered in the list
        while(curr != NULL) {
            cnt[curr->data]++;
            curr = curr->next;
        }

        //  print out which values have not been seen twice || print out if all values have been seen twice
        for(auto it : cnt) {
            if(it.second == 1) {
                cout << "This value is not encountered at least twice in the list: " << it.first << endl;
                all = false;
            }
        }
        if (all) cout << "All values encountered at least twice in the list." << endl;
    }
};

int main()
{
    int ok;
    do {
        //  user friendly input system
        int elements = 0;
        cout << "How many elements to enter?: ";
        cin >> elements;
        while(elements < 1) {
            cout << "Invalid amount of elements. Enter at least 1:";
            cin >> elements;
        }

        cout << "Enter " << elements << " values: ";
        int temp = 0;
        cin >> temp;
        lnkd* p = new lnkd(temp);
        for(int i = 0; i< elements - 1; i++) {
            cin >> temp;
            p->insert(temp);
        }

        p->print();
        p->checkIfAllAlteastTwice();
        delete p;

        cout << " Continue (1) or quit (0)?" << endl;
        cin >> ok;
    } while (ok == 1);
}
