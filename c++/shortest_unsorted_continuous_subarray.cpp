#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int findUnsortedSubarray(vector<int>& nums)
  {
    int left = 0;
    while (left < nums.size())
    {
      int i = left;
      while (++i < nums.size())
      {
        if (nums[left] > nums[i])
        {
          break;
        }
      }
      if (i != nums.size())
      {
        break;
      }
      left++;
    }
    
    int right = nums.size() - 1;
    while (right >= 0)
    {
      int i = right;
      while (--i >= 0)
      {
        if (nums[right] < nums[i])
        {
          break;
        }
      }
      if (i >= 0)
      {
        break;
      }
      right--;
    }

    return (right - left) > 0 ? (right - left + 1) : 0;
  }
};

int main()
{
  vector<int> nums = {2, 6, 4, 8, 10, 9, 15};
  Solution s;
  int result = s.findUnsortedSubarray(nums);
  cout << result << endl;
  return 0;
}
