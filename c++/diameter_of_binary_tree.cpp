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
  int diameterOfBinaryTree(TreeNode* root) {
    if (root == NULL) {
      return 0;
    }
    int max_diameter = 0;
    RecursiveTree(root, max_diameter);
    return max_diameter;
  }

private:
  int RecursiveTree(TreeNode* node, int& max_diameter) {
    int left_length = 0;
    if (node->left != NULL) {
      left_length = RecursiveTree(node->left, max_diameter) + 1;
    }
    int right_length = 0;
    if (node->right != NULL) {
      right_length = RecursiveTree(node->right, max_diameter) + 1;
    }
    if (max_diameter < left_length + right_length) {
      max_diameter = left_length + right_length;
    }
    return left_length > right_length ? left_length : right_length;
  }
};

int main() {
  TreeNode* node1 = new TreeNode(1);
  TreeNode* node2 = new TreeNode(2);
  TreeNode* node3 = new TreeNode(3);
  TreeNode* node4 = new TreeNode(4);
  TreeNode* node5 = new TreeNode(5);
  node1->left = node2;
  node1->right = node3;
  node2->left = node4;
  node2->right = node5;
  Solution s;
  int result = s.diameterOfBinaryTree(node1);
  cout << result << endl;
  delete node1;
  delete node2;
  delete node3;
  delete node4;
  delete node5;
  return 0;
}
