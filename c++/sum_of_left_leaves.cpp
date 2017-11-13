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
  int sumOfLeftLeaves(TreeNode* root) {
    if (root == NULL || (root->left == NULL && root->right==NULL)) {
      return 0;
    }
    return recursive_sum_left(root);
  }

private:
  int recursive_sum_left(TreeNode* node) {
    if (node == NULL) {
      return 0;
    }
    if (node->left != NULL && node->left->left == NULL && node->left->right == NULL) {
      return node->left->val + recursive_sum_left(node->right);
    } else {
      return recursive_sum_left(node->left) + recursive_sum_left(node->right);
    }
  }
};

int main() {
  TreeNode* node1 = new TreeNode(3);
  TreeNode* node2 = new TreeNode(9);
  TreeNode* node3 = new TreeNode(20);
  TreeNode* node4 = new TreeNode(15);
  TreeNode* node5 = new TreeNode(7);
  node1->left = node2;
  node1->right = node3;
  node3->left = node4;
  node3->right = node5;
  Solution s;
  int result = s.sumOfLeftLeaves(node1);
  cout << result << endl;
  return 0;
}
