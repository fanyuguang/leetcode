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
  TreeNode* trimBST(TreeNode* root, int L, int R) {
    if (root == NULL) {
      return NULL;
    }
    if (root->val >= L && root->val <= R) {
      root->left = trimBST(root->left, L, R);
      root->right = trimBST(root->right, L, R);
      return root;
    } else if (root->val < L) {
      return trimBST(root->right, L, R);
    } else if (root->val > R) {
      return trimBST(root->left, L, R);
    } else {
      return NULL;
    }
  }
};

int main() {
  TreeNode* node1 = new TreeNode(3);
  TreeNode* node2 = new TreeNode(0);
  TreeNode* node3 = new TreeNode(4);
  TreeNode* node4 = new TreeNode(2);
  TreeNode* node5 = new TreeNode(1);
  node1->left = node2;
  node1->right = node3;
  node2->right = node4;
  node4->left = node5;
  Solution s;
  TreeNode* trim_node = s.trimBST(node1, 1, 3);
  cout << trim_node->val << endl;
  delete node1;
  delete node2;
  delete node3;
  delete node4;
  delete node5;
  return 0;
}
