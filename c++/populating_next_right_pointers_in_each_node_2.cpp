#include <iostream>

using namespace std;

struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
  void connect(TreeLinkNode *root) {
    TreeLinkNode* current_node = root;
    while (current_node != NULL) {
      TreeLinkNode* level_node = current_node;
      TreeLinkNode* next_level_pre = NULL;
      while (level_node != NULL) {
        if (level_node->left != NULL) {
          if (next_level_pre != NULL) {
            next_level_pre->next = level_node->left;
          }
          next_level_pre = level_node->left;
        }
        if (level_node->right != NULL) {
          if (next_level_pre != NULL) {
            next_level_pre->next = level_node->right;
          }
          next_level_pre = level_node->right;
        }
        level_node = level_node->next;
      }
      while (current_node != NULL && current_node->left == NULL && current_node->right == NULL) {
        current_node = current_node->next;
      }
      if (current_node != NULL) {
        current_node = current_node->left != NULL ? current_node->left : current_node->right;
      }
    }
  }
};

int main() {
  TreeLinkNode* node1 = new TreeLinkNode(1);
  TreeLinkNode* node2 = new TreeLinkNode(2);
  TreeLinkNode* node3 = new TreeLinkNode(3);
  TreeLinkNode* node4 = new TreeLinkNode(4);
  TreeLinkNode* node5 = new TreeLinkNode(5);
  TreeLinkNode* node6 = new TreeLinkNode(7);
  node1->left = node2;
  node1->right = node3;
  node2->left = node4;
  node2->right = node5;
  node3->right = node6;
  Solution s;
  s.connect(node1);
  TreeLinkNode* node = node1;
  while (node != NULL) {
    TreeLinkNode* level_node = node;
    while (level_node != NULL) {
      cout << level_node->val << " ";
      level_node = level_node->next;
    }
    cout << endl;
    while (node != NULL && node->left == NULL && node->right == NULL) {
      node = node->next;
    }
    if (node != NULL) {
      node = node->left != NULL ? node->left : node->right;
    }
  }
  delete node1;
  delete node2;
  delete node3;
  delete node4;
  delete node5;
  delete node6;
  return 0;
}
