#include <iostream>
#include <vector>
#include <string>

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
  vector<string> binaryTreePaths(TreeNode* root)
  {
    vector<string> paths;
    if (root != NULL)
    {
      tree_traversal(root, "", paths);
    }
    return paths;
  }

private:
  void tree_traversal(TreeNode *node, string path, vector<string>& paths)
  {
    if (node->left == NULL && node->right == NULL)
    {
      paths.push_back(path + to_string(node->val));
    }
    else
    {
      if (node->left != NULL)
      {
        tree_traversal(node->left, path + to_string(node->val) + "->", paths);
      }
      if (node->right != NULL)
      {
        tree_traversal(node->right, path + to_string(node->val) + "->", paths);
      }
    }
  }
};

int main()
{
  TreeNode* node1 = new TreeNode(1);
  TreeNode* node2 = new TreeNode(2);
  TreeNode* node3 = new TreeNode(3);
  TreeNode* node4 = new TreeNode(5);
  node1->left = node2;
  node1->right = node3;
  node2->right = node4;

  Solution s;
  vector<string> result = s.binaryTreePaths(node1);
  for (string item : result)
  {
    cout << item << endl;
  }

  delete node1;
  delete node2;
  delete node3;
  delete node4;
  return 0;
}
