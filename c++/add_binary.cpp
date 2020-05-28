#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  string addBinary(string a, string b) {
    string sum_num;
    int a_length = a.length();
    int b_length = b.length();
    int carry = 0;
    int i = a_length - 1;
    int j = b_length - 1;
    while (i >= 0 || j >= 0)
    {
      int c_of_a = 0;
      int c_of_b = 0;
      if (i >= 0 && a[i] == '1')
      {
        c_of_a = 1;
      }
      if (j >= 0 && b[j] == '1')
      {
        c_of_b = 1;
      }
      int current = carry + c_of_a + c_of_b;
      sum_num = to_string(current % 2) + sum_num;
      carry = current / 2;

      i--;
      j--;
    }
    if (carry == 1)
    {
      sum_num = "1" + sum_num;
    }
    return sum_num;
  }
};

int main ()
{
  Solution s;
  string a = "11";
  string b = "1";
  string result = s.addBinary(a, b);
  cout << result << endl;
  return 0;
}
