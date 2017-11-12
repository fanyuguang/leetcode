#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maxCount(int m, int n, vector<vector<int>>& ops) {
    int min_m = m;
    int min_n = n;
    for (vector<int> iter : ops) {
      if (iter[0] < min_m) {
        min_m = iter[0];
      }
      if (iter[1] < min_n) {
        min_n = iter[1];
      }
    }
    return min_m * min_n;
  }
};

int main() {
  vector<vector<int>> ops = {{2, 2}, {3, 3}};
  Solution s;
  int result = s.maxCount(3, 3, ops);
  cout << result << endl;
  return 0;
}
