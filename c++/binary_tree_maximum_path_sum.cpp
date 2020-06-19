#include <iostream>
#include <climits>

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
  int maxPathSum(TreeNode* root)
  {
    int max = INT_MIN;
    current_max_sum(root, max);
    return max;
  }

private:
  int current_max_sum(TreeNode* node, int& max)
  {
    if (node == NULL) 
    {
      return 0;
    }
    int max_left = current_max_sum(node->left, max);
    int max_right = current_max_sum(node->right, max);

    int current_sum = node->val;
    if (max_left > 0)
    {
      current_sum += max_left;
    }
    if (max_right > 0)
    {
      current_sum += max_right;
    }

    if (current_sum > max)
    {
      max = current_sum;
    }

    if (max_left <= max_right && max_left > 0)
    {
      current_sum -= max_left;
    }
    else if (max_left >= max_right && max_right > 0)
    {
      current_sum -= max_right;
    }
    return current_sum;
  }
};

int main()
{
  // TreeNode* node1 = new TreeNode(-10);
  // TreeNode* node2 = new TreeNode(9);
  // TreeNode* node3 = new TreeNode(20);
  // TreeNode* node4 = new TreeNode(15);
  // TreeNode* node5 = new TreeNode(7);

  // node1->left = node2;
  // node1->right = node3;
  // node3->left = node4;
  // node3->right = node5;

  TreeNode* node1 = new TreeNode(1);
  TreeNode* node2 = new TreeNode(0);
  TreeNode* node3 = new TreeNode(1);
  TreeNode* node4 = new TreeNode(1);
  TreeNode* node5 = new TreeNode(2);
  TreeNode* node6 = new TreeNode(0);
  TreeNode* node7 = new TreeNode(-1);
  TreeNode* node8 = new TreeNode(0);
  TreeNode* node9 = new TreeNode(1);
  TreeNode* node10 = new TreeNode(-1);
  TreeNode* node11 = new TreeNode(0);
  TreeNode* node12 = new TreeNode(-1);
  TreeNode* node13 = new TreeNode(0);
  TreeNode* node14 = new TreeNode(1);
  TreeNode* node15 = new TreeNode(0);

  node1->left = node2;
  node1->right = node3;
  node2->left = node4;
  node2->right = node5;
  node3->left = node6;
  node3->right = node7;
  node4->left = node8;
  node4->right = node9;
  node5->left = node10;
  node5->right = node11;
  node6->left = node12;
  node6->right = node13;
  node7->left = node14;
  node7->right = node15;

  Solution s;
  int result = s.maxPathSum(node1);
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
  delete node10;
  delete node11;
  delete node12;
  delete node13;
  delete node14;
  delete node15;
  return 0;
}
