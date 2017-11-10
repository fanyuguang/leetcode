#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  char findTheDifference(string s, string t) {
    vector<int> position(s.size(), 0);
    for (char c : t) {
      bool is_finded = false;
      for (int i = 0; i < s.size(); i++) {
        if (c == s[i] && position[i] == 0) {
          position[i] = 1;
          is_finded = true;
          break;
        }
      }
      if (!is_finded) {
        return c;
      }
    }
  }
};

int main() {
  string s = "abcd";
  string t = "abcde";
  Solution solution;
  char result = solution.findTheDifference(s, t);
  cout << result << endl;
  return 0;
}
