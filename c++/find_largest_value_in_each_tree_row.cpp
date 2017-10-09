#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  vector<int> largestValues(TreeNode* root) {
    vector<int> values;
    find_largest(root, values, 0);
    return values;
  }

private:
  void find_largest(TreeNode* node, vector<int>& values, int depth) {
    if (node == NULL) {
      return;
    }
    if (values.size() < depth + 1) {
      values.push_back(node->val);
    } else {
      if (values[depth] < node->val) {
        values[depth] = node->val;
      }
    }
    if (node->left) {
      find_largest(node->left, values, depth+1);
    }
    if (node->right) {
      find_largest(node->right, values, depth+1);
    }
  }
};

int main() {
  TreeNode* node1 = new TreeNode(1);
  TreeNode* node2 = new TreeNode(3);
  TreeNode* node3 = new TreeNode(2);
  TreeNode* node4 = new TreeNode(5);
  TreeNode* node5 = new TreeNode(3);
  TreeNode* node6 = new TreeNode(9);
  node1->left = node2;
  node1->right = node3;
  node2->left = node4;
  node2->right = node5;
  node3->right = node6;
  Solution s;
  vector<int> result = s.largestValues(node1);
  for (int num : result) {
    cout << num << endl;
  }
  delete node1;
  delete node2;
  delete node3;
  delete node4;
  delete node5;
  delete node6;
  return 0;
}
