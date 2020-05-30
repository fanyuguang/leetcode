#include <iostream>

using namespace std;

class Solution
{
public:
  uint32_t reverseBits(uint32_t n)
  {
    uint32_t reverse_n = 0;
    int bit_count = 0;
    while (n > 0)
    {
      reverse_n *= 2;
      reverse_n += n % 2;
      n /= 2;
      bit_count++;
    }
    for (int i = 0; i < 32 - bit_count; i++)
    {
      reverse_n *= 2;
    }
    return reverse_n;
  }
};

int main()
{
  Solution s;
  uint32_t result = s.reverseBits(43261596);
  cout << result << endl;
  return 0;
}
