#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int findPoisonedDuration(vector<int>& timeSeries, int duration) {
    if (timeSeries.empty()) {
      return 0;
    }
    int poisoned_duration = 0;
    for (int i = 0; i < timeSeries.size() - 1; i++) {
      int neighbor_time = timeSeries[i+1] - timeSeries[i];
      if (neighbor_time < duration) {
        poisoned_duration += neighbor_time;
      } else {
        poisoned_duration += duration;
      }
    }
    poisoned_duration += duration;
    return poisoned_duration;
  }
};

int main() {
  vector<int> time_series = {1, 2};
  int duration = 2;
  Solution s;
  int result = s.findPoisonedDuration(time_series, duration);
  cout << result << endl;
  return 0;
}
