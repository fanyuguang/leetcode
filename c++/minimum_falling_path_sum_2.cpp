#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int minFallingPathSum(vector<vector<int> >& arr)
  {
    int arr_size = arr.size();
    if (arr_size == 1)
    {
      return arr[0][0];
    }
    int min_sum = INT_MAX;
    int first_min = INT_MAX;
    int second_min = INT_MAX;
    for (int i = 0; i < arr_size; i++)
    {
      int current_first_min = INT_MAX;
      int current_second_min = INT_MAX;
      for (int j = 0; j < arr_size; j++)
      {
        if (i > 0)
        {
          if (arr[i-1][j] != first_min)
          {
            arr[i][j] += first_min;
          }
          else
          {
            arr[i][j] += second_min;
          }
        }

        if (arr[i][j] <= current_first_min)
        {
          current_second_min = current_first_min;
          current_first_min = arr[i][j];
        }
        else if (arr[i][j] < current_second_min)
        {
          current_second_min = arr[i][j];
        }

        if (i == arr_size - 1)
        {
          if (arr[i][j] < min_sum)
          {
            min_sum = arr[i][j];
          }
        }
      }
      first_min = current_first_min;
      second_min = current_second_min;
    }
    return min_sum;
  }
};

int main()
{
  vector<vector<int> > arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  Solution s;
  int result = s.minFallingPathSum(arr);
  cout << result << endl;
  return 0;
}
