#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
  vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    vector<int> nums_copy(nums);
    quick_sort(nums_copy, 0, nums_copy.size() - 1);
    map<int, int> nums_mapping;
    for (int i = 0; i < nums_copy.size(); i++)
    {
      if (nums_mapping.find(nums_copy[i]) == nums_mapping.end())
      {
        nums_mapping[nums_copy[i]] = i;
      }
    }
    vector<int> smaller_numbers;
    for (int num : nums)
    {
      smaller_numbers.push_back(nums_mapping[num]);
    }
    return smaller_numbers;
  }

private:
  int partition(vector<int>& nums, int p, int q)
  {
    int num = nums[q];
    int i = p - 1;
    for (int j = p; j < q; j++)
    {
      if (nums[j] < num)
      {
        i++;
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
      }
    }
    nums[q] = nums[++i];
    nums[i] = num;
    return i;
  }

  void quick_sort(vector<int>& nums, int p, int q)
  {
    if (p < q)
    {
      int r = partition(nums, p, q);
      quick_sort(nums, p, r - 1);
      quick_sort(nums, r + 1, q);
    }
  }
};

int main()
{
  Solution s;
  vector<int> nums = {8, 1, 2, 2, 3};
  vector<int> result = s.smallerNumbersThanCurrent(nums);
  for (int item : result)
  {
    cout << item << " ";
  }
  cout << endl;
  return 0;
}
