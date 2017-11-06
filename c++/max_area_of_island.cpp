#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int bfs_grid(int i, int j, vector<vector<int> >& grid, vector<vector<int> >& visited) {
    visited[i][j] = 1;
    int count = 1;
    if (i > 0 && grid[i-1][j] == 1 && visited[i-1][j] == 0) {
      count += bfs_grid(i - 1, j, grid, visited);
    }
    if (i < grid.size() - 1 && grid[i+1][j] == 1 && visited[i+1][j] == 0) {
      count += bfs_grid(i + 1, j, grid, visited);
    }
    if (j > 0 && grid[i][j-1] == 1 && visited[i][j-1] == 0) {
      count += bfs_grid(i, j - 1, grid, visited);
    }
    if (j < grid[0].size() - 1 && grid[i][j+1] == 1 && visited[i][j+1] == 0) {
      count += bfs_grid(i, j+1, grid, visited);
    }
    return count;
  }

  int maxAreaOfIsland(vector<vector<int> >& grid) {
    int max = 0;
    if (grid.empty()) {
      return max;
    }
    vector<vector<int> > visited(grid.size(), vector<int>(grid[0].size(), 0));
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] == 1 && visited[i][j] == 0) {
          int count = bfs_grid(i, j, grid, visited);
          if (count > max) {
            max = count;
          }
        }
      }
    }
    return max;
  }
};

int main() {
  vector<int> row1 = {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0};
  vector<int> row2 = {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0};
  vector<int> row3 = {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0};
  vector<int> row4 = {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0};
  vector<int> row5 = {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0};
  vector<int> row6 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0};
  vector<int> row7 = {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0};
  vector<int> row8 = {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0};
  vector<vector<int> > grid = {row1, row2, row3, row4, row5, row6, row7, row8};
  Solution s;
  int result = s.maxAreaOfIsland(grid);
  cout << result << endl;
  return 0;
}
