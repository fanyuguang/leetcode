#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  bool checkRecord(string s) {
    int A_count = 0;
    int L_count = 0;
    for (char c : s) {
      if (c == 'A') {
        A_count++;
        L_count = 0;
      } else if (c == 'L') {
        L_count++;
      } else {
        L_count = 0;
      }
      if (A_count > 1 || L_count > 2) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  string str = "PPALLL";
  Solution s;
  bool result = s.checkRecord(str);
  if (result) {
    cout << "true" << endl;
  } else {
    cout << "false" << endl;
  }
  return 0;
}
