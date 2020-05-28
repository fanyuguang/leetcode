#include <iostream>

using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
  bool hasPathSum(TreeNode* root, int sum)
  {
    if (root == NULL)
    {
      return false;
    }
    else
    {
      return pathSum(root, root->val, sum);
    }
  }

private:
  bool pathSum(TreeNode* root, int aggregate, int sum)
  {
    if (root->left == NULL && root->right == NULL && aggregate == sum)
    {
      return true;
    }

    if (root->left != NULL)
    {
      if (pathSum(root->left, aggregate + root->left->val, sum))
      {
        return true;
      }
    }
    if (root->right != NULL)
    {
      if (pathSum(root->right, aggregate + root->right->val, sum))
      {
        return true;
      }
    }
    return false;
  }
};

int main()
{
  TreeNode* node1 = new TreeNode(5);
  TreeNode* node2 = new TreeNode(4);
  TreeNode* node3 = new TreeNode(8);
  TreeNode* node4 = new TreeNode(11);
  TreeNode* node5 = new TreeNode(13);
  TreeNode* node6 = new TreeNode(4);
  TreeNode* node7 = new TreeNode(7);
  TreeNode* node8 = new TreeNode(2);
  TreeNode* node9 = new TreeNode(1);
  node1->left = node2;
  node1->right = node3;
  node2->left = node4;
  node3->left = node5;
  node3->right = node6;
  node4->left = node7;
  node4->right = node8;
  node6->right = node9;
  
  TreeNode* node10 = new TreeNode(-2);
  TreeNode* node11 = new TreeNode(-3);
  node10->right = node11;

  Solution s;
  bool result = s.hasPathSum(node10, -5);
  if (result)
  {
    cout << "true" << endl;
  }
  else
  {
    cout << "false" << endl;
  }

  delete node1;
  delete node2;
  delete node3;
  delete node4;
  delete node5;
  delete node6;
  delete node7;
  delete node8;
  delete node9;
  delete node10;
  delete node11;
  return 0;
}
