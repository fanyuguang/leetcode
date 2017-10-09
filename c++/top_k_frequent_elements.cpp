#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    map<int, int> count_nums;
    for (auto iter : nums) {
      if (count_nums.find(iter) == count_nums.end()) {
        count_nums.insert(pair<int, int>(iter, 1));
      } else {
        count_nums[iter] += 1;
      }
    }

  }
};

int main() {
  vector<int> nums{1, 1, 1, 2, 2, 3};
  Solution S;
  vector<int> topk = S.topKFrequent(nums, 2);
  for (auto iter : topk) {
    cout << iter << endl;
  }
  return 0;
}
