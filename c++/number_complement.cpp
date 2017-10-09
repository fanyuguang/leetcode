#include <iostream>

using namespace std;

class Solution {
public:
  int findComplement(int num) {
    int num_copy = num;
    int sum = 1;
    while (num_copy > 0) {
      num_copy >>= 1;
      sum <<= 1;
    }
    int complement_num = sum - num - 1;
    return complement_num;
  }
};

int main() {
  int num = 5;
  Solution S;
  int complement_num = S.findComplement(num);
  cout << complement_num << endl;
  return 0;
}
