#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  string reverseStr(string s, int k) {
    for (int i = 0; i < s.size(); i += 2 * k) {
      int start = i;
      int end = start + k - 1;
      if (end >= s.size()) {
        end = s.size() - 1;
      }
      while (start < end) {
        char c = s[start];
        s[start] = s[end];
        s[end] = c;
        start++;
        end--;
      }
    }
    return s;
  }
};

int main() {
  string str = "abcdefg";
  Solution s;
  string result = s.reverseStr(str, 2);
  cout << result << endl;
  return 0;
}
