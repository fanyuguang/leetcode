#include <iostream>
#include <vector>
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
  vector<double> averageOfLevels(TreeNode* root) {
    int num_count = 1;
    double num_sum = (double)root->val;
    vector<double> average_nums;
    queue<TreeNode*> node_queue;
    node_queue.push(root);
    while (num_count > 0) {
      average_nums.push_back(num_sum / num_count);
      num_sum = 0;
      int num_count_copy = num_count;
      num_count = 0;
      for (int i = 0; i < num_count_copy; i++) {
        TreeNode* node = node_queue.front();
        node_queue.pop();
        if (node->left != NULL) {
          node_queue.push(node->left);
          num_count++;
          num_sum += (double)node->left->val;
        }
        if (node->right != NULL) {
          node_queue.push(node->right);
          num_count++;
          num_sum += (double)node->right->val;
        }
      }
    }
    return average_nums;
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
  Solution s;
  vector<double> result = s.averageOfLevels(node1);
  for (double num : result) {
    cout << num << endl;
  }
  delete node1;
  delete node2;
  delete node3;
  delete node4;
  delete node5;
  return 0;
}
