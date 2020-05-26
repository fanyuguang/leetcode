#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
  string longestCommonPrefix(vector<string>& strs) {
    string common_prefix = "";
    if (strs.empty())
    {
      return common_prefix;
    }

    int min_str_length = -1;
    for (string str : strs)
    {
      if (min_str_length == -1 || min_str_length < str.length())
      {
        min_str_length = str.length();
      }
    }

    for (int i = 0; i < min_str_length; i++)
    {
      char current_char = strs[0][i];
      int j = 0;
      while (++j < strs.size() && strs[j][i] == current_char) {}
      if (j == strs.size())
      {
        common_prefix += current_char;
      }
      else
      {
        break;
      }
    }
    return common_prefix;
  }
};

int main()
{
  Solution s;
  vector<string> strs = {"flower", "flow", "flight"};
  string result = s.longestCommonPrefix(strs);
  cout << result << endl;
  return 0;
}
