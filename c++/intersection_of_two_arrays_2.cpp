#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> num_store;
    for (int num : nums1) {
      if (num_store.find(num) == num_store.end()) {
        num_store[num] = 1;
      } else {
        num_store[num]++;
      }
    }
    vector<int> intersection_nums;
    for (int num : nums2) {
      if (num_store.find(num) != num_store.end() && num_store[num] != 0) {
        intersection_nums.push_back(num);
        num_store[num]--;
      }
    }
    return intersection_nums;
  }
};

int main() {
  vector<int> nums1 = {1, 2, 2, 1};
  vector<int> nums2 = {2, 2};
  Solution s;
  vector<int> result = s.intersect(nums1, nums2);
  for (int num : result) {
    cout << num << endl;
  }
  return 0;
}
