#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
    int height = M.size();
    int width = M[0].size();
    vector<vector<int>> smoother(height, vector<int>(width, 0));
    for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
        int sum = M[i][j];
        int count = 1;
        if (i > 0 && j > 0) {
          sum += M[i - 1][j - 1];
          count++;
        }
        if (i > 0 && j < width - 1) {
          sum += M[i - 1][j + 1];
          count++;
        }
        if (i < height - 1 && j > 0) {
          sum += M[i + 1][j - 1];
          count++;
        }
        if (i < height - 1 && j < width - 1) {
          sum += M[i + 1][j + 1];
          count++;
        }
        if (i > 0) {
          sum += M[i - 1][j];
          count++;
        }
        if (j > 0) {
          sum += M[i][j - 1];
          count++;
        }
        if (i < height - 1) {
          sum += M[i + 1][j];
          count++;
        }
        if (j < width - 1) {
          sum += M[i][j + 1];
          count++;
        }
        smoother[i][j] = sum / count;
      }
    }
    return smoother;
  }
};

int main() {
  vector<vector<int>> M = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
  Solution s;
  vector<vector<int>> result = s.imageSmoother(M);
  for (vector<int> iter : result) {
    for (int num : iter) {
      cout << num << " ";
    }
    cout << endl;
  }
  return 0;
}
