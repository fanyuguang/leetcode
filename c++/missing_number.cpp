#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int missingNumber(vector<int>& nums)
  {
    int min = nums[0];
    int max = nums[0];
    int sum = 0;
    for(auto iter : nums)
    {
      if (iter < min)
      {
        min = iter;
      }
      if (iter > max)
      {
        max = iter;
      }
      sum += iter;
    }
    if (min != 0)
    {
      return 0;
    }
    else if (max != nums.size())
    {
      return max + 1;
    }
    int progression_sum = (min + max) * (nums.size() + 1) / 2;
    return progression_sum - sum;
  }
};

int main()
{
  vector<int> nums;
  nums.push_back(0);
  nums.push_back(2);
  Solution S;
  int missing_number = S.missingNumber(nums);
  cout << missing_number << endl;
  return 0;
}
