#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
  bool repeatedSubstringPattern(string s)
  {
    int s_length = s.length();
    char start_c = s[0];
    char end_c = s[s_length - 1];
    for (int i = 0; i < s_length / 2; i++)
    {
      if (s[i] == end_c && s_length % (i + 1) == 0)
      {
        string repeated_pattern = s.substr(0, i + 1);
        int j = i + 1;
        while (j < s_length && repeated_pattern == s.substr(j, i + 1))
        {
          j += i + 1;
        }

        if (j == s_length)
        {
          return true;
        }
      }
    }
    return false;
  }
};

int main()
{
  string s = "abcabcabcabc";
  Solution solution;
  bool result = solution.repeatedSubstringPattern(s);
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
