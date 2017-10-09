#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  string reverseWords(string s) {
    string reverse_s = "";
    int start = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == ' ') {
        for (int j = i - 1; j >= start; j--) {
          reverse_s += s[j];
        }
        reverse_s += ' ';
        start = i + 1;
      }
    }
    for (int j = s.size() - 1; j >= start; j--) {
      reverse_s += s[j];
    }
    return reverse_s;
  }
};

int main() {
  string str = "Let's take LeetCode contest";
  Solution s;
  string reverse_str = s.reverseWords(str);
  cout << reverse_str << endl;
  return 0;
}
