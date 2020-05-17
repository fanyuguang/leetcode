#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void rotate(vector<int>& nums, int k) {
    int nums_size = nums.size();
    k = k % nums_size;
    if (nums_size == 1 || k == 0)
    {
      return;
    }

    int greatest_common_divisor = get_greatest_common_divisor(nums_size, k);
    for (int i = 0; i < greatest_common_divisor; i++)
    {
      int j = i;
      int temp = nums[i];
      int end_index = (j + k) % nums_size;
      do
      {
        int per_index = (j - k + nums_size) % nums_size;
        nums[j] = nums[per_index];
        j = per_index;
      } while (j != end_index);
      nums[end_index] = temp;
    }
  }

private:
  int get_greatest_common_divisor(int a, int b)
  {
    while (a % b)
    {
      int c = a % b;
      a = b;
      b = c;
    }
    return b;
  }
};

int main()
{
  vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
  // vector<int> nums = {-1, -100, 3, 99};
  Solution s;
  s.rotate(nums, 3);
  for (int num : nums)
  {
    cout << num << " ";
  }
  cout << endl;
  return 0;
}
