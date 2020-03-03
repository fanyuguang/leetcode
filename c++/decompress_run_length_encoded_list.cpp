#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<int> decompressRLElist(vector<int>& nums)
  {
    vector<int> decompress_nums;
    for (int i = 0; i < nums.size(); i += 2)
    {
      for (int j = 0; j < nums[i]; j++)
      {
        decompress_nums.push_back(nums[i + 1]);
      }
    }
    return decompress_nums;
  }
};

int main()
{
  Solution s;
  vector<int> nums = {1, 2, 3, 4};
  vector<int> result = s.decompressRLElist(nums);
  cout << "[";
  for (vector<int>::iterator iter = result.begin(); iter != result.end(); iter++)
  {
    cout << *iter;
    if (iter + 1 != result.end())
    {
      cout << ", ";
    }
  }
  cout << "]" << endl;

  // vector<vector<int>> matrix(2, vector<int>(3, 0));
  // vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}};
  return 0;
}
