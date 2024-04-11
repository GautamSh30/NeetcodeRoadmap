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
    // inorder traversal of BST leads to sorted version of BST node->val
    void inorder(TreeNode *root, int &k, int &ans)
    {
        if (ans != -1)
            return; // ek baar ans update kar diya uske baad further update nhi karna padega
        if (root == NULL)
            return;

        inorder(root->left, k, ans);

        k--;
        if (k == 0)
        {
            ans = root->val;
            return;
        }

        inorder(root->right, k, ans);
    }
    int kthSmallest(TreeNode *root, int k)
    {
        int ans = -1;
        inorder(root, k, ans);
        return ans;
    }
};
