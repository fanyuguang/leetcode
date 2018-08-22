#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  int compareVersion(string version1, string version2) {
    int first_index = 0;
    int second_index = 0;
    while (first_index < version1.size() || second_index < version2.size()) {
      int revision1 = 0;
      if (first_index < version1.size()) {
        int first_start = first_index;
        int first_end = first_start;
        while (first_end < version1.size() && version1[first_end] != '.') {
          first_end++;
        }
        revision1 = stoi(version1.substr(first_start, first_end - first_start));
        first_index = first_end + 1;
      }
      int revision2 = 0;
      if (second_index < version2.size()) {
        int second_start = second_index;
        int second_end = second_start;
        while (second_end < version2.size() && version2[second_end] != '.') {
          second_end++;
        }
        revision2 = stoi(version2.substr(second_start, second_end - second_start));
        second_index = second_end + 1;
      }
      if (revision1 > revision2) {
        return 1;
      } else if (revision1 < revision2) {
        return -1;
      }
    }
    return 0;
  }
};

int main() {
  string version1 = "1";
  string version2 = "1.1";
  Solution s;
  int result = s.compareVersion(version1, version2);
  cout << result << endl;
  return 0;
}
