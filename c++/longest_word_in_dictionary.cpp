#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution
{
public:
  string longestWord(vector<string>& words)
  {
    sort(words.begin(), words.end());

    string longest_word = "";
    unordered_set<string> matched_words;
    for (string word : words)
    {
      if (word.length() == 1 || matched_words.find(word.substr(0, word.length() - 1)) != matched_words.end())
      {
        matched_words.insert(word);
        longest_word = word.length() > longest_word.length() ? word : longest_word;
      }
    }

    return longest_word;
  }
};

int main()
{
  vector<string> words { "a", "banana", "app", "appl", "ap", "apply", "apple" };
  Solution s;
  string longest_word = s.longestWord(words);
  cout << longest_word << endl;
  return 0;
}
