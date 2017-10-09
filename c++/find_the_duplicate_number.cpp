#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int findDuplicate(vector<int>& nums) {
    int low = 1;
    int high = nums.size() - 1;
    while (high > low) {
      int mid = (low + high) / 2;
      int count = 0;
      for (auto iter : nums) {
        if (iter <= mid) {
          count++;
        }
      }
      if (count <= mid) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }
    return low;
  }
};

int main() {
  vector<int> nums = {1, 1, 2};
  Solution S;
  int num = S.findDuplicate(nums);
  cout << num << endl;
  return 0;
}
