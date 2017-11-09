#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  bool detectCapitalUse(string word) {
    if (word.size() == 1) {
      return true;
    }
    if (word[0] >= 'a' && word[0] <= 'z' && word[1] >= 'A' && word[1] <= 'Z') {
      return false;
    }
    char second_word = word[1];
    word = word.substr(2);
    if (second_word >= 'A' && second_word <= 'Z') {
      for (char c : word) {
        if (c >= 'a' && c <= 'z') {
          return false;
        }
      }
    }
    if (second_word >= 'a' && second_word <= 'z') {
      for (char c : word) {
        if (c >= 'A' && c <= 'Z') {
          return false;
        }
      }
    }
    return true;
  }
};

int main() {
  // string word = "USA";
  string word = "isA";
  Solution s;
  bool result = s.detectCapitalUse(word);
  if (result) {
    cout << "true" << endl;
  } else {
    cout << "false" << endl;
  }
  return 0;
}
