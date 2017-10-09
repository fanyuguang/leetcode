#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  int findLUSlength(string a, string b) {
    if (a == b) {
      return -1;
    }
    if (a.size() >= b.size()) {
      return a.size();
    } else {
      return b.size();
    }
  }
};

int main() {
  string a = "aba";
  string b = "cdc";
  Solution s;
  int result = s.findLUSlength(a, b);
  cout << result << endl;
  return 0;
}
