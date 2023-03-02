//!!!! bugged !!!


#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

class Checkpoint {
    public:
        int x, y;

        Checkpoint(int x, int y): x(x), y(y) {}

        int distance(int x2, int y2) {
          return abs(x-x2) + abs(y-y2);
        }
};

int main(void) {
    int N;
    cin >> N;
    vector<Checkpoint> checkpoints;
    for (int i = 0; i < N; i++) {
      int x, y;
      cin >> x >> y;
      checkpoints.push_back(Checkpoint(x, y));
    }

    int max_dist = -3;
    int skip = 0;
    for (int i = 1; i < N-1; i++) {
      int temp = checkpoints[i].distance(checkpoints[i+1].x, checkpoints[i+1].y);
      if (temp > max_dist) {
        max_dist = temp;
        skip = i;
      }
    }

    int distance = 0;
    for (int i = 0; i < N-1; i++) {
      if (i+1 == skip) {
          distance += checkpoints[i].distance(checkpoints[skip+1].x, checkpoints[skip+1].y);
      } else if (i == skip) {
          continue;
      } else {
        distance += checkpoints[i].distance(checkpoints[i+1].x, checkpoints[i+1].y);
      }
    }

    cout << distance;
}
