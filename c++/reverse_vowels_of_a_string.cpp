#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution
{
public:
  string reverseVowels(string s)
  {
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    int i = 0;
    int j = s.length() - 1;
    while (i < j)
    {
      if (vowels.find(s[i]) != vowels.end() && vowels.find(s[j]) != vowels.end())
      {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
        continue;
      }
      if (vowels.find(s[i]) == vowels.end())
      {
        i++;
      }
      if (vowels.find(s[j]) == vowels.end())
      {
        j--;
      }
    }
    return s;
  }
};

int main()
{
  string str = "leetcode";
  Solution s;
  string result = s.reverseVowels(str);
  cout << result << endl;
  return 0;
}
