#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int arrayPairSum(vector<int>& nums) {
    quick_sort(nums, 0, nums.size() - 1);
    int sum_min = 0;
    for (int i = 0; i < nums.size(); i += 2) {
      sum_min += nums[i];
    }
    return sum_min;
  }
  
private:
  int partition(vector<int>& nums, int p, int r) {
    int i = p - 1;
    for (int j = p; j < r; j++) {
      if (nums[j] <= nums[r]) {
        i++;
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
      }
    }
    int temp = nums[r];
    nums[r] = nums[++i];
    nums[i] = temp;
    return i;
  }

  void quick_sort(vector<int>& nums, int p, int r) {
    if (p < r) {
      int q = partition(nums, p, r);
      quick_sort(nums, p, q - 1);
      quick_sort(nums, q + 1, r);
    }
  }
};

int main() {
  vector<int> nums{1, 4, 3, 2};
  Solution s;
  int result = s.arrayPairSum(nums);
  cout << result << endl;
  return 0;
}
