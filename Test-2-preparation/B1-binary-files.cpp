#include <iostream>
#include <fstream>

using namespace std;

int countSum2Plus(fstream& fb) {
    int curr = 0;
    int prev = 0;
    int n = 0;

    int sum = 0;
    int second_ind = 1;

    while (fb.read((char*)&n, sizeof(n))) {
        if (second_ind != 2) { // if second element already encountered and stored
            //cout << n << endl;
            prev = curr;
            curr = n;
            second_ind++;
        } else {
            //cout << n << endl;
            prev = curr;
            curr = n;
            second_ind++;
            sum += n; // add second element to the sum
        }
    }

    sum += prev; // store the second from the end element
    return sum;
}

int main() {

    fstream fb("binout.txt", ios::in|ios::binary);

    cout << countSum2Plus(fb) << endl;

    fb.close();

    return 0;
}
