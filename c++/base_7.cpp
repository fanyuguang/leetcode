#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  string convertToBase7(int num) {
    bool is_negative = false;
    if (num < 0) {
      is_negative = true;
      num = -num;
    }
    string num_str = "";
    do {
      int remainder = num % 7;
      num_str = to_string(remainder) + num_str;
      num = num / 7;
    } while (num != 0);
    if (is_negative) {
      num_str = "-" + num_str;
    }
    return num_str;
  }
}; 

int main() {
  Solution s;
  string result = s.convertToBase7(100);
  cout << result << endl;
  return 0;
}
