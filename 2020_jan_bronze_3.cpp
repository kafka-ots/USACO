//INCORRECT

#include <cstdio>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cmath>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool ok(long long num, long long pos, long long K, long long X) {
    if ((K-pos) <= (num-X)) {
        return false;
    } else {
        return true;
    }
}

long long solve(long long X, long long K) {
    long long pos = 1;
    long long num = 0;
    long long sum = 0;
    for (int i = 0; i < K; i++) {
        if (ok(num, pos, K, X)) {
            num++;
        } else {
            num--;
        }
        sum += num;
        pos++;
    }
}
 
int main() {
    ifstream fin("race.in");
    ofstream fout("race.out");

    long long K, N;
    fin >> K >> N;

    for (int i = 0; i < N; i++) {
        long long X;
        fin >> X;
        long long temp;
        temp = solve(X, K);
    }
}
