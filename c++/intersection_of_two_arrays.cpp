#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2){
    // method 1
    /**
    set<int> set1(nums1.begin(), nums1.end());
    set<int> section;
    for (auto iter : nums2) {
      if (set1.find(iter) != set1.end()) {
        section.insert(iter);
      }
    }
    **/

    // method 2
    set<int> section;
    for (auto iter : nums2) {
      if (find(nums1.begin(), nums1.end(), iter) != nums1.end()) {
        section.insert(iter);
      }
    }
    return vector<int>(section.begin(), section.end());
  }
};

int main() {
  vector<int> nums1{1, 2, 2, 1};
  vector<int> nums2{2, 2};
  Solution S;
  vector<int> section = S.intersection(nums1, nums2);
  for (auto iter : section) {
    cout << iter << endl;
  }
  return 0;
}
