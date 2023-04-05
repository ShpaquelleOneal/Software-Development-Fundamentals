#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin_id;
    ifstream fin_words;
    fin_id.open("int_id_in.txt", ios::in|ios::binary);
    fin_words.open("words_in.txt", ios::in|ios::binary);

    ofstream fout;
    fout.open("h10_out.txt");













    fin_id.close();
    fin_words.close();
    fout.close();
}
