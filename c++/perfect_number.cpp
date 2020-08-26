#include <iostream>

using namespace std;

class Solution
{
public:
  bool checkPerfectNumber(int num)
  {
    if (num == 0)
    {
      return false;
    }
    int sum = 0;
    for (int i = 1; i <= num / 2; i++)
    {
      if (num % i == 0)
      {
        sum += i;
      }
    }
    return sum == num;
  }
};

int main()
{
  Solution s;
  bool result = s.checkPerfectNumber(28);
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
