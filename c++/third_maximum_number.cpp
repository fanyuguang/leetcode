#include <climits>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution
{
public:
  int thirdMax(vector<int>& nums)
  {
    set<int> max;
    for (int num : nums)
    {
      max.insert(num);
      if (max.size() > 3)
      {
        max.erase(max.begin());
      }
    }
    return max.size() < 3 ? *max.rbegin() : *max.begin();
  }

  int thirdMax2(vector<int>& nums)
  {
    long max1 = LONG_MIN;
    long max2 = LONG_MIN;
    long max3 = LONG_MIN;
    for (int num : nums) 
    {
      if (num > max1)
      {
        max3 = max2;
        max2 = max1;
        max1 = num;
      }
      else if (num > max2 && num < max1)
      {
        max3 = max2;
        max2 = num;
      }
      else if (num > max3 && num < max2)
      {
        max3 = num;
      }
    }
    return max3 == LONG_MIN ? max1 : max3;
  }
};

int main()
{
  // vector<int> nums = {2, 2, 3, 1};
  vector<int> nums = {5, 2, 2};
  Solution s;
  int result = s.thirdMax(nums);
  cout << result << endl;
  return 0;
}
