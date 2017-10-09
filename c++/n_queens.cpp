#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
  vector<vector<string>> solveNQueens(int n)
  {
  }
};

int main()
{
  int n = 4;
  vector<vector<string>> solve;
  Solution S;
  solve = S.solveNQueens(n);
  for (auto iter1 : solve)
  {
    for (auto iter2 : iter1)
    {
      cout << iter2 << endl;
    }
    cout << endl;
  }
  return 0;
}
