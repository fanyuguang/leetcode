#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> two_index;
    unordered_map<int, int> num_store;
    for (int i = 0; i < nums.size(); i++) {
      if (num_store.find(target - nums[i]) != num_store.end()) {
        two_index.push_back(i);
        two_index.push_back(num_store[target - nums[i]]);
      } else {
        num_store[nums[i]] = i;
      }
    }
    return two_index;
  }
};

int main() {
  vector<int> nums = {2, 7, 11, 15};
  Solution s;
  vector<int> result = s.twoSum(nums, 9);
  for (int num : result) {
    cout << num << endl;
  }
  return 0;
}
