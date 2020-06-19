#include <iostream>

using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(NULL), right(NULL) {}
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  TreeNode(int x, TreeNode *left, TreeNode* right) : val(0), left(left), right(right) {}
};

class Solution
{
public:
  int pathSum(TreeNode* root, int sum)
  {
    if (root == NULL)
    {
      return 0;
    }
    return sum_current(root, 0, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
  }

private:
  int sum_current(TreeNode* node, int pre, int sum)
  {
    if (node == NULL)
    {
      return 0;
    }
    pre = pre + node->val;
    return (pre == sum) + sum_current(node->left, pre, sum) + sum_current(node->right, pre, sum);
  }
};

int main()
{
  TreeNode* node1 = new TreeNode(10);
  TreeNode* node2 = new TreeNode(5);
  TreeNode* node3 = new TreeNode(-3);
  TreeNode* node4 = new TreeNode(3);
  TreeNode* node5 = new TreeNode(2);
  TreeNode* node6 = new TreeNode(11);
  TreeNode* node7 = new TreeNode(3);
  TreeNode* node8 = new TreeNode(-2);
  TreeNode* node9 = new TreeNode(1);

  node1->left = node2;
  node1->right = node3;
  node2->left = node4;
  node2->right = node5;
  node3->right = node6;
  node4->left = node7;
  node4->right = node8;
  node5->right = node9;

  Solution s;
  int result = s.pathSum(node1, 8);
  cout << result << endl;

  delete node1;
  delete node2;
  delete node3;
  delete node4;
  delete node5;
  delete node6;
  delete node7;
  delete node8;
  delete node9;
}
