#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> plusOne(vector<int>& digits) {
    int temp = 1;
    for (auto iter = digits.rbegin(); iter != digits.rend(); iter++) {
      *iter += temp;
      temp = *iter / 10;
      *iter = *iter % 10;
    }
    if (temp > 0) {
      vector<int> plus_digits;
      plus_digits.push_back(temp);
      for (auto iter : digits) {
        plus_digits.push_back(iter);
      }
      return plus_digits;
    } else {
      return digits;
    }
  }
};

int main() {
  vector<int> digits;
  digits.push_back(1);
  digits.push_back(0);
  Solution S;
  vector<int> plus_digits = S.plusOne(digits);
  for (auto iter : plus_digits) {
    cout << iter << endl;
  }
  return 0;
}
