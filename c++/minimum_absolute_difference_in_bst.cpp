#include <iostream>
#include <cmath>
#include <limits.h>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution {
public:
  int getMinimumDifference(TreeNode* root) {
    int min_difference = INT_MAX;
    RecursiveTraversal(root, min_difference);
    return min_difference;
  }

private:
  void RecursiveTraversal(TreeNode* node, int& min_difference) {
    if (node->left != NULL) {
      TreeNode* left_max = node->left;
      while (left_max->right != NULL) {
        left_max = left_max->right;
      }
      int left_difference = abs(node->val - left_max->val);
      if (left_difference < min_difference) {
        min_difference = left_difference;
      }
      RecursiveTraversal(node->left, min_difference);
    }
    if (node->right != NULL) {
      TreeNode* right_min = node->right;
      while (right_min->left != NULL) {
        right_min = right_min->left;
      }
      int right_difference = abs(node->val - right_min->val);
      if (right_difference < min_difference) {
        min_difference = right_difference;
      }
      RecursiveTraversal(node->right, min_difference);
    }
  }
};

int main() {
  TreeNode* node1 = new TreeNode(1);
  TreeNode* node2 = new TreeNode(3);
  TreeNode* node3 = new TreeNode(2);
  node1->right = node2;
  node2->left = node3;
  Solution s;
  int result = s.getMinimumDifference(node1);
  cout << result << endl;
  delete node1;
  delete node2;
  delete node3;
  return 0;
}
