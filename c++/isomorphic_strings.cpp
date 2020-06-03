#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution
{
public:
  bool isIsomorphic(string s, string t)
  {
    unordered_map<char, char> c_mapping;
    unordered_set<char> c_set;
    for (int i = 0; i < s.length(); i++)
    {
      if (c_mapping.find(s[i]) != c_mapping.end())
      {
        if (c_mapping[s[i]] != t[i])
        {
          return false;
        }
      }
      else
      {
        c_mapping[s[i]] = t[i];
        if (c_set.find(t[i]) != c_set.end())
        {
          return false;
        }
        c_set.insert(t[i]);
      }
      s[i] = t[i];
    }
    return s == t;
  }
};

int main()
{
  // string s = "paper";
  // string t = "title";
  string s = "ab";
  string t = "aa";

  Solution solution;
  bool result = solution.isIsomorphic(s, t);
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
