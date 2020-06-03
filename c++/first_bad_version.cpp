#include <iostream>

using namespace std;

class Solution
{
public:
  int firstBadVersion(int n)
  {
    if (isBadVersion(1))
    {
      return 1;
    }
    int first = 1;
    int last = n;
    while (first < last)
    {
      int mid = first / 2 + last / 2;
      bool is_mid_bad = isBadVersion(mid);
      if (is_mid_bad)
      {
        last = mid;
        continue;
      }
      bool is_mid_next_bad = isBadVersion(mid + 1);
      if (!is_mid_next_bad)
      {
        first = mid + 1;
        continue;
      }
      break;
    }
    return first / 2 + last / 2 + 1;
  }
  
  bool isBadVersion(int version)
  {
    int first_bad_version = 4;
    if (version >= first_bad_version)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
};

int main()
{
  Solution s;
  int result = s.firstBadVersion(5);
  cout << result << endl;
  return 0;
}
