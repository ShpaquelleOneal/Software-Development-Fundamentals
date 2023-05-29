#include <iostream>
#include <fstream>

using namespace std;


int main() {

    int bb [5] = { 1, 4, 6, 2, 12};
    fstream fb("binout.txt", ios::out|ios::binary);
    fb.write((char *) bb , 20);


    fb.close();


    return 0;
}
