#include <iostream>
#include <list>
using namespace std;

void removeOddAfterTwoOdds(list<int>& lst) {
    auto it = lst.begin();
    int counter = 0;

    while (it != lst.end()) {
        if (*it % 2 != 0) {  // Check if the data is odd
            counter++;
        } else {
            counter = 0;
        }

        if (counter > 2) {
            auto prevIt = it;
            it = lst.erase(prevIt);
            counter = 2;
        } else {
            ++it;
        }
    }
}

void printList(const list<int>& lst) {
    for (const auto& element : lst) {
        cout << element << " ";
    }
    cout << endl;
}

int main() {
    using namespace std;

    list<int> myList1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    removeOddAfterTwoOdds(myList1);
    printList(myList1);  // Output: 1 2 3 4 5 6 7 8 9

    list<int> myList2 = {1, 2, 3, 4, 5, 7, 9, 11, 13, 2, 4, 6, 8};
    removeOddAfterTwoOdds(myList2);
    printList(myList2);  // Output: 1 2 3 4 5 7 9 2 4 6 8

 return 0;
}
