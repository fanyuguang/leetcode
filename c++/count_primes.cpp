#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int countPrimes(int n)
  {
    if (n <= 2)
    {
      return 0;
    }
    vector<bool> is_primes(n - 1, true);
    int count_of_primes = 0;
    for (int i = 2; i < n; i++)
    {
      if (!is_primes[i])
      {
        continue;
      }
      count_of_primes++;
      for (int j = 2; i * j < n; j++)
      {
        is_primes[i * j] = false;
      }
    }
    return count_of_primes;
  }
};

int main()
{
  Solution s;
  int result = s.countPrimes(10);
  cout << result << endl;
  return 0;
}
