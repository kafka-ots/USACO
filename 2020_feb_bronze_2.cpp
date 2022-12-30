#include <cstdio>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;
 
int main() {
    ifstream fin ("breedflip.in");
    ofstream fout ("breedflip.out");

    long long N;
    fin >> N;
    string A, B;
    fin >> A >> B;
    long long ans = 0;
    bool mis = false;

    for (long long i = 0; i < N; i++) {
        if (A[i] != B[i]) {
            if (!mis) {
                ans++;
                mis = true;
            }
        } else {
            mis = false;
        }
    }
    fout << ans << endl;
}
