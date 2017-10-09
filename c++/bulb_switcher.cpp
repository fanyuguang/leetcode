#include <iostream>
#include <math.h>

using namespace std;

class Solution
{
public:
  int bulbSwitch(int n)
  {
    return (int)sqrt(n);
  }
};

int main()
{
  int n = 99999;
  Solution S;
  int nums_of_on = S.bulbSwitch(n);
  cout << nums_of_on << endl;
  return 0;
}
