#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int minMoves(vector<int>& nums) {
    int min_num = nums[0];
    for (int num : nums) {
      if (num < min_num) {
        min_num = num;
      }
    }
    int min_moves = 0;
    for (int num : nums) {
      min_moves += num - min_num;
    }
    return min_moves;
  }
};

int main() {
  vector<int> nums = {1, 2, 3};
  Solution s;
  int result = s.minMoves(nums);
  cout << result << endl;
  return 0;
}
