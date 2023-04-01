#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main(void) {
    vector<pair<int, string>> cows = {
    make_pair(0, "Bessie"),
    make_pair(0, "Elsie"),
    make_pair(0, "Daisy"),
    make_pair(0, "Gertie"),
    make_pair(0, "Annabelle"),
    make_pair(0, "Maggie"),
    make_pair(0, "Henrietta")
    };
    
    int N;
    cin >> N;
    int compare = 0;
    
    for (int i = 0; i < N; i++) {
        string name;
        int num;
        compare = num;
        cin >> name >> num;
        if (name == "Bessie") {
            cows[0].first += num;
        } else if (name == "Elsie") {
            cows[1].first += num;
        } else if (name == "Daisy") {
            cows[2].first += num;
        } else if (name == "Gertie") {
            cows[3].first += num;
        } else if (name == "Annabelle") {
            cows[4].first += num;
        } else if (name == "Maggie") {
            cows[5].first += num;
        } else if (name == "Henrietta") {
            cows[6].first += num;
        }
    }
    sort(cows.begin(), cows.end());
    
    int firstNum = cows[0].first;
    
    if (N == 1) {
        for (int i = 0; i < cows.size(); i++) {
            if (cows[i].first != 0) {
                cout << cows[i].second;
                return 0;
            }
        }
    }
    bool tie = true;
    for (int i = 0; i < N; i++) {
        if (cows[i].first != 0 && cows[i].first != compare) {
            tie = false;
        }
    }
    if (tie) {
        cout << "TIE";
        return 0;
    }
    
    for (int i = 0; i < N; i++) {
        if (cows[i].first != firstNum) {
            cout << cows[i].second;
            return 0;
        }
    }
}
