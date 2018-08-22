#include <iostream>

using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : var(x), left(NULL), right(NULL) {};
};

class Solution
{
public:
  TreeNode* pruneTree(TreeNode* root)
  {

  }
};

int main()
{
  TreeNode* node1 = new TreeNode(1);
  TreeNode* node2 = new TreeNode(1);
  TreeNode* node3 = new TreeNode(0);
  TreeNode* node4 = new TreeNode(1);
  TreeNode* node5 = new TreeNode(1);
  TreeNode* node6 = new TreeNode(0);
  TreeNode* node7 = new TreeNode(1);
  TreeNode* node8 = new TreeNode(0);

  node1->left = node2;
  node1->right = node3;
  node2->left = node4;
  node2->right = node5;
  node3->left = node6;
  node3->right = node7;
  node4->left = node8;

  Solution s;
  TreeNode* root = s.pruneTree(node1);
  cout << root->val << endl;

  delete node1;
  delete node2;
  delete node3;
  delete node4;
  delete node5;
  delete node6;
  delete node7;
  delete node8;

  return 0;
}
