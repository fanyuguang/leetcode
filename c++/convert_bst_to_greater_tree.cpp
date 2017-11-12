#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode* convertBST(TreeNode* root) {
    if (root != NULL) {
      sumTreeRight(root, 0);
    }
    return root;
  }

private:
  int sumTreeRight(TreeNode* node, int sum_parent_right) {
    if (node->right != NULL) {
      node->val += sumTreeRight(node->right, sum_parent_right);
    } else {
      node->val += sum_parent_right;
    }
    if (node->left != NULL) {
      return sumTreeRight(node->left, node->val);
    } else {
      return node->val;
    }
  }
};

int main() {
  TreeNode* node1 = new TreeNode(2);
  TreeNode* node2 = new TreeNode(0);
  TreeNode* node3 = new TreeNode(3);
  TreeNode* node4 = new TreeNode(-4);
  TreeNode* node5 = new TreeNode(1);
  node1->left = node2;
  node1->right = node3;
  node2->left = node4;
  node2->right = node5;
  Solution s;
  TreeNode* result = s.convertBST(node1);
  cout << result->val << endl;
  return 0;
}
