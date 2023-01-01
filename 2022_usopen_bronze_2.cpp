//INCOMPLETE!!! basic concept but incorrect
//must loop more

#include <cstdio>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cmath>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
 
int main() {
    long long N;
    cin >> N;

    pair<long long, long long> interval(1, pow(10, 9));
    bool condition;
    long long amt = 0;
    int ans;
    for (int i = 0; i < N; i++) {
        long long num;
        char letter;
        cin >> letter >> num;


        if (letter == 'G') {
            if (num >= interval.first && num <= interval.second) { // if in interval
                condition = true;
                interval.first = num;
            } else {
                condition = false;
                amt++;
            }
        }
        if (letter == 'L') {
            if (num >= interval.first && num <= interval.second) { // if in interval
                condition = true;
                interval.second = num;
            } else {
                condition = false;
                amt++;
            }
        }
        ans = min(N, amt);
    }
    
    cout << ans << endl;
}
