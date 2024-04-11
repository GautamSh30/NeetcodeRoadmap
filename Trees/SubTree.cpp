
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
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (!subRoot)
            return true;
        if (!root)
            return false;

        if (sameTree(root, subRoot))
            return true;

        return (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot));
    }

    bool sameTree(TreeNode *a, TreeNode *b)
    {
        if (!a || !b)
            return (a == b);

        return (a->val == b->val && sameTree(a->left, b->left) && sameTree(a->right, b->right));
    }
};
