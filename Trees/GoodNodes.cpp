
#include <bits/stdc++.h>

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
    void dfs(TreeNode *root, int &ans, int a)
    {
        if (root == NULL)
            return;

        if (root->val >= a)
        {
            ans++;
            a = root->val;
        }

        if (root->left)
            dfs(root->left, ans, a);
        if (root->right)
            dfs(root->right, ans, a);
    }
    int goodNodes(TreeNode *root)
    {
        int ans = 0, a = INT_MIN;
        dfs(root, ans, a);
        return ans;
    }
};
