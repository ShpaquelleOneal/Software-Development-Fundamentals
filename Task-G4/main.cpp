#include <iostream>

using namespace std;

struct lnkd {
    int data;
    lnkd *next;

public:
    lnkd(int d) : data(d), next(NULL) {} // constructor
    ~lnkd() {
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

    lnkd* insert_first (int d) { // returns pointer to the first inserted element
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
};

int main()
{
    int elem = 0;
    int tem = 0;

    lnkd head(1);

    cout << "enter " << elem << "numbers" << endl;
    for (int i = 0; i < elem; i++) {
        cin>>tem;
        head.data = insert(tem);
    }
}
