#include <iostream>

using namespace std;

class Solution {
public:
  bool hasAlternatingBits(int n) {
    int iter_bit;
    while (n > 0) {
      iter_bit = n & 1 ? 1 : 0;
      n = n >> 1;
      cout << iter_bit << endl;
      if (!iter_bit ^ (1 & n)) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  int n = 10;
  Solution s;
  bool result = s.hasAlternatingBits(n);
  if (result) {
    cout << "true" << endl;
  } else {
    cout << "false" << endl;
  }
  return 0;
}
