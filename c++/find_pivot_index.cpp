#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int pivotIndex(vector<int>& nums) {
    int sum_right = 0;
    for (int i = 1; i < nums.size(); i++) {
      sum_right += nums[i];
    }
    int sum_left =0; 
    for (int i = 0; i < nums.size(); i++) {
      if (sum_left == sum_right) {
        return i;
      }
      sum_left += nums[i];
      sum_right -= nums[i + 1];
    }
    return -1;
  }
};

int main() {
  vector<int> nums = {1, 7, 3, 6, 5, 6};
  Solution s;
  int result = s.pivotIndex(nums);
  cout << result << endl;
  return 0;
}
