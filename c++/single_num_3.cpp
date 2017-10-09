#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<int> singleNumber(vector<int>& nums)
  {
    vector<int> single_nums;
    int xor_num = 0;
    for (auto iter : nums)
    {
      xor_num  ^= iter;
    }
    int first_one_index;
    for (first_one_index = 0; first_one_index < 32; first_one_index++)
    {
      if (((xor_num >> first_one_index) & 1) == 1)
      {
        break;
      }
    }
    if (first_one_index == 32)
    {
      return single_nums;
    }
    int num1 = 0;
    int num2 = 0;
    for (auto iter : nums)
    {
      if (((iter >> first_one_index) & 1) == 1)
      {
        num1 ^= iter;
      }
    }
    num2 = num1 ^ xor_num;
    single_nums.push_back(num1);
    single_nums.push_back(num2);
    return single_nums;
  }
};

int main()
{
  vector<int> nums;
  nums.push_back(1);
  nums.push_back(0);
  Solution S;
  vector<int> single_nums;
  single_nums = S.singleNumber(nums);
  for (auto iter : single_nums)
  {
    cout << iter << endl;
  }
  return 0;
}
