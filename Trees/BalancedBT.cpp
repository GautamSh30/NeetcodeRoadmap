#include <iostream>

using namespace std;

//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int height(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int l = height(root->left);
        int r = height(root->right);

        if (l == -1 || r == -1)
            return -1;

        int ans = max(l, r) + 1;

        if (abs(l - r) > 1)
            return -1;

        return ans;
    }
    bool isBalanced(TreeNode *root)
    {
        return height(root) != -1;
    }
};
