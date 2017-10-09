#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left (NULL), right(NULL) {}
};

class Solution {
public:
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> level_order_node;
    if (root == NULL) {
      return level_order_node;
    }
    queue<TreeNode*> level;
    level.push(root);
    level.push(NULL);
    vector<int> temp_level;
    while (!level.empty()) {
      TreeNode* node = level.front();
      level.pop();
      if (node != NULL) {
        temp_level.push_back(node->val);
        if (node->left != NULL) {
          level.push(node->left);
        }
        if (node->right != NULL) {
          level.push(node->right);
        }
      } else {
        level_order_node.push_back(temp_level);
        temp_level.clear();
        if (!level.empty()) {
          level.push(NULL);
        }
      }
    }
    reverse(level_order_node.begin(), level_order_node.end());
    return level_order_node;
  }
};

int main() {
  TreeNode* node1 = new TreeNode(3);
  TreeNode* node2 = new TreeNode(9);
  TreeNode* node3 = new TreeNode(20);
  TreeNode* node4 = new TreeNode(15);
  TreeNode* node5 = new TreeNode(7);

  node1->left = node2;
  node1->right = node3;
  node3->left = node4;
  node3->right = node5;
  
  Solution S;
  vector<vector<int>> level_order_traversal = S.levelOrderBottom(node1);
  int i = level_order_traversal.size();
  for (auto level_iter : level_order_traversal) {
    cout << "level : " << i-- << endl;
    for (auto node_iter : level_iter) {
      cout << node_iter << endl;
    }
  }

  return 0;
}
