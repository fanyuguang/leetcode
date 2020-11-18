#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  double findMaxAverage(vector<int>& nums, int k)
  {
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
      sum += nums[i];
    }
    int max_sum = sum;
    for (int i = k; i < nums.size(); i++)
    {
      sum -= nums[i - k];
      sum += nums[i];
      if (sum > max_sum)
      {
        max_sum = sum;
      }
    }
    return (double)max_sum / k;
  }
};

int main()
{
  vector<int> nums = {1, 12, -5, -6, 50, 3};
  Solution s;
  double result = s.findMaxAverage(nums, 4);
  cout << result << endl;
  return 0;
}
