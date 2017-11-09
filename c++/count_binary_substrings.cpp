#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int countBinarySubstrings(string s) {
    int binary_substrings = 0;
    int pre_length = 0;
    int start_index = 0;
    char c = s[0];
    for (int index = 0; index < s.size(); index++) {
      if (s[index] != c) {
        if (pre_length == 0) {
          pre_length = index;
          start_index = index;
          c = s[index];
          continue;
        }
        int current_length = index - start_index;
        binary_substrings += pre_length < current_length ? pre_length : current_length;
        pre_length = current_length;
        start_index = index;
        c = s[index];
      }
    }
    if (start_index < s.size()) {
      int current_length = s.size() - start_index;
      binary_substrings += pre_length < current_length ? pre_length : current_length;
    }
    return binary_substrings;
  }
};

int main() {
  // string str = "00110011";
  string str = "10101";
  Solution s;
  int result = s.countBinarySubstrings(str);
  cout << result << endl;
  return 0;
}
