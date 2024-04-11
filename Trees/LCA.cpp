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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root)
            return NULL;

        // agar ancestor h to ek se >= to hona chaiye aur ek se <= hona chaiye
        /*

            ans                     (ans=p)              (ans=p)
            /  \                     /                       \
           p    q                   q                          q

         */

        int cur = root->val;
        if (cur < p->val && cur < q->val)
        {
            return lowestCommonAncestor(root->right, p, q); // badi value ke liye check hoga
        }
        else if (cur > p->val && cur > q->val)
        {
            return lowestCommonAncestor(root->left, p, q); // choti value ke liye check hoga
        }
        return root;
    }
};
