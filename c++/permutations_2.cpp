#include <algorithm>
#include <iostream>
#include <limits.h>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    if (nums.empty())
    {
      return vector<vector<int>>();
    }

    int nums_size = nums.size();
    int permutation_unique_count = 1;
    map<int, int> nums_stats;
    for (int i = 0; i < nums_size; i++)
    {
      if (nums_stats.find(nums[i]) == nums_stats.end())
      {
        nums_stats[nums[i]] = 1;
      }
      else
      {
        nums_stats[nums[i]]++;
      }

      permutation_unique_count *= i + 1;
      permutation_unique_count /= nums_stats[nums[i]];
    }

    vector<vector<int>> permutation_unique_nums(permutation_unique_count, vector<int>(nums_size, INT_MIN));
    vector<int> last_indexes(permutation_unique_count, -1);

    int duplicated_count = permutation_unique_count;
    int remain_nums_size = nums_size;
    for (pair<int, int> item : nums_stats)
    {
      int current_num = item.first;
      int current_nums_stats = item.second;
      for (int i = current_nums_stats; i >= 1; i--)
      {
        duplicated_count *= i;
        duplicated_count /= remain_nums_size - i + 1;
      }
      remain_nums_size -= current_nums_stats;

      for (int i = 0; i < current_nums_stats; i++)
      {
        int empty_index = -1;
        int j = 0;
        while (j < permutation_unique_count)
        {
          do {
            empty_index++;
            if (empty_index >= nums_size)
            {
              empty_index = 0;
            }
          } while (permutation_unique_nums[j][empty_index] != INT_MIN || empty_index <= last_indexes[j]);

          int after_empty_index_count = 0;
          for (int k = empty_index + 1; k < nums_size; k++)
          {
            if (permutation_unique_nums[j][k] == INT_MIN)
            {
              after_empty_index_count++;
            }
          }
          int current_duplicated_count = duplicated_count;
          for (int k = 1; k <= current_nums_stats - i - 1; k++)
          {
            current_duplicated_count *= after_empty_index_count - k + 1;
            current_duplicated_count /= k;
          }

          for (int k = 0; k < current_duplicated_count; k++)
          {
            permutation_unique_nums[j][empty_index] = current_num;
            last_indexes[j] = empty_index;
            j++;
          }
        }
      }
      fill(last_indexes.begin(), last_indexes.end(), -1);
    }
    return permutation_unique_nums;
  }
};

int main()
{
  Solution s;
  vector<int> nums = {1, 1, 2};
  vector<vector<int>> full_permutation_nums = s.permuteUnique(nums);
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

