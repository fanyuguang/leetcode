#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
      int index = abs(nums[i]) - 1;
      if (nums[index] > 0) {
        nums[index] = -nums[index];
      }
    }
    vector<int> disappeared_numbers;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] > 0) {
        disappeared_numbers.push_back(i + 1);
      }
    }
    return disappeared_numbers;
  }
};

int main() {
  vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
  Solution s;
  vector<int> result = s.findDisappearedNumbers(nums);
  for (int num : nums) {
    cout << num << endl;
  }
  return 0;
}
