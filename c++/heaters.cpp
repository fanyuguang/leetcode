#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int findRadius(vector<int>& houses, vector<int>& heaters)
  {
    std::sort(houses.begin(), houses.end());
    std::sort(heaters.begin(), heaters.end());
    int max_radius = 0;
    int j = 0;
    for (int i = 0; i < houses.size(); i++)
    {
      while (j < heaters.size() && houses[i] > heaters[j])
      {
        j++;
      }
      int current_radius = INT_MAX;
      if (j !=0 && houses[i] - heaters[j - 1] < current_radius)
      {
        current_radius = houses[i] - heaters[j - 1];
      }
      if (j != heaters.size() && heaters[j] - houses[i] < current_radius)
      {
        current_radius = heaters[j] - houses[i];
      }
      if (current_radius > max_radius)
      {
        max_radius = current_radius;
      }
    }
    return max_radius;
  }
};

int main()
{
  vector<int> houses = {1, 2, 3, 4};
  vector<int> heaters = {1, 4};
  Solution s;
  int result = s.findRadius(houses, heaters);
  cout << result << endl;
  return 0;
}
