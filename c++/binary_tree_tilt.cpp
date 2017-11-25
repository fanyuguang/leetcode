#include <iostream>
#include <cmath>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution {
public:
  int findTilt(TreeNode* root) {
    if (root == NULL) {
      return 0;
    }
    int tilt = 0;
    RecursiveTraversal(root, tilt);
    return tilt;
  }

private:
  int RecursiveTraversal(TreeNode* node, int& tilt) {
    int sum_left = 0;
    if (node->left != NULL) {
      sum_left = RecursiveTraversal(node->left, tilt);
    }
    int sum_right = 0;
    if (node->right != NULL) {
      sum_right = RecursiveTraversal(node->right, tilt);
    }
    tilt += abs(sum_left - sum_right);
    return node->val + sum_right + sum_left;
  }
};

int main() {
  TreeNode* node1 = new TreeNode(1);
  TreeNode* node2 = new TreeNode(2);
  TreeNode* node3 = new TreeNode(3);
  node1->left = node2;
  node1->right = node3;
  Solution s;
  int result = s.findTilt(node1);
  cout << result << endl;
  delete node1;
  delete node2;
  delete node3;
  return 0;
}
