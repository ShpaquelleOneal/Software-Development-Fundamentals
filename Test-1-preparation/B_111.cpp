#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool hasNoDigits(const string& line) {
    for (char c : line) {
        if (c >= '0' && c <= '9') {
            return false;
        }
    }
    return true;
}

void PrintLastLineAfterLineWithoutNoDigits(ifstream& fin) {
    string currentLine, lastLine;

    while (getline(fin, currentLine)) {
        if (hasNoDigits(currentLine)) {
            lastLine = currentLine;
        }
    }

    if (!lastLine.empty()) {
        cout << "Last line after line without any digits: " << lastLine << endl;
    } else {
        cout << "No line found after a line without any digits." << endl;
    }
}

int main() {
    ifstream fin("text2.txt");

    if (!fin) {
        cerr << "Failed to open the input file." << endl;
        return 1;
    }

    PrintLastLineAfterLineWithoutNoDigits(fin);

    fin.close();

    return 0;
}
