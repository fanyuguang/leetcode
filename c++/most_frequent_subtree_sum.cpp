#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits.h>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution {
public:
  vector<int> findFrequentTreeSum(TreeNode* root) {
    vector<int> sorted_frequent_count;
    unordered_map<int, int> sum_count;
    if (root == NULL) {
      return sorted_frequent_count;
    }
    RecurTreeSum(root, sum_count);
    int max = INT_MIN;
    for (pair<int, int> iter : sum_count) {
      if (iter.second >= max) {
        max = iter.second;
      }
    }
    for (pair<int, int> iter : sum_count) {
      if (iter.second == max) {
        sorted_frequent_count.push_back(iter.first);
      }
    }
    return sorted_frequent_count;
  }

private:
  int RecurTreeSum(TreeNode* node, unordered_map<int, int>& sum_count) {
    int sum = node->val;
    if (node->left != NULL) {
      sum += RecurTreeSum(node->left, sum_count);
    }
    if (node->right != NULL) {
      sum += RecurTreeSum(node->right, sum_count);
    }
    if (sum_count.find(sum) != sum_count.end()) {
      sum_count[sum]++;
    } else {
      sum_count[sum] = 1;
    }
    return sum;
  }
};

int main() {
  TreeNode* node1 = new TreeNode(5);
  TreeNode* node2 = new TreeNode(2);
  TreeNode* node3 = new TreeNode(-5);
  node1->left = node2;
  node1->right = node3;
  Solution s;
  vector<int> result = s.findFrequentTreeSum(node1);
  for (int num : result) {
    cout << num << endl;
  }
  return 0;
}
