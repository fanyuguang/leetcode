#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution
{
public:
  bool wordPattern(string pattern, string str)
  {
    unordered_map<char, string> pattern_map;
    unordered_set<string> str_span_set;
    int i = 0;
    int p = 0;
    int q = 0;
    while (i < pattern.length() && p < str.length())
    {
      q = p;
      while (q < str.length() && str[q] != ' ')
      {
        q++;
      }
      string str_span = str.substr(p, q - p);
      if (pattern_map.find(pattern[i]) != pattern_map.end())
      {
        if (str_span != pattern_map[pattern[i]])
        {
          return false;
        }
      }
      else
      {
        if (str_span_set.find(str_span) != str_span_set.end())
        {
          return false;
        }
        pattern_map[pattern[i]] = str_span;
        str_span_set.insert(str_span);
      }
      i++;
      p = q + 1;
    }
    if (i < pattern.length() || p < str.length())
    {
      return false;
    }
    return true;
  }
};

int main()
{
  string pattern = "abba";
  string str = "dog cat cat dog";
  Solution s;
  bool result = s.wordPattern(pattern, str);
  if (result)
  {
    cout << "true" << endl;
  }
  else
  {
    cout << "false" << endl;
  }
  return 0;
}
