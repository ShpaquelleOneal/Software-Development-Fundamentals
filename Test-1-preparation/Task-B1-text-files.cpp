#include <iostream>
#include <fstream>

using namespace std;

int countExtraAdjacentSpaces(string s) {
    int cnt = 0;
    for (int i = 0; i < s.length(); i++) {
        if (isspace(s[i])) {
            int j = i;
            while (isspace(s[j+1]) && j+1 != s.length()) {
                cnt++;
                j++;
            }
            i = j;
        }
    }
    return cnt;
}

int main () {
    ifstream fin;
    fin.open("text.txt");

    string t;
    int spaces = 0;


    getline(fin, t);
    while (fin) {
        spaces += countExtraAdjacentSpaces(t);
        getline(fin, t);
    }
    cout << spaces << " extra adjacent spaces";

    fin.close();

}
