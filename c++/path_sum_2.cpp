#include <iostream>
#include <vector>
#include <stack>

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
  vector<vector<int> > pathSum(TreeNode* root, int sum)
  {
    vector<vector<int> > paths;
    vector<int> nodes;
    int current_sum = 0;
    sum_recursion(root, nodes, paths,current_sum, sum);
    return paths;
  }

private:
  void sum_recursion(TreeNode* node, vector<int>& nodes, vector<vector<int> >& paths, int current_sum, int sum)
  {
    if (node == NULL)
    {
      return;
    }

    current_sum += node->val;
    nodes.push_back(node->val);
    if (node->left == NULL && node->right == NULL && current_sum == sum)
    {
      paths.push_back(nodes);
    }
    sum_recursion(node->left, nodes, paths, current_sum, sum);
    sum_recursion(node->right, nodes, paths, current_sum, sum);

    current_sum -= node->val;
    nodes.pop_back();
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
  TreeNode* node9 = new TreeNode(5);
  TreeNode* node10 = new TreeNode(1);
  node1->left = node2;
  node1->right = node3;
  node2->left = node4;
  node3->left = node5;
  node3->right = node6;
  node4->left = node7;
  node4->right = node8;
  node6->left = node9;
  node6->right = node10;

  Solution s;
  vector<vector<int> > result = s.pathSum(node1, 22);
  for (vector<int> items : result)
  {
    for (int item : items)
    {
      cout << item << " ";
    }
    cout << endl;
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
  return 0;
}
