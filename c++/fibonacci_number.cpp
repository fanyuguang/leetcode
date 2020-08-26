#include <iostream>

using namespace std;

class Solution
{
public:
  int fib(int N)
  {
    if (N == 0)
    {
      return 0;
    }
    else if (N == 1)
    {
      return 1;
    }
    else
    {
      return fib(N - 1) + fib(N - 2);
    }
  }

  int fib2(int N)
  {
    int first = 0;
    int second = 1;
    for (int i = 2; i <= N; i += 2)
    {
      first = first + second;
      second = first + second;
    }
    return (N % 2 == 0) ? first : second;
  }
};

int main()
{
  Solution s;
  int result = s.fib2(4);
  cout << result << endl;
  return 0;
}
