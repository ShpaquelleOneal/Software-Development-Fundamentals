#include <iostream>
#include <fstream>
using namespace std;

const int MAX_WORD_LENGTH = 256;
const int MAX_LETTERS = 26;

int main() {
    // open text files
    ifstream fin("post.in.txt");
    ofstream fon("post.out.txt");

    // Check if input file is open
    if (!fin.is_open()) {
        fon << "Error opening input file..." << endl;
        return 0;
    }

    // set up an array to count letters
    int encounters[MAX_LETTERS] = {0};
    int total_gl = 0;

    char destinations[MAX_WORD_LENGTH]; // length of word (1 to 255 + null = 256)

    // count how many times first letters are encountered
    while(fin >> destinations) {
        char temp = destinations[0];
        if(temp >= 'A' && temp <= 'Z') {
            encounters[25 - int('Z' - temp)]++;
            total_gl++;
        }
        else {
            encounters[25 - int('z' - temp)]++;
            total_gl++;
        }
    }
    fin.close();

    // if there are 0 words, print "nothing"
    if(total_gl == 0) {
        fon << "nothing";
    } else {
        // iterate through the text file for each letter and print words in order
        for(int i=0; i < MAX_LETTERS; i++) {
            if (encounters[i] != 0){
                int total = encounters[i];
                int skip = 0;
                while(total != 0) {
                    fin.open("post.in");
                    while(fin >> destinations) {
                        if (destinations[0] == 'a' + i || destinations[0] == 'A' + i) {
                            skip++;
                            if(skip == total) { // print out if the word is correct
                                if(total_gl == 1) { // special case if the word is the last one, don't add space after it
                                    total--;
                                    skip = 0;
                                    fon << destinations;
                                    break;
                                } else {
                                    total--;
                                    total_gl--;
                                    skip = 0;
                                    fon << destinations << ' ';
                                    break;
                                }
                            }
                        }
                    }
                    fin.close();
                }
            }
        }
    }
    fon.close();
    return 0;
}
