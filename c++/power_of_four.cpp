#include <iostream>

using namespace std;

class Solution
{
public:
  bool isPowerOfFour(int num)
  {
    return num > 0 && !(num & (num - 1)) && (num - 1) % 3 == 0;
  }
};

int main()
{
  Solution s;
  bool result = s.isPowerOfFour(16);
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
