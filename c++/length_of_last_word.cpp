#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  int lengthOfLastWord(string s) {
    int length_of_last = 0;
    bool is_first_char = true;
    for (int i = s.length()- 1; i >= 0; i--)
    {
      if (s[i] != ' ')
      {
        if (is_first_char)
        {
          is_first_char = false;
        }
        length_of_last++;
      }
      else
      {
        if (!is_first_char)
        {
          break;
        }
      }
    }
    return length_of_last;
  }
};

int main()
{
  Solution s;
  string str = "Hello world";
  str = "a ";
  int result = s.lengthOfLastWord(str);
  cout << result << endl;
  return 0;
}
