#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> permute(vector<int>& nums) {
    if (nums.empty())
    {
      return vector<vector<int>>();
    }

    int nums_count = nums.size();
    int full_permutation_count = 1;
    for (int i = 1; i <= nums_count; i++)
    {
      full_permutation_count *= i;
    }
    vector<vector<int>> full_permutation_nums(full_permutation_count, vector<int>(nums_count, INT_MIN));

    int duplicated_item_count = full_permutation_count;
    for (int i = 0; i < nums_count; i++)
    {
      duplicated_item_count /= (nums_count - i);
      int empty_index = -1;
      for (int j = 0; j < full_permutation_count;)
      {
        do {
          empty_index++;
          if (empty_index >= nums_count)
          {
            empty_index = 0;
          }
        } while (full_permutation_nums[j][empty_index] != INT_MIN);

        for (int k = 0; k < duplicated_item_count; k++)
        {
          full_permutation_nums[j++][empty_index] = nums[i];
        }
      }
    }
    return full_permutation_nums;
  }
};

int main()
{
  Solution s;
  vector<int> nums = {1, 2, 3};
  vector<vector<int>> full_permutation_nums = s.permute(nums);
  for (vector<int> items : full_permutation_nums)
  {
    for (int item : items)
    {
      cout << item << " ";
    }
    cout << endl;
  }
  return 0;
}

