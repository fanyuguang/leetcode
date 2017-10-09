#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> constructArray(int n, int k) {
    vector<int> arrangements;
    int i = 1;
    int j = n;
    while (i <= j) {
      if (k > 1) {
        arrangements.push_back(k-- % 2 ? i++ : j--);
      } else {
        arrangements.push_back(i++);
      }
    }
    return arrangements;
  }
};

int main() {
  int n = 3;
  int k = 1;
  Solution s;
  vector<int> result = s.constructArray(n, k);
  for (int num : result) {
    cout << num << endl;
  }
  return 0;
}
