#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  string licenseKeyFormatting(string S, int K) {
    string formatting_str = "";
    int count = 0;
    for (int i = S.size() - 1; i >= 0; i--) {
      if (S[i] != '-') {
        char c = S[i];
        if (c >= 'a' && c <= 'z') {
          c = c - 'a' + 'A';
        }
        formatting_str = c + formatting_str;
        count++;
        if (count == K) {
          formatting_str = "-" + formatting_str;
          count = 0;
        }
      }
    }
    if (formatting_str[0] == '-') {
      formatting_str = formatting_str.substr(1, formatting_str.size() - 1);
    }
    return formatting_str;
  }
};

int main() {
  string str = "2-5g-3-J";
  Solution s;
  string result = s.licenseKeyFormatting(str, 2);
  cout << result << endl;
  return 0;
}
