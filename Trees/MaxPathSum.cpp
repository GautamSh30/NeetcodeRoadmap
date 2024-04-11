
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
    int helper(TreeNode *root, int &ans)
    {
        if (!root)
            return 0;

        int l = max(0, helper(root->left, ans));
        // max(0, ...) => if function give negative answer discard it
        int r = max(0, helper(root->right, ans));

        ans = max(ans, l + r + root->val); // stores maximum ans
        return root->val + max(l, r);
        // if right give max sum then take it or if left take then take that
    }

    int maxPathSum(TreeNode *root)
    {
        int ans = INT_MIN;
        helper(root, ans);
        return ans;
    }
};
