#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
  int val;
  int smaller_count;
  int duplicated;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int v, int s) : val(v), smaller_count(s), duplicated(1), left(NULL), right(NULL) {}
};

class Solution {
public:
  vector<int> countSmaller(vector<int>& nums) {
    vector<int> smaller(nums.size(), 0);
    vector<int> binary_nums;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
      int p = 0;
      int q = binary_nums.size();
      while (p < q)
      {
        int mid = (p + q) / 2;
        if (nums[i] <= binary_nums[mid])
        {
          q = mid;
        }
        else
        {
          p = mid + 1;
        }
      }
      binary_nums.insert(binary_nums.begin() + q, nums[i]);
      smaller[i] = q;
    }
    return smaller;
  }

  vector<int> countSmaller2(vector<int>& nums) {
    vector<int> smaller(nums.size(), 0);
    TreeNode* root = NULL;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
      int current_smaller = insert(root, nums[i]);
      smaller[i] = current_smaller;
    }
    return smaller;
  }

private:
  int insert(TreeNode*& node, int num)
  {
    if (node == NULL)
    {
      node = new TreeNode(num, 0);
      return 0;
    }
    if (num < node->val)
    {
      node->smaller_count++;
      return insert(node->left, num);
    }
    else if (num > node->val)
    {
      return insert(node->right, num) + node->smaller_count + node->duplicated;
    }
    else
    {
      node->duplicated++;
      return node->smaller_count;
    }
  }
};

int main()
{
  Solution s;
  vector<int> nums = {5, 2, 6, 1};
  // vector<int> nums;
  // vector<int> nums = {26,78,27,100,33,67,90,23,66,5,38,7,35,23,52,22,83,51,98,69,81,32,78,28,94,13,2,97,3,76,99,51,9,21,84,66,65,36,100,41};
  vector<int> result = s.countSmaller2(nums);
  for (int item : result)
  {
    cout << item << " ";
  }
  cout << endl;
  return 0;
}
