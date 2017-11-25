#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  vector<string> findRelativeRanks(vector<int>& nums) {
    vector<int> nums_rank(nums);
    QuickSort(nums_rank, 0, nums_rank.size() - 1);
    unordered_map<int, string> score_store;
    score_store[nums_rank[0]] = "Gold Medal";
    score_store[nums_rank[1]] = "Silver Medal";
    score_store[nums_rank[2]] = "Bronze Medal";
    for (int i = 3; i < nums_rank.size(); i++) {
      score_store[nums_rank[i]] = to_string(i + 1);
    }
    vector<string> relative_ranks;
    for (int num : nums) {
      relative_ranks.push_back(score_store[num]);
    }
    return relative_ranks;
  }

private:
  int partition(vector<int>& nums, int p, int r) {
    int i = p - 1;
    for (int j = p; j <= r; j++) {
      if (nums[j] >= nums[r]) {
        int temp = nums[++i];
        nums[i] = nums[j];
        nums[j] = temp;
      }
    }
    return i;
  }

  void QuickSort(vector<int>& nums, int p, int r) {
    if (p < r) {
      int q = partition(nums, p, r);
      QuickSort(nums, p, q - 1);
      QuickSort(nums, q + 1, r);
    }
  }
};

int main() {
  vector<int> nums = {5, 4, 3, 2, 1};
  Solution s;
  vector<string> result = s.findRelativeRanks(nums);
  for (string str : result) {
    cout << str << endl;
  }
  return 0;
}
