#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  bool PredictTheWinner(vector<int>& nums) {
    int length = nums.size();
    if (length == 1 || length % 2 == 0) {
      return true;
    }
    vector<vector<int> > dp(length, vector<int>(length, 0));
    for (int i = 0; i < length; i++) {
      dp[i][i] = nums[i];
    }
    for (int i = length - 2; i >= 0; i--) {
      for (int j = i + 1; j < length; j++) {
        dp[i][j] = max(nums[i] - dp[i+1][j], nums[j] - dp[i][j-1]);
        cout << "a[" << i << "~" << j << "] = " << dp[i][j] << endl;
      }
    }
    return dp[0][length-1] >= 0;
  }
};

int main() {
  // vector<int> nums{1, 5, 233, 7, 2};
  vector<int> nums{1, 5, 2, 10, 6};
  Solution s;
  if (s.PredictTheWinner(nums)) {
    cout << "true" << endl;
  } else {
    cout << "false" << endl;
  }
  return 0;
}
