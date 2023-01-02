#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    //reading input
    vector<long long> tuitions;
    for (int i = 0; i < N; i++) {
        long long temp;
        cin >> temp;
        tuitions.push_back(temp);
    }

    sort(tuitions.begin(), tuitions.end());

    long long highest_tuition = 0;
    long long tuition = 0;

    for (int i = 0; i < N; i++) {
        long long money = (N-i)*tuitions[i];
        if (money > highest_tuition) {
            highest_tuition = money;
            tuition = tuitions[i];
        }
    }

    cout << highest_tuition << " " << tuition << endl;

}
