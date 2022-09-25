//i'm sure this isnt the best way to do it, but it's not too slow...
//actually did this one without any help at all (for the main algorithm at least)

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;



int main(void) {
    ifstream fin ("cownomics.in");
    ofstream fout ("cownomics.out");
    int N, M;
    int l = 0;
    fin >> N >> M;
    char genomes[N*2][M];
    string temp;

    
    for (int z = 0; z < N*2; z++) {
        fin >> temp;
        l = 0;
        for (int y = 0; y < M; y++) {
            genomes[z][y] = temp[l];
            l++;
        }
    }


    int count = 0;
    int res = 0;



    for (int i = 0; i < M; i++) {
            count = 0;
            for (int column2 = N; column2 < N*2; column2++) {
                char g2 = genomes[column2][i];

                for (int column = 0; column < N; column++) {
                    char g = genomes[column][i];
                    if (g != g2) {
                        count++;
                    }
                }


            }
            if (count == N*N) {
                res++;
            }
    }
    fout << res << "\n";
}
