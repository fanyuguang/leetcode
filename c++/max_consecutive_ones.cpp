#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int findMaxConsecutiveOnes(vector<int>& nums) {
    int max_count = 0;
    int start_index = -1;
    for (int index = 0; index < nums.size(); index++) {
      if (nums[index] == 0) {
        if (index > start_index + 1 && (index - start_index - 1) > max_count) {
          max_count = index - start_index - 1;
        }
        start_index = index;
      }
    }
    if (start_index < (int)nums.size() - 1 && (int)(nums.size() - start_index - 1) > max_count) {
      max_count = nums.size() - start_index - 1;
    }
    return max_count;
  }
};

int main() {
  vector<int> nums{1, 1, 0, 1, 1, 1};
  Solution s;
  int result = s.findMaxConsecutiveOnes(nums);
  cout << result << endl;
  return 0;
}
