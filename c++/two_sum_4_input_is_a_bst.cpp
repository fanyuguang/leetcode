#include <iostream>
#include <unordered_set>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  bool findTarget(TreeNode* root, int k) {
    unordered_set<int> num_store;
    return is_finded(root, num_store, k);
  }

private:
  bool is_finded(TreeNode* node, unordered_set<int>& num_store, int k) {
    if (node == NULL) {
      return false;
    }
    if (num_store.find(k - node->val) != num_store.end()) {
      return true;
    } else {
      num_store.insert(node->val);
      return is_finded(node->left, num_store, k) || is_finded(node->right, num_store, k);
    }
  }
};

int main() {
  TreeNode* node1 = new TreeNode(5);
  TreeNode* node2 = new TreeNode(3);
  TreeNode* node3 = new TreeNode(6);
  TreeNode* node4 = new TreeNode(2);
  TreeNode* node5 = new TreeNode(4);
  TreeNode* node6 = new TreeNode(7);
  node1->left = node2;
  node1->right = node3;
  node2->left = node4;
  node2->right = node5;
  node3->right = node6;
  Solution s;
  bool result = s.findTarget(node1, 9);
  if (result) {
    cout << "true" << endl;
  } else {
    cout << "false" << endl;
  }
  delete node1;
  delete node2;
  delete node3;
  delete node4;
  delete node5;
  delete node6;
  return 0;
}
