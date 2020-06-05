#include <iostream>
#include <vector>

using namespace std;

class NumArray
{
public:
  NumArray(vector<int>& nums)
  {
    accumulated_nums.push_back(0);
    for (int i = 0; i < nums.size(); i++)
    {
      accumulated_nums.push_back(accumulated_nums[accumulated_nums.size() - 1] + nums[i]);
    }
  }

  int sumRange(int i, int j)
  {
    return accumulated_nums[j + 1] - accumulated_nums[i];
  }

private:
  vector<int> accumulated_nums;
};

int main()
{
  vector<int> nums = {-2, 0, 3, -5, 2, -1};
  NumArray* obj = new NumArray(nums);
  int result = obj->sumRange(2, 5);
  cout << result << endl;
  return 0;
}
