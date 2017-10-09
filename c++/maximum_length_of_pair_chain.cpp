#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  int findLongestChain(vector<vector<int> >& pairs) {
    int length = pairs.size();
    if (length == 0) {
      return 0;
    }
    sort(pairs.begin(), pairs.end(), compare_vector);
    vector<int> dp(length, 1);
    for (int i = 1; i < length; i++) {
      for (int j = 0; j < i; j++) {
        if (pairs[j][1] < pairs[i][0] && dp[i] < dp[j] + 1) {
          dp[i] = dp[j] + 1;
        }
      }
    }
    int longest_chaim = 1;
    for (int num : dp) {
      if (num > longest_chaim) {
        longest_chaim = num;
      }
    }
    return longest_chaim;
  }

private:
  static bool compare_vector(vector<int>& v1, vector<int>& v2) {
    return v1[0] < v2[0];
  }
};

int main() {
  vector<vector<int> > pairs;
  vector<int> sub_pair1 = {1, 2};
  vector<int> sub_pair2 = {2, 3};
  vector<int> sub_pair3 = {3, 4};
  pairs.push_back(sub_pair1);
  pairs.push_back(sub_pair2);
  pairs.push_back(sub_pair3);
  Solution s;
  int result = s.findLongestChain(pairs);
  cout << result << endl;
  return 0;
}
