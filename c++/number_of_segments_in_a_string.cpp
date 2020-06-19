#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
  int countSegments(string s)
  {
    int count = 0;
    for (int i = 0; i < s.size(); i++)
    {
      if (s[i] != ' ' && (i + 1 == s.size() || s[i + 1] == ' '))
      {
        count++;
      }
    }
    return count;
  }
};

int main()
{
  string s = "Hello, my name is John";
  Solution solution;
  int result = solution.countSegments(s);
  cout << result << endl;
  return 0;
}
