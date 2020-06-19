#include <iostream>

using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(NULL), right(NULL) {};
  TreeNode(int x) : val(x), left(NULL), right(NULL) {};
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {};
};

class Solution
{
public:
  int countNodes(TreeNode* root)
  {
    return sub_count_nodes(root, -1, -1);
  }

private:
  int sub_count_nodes(TreeNode* node, int parent_left_depth, int parent_right_depth)
  {
    int left_depth = 0;
    if (parent_left_depth == -1)
    {
      TreeNode* left_node = node;
      while(left_node != NULL)
      {
        left_depth++;
        left_node = left_node->left;
      }
    }
    else
    {
      left_depth = parent_left_depth - 1;
    }

    int right_depth = 0;
    if (parent_right_depth == -1)
    {
      TreeNode* right_node = node;
      while(right_node != NULL)
      {
        right_depth++;
        right_node = right_node->right;
      }
    }
    else
    {
      right_depth = parent_right_depth - 1;
    }

    if (left_depth == right_depth)
    {
      return (1 << left_depth) - 1;
    }
    return 1 + sub_count_nodes(node->left, left_depth, -1) + sub_count_nodes(node->right, -1, right_depth);
  }
};

int main()
{
  TreeNode *node1 = new TreeNode(1);
  TreeNode *node2 = new TreeNode(2);
  TreeNode *node3 = new TreeNode(3);
  TreeNode *node4 = new TreeNode(4);
  TreeNode *node5 = new TreeNode(5);
  TreeNode *node6 = new TreeNode(6);
  node1->left = node2;
  node1->right = node3;
  node2->left = node4;
  node2->right = node5;
  node3->left = node6;

  Solution s;
  int result = s.countNodes(node1);
  cout << result << endl;
  return 0;
}
