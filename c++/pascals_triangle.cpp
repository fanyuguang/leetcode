#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> pascal_triangle;
    pascal_triangle.resize(numRows);
    for (int i = 0; i < numRows; i++)
    {
      pascal_triangle[i].resize(i + 1);
      for (int j = 0; j < i + 1; j++)
      {
        if (j == 0 || j == i)
        {
          pascal_triangle[i][j] = 1;
          continue;
        }
        pascal_triangle[i][j] = pascal_triangle[i-1][j-1] + pascal_triangle[i-1][j];
      }
    }
    return pascal_triangle;
  }
};

int main()
{
  Solution s;
  vector<vector<int>> result = s.generate(5);
  for (vector<int> iters : result)
  {
    for (int iter : iters)
    {
      cout << iter << " ";
    }
    cout << endl;
  }
  return 0;
}
