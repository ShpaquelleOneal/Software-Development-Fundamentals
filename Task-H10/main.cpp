/*******************************************

Edgars Spira es22027

H10. Read text from two given text files. Text in both given file contains identified words.
One line in file is one word in format <integer ID> <Word max 30 characters>
Merge both files in third file.
Print data in third file in descending order by ID value.
The same ID may not appear twice in third file. If two words have the same ID, concatenate them in third file.

Program created: 07.04.2023

*******************************************/

#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>

using namespace std;

// function to remove trailing spaces from a string
void trimBack(string& s) {
    size_t end = s.find_last_not_of(" "); // find the position of last non " " (space) character
    if (end != string::npos) { // if non-space character is found >
        s = s.substr(0, end + 1); // remove excessive spaces up to last character found before
    } else { // if non-space is not found, clear the string
        s.clear();
    }
}

// function to remove front spaces, same as trimBack
void trimFront(string& s) {
    size_t start = s.find_first_not_of(" ");
    if (start != string::npos) {
        s = s.substr(start);
    } else {
        s.clear();
    }
}

// function to read from file in format (<int>"space"<string>) and add to the map
void readFileMap(ifstream &file, map<int,string> &cst_map) {
    string word;
    int id;
    while (file >> id) { // read ID
        getline(file, word); // read everything after ID
        word = word.substr(1); // remove leading space from the word

        // sanitize spaces from both sides
        trimFront(word);
        trimBack(word);
        cst_map[id] = cst_map[id] + word + " "; // insert data to the map
    }
    file.close();
}

int main() {
    int ok;
    do {
        // open input and output files
        ifstream fin_one("file_1.txt");
        ifstream fin_two("file_2.txt");

        ofstream fon("merged.txt");

        // check if input files have been opened
        if (!fin_one.is_open() && !fin_two.is_open() || !fon.is_open()) {
            fon << "Error opening files..." << endl;
            return 0;
        }

        // Check if the file is empty
        if (fin_one.peek() == ifstream::traits_type::eof() && fin_two.peek() == ifstream::traits_type::eof()) {
            fon << "Both files are empty...";
            return 0;
        }

        // add data to the map using function
        map<int, string> merged;

        readFileMap(fin_one, merged);
        readFileMap(fin_two, merged);

        // map is automatically ordered ASC by key
        // backwards iteration of map to print out in DESC order and trim trailing space
        for (auto iter = merged.rbegin(); iter != merged.rend(); ++iter) {
            string temp = iter -> second;
            trimBack(temp);
            fon << iter -> first << " " << temp << endl;
        }

        fon.close();

        cout << " Continue (1) or quit (0)?" << endl;
        cin >> ok;
    } while (ok == 1);
    return 0;
}
