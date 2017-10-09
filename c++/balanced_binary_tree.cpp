#include <iostream>
#include <cmath>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  bool isBalanced(TreeNode* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) {
      return true;
    }
    if (abs(subtree_height(root->left) - subtree_height(root->right)) <= 1) {
      return isBalanced(root->left) && isBalanced(root->right);
    } else {
      return false;
    }
  }

private:
  int subtree_height(TreeNode* node) {
    if (node == NULL) {
      return 0;
    } else if (node->left == NULL && node->right == NULL) {
      return 1;
    }
    return max(subtree_height(node->left), subtree_height(node->right)) + 1;
  }
};

int main() {
  TreeNode* node1 = new TreeNode(1);
  TreeNode* node2 = new TreeNode(2);
  TreeNode* node3 = new TreeNode(3);
  TreeNode* node4 = new TreeNode(4);
  TreeNode* node5 = new TreeNode(5);
  TreeNode* node6 = new TreeNode(6);
  TreeNode* node7 = new TreeNode(7);

  node1->left = node2;
//  node1->right = node3;
  node2->left = node4;
  node2->right = node5;
//  node3->left = node6;
//  node3->right = node7;

  Solution s;
  if (s.isBalanced(node1)) {
    cout << "Balanced Binary Tree" << endl;
  } else {
    cout << "Non-balanced Binary Tree" << endl;
  }
  delete node1;
  delete node2;
  delete node3;
  delete node4;
  delete node5;
  delete node6;
  delete node7;
  return 0;
}
