#include <iostream>

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
  bool isSubtree(TreeNode* s, TreeNode* t)
  {
    return is_same_tree(s, t) || (s != NULL && (isSubtree(s->left, t) || isSubtree(s->right, t)));
  }

  bool is_same_tree(TreeNode* s, TreeNode* t)
  {
    if (s == NULL && t == NULL)
    {
      return true;
    }
    else if (s != NULL && t != NULL)
    {
      return s->val == t->val && is_same_tree(s->left, t->left) && is_same_tree(s->right, t->right);
    }
    else
    {
      return false;
    }
  }
};

int main()
{
  TreeNode* s_node1 = new TreeNode(3);
  TreeNode* s_node2 = new TreeNode(4);
  TreeNode* s_node3 = new TreeNode(5);
  TreeNode* s_node4 = new TreeNode(1);
  TreeNode* s_node5 = new TreeNode(2);

  TreeNode* t_node1 = new TreeNode(4);
  TreeNode* t_node2 = new TreeNode(1);
  TreeNode* t_node3 = new TreeNode(2);

  s_node1->left = s_node2;
  s_node1->right = s_node3;
  s_node2->left = s_node4;
  s_node2->right = s_node5;

  t_node1->left = t_node2;
  t_node1->right = t_node3;

  Solution s;
  bool result = s.isSubtree(s_node1, t_node1);
  if (result)
  {
    cout << "true" << endl;
  }
  else
  {
    cout << "false" << endl;
  }

  delete s_node1;
  delete s_node2;
  delete s_node3;
  delete s_node4;
  delete s_node5;
  delete t_node1;
  delete t_node2;
  delete t_node3;

  return 0;
}
