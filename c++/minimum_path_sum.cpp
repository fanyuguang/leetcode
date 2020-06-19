#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:
  int minPathSum(vector<vector<int> >& grid)
  {
    vector<vector<int> > path_sum(grid.size(), vector<int>(grid[0].size(), -1));
    return subMinPathSum(grid, path_sum, grid.size() - 1, grid[0].size() - 1);
  }

private:
  int subMinPathSum(vector<vector<int> >& grid, vector<vector<int> >& path_sum, int i, int j)
  {
    if (path_sum[i][j] != -1)
    {
      return path_sum[i][j];
    }
    int min = INT_MAX;
    if (i > 0)
    {
      int top_sum = subMinPathSum(grid, path_sum, i-1, j);
      if (top_sum < min)
      {
        min = top_sum;
      }
    }
    if (j > 0)
    {
      int left_sum = subMinPathSum(grid, path_sum, i, j-1);
      if (left_sum < min)
      {
        min = left_sum;
      }
    }

    int current_min = grid[i][j];
    if (i != 0 || j != 0)
    {
      current_min += min;
    }
    path_sum[i][j] = current_min;
    return current_min;
  }
};

int main()
{
  // vector<vector<int> > grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
  vector<vector<int> > grid = {{3,8,6,0,5,9,9,6,3,4,0,5,7,3,9,3},{0,9,2,5,5,4,9,1,4,6,9,5,6,7,3,2},{8,2,2,3,3,3,1,6,9,1,1,6,6,2,1,9},{1,3,6,9,9,5,0,3,4,9,1,0,9,6,2,7},{8,6,2,2,1,3,0,0,7,2,7,5,4,8,4,8},{4,1,9,5,8,9,9,2,0,2,5,1,8,7,0,9},{6,2,1,7,8,1,8,5,5,7,0,2,5,7,2,1},{8,1,7,6,2,8,1,2,2,6,4,0,5,4,1,3},{9,2,1,7,6,1,4,3,8,6,5,5,3,9,7,3},{0,6,0,2,4,3,7,6,1,3,8,6,9,0,0,8},{4,3,7,2,4,3,6,4,0,3,9,5,3,6,9,3},{2,1,8,8,4,5,6,5,8,7,3,7,7,5,8,3},{0,7,6,6,1,2,0,3,5,0,8,0,8,7,4,3},{0,4,3,4,9,0,1,9,7,7,8,6,4,6,9,5},{6,5,1,9,9,2,2,7,4,2,7,2,2,3,7,2},{7,1,9,6,1,2,7,0,9,6,6,4,4,5,1,0},{3,4,9,2,8,3,1,2,6,9,7,0,2,4,2,0},{5,1,8,8,4,6,8,5,2,4,1,6,2,2,9,7}};
  Solution s;
  int result = s.minPathSum(grid);
  cout << result << endl;
  return 0;
}
