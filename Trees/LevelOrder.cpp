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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans; // return value

        queue<TreeNode *> q; // level order => queue

        if (root == NULL)
            return ans; // empty tree => empty ans

        q.push(root); // initialize queue
        while (!q.empty())
        {
            int s = q.size(); // to run loop

            vector<int> lvl; // temp vector to be pushed in ans

            for (int i = 0; i < s; i++)
            {
                TreeNode *node = q.front(); // iske left aur right check karne h
                q.pop();

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);

                lvl.push_back(node->val);
            }

            ans.push_back(lvl);
        }
        return ans;
    }
};
