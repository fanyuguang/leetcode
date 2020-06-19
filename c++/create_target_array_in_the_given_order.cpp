#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<int> createTargetArray(vector<int>& nums, vector<int>& index)
  {
    // vector<int> target(index.size(), 0);
    vector<int> target;
    for (int i = 0; i < nums.size(); i++)
    {
      target.insert(target.begin() + index[i], nums[i]);
    }
    return target;
  }
};

int main()
{
  vector<int> nums = {0, 1, 2, 3, 4};
  vector<int> index = {0, 1, 2, 2, 1};
  Solution s;
  vector<int> result = s.createTargetArray(nums, index);
  for (int num : result)
  {
    cout << num << " ";
  }
  cout << endl;
  return 0;
}
