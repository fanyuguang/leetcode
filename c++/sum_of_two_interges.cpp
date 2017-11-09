#include <iostream>

using namespace std;

class Solution {
public:
  int getSum(int a, int b) {
    return b == 0 ? a : getSum(a ^ b, (a & b) << 1);
  }
};

int main() {
  Solution s;
  int result = s.getSum(1, 2);
  cout << result << endl;
  return 0;
}
