#include <iostream>
#include <cmath>

using namespace std;

class Solution
{
public:
  bool judgeSquareSum(int c)
  {
    for (int a = 0; a * a <= c / 2; a++)
    {
      int b = sqrt(c - a * a);
      if (a * a + b * b == c)
      {
        return true;
      }
    }
    return false;
  }
};

int main()
{
  Solution s;
  bool result = s.judgeSquareSum(5);
  if (result)
  {
    cout << "true" << endl;
  }
  else
  {
    cout << "false" << endl;
  }
  return 0l;
}
