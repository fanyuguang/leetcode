#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int> char_store;
    for (char c : magazine) {
      if (char_store.find(c) != char_store.end()) {
        char_store[c]++;
      } else {
        char_store[c] = 1;
      }
    }
    for (char c: ransomNote) {
      if (char_store.find(c) == char_store.end() || char_store[c] == 0) {
        return false;
      } else {
        char_store[c]--;
      }
    }
    return true;
  }
};

int main() {
  string ransonNote = "aa";
  string magazine = "aab";
  Solution s;
  bool result = s.canConstruct(ransonNote, magazine);
  if (result) {
    cout << "true" << endl;
  } else {
    cout << "false" << endl;
  }
  return 0;
}
