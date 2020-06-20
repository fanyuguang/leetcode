#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<int> sortArrayByParityII(vector<int>& A)
  {
    int a_size = A.size();
    int i = 0;
    int j = 1;
    while (i < a_size && j < a_size)
    {
      while (i < a_size && A[i] % 2 == 0)
      {
        i += 2;
      }
      while (j < a_size && A[j] % 2 == 1)
      {
        j += 2;
      }
      if (i < a_size && j < a_size)
      {
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
      }
      i += 2;
      j += 2;
    }
    return A;
  }
};

int main()
{
  // vector<int> A = {4, 2, 5, 7};
  vector<int> A = {3, 2};
  Solution s;
  vector<int> result = s.sortArrayByParityII(A);
  for (int item : result)
  {
    cout << item << " ";
  }
  cout << endl;
  return 0;
}
