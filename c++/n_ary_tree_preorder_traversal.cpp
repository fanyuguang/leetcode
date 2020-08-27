#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Node
{
public:
  int val;
  vector<Node*> children;
  Node() {}
  Node (int _val) { val = _val; }
  Node (int _val, vector<Node*> _children) { val = _val; children = _children; }
};

class Solution
{
public:
  vector<int> preorder(Node* root)
  {
    vector<int> preorder_vals;

    stack<Node*> node_stack;
    if (root != NULL)
    {
      node_stack.push(root);
    }

    while (!node_stack.empty())
    {
      Node* node = node_stack.top();
      preorder_vals.push_back(node->val);
      node_stack.pop();
      for (auto iter = node->children.rbegin(); iter != node->children.rend(); iter++)
      {
        node_stack.push(*iter);
      }
    }

    return preorder_vals;
  }
};

int main()
{
  Node* node1 = new Node(1);
  Node* node2 = new Node(3);
  Node* node3 = new Node(2);
  Node* node4 = new Node(4);
  Node* node5 = new Node(5);
  Node* node6 = new Node(6);

  node1->children = {node2, node3, node4};
  node2->children = {node5, node6};

  Solution s;
  vector<int> result = s.preorder(node1);
  for (auto val : result)
  {
    cout << val << " ";
  }
  cout << endl;
  return 0;
}
