#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

class Solution {
public:
  int maximumProduct(vector<int>& nums) {
    vector<int> max_nums(3, INT_MIN);
    vector<int> min_nums(2, 0);
    for (int i = 0; i < nums.size(); i++) {
      int j = 2;
      while (j >= 0 && nums[i] > max_nums[j]) {
        j--;
      }
      if (++j < 3) {
        for (int k = 2; k > j; k--) {
          max_nums[k] = max_nums[k - 1];
        }
        max_nums[j] = nums[i];
      }
      if (nums[i] < min_nums[0]) {
        min_nums[1] = min_nums[0];
        min_nums[0] = nums[i];
      } else if (nums[i] < min_nums[1]) {
        min_nums[1] = nums[i];
      }
    }
    int product = max_nums[0] * max_nums[1] * max_nums[2];
    if (min_nums[1] < 0 && product < max_nums[0] * min_nums[0] * min_nums[1]) {
      product = max_nums[0] * min_nums[0] * min_nums[1];
    }
    return product;
  }
};

int main() {
  vector<int> nums = {1, 2, 3, 4};
  Solution s;
  int result = s.maximumProduct(nums);
  cout << result << endl;
  return 0;
}
