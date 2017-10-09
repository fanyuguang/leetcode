#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> countBits(int num) {
    vector<int> result;
    if (num < 0) {
      return result;
    }
    result.push_back(0);
    int count = 0;
    for (int i = 0; i < num; ++i) {
      if (i & 1 == 0) {
        count++;
      } else {
        count = count - num_of_postfixone(i) + 1;
      }
      result.push_back(count);
    }
    return result;
  }

  int num_of_postfixone(int num) {
    int first_one = num ^ (num + 1);
    int count = 0;
    while (first_one) {
      first_one >>= 1;
      count++;
    }
    cout << num << " " << count - 1 << endl;
    return count - 1;
  }
};

int main()
{
  int num = 5;
  Solution S;
  vector<int> result = S.countBits(num);
  for (auto iter : result) {
    cout << iter << endl;
  }
  return 0;
}
