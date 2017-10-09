#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int islandPerimeter(vector<vector<int>>& grid) {
    int height = grid.size();
    if (height == 0) {
      return 0;
    }
    int width = grid[0].size();
    if (width == 0) {
      return 0;
    }
    int perimeter = 0;
    for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
        if (grid[i][j] == 1) {
          if (i == 0 || grid[i-1][j] == 0) {
            perimeter++;
          }
          if (i == height - 1 || grid[i+1][j] == 0) {
            perimeter++;
          }
          if (j == 0 || grid[i][j-1] == 0) {
            perimeter++;
          }
          if (j == width - 1 || grid[i][j+1] == 0) {
            perimeter++;
          }
        }
      }
    }
    return perimeter;
  }
};

int main() {
  vector<vector<int> > grid;
  vector<int> grid_row1{0, 1, 0, 0};
  vector<int> grid_row2{1, 1, 1, 0};
  vector<int> grid_row3{0, 1, 0, 0};
  vector<int> grid_row4{1, 1, 0, 0};
  grid.push_back(grid_row1);
  grid.push_back(grid_row2);
  grid.push_back(grid_row3);
  grid.push_back(grid_row4);
  Solution s;
  int perimeter = s.islandPerimeter(grid);
  cout << perimeter << endl;
  return 0;
}
