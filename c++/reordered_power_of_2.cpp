#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  bool reorderedPowerOf2(int N)
  {
    vector<int> N_digits = count(N);
    int power_of_two = 1;
    for (int i = 0; i < 31; i++)
    {
      vector<int> current_digits = count(1 << i);
      if (current_digits == N_digits)
      {
        return true;
      }
    }
    return false;
  }

private:
  vector<int> count(int num)
  {
    vector<int> digits(10, 0);
    while (num > 0)
    {
      digits[num % 10]++;
      num /= 10;
    }
    return digits;
  }
};

int main()
{
  Solution s;
  bool result = s.reorderedPowerOf2(46);
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
