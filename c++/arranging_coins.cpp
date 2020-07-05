#include <cmath>
#include <iostream>

using namespace std;

class Solution
{
public:
  int arrangeCoins(int n)
  {
    int i = 0;
    long sum = 0;
    while (sum <= n)
    {
      sum += ++i;
    }
    return i - 1;
  }

  int arrangeCoins2(int n)
  {
    int i = (int)(sqrt(8 * (long)n + 1) - 1) / 2;
    return i;
  }
};

int main()
{
  Solution s;
  int result = s.arrangeCoins2(5);
  cout << result << endl;
  return 0;
}
