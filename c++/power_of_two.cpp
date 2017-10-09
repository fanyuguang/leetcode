#include <iostream>

using namespace std;

class Solution {
public:
  bool isPowerOfTwo(int n) {
    if (n <= 0) {
      return false;
    }
    int count = 0;
    while (n) {
      if (n & 1) {
        count++;
      }
      n >>= 1;
      cout << n << endl;
    }
    if (count > 1) {
      return false;
    } else {
      return true;
    }
  }
};

int main() {
  int n = -16;
  Solution S;
  if (S.isPowerOfTwo(n)) {
    cout << "is power of two" << endl;
  } else {
    cout << "is not power of two" << endl;
  }
  return 0;
}
