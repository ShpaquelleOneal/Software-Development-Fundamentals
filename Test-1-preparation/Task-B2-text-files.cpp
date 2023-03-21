#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void removeExtraAdjacentSpaces(ifstream& fin, ofstream& fon) {

    string t;
    getline(fin, t);

    while (fin) {
        for (int i = 0; i < t.length(); i++) {
            if (isspace(t[i])) {
                while(isspace(t[i+1]) && i+1 != t.length()) {
                    t.erase(i+1, 1);
                }
            }
        }
        fon << t << endl;
        getline(fin, t);
    }
}

int main () {
    ifstream fin;
    ofstream fon;
    fin.open("text2.txt");
    fon.open("exit2.txt");

    removeExtraAdjacentSpaces(fin, fon);

    fin.close();
    fon.close();

}
