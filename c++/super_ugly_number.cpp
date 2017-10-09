#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
  int nthSuperUglyNumber(int n, vector<int>& primes) {
    int primes_len = primes.size();
    vector<int> primes_index(primes_len, 0);
    vector<int> ugly_numbers = {1};
    while (ugly_numbers.size() < n) {
      int min = INT_MAX;
      vector<int> min_index;
      for (int i = 0; i < primes_len; i++) {
        if (primes[i] * ugly_numbers[primes_index[i]] < min) {
          min = primes[i] * ugly_numbers[primes_index[i]];
          min_index.clear();
          min_index.push_back(i);
        } else if (primes[i] * ugly_numbers[primes_index[i]] == min) {
          min_index.push_back(i);
        }
      }
      cout << "min : " << min << endl;
      for (int i : min_index) {
        primes_index[i]++;
      }
      ugly_numbers.push_back(min);
    }
    return ugly_numbers[n-1];
  }
};

int main() {
  int n = 12;
  vector<int> primes = {2, 7, 13, 19};
  Solution S;
  int result = S.nthSuperUglyNumber(n, primes);
  cout << result << endl;
}
