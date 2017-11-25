#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  int firstUniqChar(string s) {
    unordered_map<char, int> char_store;
    for (int i = s.size() - 1; i >= 0; i--) {
      if (char_store.find(s[i]) == char_store.end()) {
        char_store[s[i]] = i;
      } else {
        char_store[s[i]] = s.size();
      }
    }
    int first_unique = s.size();
    for (pair<char, int> iter : char_store) {
      if (iter.second < first_unique) {
        first_unique = iter.second;
      }
    }
    if (first_unique == s.size()) {
      return -1;
    } else {
      return first_unique;
    }
  }
};

int main() {
  // string str = "loveleetcode";
  string str = "aadadaad";
  Solution s;
  int result = s.firstUniqChar(str);
  cout << result << endl;
  return 0;
}
