#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  void wiggleSort(vector<int>& nums)
  {
    int nums_size = nums.size();
    std::nth_element(nums.begin(), nums.begin() + nums_size / 2, nums.end());
    int mid_num = nums[nums_size / 2];
    // int mid_num = nth_element(nums, 0, nums_size - 1, nums_size / 2 + 1);
    int i = 0;
    int j = 0;
    int k = nums_size - 1;
    while (j <= k)
    {
      int j_map = travel_by_odd_even(j, nums_size);
      if (nums[j_map] > mid_num)
      {
        int i_map = travel_by_odd_even(i, nums_size);
        swap(nums[j_map], nums[i_map]);
        i++;
        j++;
      }
      else if (nums[j_map] < mid_num)
      {
        int k_map = travel_by_odd_even(k, nums_size);
        swap(nums[j_map], nums[k_map]);
        k--;
      }
      else
      {
        j++;
      }
    }
  }

private:
  int nth_element(vector<int>& nums, int first, int last, int nth)
  {
    int p = partition(nums, first, last);
    if (p == nth - 1)
    {
      return nums[p];
    }
    else if (p < nth)
    {
      return nth_element(nums, p + 1, last, nth);
    }
    else
    {
      return nth_element(nums, first, p - 1, nth);
    }
  }

  int partition(vector<int>& nums, int first, int last)
  {
    int i = first - 1;
    for (int j = first; j <= last; j++)
    {
      if (nums[j] <= nums[last])
      {
        int temp = nums[++i];
        nums[i] = nums[j];
        nums[j] = temp;
      }
    }
    return i;
  }

  int travel_by_odd_even(int i, int nums_size)
  {
    // nums_size = 5
    // i:      0 1 2 3 4
    //         1 3 5 7 9
    // return: 1 3 0 2 4 
    return (2 * i + 1) % (nums_size | 1);
  }
};

int main()
{
  // vector<int> nums = {5, 1, 1, 6, 4, 1};
  vector<int> nums = {1, 1, 2, 1, 2, 2, 1};
  Solution s;
  s.wiggleSort(nums);
  for (int num : nums)
  {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}
