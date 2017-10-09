#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<string> findWords(vector<string>& words) {
    map<char, int> row_char = {{'q', 1}, {'w', 1}, {'e', 1}, {'r', 1}, {'t', 1}, {'y', 1}, {'u', 1}, {'i', 1}, {'o', 1}, {'p', 1}, 
                               {'a', 2}, {'s', 2}, {'d', 2}, {'f', 2}, {'g', 2}, {'h', 2}, {'j', 2}, {'k', 2}, {'l', 2}, 
                               {'z', 3}, {'x', 3}, {'c', 3}, {'v', 3}, {'b', 3}, {'n', 3}, {'m', 3}};
    vector<string> row_words;
    for (string str : words) {
      string str_copy = str;
      transform(str.begin(), str.end(), str_copy.begin(), ::tolower);
      int start_row = row_char[str_copy[0]];
      bool is_end = true;
      for (char c : str_copy) {
        if (row_char[c] != start_row) {
          is_end = false;
          break;
        }
      }
      if (is_end) {
        row_words.push_back(str);
      }
    }
    return row_words;
  }
};

int main() {
  vector<string> words = {"Hello", "Alaska", "Dad", "Peace"}; 
  Solution S;
  vector<string> row_words = S.findWords(words);
  for (string str : row_words) {
    cout << str << endl;
  }
  return 0;
}
