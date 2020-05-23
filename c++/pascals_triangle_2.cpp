#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> getRow(int rowIndex) {
    vector<int> pascal_triangle;
    long num = 1;
    for (int i = 0; i < rowIndex + 1; i++)
    {
      if (i == 0 || i == rowIndex)
      {
        pascal_triangle.push_back(1);
        continue;
      }
      num *= (rowIndex + 1 - i);
      num /= i;
      pascal_triangle.push_back((int)num);
    }
    return pascal_triangle;
  }
};

int main()
{
  Solution s;
  vector<int> result = s.getRow(3);
  for (int iter : result)
  {
    cout << iter << " ";
  }
  cout << endl;
  return 0;
}
