#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
    sort(people.begin(), people.end(), compare);
    vector<pair<int, int> > reconstruct_people;
    for (pair<int, int> people_info : people) {
      reconstruct_people.insert(reconstruct_people.begin() + people_info.second, people_info);
    }
    return reconstruct_people;
  }
  
private:
  static bool compare(const pair<int, int>& v1, const pair<int, int>& v2) {
      return v1.first > v2.first || (v1.first == v2.first && v1.second < v2.second);
  }
};

int main() {
  vector<pair<int, int> > people;
  pair<int, int> people1(7, 0);
  pair<int, int> people2(4, 4);
  pair<int, int> people3(7, 1);
  pair<int, int> people4(5, 0);
  pair<int, int> people5(6, 1);
  pair<int, int> people6(5, 2);
  people.push_back(people1);
  people.push_back(people2);
  people.push_back(people3);
  people.push_back(people4);
  people.push_back(people5);
  people.push_back(people6);
  Solution s;
  vector<pair<int, int> > result = s.reconstructQueue(people);
  for (pair<int, int> people_info : result) {
    cout << "[" << people_info.first << ", " << people_info.second << "]" << endl;
  }
  return 0;
}
