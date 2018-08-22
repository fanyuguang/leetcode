#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int findLengthOfLCIS(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }
    int max_length = 1;
    int count = 1;
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] > nums[i - 1]) {
        count++;
      } else {
        if (count > max_length) {
          max_length = count;
        }
        count = 1;
      }
    }
    if (count > max_length) {
      max_length = count;
    }
    return max_length;
  }
};

int main() {
  vector<int> nums = {1, 3, 5, 4, 7};
  Solution s;
  int result = s.findLengthOfLCIS(nums);
  cout << result << endl;
  return 0;
}
