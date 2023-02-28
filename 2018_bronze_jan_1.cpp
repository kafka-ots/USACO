#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

class Rectangle {
  public:
    int x1, y1, x2, y2;

    Rectangle() {}

    Rectangle(int x1, int y1, int x2, int y2): x1(x1), y1(y1), x2(x2), y2(y2) {}

    bool covers(int x, int y) {
      return x1 <= x && x <=x2 && y1 <= y && y <= y2;
    }

    int area() {
      return (x2-x1)*(y2-y1);
    }

    Rectangle intersection(const Rectangle &other) {
      Rectangle res(
          max(x1, other.x1), max(y1, other.y1),
          min(x2, other.x2), min(y2, other.y2)
          );
      return res;
    }
};

int main(void) {
  Rectangle lawnBoard;
  cin >> lawnBoard.x1 >> lawnBoard.y1 >> lawnBoard.x2 >> lawnBoard.y2;
  Rectangle feedBoard;
  cin >> feedBoard.x1 >> feedBoard.y1 >> feedBoard.x2 >> feedBoard.y2;

  int count = 0;
  if (feedBoard.covers(lawnBoard.x1, lawnBoard.y1)) count++;
  if (feedBoard.covers(lawnBoard.x2, lawnBoard.y2)) count++;
  if (feedBoard.covers(lawnBoard.x1, lawnBoard.y2)) count++;
  if (feedBoard.covers(lawnBoard.x2, lawnBoard.y1)) count++;

  if (count < 2) {
    cout << lawnBoard.area();
  } else if (count == 4) {
    cout << 0;
  } else {
    Rectangle inter = feedBoard.intersection(lawnBoard);
    cout << (lawnBoard.area()-inter.area());
  }
}
