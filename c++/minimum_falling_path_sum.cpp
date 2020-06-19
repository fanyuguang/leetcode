#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int minFallingPathSum(vector<vector<int> >& A)
  {
    int a_size = A.size();
    if (a_size == 1)
    {
      return A[0][0];
    }
    int min_sum = INT_MAX;
    for (int i = 1; i < a_size; i++)
    {
      for (int j = 0; j < a_size; j++)
      {
        int upper_min = A[i-1][j];
        if (j > 0)
        {
          upper_min = std::min(upper_min, A[i-1][j-1]);
        }
        if (j < a_size - 1)
        {
          upper_min = std::min(upper_min, A[i-1][j+1]);
        }
        A[i][j] = upper_min + A[i][j];
        if (i == a_size - 1 && A[i][j] < min_sum)
        {
          min_sum = A[i][j];
        }
      }
    }
    return min_sum;
  }
};

int main()
{
  vector<vector<int> > A = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  Solution s;
  int result = s.minFallingPathSum(A);
  cout << result << endl;
  return 0;
}
