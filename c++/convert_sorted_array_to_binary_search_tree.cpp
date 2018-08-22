#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution {
public:
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    if (nums.empty()) {
      return NULL;
    }
    TreeNode* root = CreateTree(nums, 0, nums.size() - 1);
    return root;
  }

private:
  TreeNode* CreateTree(vector<int>& nums, int start, int end) {
    int mid = (start + end) / 2;
    TreeNode* node = new TreeNode(nums[mid]);
    if (start < mid) {
      TreeNode* left = CreateTree(nums, start, mid - 1);
      node->left = left;
    }
    if (mid < end) {
      TreeNode* right = CreateTree(nums, mid + 1, end);
      node->right = right;
    }
    return node;
  }
};

int main() {
  vector<int> nums = {-10, -3, 0, 5, 9};
  Solution s;
  TreeNode* root = s.sortedArrayToBST(nums);
  cout << root->val << endl;
  return 0;
}
