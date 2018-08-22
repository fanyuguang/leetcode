#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  int longestPalindrome(string s) {
    unordered_map<char, int> char_count;
    for (char c : s) {
      if (char_count.find(c) == char_count.end()) {
        char_count[c] = 1;
      } else {
        char_count[c]++;
      }
    }
    bool odd_exist = false;
    int half_length = 0;
    for (pair<char, int> iter : char_count) {
      half_length += iter.second / 2;
      if (!odd_exist && iter.second % 2 == 1) {
        odd_exist = true;
      }
    }
    int longest_palindrome = half_length * 2;
    if (odd_exist) {
      longest_palindrome++;
    }
    return longest_palindrome;
  }
};

int main() {
  string str = "abccccdd";
  Solution s;
  int result = s.longestPalindrome(str);
  cout << result << endl;
  return 0;
}
