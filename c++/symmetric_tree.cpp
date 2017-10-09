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
  bool isSymmetric(TreeNode* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) {
      return true;
    } else if ((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL)) {
      return false;
    }
    TreeNode* node1 = root->left;
    TreeNode* node2 = root->right;
    stack<TreeNode*> node_stack1;
    node_stack1.push(node1);
    stack<TreeNode*> node_stack2;
    node_stack2.push(node2);
    while (!node_stack1.empty() && !node_stack2.empty()) {
      TreeNode* node_top1 = node_stack1.top();
      TreeNode* node_top2 = node_stack2.top();
      if (node_top1->val != node_top2->val) {
        return false;
      }
      node_stack1.pop();
      node_stack2.pop();
      if(node_top1->left != NULL && node_top2->right != NULL) {
        node_stack1.push(node_top1->left);
        node_stack2.push(node_top2->right);
      } else if ((node_top1->left == NULL && node_top2->right != NULL) || (node_top1->left != NULL && node_top2->right == NULL)) {
        return false;
      }
      if(node_top1->right != NULL && node_top2->left != NULL) {
        node_stack1.push(node_top1->right);
        node_stack2.push(node_top2->left);
      } else if ((node_top1->right == NULL && node_top2->left != NULL) || (node_top1->right != NULL && node_top2->left == NULL)) {
        return false;
      }
    }
    if (!node_stack1.empty() || !node_stack2.empty()) {
      return false;
    } else {
      return true;
    }
  }
};

int main() {
  TreeNode* node1 = new TreeNode(1);
  TreeNode* node2 = new TreeNode(2);
  TreeNode* node3 = new TreeNode(2);
  TreeNode* node4 = new TreeNode(3);
  TreeNode* node5 = new TreeNode(4);
  TreeNode* node6 = new TreeNode(4);
  TreeNode* node7 = new TreeNode(3);

  node1->left = node2;
  node1->right = node3;
  node2->left = node4;
  node2->right = node5;
  node3->left = node6;
//  node3->right = node7;

  Solution S;
  if (S.isSymmetric(node1)) {
    cout << "is symmetric" << endl;
  } else {
    cout << "is not symmetric" << endl;
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
