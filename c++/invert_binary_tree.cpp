#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode* invertTree(TreeNode* root)
    {
        if (root != NULL)
        {
            TreeNode *temp_node = root->left;
            root->left = root->right;
            root->right = temp_node;
        }
        else
        {
            return root;
        }
        if (root->left != NULL)
        {
            invertTree(root->left);
        }
        if (root->right != NULL)
        {
            invertTree(root->right);
        }
        return root;
    }

    void print(TreeNode* root)
    {
        if (root != NULL)
        {
            cout << root->val << endl;
        }
        if (root->left != NULL)
        {
            print(root->left);
        }
        if (root->right != NULL)
        {
            print(root->right);
        }
    }
};

int main()
{
    TreeNode *root = new TreeNode(4);
    TreeNode *node1 = new TreeNode(2);
    TreeNode *node2 = new TreeNode(7);
    TreeNode *node3 = new TreeNode(1);
    TreeNode *node4 = new TreeNode(3);
    TreeNode *node5 = new TreeNode(6);
    TreeNode *node6 = new TreeNode(9);
    
    root->left = node1;
    root->right = node2;
    node1->left = node3;
    node1->right = node4;
    node2->left = node5;
    node2->right = node6;
    
    Solution s;
    TreeNode * new_root = s.invertTree(root);
    s.print(new_root);
    delete root;
    delete node1;
    delete node2;
    delete node3;
    delete node4;
    delete node5;
    delete node6;
    return 0;
}
