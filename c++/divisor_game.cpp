#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  Solution()
  {
    divisor_table_[1] = false;
    divisor_table_[2] = true;
  }

  bool divisorGame(int N)
  {
    if (divisor_table_.find(N) != divisor_table_.end())
    {
      return divisor_table_[N];
    }

    for (int i = 1; i <= N / 2; i++)
    {
      if (N % i == 0)
      {
        if (divisor_table_.find(N - i) != divisor_table_.end())
        {
          if (!divisor_table_[N - i])
          {
            divisor_table_[N] = true;
            return true;
          }
        }
        else if (!divisorGame(N - i))
        {
          divisor_table_[N] = true;
          return true;
        }
      }
    }
    divisor_table_[N] = false;
    return false;
  }

private:
  unordered_map<int, bool> divisor_table_;
};

int main()
{
  int N = 2;
  Solution s;
  bool result = s.divisorGame(N);
  if (result)
  {
    cout << "True" << endl;
  }
  else
  {
    cout << "False" << endl;
  }
  return 0;
}
