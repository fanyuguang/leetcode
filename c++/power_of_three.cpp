#include <iostream>

using namespace std;

class Solution {
public:
  bool isPowerOfThree(int n) {
    if (n > 0 && 1162261467 % n == 0) {
      return true;
    } else {
      return false;
    }
  }
};

int main() {
  Solution s;
  bool result = s.isPowerOfThree(9);
  if (result) {
    cout << "true" << endl;
  } else {
    cout << "false" << endl;
  }
  return 0;
}
