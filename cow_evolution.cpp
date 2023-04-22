#include <iostream>
#include <cmath>
#include <vector>
#include <utility>
#import <string>
#include <cctype>
#include <algorithm>
using namespace std;
#define ll long long

int N;
vector<string> cows[30];
vector<string> allCharacteristics;

bool check(int A, int B) {
  bool AnotB = false, BnotA = false, both = false;
  for (int i = 0; i < N; i++) {
    bool hasA = false, hasB = false;
    for (int j = 0; j < (int)cows[i].size(); j++) {
      if (cows[i][j] == allCharacteristics[A]) {
        hasA = true;
      }
      if (cows[i][j] == allCharacteristics[B]) {
        hasB = true;
      }
    }
    if (hasA && !hasB) {
      AnotB = true;
    }
    if (hasB && !hasA) {
      BnotA = true;
    }
    if (hasA && hasB) {
      both = true;
    }
  }
  if (AnotB && BnotA && both) {
    return false;
  } else {
    return true;
  }
}

int main(void) {
  cin >> N;
  int num;
  string characteristic;
  for (int i = 0; i < N; i++) {
    cin >> num;
    for (int j = 0; j < num; j++) {
      cin >> characteristic;
      cows[i].push_back(characteristic);
      if (find(allCharacteristics.begin(), allCharacteristics.end(), characteristic) == allCharacteristics.end()) {
        allCharacteristics.push_back(characteristic);
      }
    }
  }
  
  for (int i = 0; i < (int)allCharacteristics.size(); i++) {
    for (int j = i+1; j < (int)allCharacteristics.size(); j++) {
      if (!check(i, j)) {
        cout << "no" << endl;
        return 0;
      }
    }
  }
  cout << "yes" << endl;
  return 0;
}
