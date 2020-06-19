#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
  bool isSubsequence(string s, string t)
  {
    unordered_map<char, vector<int> > index_mapping;
    for (int i = 0; i < t.size(); i++)
    {
      index_mapping[t[i]].push_back(i);
    }
    int pre = -1;
    for (char c : s)
    {
      if (index_mapping.find(c) == index_mapping.end())
      {
        return false;
      }
      auto current = upper_bound(index_mapping[c].begin(), index_mapping[c].end(), pre);
      if (current == index_mapping[c].end())
      {
        return false;
      }
      pre = *current;
    }
    return true;
  }
};

int main()
{
  string s = "abc";
  string t = "ahbgdc";
  Solution solution;
  bool result = solution.isSubsequence(s, t);
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
