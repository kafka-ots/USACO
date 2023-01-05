#include <cstdio>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cmath>
#include <iostream>

using namespace std;


int main() {
    ifstream fin("word.in");
    ofstream fout("word.out");

    int N, K;
    fin >> N >> K;

    vector<string> words;
    for (int i = 0; i < N; i++) {
        string temp;
        fin >> temp;
        words.push_back(temp);
    }

    int word_counter = 0;
    int counter = 0;
    int new_line = 0;
    while (word_counter < N) {
        int size = words[word_counter].size();
        if (counter + size > K) {
            fout << endl;
            counter = 0;
            new_line = 0;
        } else {
            if (new_line == 0) {
                fout << words[word_counter];
            } else {
                fout << " " << words[word_counter];
            }
            word_counter++;
            counter += size;
            new_line++;
        }
    }
}

