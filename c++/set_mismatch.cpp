#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<int> findErrorNums(vector<int>& nums)
  {
    long sum = 0;
    long original_sum = nums.size() * (nums.size() + 1) / 2;
    for (int i = 0; i < nums.size(); i++)
    {
      sum += nums[i];
    }
    int twice_num;
    for (int i = 0; i < nums.size();)
    {
      if (i != nums[i] - 1)
      {
        if (nums[nums[i] - 1] == nums[i])
        {
          twice_num = nums[i];
          break;
        }

        int temp = nums[i] - 1;
        nums[i] = nums[temp];
        nums[temp] = temp + 1;
      }
      else
      {
        i++;
      }
    }
    int miss_num = twice_num - sum + original_sum;
    return {twice_num, miss_num};
  }
};

int main()
{
  // vector<int> nums = {1, 2, 2, 4};
  // vector<int> nums = {1, 3, 3};
  // vector<int> nums = {3, 2, 3, 4, 6, 5};
  // vector<int> nums = {2, 2};
  // vector<int> nums = {2, 3, 2};
  vector<int> nums = {3, 2, 2};
  Solution s;
  vector<int> result = s.findErrorNums(nums);
  cout << "twice_num: " << result[0] << endl;
  cout << "miss_num: " << result[1] << endl;
  return 0;
}
