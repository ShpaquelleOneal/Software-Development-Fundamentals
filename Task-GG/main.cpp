#include <iostream>
#include <map>

using namespace std;

struct lnkd {
    int data;
    lnkd *next;

public:
    lnkd(int d) : data(d), next(nullptr) {} // constructor

    ~lnkd() {
        if (next != nullptr) {
            delete next;
        }
    }

    int value() {
        return data;
    }

    lnkd *iter() {
        return next;
    }

    void insert(int d) {
        lnkd *x = new lnkd(d);
        x->next = next;
        next = x;
    }

    lnkd *insert_first(int d) {
        lnkd *x = new lnkd(d);
        x->next = this;
        return x;
    }

    lnkd *insert_ordered(int d) {
        if (d <= data) return insert_first(d);
        else {
            if (next != nullptr) {
                if (d <= next->data)
                    insert(d);
                else
                    next->insert_ordered(d);
            } else {
                insert(d);
            }
            return this;
        }
    }

    void print() {
        cout << data << " ";
        if (next != nullptr) next->print();
    }

    void checkIfAllAtLeastTwice() {
        lnkd *curr = this;
        map<int, int> cnt;
        bool all = true;

        while (curr != nullptr) {
            cnt[curr->data]++;
            curr = curr->next;
        }

        for (const auto& it : cnt) {
            if (it.second == 1) {
                throw runtime_error("Value encountered only once in the list: " + to_string(it.first));
            }
        }

        cout << "All values encountered at least twice in the list." << endl;
    }
};

int main() {
    int ok;
    do {
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
        lnkd *p = new lnkd(temp);
        for (int i = 0; i < elements - 1; i++) {
            cin >> temp;
            p->insert(temp);
        }

        p->print();
        try {
            p->checkIfAllAtLeastTwice();
        } catch (const exception& e) {
            cout << "Exception: " << e.what() << endl;
        }
        delete p;

        cout << "Continue (1) or quit (0)?" << endl;
        cin >> ok;
    } while (ok == 1);
}
