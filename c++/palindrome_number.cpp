#include <iostream>

using namespace std;

class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0)
    {
      return false;
    }
    int high = 1;
    while(x / high >= 10)
    {
      high *= 10;
    }
    while (high > 1)
    {
      if (x / high != x % 10)
      {
        return false;
      }
      x = (x % high) / 10;
      high /= 100;
    }
    return true;
  }

  bool isPalindrome2(int x) {
    if (x < 0 || (x != 0 && x % 10 == 0))
    {
      return false;
    }
    int revert_x = 0;
    while (x > revert_x)
    {
      revert_x = revert_x * 10 + x % 10;
      x /= 10;
    }
    if (x == revert_x || x == revert_x / 10)
    {
      return true;
    }
    return false;
  }
};

int main()
{
  Solution s;
  // int x = 121;
  int x = 1000000001;
  bool result = s.isPalindrome2(x);
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
