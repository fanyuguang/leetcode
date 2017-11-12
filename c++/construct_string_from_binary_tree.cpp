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
  string tree2str(TreeNode* t) {
    if (t == NULL) {
      return "";
    }
    if (t->right != NULL) {
      return to_string(t->val) + "(" + tree2str(t->left) + ")" + "(" + tree2str(t->right) + ")";
    } else if (t->left != NULL && t->right == NULL) {
      return to_string(t->val) + "(" + tree2str(t->left) + ")";
    } else {
      return to_string(t->val);
    }
  }
};

int main() {
  TreeNode* node1 = new TreeNode(1);
  TreeNode* node2 = new TreeNode(2);
  TreeNode* node3 = new TreeNode(3);
  TreeNode* node4 = new TreeNode(4);
  node1->left = node2;
  node1->right = node3;
  node2->right = node4;
  Solution s;
  string result = s.tree2str(node1);
  cout << result << endl;
  delete node1;
  delete node2;
  delete node3;
  delete node4;
  return 0;
}
