#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<int> productExceptSelf(vector<int>& nums)
  {
    pre_next_product(nums, 1, 0, nums.size());
    return nums;
  }

  int pre_next_product(vector<int>& nums, int pre_product, int index, int size)
  {
    int next_product = 1;
    if (index < size)
    {
      next_product = pre_next_product(nums, pre_product * nums[index], index + 1, size);
      int temp = nums[index];
      nums[index] = pre_product * next_product;
      next_product *= temp;
    }
    return next_product;
  }
};

int main()
{
  vector<int> nums;
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(3);
  nums.push_back(4);
  Solution S;
  vector<int> output;
  output = S.productExceptSelf(nums);
  for (auto iter : output)
  {
    cout << iter << endl;
  }
  return 0;
}
