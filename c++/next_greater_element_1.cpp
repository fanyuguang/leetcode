#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
    vector<int> next_greater_nums;
    for (int find_num : findNums) {
      int greater_num = -1;
      bool flag = false;
      for (int num : nums) {
        if (flag && num > find_num) {
          greater_num = num;
          break;
        }
        if (find_num == num) {
          flag = true;
        }
      }
      next_greater_nums.push_back(greater_num);
    }
    return next_greater_nums;
  }
};

int main() {
  vector<int> findNums{4, 1, 2};
  vector<int> nums{1, 3, 4, 2};
  Solution s;
  vector<int> result = s.nextGreaterElement(findNums, nums);
  for (int num : result) {
    cout << num << endl;
  }
  return 0;
}
