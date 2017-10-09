#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
  TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    if (nums.empty()) {
      return NULL;
    }
    int max_num = nums[0];
    int max_index = 0;
    for (int index = 0; index < nums.size(); index++) {
      if (nums[index] > max_num) {
        max_num = nums[index];
        max_index = index;
      }
    }
    vector<int> left_nums;
    vector<int> right_nums;
    for (int index = 0; index < max_index; index++) {
      left_nums.push_back(nums[index]);
    }
    for (int index = max_index + 1; index < nums.size(); index++) {
      right_nums.push_back(nums[index]);
    }
    TreeNode* node = new TreeNode(max_num);
    node->left = constructMaximumBinaryTree(left_nums);
    node->right = constructMaximumBinaryTree(right_nums);
    return node;
  }
};

int main() {
  vector<int> nums{3, 2, 1, 6, 0, 5};
  Solution s;
  TreeNode* tree_root = s.constructMaximumBinaryTree(nums);
  cout << tree_root->val << endl;
  return 0;
}
