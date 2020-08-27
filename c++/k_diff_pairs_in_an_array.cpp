#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int findPairs(vector<int>& nums, int k)
  {
    if (k < 0)
    {
      return 0;;
    }

    unordered_map<int, int> unique_nums;
    int large_than_one_count = 0;
    for (auto num : nums)
    {
      if (unique_nums.find(num) != unique_nums.end())
      {
        if (unique_nums[num] == 1)
        {
          unique_nums[num]++;
          large_than_one_count++;
        }
      }
      else
      {
        unique_nums[num] = 1;
      }
    }

    if (k == 0)
    {
      return large_than_one_count;
    }

    int paires = 0;
    for (unordered_map<int, int>::iterator iter = unique_nums.begin(); iter != unique_nums.end(); iter++)
    {
      if (unique_nums.find(iter->first + k) != unique_nums.end())
      {
        paires++;
      }
    }
    return paires;
  }
};

int main()
{
  // vector<int> nums = {3, 1, 4, 1, 5};
  vector<int> nums = {1, 3, 1, 5, 4};
  Solution s;
  int result = s.findPairs(nums, 0);
  cout << result << endl;
  return 0;
}
