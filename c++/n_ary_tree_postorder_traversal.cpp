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
  vector<int> postorder(Node* root)
  {
    vector<int> postorder_vals;

    stack<Node*> node_stack;
    Node* current = root;
    Node* pre = NULL;

    while (current != NULL || !node_stack.empty())
    {
      while (current != NULL)
      {
        node_stack.push(current);
        current = current->children.empty() ? NULL : current->children[0];
      }

      current = node_stack.top();
      if (current->children.empty() || pre == current->children[current->children.size() - 1])
      {
        postorder_vals.push_back(current->val);
        node_stack.pop();
        pre = current;
        current = NULL;
      }
      else
      {
        int i = 0;
        while (i < current->children.size() && pre != current->children[i])
        {
          i++;
        }
        current = current->children[++i];
      }
    }

    return postorder_vals;
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
  vector<int> result = s.postorder(node1);
  for (auto val : result)
  {
    cout << val << " ";
  }
  cout << endl;
  return 0;
}
