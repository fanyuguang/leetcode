#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  string countAndSay(int n) {
    if (n == 1)
    {
      return "1";
    }
    string str = countAndSay(n-1);
    cout << str << endl;
    char c = str[0];
    int c_count = 0;
    string s = "";
    for (int i = 0; i < str.length(); i++)
    {
      if (c == str[i])
      {
        c_count++;
      }
      else
      {
        s = s + to_string(c_count) + c;
        c = str[i];
        c_count = 1;
      }
    }
    s = s + to_string(c_count) + c;
    return s;
  }
};

int main()
{
  Solution s;
  string result = s.countAndSay(5);
  cout << result << endl;
  return 0;
}
