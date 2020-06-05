#include <iostream>

using namespace std;

class Solution
{
public:
  bool isPerfectSquare(int num)
  {
    // Newton-Raphson method
    long x = num;
    while (x * x > num)
    {
      x = (x + num / x) / 2;
    }
    return x * x == num;
  }

  bool isPerfectSquare2(int num)
  {
    long sum = 0;
    for (int i = 1; i <= num && sum < num;)
    {
      sum += i;
      i += 2;
    }
    return num == sum;
  }
};

int main()
{
  Solution s;
  bool result = s.isPerfectSquare2(15);
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
