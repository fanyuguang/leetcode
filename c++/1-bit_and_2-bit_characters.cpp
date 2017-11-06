#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool isOneBitCharacter(vector<int>& bits) {
    int i = 0;
    while (i < bits.size()) {
      if (i == bits.size() - 1) {
        return true;
      }
      if (bits[i] == 0) {
        i++;
      } else {
        i += 2;
      }
    }
    return false;
  }
};

int main() {
  // vector<int> bits = {1, 0, 0};
  vector<int> bits = {1, 1, 1, 0};
  Solution s;
  bool result = s.isOneBitCharacter(bits);
  if (result) {
    cout << "true" << endl;
  } else {
    cout << "false" << endl;
  }
  return 0;
}
