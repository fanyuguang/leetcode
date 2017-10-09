#include <iostream>

using namespace std;

class Solution {
public:
  int integerBreak(int n) {
    if (n == 2 || n == 3) {
      return n - 1;
    }
    int count_3 = n / 3;
    int remainder = n % 3;
    int max_product = 1;
    for (int i = 0; i < count_3; i++) {
      max_product *= 3;
    }
    if (remainder == 1) {
      return max_product / 3 * 4;
    } else if (remainder ==2) {
      return max_product * 2;
    } else {
      return max_product;
    }
  }
};

int main() {
  int n = 2;
  Solution s;
  int result = s.integerBreak(n);
  cout << result << endl;
  return 0;
}
