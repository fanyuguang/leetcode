#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
  bool isValid(string s) {
    unordered_map<char, int> c_map = {{'(', -1}, {')', 1}, {'[', -2}, {']', 2}, {'{', -3}, {'}', 3}};
    stack<char> c_stack;
    for (char c : s)
    {
      if (c_stack.empty() || c_map[c_stack.top()] + c_map[c] != 0)
      {
        c_stack.push(c);
      }
      else
      {
        c_stack.pop();
      }
    }
    if (c_stack.empty())
    {
      return true;
    }
    else
    {
      return false;
    }
  }
};

int main()
{
  Solution s;
  string str = "()[]{}";
  bool result = s.isValid(str);
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
