#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

class Cow {
  public:
    int id, side, cnt = 0;

    Cow(int id, int side): id(id), side(side) {}

    void reset(int side1) {
      if (side1 != side) {
        cnt++;
        side = side1;
      }
    }
};

int main(void) {
  int n;
  cin >> n;
  vector<Cow> cows;
  for (int i = 0; i < 11; i++) {
    cows.push_back(Cow(-3, -3));
  }
  for (int i = 0; i < n; i++) {
    int id;
    cin >> id;
    int side;
    cin >> side;
    if (cows[id].id == -3) {
      cows[id].id = id;
      cows[id].side = side;
    } else {
      cows[id].reset(side);
    }
  }
  int cnt = 0;
  for (int i = 0; i < 11; i++) {
    if (cows[i].side != -3) {
      cnt += cows[i].cnt;
    }
  }
  cout << cnt;
}





