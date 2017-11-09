#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int minMoves2(vector<int>& nums) {
    QuickSort(nums, 0, nums.size() - 1);
    int base_moves = 0;
    int base_num = nums[0];
    vector<int> cumulative_moves;
    for (int num : nums) {
      base_moves += num - base_num;
      cumulative_moves.push_back(base_moves);
      cout << base_moves << endl;
    }
    int min_moves = base_moves;
    int index = 0;
    while (++base_num <= nums[nums.size() - 1]) {
      while (base_num > nums[index]) {
        index++;
      }
      int moves = base_moves + index * (base_num - nums[0]) - 2 * cumulative_moves[index - 1] - 
                  (nums.size() - index) * (base_num - nums[0]);
      if (moves < min_moves) {
        min_moves = moves;
      }
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
  // vector<int> nums = {1, 2, 3};
  vector<int> nums = {203125577,-349566234,230332704,48321315,66379082,386516853,50986744,-250908656,-425653504,-212123143};
  Solution s;
  int result = s.minMoves2(nums);
  cout << result << endl;
  return 0;
}
