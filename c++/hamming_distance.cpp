#include <iostream>

using namespace std;

class Solution{
public:
  int hammingDistance(int x, int y) {
    int distance = 0;
    int count = 1;
    while (x > 0 || y > 0) {
      distance += (x ^ y) & 1;
      x >>= 1;
      y >>= 1;
    }
    return distance;
  }
};

int main() {
  int x = 1;
  int y = 4;
  Solution S;
  int distance = S.hammingDistance(x, y);
  cout << distance << endl;
  return 0;
}
