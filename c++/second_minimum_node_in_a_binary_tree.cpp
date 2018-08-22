#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  int findSecondMinimumValue(TreeNode* root) {
    if (root == NULL) {
      return -1;
    }
    int second_min = -1;
    RecursiveTree(root, root->val, second_min);
    return second_min;
  }

private:
  void RecursiveTree(TreeNode* node, int& root_val, int& second_min) {
    if (node->left != NULL && node->right != NULL) {
      if (node->left->val != root_val) {
        if (second_min == -1 || node->left->val < second_min) {
          second_min = node->left->val;
        }
        RecursiveTree(node->right, root_val, second_min);
      } else if (node->right->val != root_val) {
        if (second_min == -1 || node->right->val < second_min) {
          second_min = node->right->val;
        }
        RecursiveTree(node->left, root_val, second_min);
      } else {
        RecursiveTree(node->left, root_val, second_min);
        RecursiveTree(node->right, root_val, second_min);
      }
    }
  }
};

int main() {
  TreeNode* node1 = new TreeNode(2);
  TreeNode* node2 = new TreeNode(2);
  TreeNode* node3 = new TreeNode(5);
  TreeNode* node4 = new TreeNode(5);
  TreeNode* node5 = new TreeNode(7);
  node1->left = node2;
  node1->right = node3;
  node3->left = node4;
  node3->right = node5;
  Solution s;
  int result = s.findSecondMinimumValue(node1);
  cout << result << endl;
  return 0;
}
