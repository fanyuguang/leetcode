#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
    int row_size = nums.size();
    int col_size = nums[0].size();
    if (r * c != row_size * col_size) {
      return nums;
    }
    vector<vector<int> > nums_reshape(r, vector<int>(c, 0));
    for (int i = 0; i < row_size; i++) {
      for (int j = 0; j < col_size; j++) {
        int index = i * col_size + j;
        nums_reshape[index / c][index % c] = nums[i][j];
      }
    }
    return nums_reshape;
  }
};

int main() {
  vector<vector<int> > nums;
  vector<int> num1{1, 2};
  vector<int> num2{3, 4};
  nums.push_back(num1);
  nums.push_back(num2);
  Solution s;
  vector<vector<int> > nums_reshape = s.matrixReshape(nums, 1, 4);
  for (vector<int> row_num : nums_reshape) {
    for (int col_num : row_num) {
      cout << col_num << " ";
    }
    cout << endl;
  }
  return 0;
}
