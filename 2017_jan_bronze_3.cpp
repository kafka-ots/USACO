#include <cstdio>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;
 
int main() {
    ifstream fin ("cowtip.in");
    ofstream fout ("cowtip.out");

    int N;
    fin >> N;

    vector<vector<char>> farm(N, vector<char> (N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char temp;
            fin >> temp;
            farm[i][j] = temp;
        }
    }

    int total = 0;
    for (int i = N-1; i >= 0; i--) {
        for (int j = N-1; j >= 0; j--) {
            if (farm[i][j] == '1') {
                total++;
                for (int x = 0; x <= i; x++) {
                    for (int y = 0; y <= j; y++) {
                        if (farm[x][y] == '0') {
                            farm[x][y] = '1';
                        } else {
                            farm[x][y] = '0';
                        }
                    }
                }
            }
        }
    }
    fout << total << endl;   
}
