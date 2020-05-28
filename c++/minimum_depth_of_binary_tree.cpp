#include <iostream>
#include <queue>

using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(NULL), right(NULL) {}
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
  int minDepth(TreeNode* root)
  {
    int depth = 0;
    queue<TreeNode*> node_queue;
    if (root == NULL)
    {
      return depth;
    }
    else
    {
      node_queue.push(root);
      node_queue.push(NULL);
      depth++;
    }
    while (!node_queue.empty())
    {
      TreeNode* node = node_queue.front();
      node_queue.pop();
      if (node == NULL)
      {
        node_queue.push(NULL);
        depth++;
        continue;
      }

      if (node->left == NULL && node->right == NULL)
      {
        break;
      }
      if (node->left != NULL)
      {
        node_queue.push(node->left);
      }
      if (node->right != NULL)
      {
        node_queue.push(node->right);
      }
    }
    return depth;
  }
};

int main()
{
  TreeNode* node1 = new TreeNode(3);
  TreeNode* node2 = new TreeNode(9);
  TreeNode* node3 = new TreeNode(20);
  TreeNode* node4 = new TreeNode(15);
  TreeNode* node5 = new TreeNode(7);
  node1->left = node2;
  node1->right = node3;
  node3->left = node4;
  node3->right = node5;

  Solution s;
  int result = s.minDepth(node1);
  cout << result << endl;

  delete node1;
  delete node2;
  delete node3;
  delete node4;
  delete node5;
  return 0;
}
