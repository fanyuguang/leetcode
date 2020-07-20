#include <iostream>
#include <vector>

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
  vector<int> findMode(TreeNode* root)
  {
    vector<int> modes;
    int count = 0;
    int max_mode_count = 0;
    TreeNode* pre = NULL;
    inorder_traversal(root, pre, count, max_mode_count, modes);
    return modes;
  }

private:
  void inorder_traversal(TreeNode* node, TreeNode*& pre, int& count, int& max_mode_count, vector<int>& modes)
  {
    if (node == NULL)
    {
      return;
    }
    inorder_traversal(node->left, pre, count, max_mode_count, modes);

    count = (pre == NULL || node->val != pre->val) ? 1 : count + 1;

    if (count >= max_mode_count)
    {
      if (count > max_mode_count)
      {
        modes.clear();
        max_mode_count = count;
      }
      modes.push_back(node->val);
    }

    pre = node;
    inorder_traversal(node->right, pre, count, max_mode_count, modes);
  }
};

int main()
{
  TreeNode *node1 = new TreeNode(1);
  TreeNode *node2 = new TreeNode(2);
  TreeNode *node3 = new TreeNode(2);
  node1->right = node2;
  node2->left = node3;

  Solution s;
  vector<int> result = s.findMode(node1);
  for (int item : result)
  {
    cout << item << " ";
  }
  cout << endl;
  return 0;
}
