#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
  string optimalDivision(vector<int>& nums) {
    if (nums.size() == 1) {
      return to_string(nums[0]);
    }
    if (nums.size() == 2) {
      return to_string(nums[0]) + "/" + to_string(nums[1]);
    }
    string division = to_string(nums[0]) + "/(";
    for (int i = 1; i < nums.size(); i++) {
      division += to_string(nums[i]) + "/";
    }
    return division.substr(0, division.size()-1) + ")";
  }
};

int main() {
  vector<int> nums{1000, 100, 10, 2};
  Solution s;
  string result = s.optimalDivision(nums);
  cout << result << endl;
  return 0;
}
