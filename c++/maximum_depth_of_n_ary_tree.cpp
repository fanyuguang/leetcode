#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
  int val;
  vector<Node*> children;

  Node() {}
  Node(int _val) { val = _val; }
  Node(int _val, vector<Node*> _children) { val = _val; children = _children; }
};

class Solution
{
public:
  int maxDepth(Node* root)
  {
    if (root == NULL)
    {
      return 0;
    }

    int max_depth_of_sub_tree = 0;
    for (Node* node : root->children)
    {
      int current_depth = maxDepth(node);
      max_depth_of_sub_tree = max(max_depth_of_sub_tree, current_depth);
    }
    return max_depth_of_sub_tree + 1;
  }
};

int main()
{
  Node* node1 = new Node(1);
  Node* node2 = new Node(2);
  Node* node3 = new Node(3);
  Node* node4 = new Node(4);
  Node* node5 = new Node(5);
  Node* node6 = new Node(6);

  node1->children = {node2, node3, node4};
  node3->children = {node5, node6};

  Solution s;
  int max_depth = s.maxDepth(node1);
  cout << max_depth << endl;

  delete node1;
  delete node2;
  delete node3;
  delete node4;
  delete node5;
  delete node6;

  return 0;
}
