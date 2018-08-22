#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  string addStrings(string num1, string num2) {
    string add_num = "";
    int num1_index = num1.size() - 1;
    int num2_index = num2.size() - 1;
    int carry = 0;
    while (num1_index >= 0 || num2_index >= 0 || carry != 0) {
      int num1_single = 0;
      if (num1_index >= 0) {
        num1_single = num1[num1_index--] - '0';
      }
      int num2_single = 0;
      if (num2_index >= 0) {
        num2_single = num2[num2_index--] - '0';
      }
      int num = (num1_single + num2_single + carry) % 10;
      carry = ((num1_single + num2_single + carry) / 10);
      add_num = to_string(num) + add_num;
    }
    return add_num;
  }
};

int main() {
  string num1 = "119";
  string num2 = "22";
  Solution s;
  string result = s.addStrings(num1, num2);
  cout << result << endl;
  return 0;
}
