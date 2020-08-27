#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int findLHS(vector<int>& nums)
  {
    unordered_map<int, int> nums_stats;
    for (int num : nums)
    {
      if (nums_stats.find(num) != nums_stats.end())
      {
        nums_stats[num]++;
      }
      else
      {
        nums_stats[num] = 1;
      }
    }
    int longest_subsequence = 0;
    for (auto iter = nums_stats.begin(); iter != nums_stats.end(); iter++)
    {
      if (nums_stats.find(iter->first + 1) != nums_stats.end() && iter->second + nums_stats[iter->first + 1] > longest_subsequence)
      {
        longest_subsequence = iter->second + nums_stats[iter->first + 1];
      }
    }
    return longest_subsequence;
  }
};

int main()
{
  vector<int> nums = {1, 3, 2, 2, 5, 2, 3, 7};
  Solution s;
  int result = s.findLHS(nums);
  cout << result << endl;
  return 0;
}
