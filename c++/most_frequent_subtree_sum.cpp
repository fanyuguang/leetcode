#include <iosteam>
#include <vector>

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
    RecurTreeSum(root, sum_count);
  }
private:
  int RecurTreeSum(TreeNode* node, unordered_map<int, int>& sum_count) {

  }
};

int main() {
  TreeNode node1 = new TreeNode(5);
  TreeNode node2 = new TreeNode(2);
  TreeNode node3 = new TreeNode(-3);
  node1->left = node2;
  node1->right = node3;
  Solution s;
  vector<int> result = s.findFrequentTreeSum(node1);
  for (int num : result) {
    cout << num << endl;
  }
  return 0;
}
