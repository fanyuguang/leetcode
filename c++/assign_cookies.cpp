#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int findContentChildren(vector<int>& g, vector<int>& s) {
    QuickSort(g, 0, g.size() - 1);
    QuickSort(s, 0, s.size() - 1);
    int content_children = 0;
    int i = g.size() - 1;
    int j = s.size() - 1;
    while (i >= 0 && j >= 0) {
      if (s[j] >= g[i]) {
        content_children++;
        i--;
        j--;
      } else {
        i--;
      }
    }
    return content_children;
  }

private:
  int partition(vector<int>& nums, int p, int r) {
    int i = p - 1;
    for (int j = p; j < r; j++) {
      if (nums[j] < nums[r]) {
        int temp = nums[++i];
        nums[i] = nums[j];
        nums[j] = temp;
      }
    }
    int temp = nums[r];
    nums[r] = nums[++i];
    nums[i] = temp;
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
  vector<int> g = {1, 2};
  vector<int> s = {1, 2, 3};
  Solution solution;
  int result = solution.findContentChildren(g, s);
  cout << result << endl;
  return 0;
}
