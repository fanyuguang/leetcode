#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
  vector<string> fizzBuzz(int n) {
    vector<string> fizz_buzz;
    for (int i = 1; i <= n; i++) {
      if (i % 3 == 0 && i % 5 == 0) {
        fizz_buzz.push_back("FizzBuzz");
      } else if (i % 3 == 0 && i % 5 != 0) {
        fizz_buzz.push_back("Fizz");
      } else if (i % 3 != 0 && i % 5 == 0) {
        fizz_buzz.push_back("Buzz");
      } else {
        fizz_buzz.push_back(to_string(i));
      }
    }
    return fizz_buzz;
  }
};

int main() {
  int n = 15;
  Solution s;
  vector<string> result = s.fizzBuzz(n);
  for (string num : result) {
    cout << num << endl;
  }
  return 0;
}
