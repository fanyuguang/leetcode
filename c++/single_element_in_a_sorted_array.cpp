#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int singleNonDuplicate(vector<int>& nums) {
    int single_num = 0;
    for (int num : nums) {
      single_num = single_num ^ num;
    }
    return single_num;
  }
};

int main() {
  vector<int> nums{1, 1, 2, 3, 3, 4, 4, 8, 8};
  Solution s;
  int result = s.singleNonDuplicate(nums);
  cout << result << endl;
  return 0;
}
