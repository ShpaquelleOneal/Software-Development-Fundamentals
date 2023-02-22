/*******************************************

Edgars Spira es22027

F18. Create program to read given text file and print into another text file number of words by length.
Count all one-letter words, all two-letter words, all three-letter words, ... and print number of words into output file.
Word in input file is string containing only English alphabet letters.
All other symbols in text file are interpreted as word separators.

Program created: 22.02.2023

*******************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main() {
    int ok;
    do
    {
        ifstream fin;
        ofstream fon;

        // use map for convenient storage words count
        string c;
        map<int, int> count;

        // open required files for input and output
        fin.open("f_18in.txt");
        fon.open("f_18out.txt");

        // iterate through every line of the text file
        getline(fin, c);
        while (fin) {
            int letters = 0;

            // iterate through the string, check if the value is a letter and count them into a word
            for (unsigned int i = 0; i < c.length(); i++) {
                if ((c[i] >= 'A' && c[i] <= 'Z') || (c[i] >= 'a' && c[i] <= 'z')) {
                    letters++;
                    if (i+1 == c.length()) count[letters]++; // special case if it is the last letter, save it
                }

                // if the value is not a letter, reset letter count and save the result to the map
                else {
                    if (letters != 0) count[letters]++;
                    letters = 0;
                }
            }
            getline(fin, c); //read new line
        }

        // print the result to the text file
        fon << "Number of letters in a word / Number of such words" << endl;
        for (auto it : count) {
            fon << it.first << " letter word / appears " << it.second << " times" << endl;
        }

        //close all opened files
        fin.close();
        fon.close();

        cout << "Operation successful." << endl;
        cout << "Repeat (1) or quit (0)?" << endl;
        cin >> ok;
    } while (ok == 1);
}
