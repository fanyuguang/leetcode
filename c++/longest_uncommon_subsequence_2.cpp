#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
  int findLUSlength(vector<string>& strs) {
    int max_uncomment = -1;
    int strs_size = strs.size();
    for (int i = 0; i < strs_size; i++) {
      bool flag = true;
      for (int j = 0; j < strs_size; j++) {
        if (j == i) {
          continue;
        }
        if (is_subsequence(strs[i], strs[j])) {
          flag = false;
          break;
        }
      }
      if (flag) {
        max_uncomment = max_uncomment > (int)strs[i].size() ? max_uncomment : (int)strs[i].size();
      }
    }
    return max_uncomment;
  }

private:
  bool is_subsequence(string& str1, string& str2) {
    int i = 0;
    int j = 0;
    while (i < str1.size() && j < str2.size()) {
      if (str1[i] == str2[j]) {
        i++;
        j++;
      } else {
        j++;
      }
    }
    if (i < str1.size()) {
      return false;
    } else {
      return true;
    }
  }
};

int main() {
  vector<string> strs{"aba", "cdc", "eae"};
  Solution s;
  int result = s.findLUSlength(strs);
  cout << result << endl;
  return 0;
}
