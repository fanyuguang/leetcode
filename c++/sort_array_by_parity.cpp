#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<int> sortArrayByParityII(vector<int>& A)
  {
    int i = 0;
    int j = A.size() - 1;
    while (i < j)
    {
      while (i < j && A[i] % 2 == 0)
      {
        i++;
      }
      while (j > i && A[j] % 2 == 1)
      {
        j--;
      }
      if (i < j)
      {
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
      }
      i++;
      j--;
    }
    return A;
  }
};

int main()
{
  vector<int> A = {3, 1, 2, 4};
  Solution s;
  vector<int> result = s.sortArrayByParityII(A);
  for (int item : result)
  {
    cout << item << " ";
  }
  cout << endl;
  return 0;
}
