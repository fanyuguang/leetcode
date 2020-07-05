#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  void sortColors(vector<int>& nums)
  {
    int i = -1;
    int j = nums.size();
    int k = 0;
    while (k < j)
    {
      if (nums[k] == 2)
      {
        j--;
        int temp = nums[j];
        nums[j] = nums[k];
        nums[k] = temp;
        continue;
      }
      else if (nums[k] == 0)
      {
        i++;
        int temp = nums[i];
        nums[i] = nums[k];
        nums[k] = temp;
      }
      k++;
    }
  }
};

int main()
{
  // vector<int> nums = {2, 0, 2, 1, 1, 0};
  vector<int> nums = {1, 2, 0};
  Solution s;
  s.sortColors(nums);
  for (int num : nums)
  {
    cout << num << " ";
  }
  cout << endl;
  return 0;
}
