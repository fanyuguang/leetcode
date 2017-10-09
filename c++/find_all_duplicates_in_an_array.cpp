#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
  vector<int> findDuplicates(vector<int>& nums) {
    vector<int> duplicates_num;
    unordered_set<int> nums_hash;
    for (int num : nums) {
      if (nums_hash.count(num) == 0) {
        nums_hash.insert(num);
      } else {
        duplicates_num.push_back(num);
      }
    }
    return duplicates_num;
  }
};

int main() {
  vector<int> nums{4, 3, 2, 7, 8, 2, 3, 1};
  Solution s;
  vector<int> result = s.findDuplicates(nums);
  for (int num : result) {
    cout << num << endl;
  }
  return 0;
}
