#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  int findBottomLeftValue(TreeNode* root) {
    queue<TreeNode*> node_queue;
    node_queue.push(root);
    TreeNode* node;
    while (!node_queue.empty()) {
      node = node_queue.front();
      node_queue.pop();
      if (node->right != NULL) {
        node_queue.push(node->right);
      }
      if (node->left != NULL) {
        node_queue.push(node->left);
      }
    }
    return node->val;
  }
};

int main() {
  TreeNode* node1 = new TreeNode(1);
  TreeNode* node2 = new TreeNode(2);
  TreeNode* node3 = new TreeNode(3);
  TreeNode* node4 = new TreeNode(4);
  TreeNode* node5 = new TreeNode(5);
  TreeNode* node6 = new TreeNode(6);
  TreeNode* node7 = new TreeNode(7);
  node1->left = node2;
  node1->right= node3;
  node2->right = node4;
  node3->left = node5;
  node3->right = node6;
  node5->left = node7;
  Solution s;
  int result = s.findBottomLeftValue(node1);
  cout << result << endl;
  delete node1;
  delete node2;
  delete node3;
  delete node4;
  delete node5;
  delete node6;
  delete node7;
  return 0;
}
