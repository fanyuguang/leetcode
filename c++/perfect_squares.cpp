#include <iostream>
#include <cmath>

using namespace std;

class Solution
{
public:
  int numSquares(int n)
  {
    for (int i = 2; i * i <= n; i++)
    {
      while (n != 1 && n % (i * i) == 0)
      {
        n /= (i * i);
      }
    }
    if (n == 1)
    {
      return 1;
    }

    if (n % 8 == 7)
    {
      return 4;
    }

    for (int i = 1; i * i < n; i++)
    {
      int j = sqrt(n - i * i);
      if (i * i + j * j == n)
      {
        return 2;
      }
    }
    return 3;
  }
};

int main()
{
  Solution s;
  int result = s.numSquares(13);
  cout << result << endl;
  return 0;
}
