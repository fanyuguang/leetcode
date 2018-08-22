#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

class Solution {
public:
  int numberOfBoomerangs(vector<pair<int, int>>& points) {
    int size = points.size();
    vector<unordered_map<int, int>> points_distance(size);
    for (int i = 0; i < size; i++) {
      for (int j = i + 1; j < size; j++) {
        int distance = pow(points[i].first - points[j].first, 2) + pow(points[i].second - points[j].second, 2);
        if (points_distance[i].find(distance) == points_distance[i].end()) {
          points_distance[i][distance] = 1;
        } else {
          points_distance[i][distance]++;
        }
        if (points_distance[j].find(distance) == points_distance[j].end()) {
          points_distance[j][distance] = 1;
        } else {
          points_distance[j][distance]++;
        }
      }
    }
    int boomerangs_count = 0;
    for (int i = 0; i < size; i++) {
      for (pair<int, int> iter : points_distance[i]) {
        boomerangs_count += iter.second * (iter.second - 1);
      }
    }
    return boomerangs_count;
  }
};

int main() {
  vector<pair<int, int>> points = {make_pair(0, 0), make_pair(1, 0), make_pair(2, 0)};
  Solution s;
  int result = s.numberOfBoomerangs(points);
  cout << result << endl;
  return 0;
}
