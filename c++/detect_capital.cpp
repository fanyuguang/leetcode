#include <iostream>
#include <string>

class Solution {
public:
  bool detectCapitalUse(string word) {
    if (word.size() == 1) {
      return true;
    }
    bool is_lower = true;
    if (word[0] >= 'A' && word[0] <= 'Z') {
      is_lower = false;
    }
    for (char c : word) {
      if (is_lower && (c >= 'A' && c <= 'Z'))a {
        return false;
      } else if ()
    }
  }
};

int main() {
  string word = "USA";
  Solution s;
  bool result = s.detectCapitalUse(word);
  if (result) {
    cout << "true" << endl;
  } else {
    cout << "false" << endl;
  }
  return 0;
}
