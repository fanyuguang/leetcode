#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = nums1.size() - 1;
    m--;
    n--;
    while (n >= 0)
    {
      if (m >= 0 && nums1[m] > nums2[n])
      {
        nums1[i] = nums1[m];
        m--;
      }
      else
      {
        nums1[i] = nums2[n];
        n--;
      }
      i--;
    }
  }
};

int main()
{
  Solution s;
  vector<int> nums1 = {1, 2, 3, 0, 0, 0};
  vector<int> nums2 = {2, 5, 6};
  s.merge(nums1, 3, nums2, 3);
  for (int num : nums1)
  {
    cout << num << " ";
  }
  cout << endl;
  return 0;
}
