#include <iostream>

using namespace std;

class Solution
{
public:
  int trailingZeroes(int n)
  {
    int five_count = 0;
    while (n > 0)
    {
      n /= 5;
      five_count += n;
    }
    return five_count;
  }
};

int main()
{
  Solution s;
  int result = s.trailingZeroes(26);
  cout << result << endl;
  return 0;
}
