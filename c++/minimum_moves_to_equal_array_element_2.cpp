#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
  int minMoves2(vector<int>& nums) {
    QuickSort(nums, 0, nums.size() - 1);
    int mid_index = nums.size() / 2;
    int min_moves = 0;
    for (int num : nums) {
      min_moves += abs(num - nums[mid_index]);
    }
    return min_moves;
  }

private:
  int Partition(vector<int>& nums, int p, int r) {
    int mid_num = nums[r];
    int i = p - 1;
    for(int j = p; j < r; j++) {
      if (nums[j] < mid_num) {
        int temp = nums[++i];
        nums[i] = nums[j];
        nums[j] = temp;
      }
    }
    int temp = nums[++i];
    nums[i] = nums[r];
    nums[r] = temp;
    return i;
  }

  void QuickSort(vector<int>& nums, int p, int r) {
    if (p < r) {
      int q = Partition(nums, p, r);
      QuickSort(nums, p, q - 1);
      QuickSort(nums, q + 1, r);
    }
  }
};

int main() {
  vector<int> nums = {1, 2, 3};
  Solution s;
  int result = s.minMoves2(nums);
  cout << result << endl;
  return 0;
}
