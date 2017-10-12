#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  bool judgeCircle(string moves) {
    vector<int> point{0, 0};
    for (char step : moves) {
      if (step == 'L') {
        point[0]--;
      } else if (step == 'R') {
        point[0]++;
      } else if (step == 'D') {
        point [1]--;
      } else if (step == 'U') {
        point[1]++;
      } else {
        return false;
      }
    }
    if (point[0] == 0 && point[1] == 0) {
      return true;
    } else {
      return false;
    }
  }
};

int main() {

  string moves = "UD";
  Solution s;
  bool result = s.judgeCircle(moves);
  if (result) {
    cout << "true" << endl;
  } else {
    cout << "false" << endl;
  }
  return 0;
}
