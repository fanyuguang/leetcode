#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> findDisappearedNumbers(vector<int>& nums) {
  }
};

int main() {
  vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
  Solution s;
  vector<int> result = s.findDisappearedNumbers(nums);
  for (int num : result) {
    cout << num << endl;
  }
  return 0;
}
