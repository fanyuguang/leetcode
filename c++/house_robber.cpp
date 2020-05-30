#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int rob(vector<int>& nums)
  {
    int nums_size = nums.size();
    if (nums_size == 0)
    {
      return 0;
    }
    if (nums_size > 1)
    {
      nums[1] = nums[1] > nums[0] ? nums[1] : nums[0];
    }

    for (int i = 2; i < nums_size; i++)
    {
      nums[i] = nums[i] + nums[i - 2] > nums[i - 1] ? nums[i] + nums[i - 2] : nums[i - 1];
    }

    return nums[nums_size - 1];
  }
};

int main()
{
  Solution s;
  // vector<int> nums = {1, 2, 3, 1};
  vector<int> nums = {226,174,214,16,218,48,153,131,128,17,157,142,88,43,37,157,43,221,191,68,206,23,225,82,54,118,111,46,80,49,245,63,25,194,72,80,143,55,209,18,55,122,65,66,177,101,63,201,172,130,103,225,142,46,86,185,62,138,212,192,125,77,223,188,99,228,90,25,193,211,84,239,119,234,85,83,123,120,131,203,219,10,82,35,120,180,249,106,37,169,225,54,103,55,166,124};
  int result = s.rob(nums);
  cout << result << endl;
  return 0;
}
