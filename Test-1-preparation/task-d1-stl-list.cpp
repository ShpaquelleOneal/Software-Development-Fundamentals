#include <iostream>
#include <list>

using namespace std;

void incDecOdd (list<int>& tempL) {
    for (auto it=tempL.begin(); it!=tempL.end(); it++) {
        if (*it%2 != 0) {
                //cout << "spec: " << *it << endl;
            if(*it > 0){
                *it = *it - 1;
            } else {
                *it = *it + 1;
            }
        }
    }

}


int main () {
    list<int> lst; // create an empty list
    int i = 0;
    for(i=-10; i<10; i++) {
        lst.push_back(i);
    }

    cout << "Contents: " << endl;
    list<int>::iterator p = lst.begin();
    while(p != lst.end()) {
        cout << *p << " ";
        p++;
    }

    incDecOdd(lst);
    cout << "Contents: ";
    list<int>::iterator h = lst.begin();
    while(h != lst.end()) {
        cout << *h << " ";
        h++;
    }

}
