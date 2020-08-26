#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int minCostClimbingStairs(vector<int>& cost)
  {
    int cost_size = cost.size();
    for (int i = 2; i < cost_size; i++)
    {
      cost[i] += min(cost[i - 2], cost[i - 1]);
    }
    return min(cost[cost_size - 1], cost[cost_size - 2]);
  }
};

int main()
{
  vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
  Solution s;
  int result = s.minCostClimbingStairs(cost);
  cout << result << endl;
  return 0;
}
