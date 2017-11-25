#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> selfDividingNumbers(int left, int right) {
    vector<int> nums;
    for (int i = left; i <= right; i++) {
      int j = i;
      bool flag = true;
      while (j > 0) {
        int remainder = j % 10;
        if (remainder == 0 || i % remainder != 0) {
          flag = false;
          break;
        }
        j = j / 10;
      }
      if (flag) {
        nums.push_back(i);
      }
    }
    return nums;
  }
};

int main() {
  int left = 1;
  int right = 22;
  Solution s;
  vector<int> result = s.selfDividingNumbers(left, right);
  for (int num : result) {
    cout << num << endl;
  }
  return 0;
}
