#include <iostream>

using namespace std;

class Solution
{
public:
  int guessNumber(int n)
  {
    long start = 1;
    long end = n;
    while (start <= end)
    {
      long mid = (start + end) / 2;
      if (guess(mid) == -1)
      {
        start = mid + 1;
      }
      else if (guess(mid) == 1)
      {
        end = mid - 1;
      }
      else
      {
        return mid;
      }
    }
    return -1;
  }

  int guess(int num)
  {
    int guess_num = 1;
    if (num < guess_num)
    {
      return -1;
    }
    else if (num > guess_num)
    {
      return 1;
    }
    else
    {
      return 0;
    }
  }
};

int main()
{
  Solution s;
  int result = s.guessNumber(1);
  cout << result << endl;
  return 0;
}
