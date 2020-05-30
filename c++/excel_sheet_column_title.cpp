#include <iostream>

using namespace std;

class Solution
{
public:
  string convertToTitle(int n)
  {
    string title = "";
    while (n-- > 0)
    {
      title = (char)(n % 26 + 'A') + title;
      n /= 26;
    }
    return title;
  }
};

int main()
{
  Solution s;
  string result = s.convertToTitle(28);
  cout << result << endl;
  return 0;
}
