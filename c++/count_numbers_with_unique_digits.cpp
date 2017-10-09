#include <iostream>

using namespace std;

class Solution{
public:
  int countNumbersWithUniqueDigits(int n) {
    if (n == 0) {
      return 1;
    }
    if (n == 1) {
      return 10;
    }
    int count_per = 9;
    int count = 10;
    for (int i = 2; i <= n && i <= 10; i++) {
      count_per *= 11 - i;
      count += count_per;
    }
    return count;
  }
};

int main() {
  int n = 2;
  Solution s;
  int result = s.countNumbersWithUniqueDigits(n);
  cout << result << endl;
  return 0;
}
