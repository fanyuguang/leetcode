#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
  int findShortestSubArray(vector<int>& nums) {
    unordered_map<int, vector<int>> num_count;
    for (int i = 0; i < nums.size(); i++) {
      if (num_count.find(nums[i]) == num_count.end()) {
        num_count[nums[i]] = vector<int>({1, i, i});
      } else {
        num_count[nums[i]][0]++;
        num_count[nums[i]][2] = i;
      }
    }
    int max_frequency_num = 0;
    int shortest_subarray_length = nums.size();
    for (pair<int, vector<int>> iter : num_count) {
      if (iter.second[0] > max_frequency_num) {
        max_frequency_num = iter.second[0];
        shortest_subarray_length = iter.second[2] - iter.second[1] + 1;
      } else if (iter.second[0] == max_frequency_num && (iter.second[2] - iter.second[1] + 1) < shortest_subarray_length) {
        shortest_subarray_length = iter.second[2] - iter.second[1] + 1;
      }
    }
    return shortest_subarray_length;
  }
};

int main() {
  vector<int> nums = {1, 2, 2, 3, 1};
  Solution s;
  int result = s.findShortestSubArray(nums);
  cout << result << endl;
  return 0;
}
