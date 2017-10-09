#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
  {
    if (p->val > q->val)
    {
      TreeNode* temp_node = p;
      p = q;
      q = temp_node;
    }
    TreeNode* temp_root = root;
    while (true)
    {
      if (p->val == temp_root->val || q->val == temp_root->val || (p->val < temp_root->val && q->val > temp_root->val))
      {
        return temp_root;
      }
      else if (p->val < temp_root->val && q->val < temp_root->val)
      {
        temp_root = temp_root->left;
      }
      else if (p->val > temp_root->val && q->val > temp_root->val)
      {
        temp_root = temp_root->right;
      }
    }
  }
};

int main()
{
  TreeNode* root = new TreeNode(6);
  TreeNode* node1 = new TreeNode(2);
  TreeNode* node2 = new TreeNode(8);
  TreeNode* node3 = new TreeNode(0);
  TreeNode* node4 = new TreeNode(4);
  TreeNode* node5 = new TreeNode(7);
  TreeNode* node6 = new TreeNode(9);
  TreeNode* node7 = new TreeNode(3);
  TreeNode* node8 = new TreeNode(5);
  root->left = node1;
  root->right = node2;
  node1->left = node3;
  node1->right = node4;
  node2->left = node5;
  node2->right = node6;
  node4->left = node7;
  node4->right = node8;

  Solution s;
  TreeNode* common_ancestor_node = s.lowestCommonAncestor(root, node7, node8);
  cout << common_ancestor_node->val << endl;
  delete root;
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
