#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int checkRecord(int n) {
    int mod = 1000000007;
    vector<int> record(6, 1);
    for (int i = 0; i < n; i++) {
      int num0 = record[0];
      int num1 = record[1];
      int num2 = record[2];
      int num3 = record[3];
      int num4 = record[4];
      int num5 = record[5];
      record[0] = num2;
      record[1] = (num0 + num2) % mod;
      record[2] = (num1 + num2) % mod;
      record[3] = (num2 + num5) % mod;
      record[4] = ((num2 + num3) % mod + num5) % mod;
      record[5] = ((num2 + num4) % mod + num5) % mod;
    }
    return record[5];
  }

  int checkRecord2(int n) {
    int mod = 1000000007;
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 1)));
    for (int i = 1; i < n + 1; i++) {
      for (int a = 0; a < 2; a++) {
        for (int l = 0; l < 3; l++) {
          int num_of_records = dp[i - 1][a][2];
          if (a > 0) {
            num_of_records = (num_of_records + dp[i - 1][a - 1][2]) % mod;
          }
          if (l > 0) {
            num_of_records = (num_of_records + dp[i - 1][a][l - 1]) % mod;
          }
          dp[i][a][l] = num_of_records;
        }
      }
    }
    return dp[n][1][2];
  }
};

int main() {
  Solution s;
  int result = s.checkRecord(21230);
  cout << result << endl;
  return 0;
}
