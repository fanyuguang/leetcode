#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if (t1 != NULL && t2 != NULL) {
      int val = t1->val + t2->val;
      TreeNode* node = new TreeNode(val);
      node->left = mergeTrees(t1->left, t2->left);
      node->right = mergeTrees(t1->right, t2->right);
      return node;
    } else if (t1 != NULL && t2 == NULL) {
      return t1;
    } else if (t1 == NULL && t2 != NULL) {
      return t2;
    } else {
      return NULL;
    }
  }
};

int main() {
  TreeNode* node1_1 = new TreeNode(1);
  TreeNode* node1_2 = new TreeNode(3);
  TreeNode* node1_3 = new TreeNode(2);
  TreeNode* node1_4 = new TreeNode(5);
  node1_1->left = node1_2;
  node1_2->right = node1_3;
  node1_2->left = node1_4;
  TreeNode* node2_1 = new TreeNode(2);
  TreeNode* node2_2 = new TreeNode(1);
  TreeNode* node2_3 = new TreeNode(3);
  TreeNode* node2_4 = new TreeNode(4);
  TreeNode* node2_5 = new TreeNode(7);
  node2_1->left = node2_2;
  node2_1->right = node2_3;
  node2_2->right = node2_4;
  node2_3->right = node2_5;
  Solution s;
  TreeNode* merge_node = s.mergeTrees(node1_1, node2_1);
  cout << merge_node->val << endl;
  delete node1_1;
  delete node1_2;
  delete node1_3;
  delete node1_4;
  delete node2_1;
  delete node2_2;
  delete node2_3;
  delete node2_4;
  delete node2_5;
  return 0;
}
