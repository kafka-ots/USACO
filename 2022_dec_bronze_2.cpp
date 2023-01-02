#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
 
int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int N, K;
        cin >> N >> K;
        string cows;
        cin >> cows;
        int patches = 0;
        int pos = 0;
        vector<char> position(N, '.');
        int lastH = -1e9;
        int lastG = -1e9;

        for (int j = 0; j < N; j++) {
            if (cows[j] == 'H' && lastH < j-K) {
                int pos = min(N-1, j+K);
                if (position[pos] != '.') pos--;

                position[pos] = 'H'; patches++;
                lastH = pos;
            } else if (cows[j] == 'G' && lastG < j-K) {
                int pos = min(N-1, j+K);
                if (position[pos] != '.') pos--;

                position[pos] = 'G'; patches++;
                lastG = pos;
            }
        }
        cout << patches << '\n';
        for (char c: position) cout << c;
        cout << '\n';
    }
}
