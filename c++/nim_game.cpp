#include <iostream>

using namespace std;

class Solution {
public:
  bool canWinNim(int n) {
    if (n % 4 == 0) {
      return false;
    } else {
      return true;
    }
  }
};

int main() {
  int n = 4;
  Solution s;
  if (s.canWinNim(n)) {
    cout << "Win" << endl;
  } else {
    cout << "Lose" << endl;
  }
  return 0;
}
