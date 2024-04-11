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
    bool isValidBST(TreeNode *root)
    {
        return f(root, LLONG_MIN, LLONG_MAX); // keep track to minimum and maximum in traversal
    }
    bool f(TreeNode *root, long mn, long mx)
    {
        if (root == NULL)
            return true; // base case

        if (root->val >= mx || root->val <= mn)
            return false;
        return f(root->left, mn, root->val) && f(root->right, root->val, mx); // left me jaenge tab apna maximum root->val hi hoga aur right me jaenge tab apni max value to kitni bhi ho sakti h lekin apna minimum root->val to hoga hi
    }
};
