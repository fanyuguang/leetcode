#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  int countSubstrings(string s) {
    if (s == "") {
      return 0;
    }
    int s_length = s.size();
    bool dp[s_length][s_length];
    for (int i = 0; i < s_length; i++) {
      dp[i][i] = true;
    }
    int count = s_length;
    for (int i = s_length - 2; i >= 0; i--) {
      for (int j = i + 1; j < s_length; j++) {
        if (s[i] == s[j] && ((i + 1 >= j - 1) || ((i + 1 < j - 1) && dp[i+1][j-1]))) {
          cout << i << " " << j << endl;
          dp[i][j] = true;
          count++;
        } else {
          dp[i][j] = false;
        }
      }
    }
    return count;
  }
};

int main() {
  // string str = "aaa";
  string str = "fdsklf";
  Solution s;
  int result = s.countSubstrings(str);
  cout << result << endl;
  return 0;
}
