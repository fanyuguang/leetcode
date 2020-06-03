#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  bool containsNearbyDuplicate(vector<int>& nums, int k)
  {
    unordered_map<int, int> num_map;
    for (int i = 0; i < nums.size(); i++)
    {
      if (num_map.find(nums[i]) != num_map.end() && (i - num_map[nums[i]] <= k))
      {
        return true;
      }
      else
      {
        num_map[nums[i]] = i;
      }
    }
    return false;
  }
};

int main()
{
  vector<int> nums = {1, 0, 1, 1};
  // vector<int> nums = {1, 2, 3, 1, 2, 3};
  Solution s;
  bool result = s.containsNearbyDuplicate(nums, 1);
  if (result)
  {
    cout << "true" << endl;
  }
  else
  {
    cout << "false" << endl;
  }
  return 0;
}
