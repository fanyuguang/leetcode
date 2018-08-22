#include <iostream>

using namespace std;

class Solution {
public:
  string toHex(int num) {
    string hex_num = "";
    if (num == 0) {
      hex_num = "0";
    } else if (num == -2147483648) {
      hex_num = "80000000";
    } else if (num > 0) {
      while (num > 0) {
        int single_num = num % 16;
        num = num / 16;
        char c_single_num;
        if (single_num > 9) {
          c_single_num = single_num - 10 + 'a';
        } else {
          c_single_num = single_num + '0';
        }
        hex_num = c_single_num + hex_num;
      }
    } else {
      num = 0 - num;
      int carry = 1;
      int bit_count = 0;
      while (num > 0) {
        int single_num = (15 - num % 16 + carry) % 16;
        carry = (15 - num % 16 + carry) / 16;
        cout << "single_num : " << single_num << endl;
        cout << "carry : " << carry << endl;
        num = num / 16;
        char c_single_num;
        if (single_num > 9) {
          c_single_num = single_num - 10 + 'a';
        } else {
          c_single_num = single_num + '0';
        }
        hex_num = c_single_num + hex_num;
        bit_count++;
      }
      if (carry > 0) {
        hex_num = to_string(carry) + hex_num;
        bit_count++;
      }
      while (++bit_count <= 8) {
        hex_num = "f" + hex_num;
      }
    }
    return hex_num;
  }
};

int main() {
  Solution s;
  string result = s.toHex(-2147483648);
  cout << result << endl;
  return 0;
}
