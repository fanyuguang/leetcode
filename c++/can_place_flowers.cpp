#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  bool canPlaceFlowers(vector<int>& flowerbed, int n)
  {
    int max_plot = 0;
    int zero_count = 1;
    for (int plot : flowerbed)
    {
      if (plot == 0)
      {
        zero_count++;
      }
      else
      {
        max_plot += (zero_count - 1) / 2;
        zero_count = 0;
      }
    }
    max_plot += (zero_count) / 2;
    return max_plot >= n;
  }
};

int main()
{
  vector<int> flowerbed = {1, 0, 0, 0, 1};
  Solution s;
  bool result = s.canPlaceFlowers(flowerbed, 2);
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
