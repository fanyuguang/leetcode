#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
  vector<int> constructRectangle(int area) {
    int width = sqrt(area);
    while (area % width != 0) {
      width--;
    }
    return vector<int>({area / width, width});
  }
};

int main() {
  Solution s;
  vector<int> result = s.constructRectangle(4);
  for (int num : result) {
    cout << num << endl;
  }
  return 0;
}
