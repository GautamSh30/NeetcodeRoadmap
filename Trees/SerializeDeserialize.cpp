
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

class Codec
{
public:
    string serialize(TreeNode *root)
    {
        if (root == NULL)
            return "";

        string ans = "";
        queue<TreeNode *> q; // level order traversal

        q.push(root);
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();

            if (node == NULL)
                ans.append("*,"); // *=>NULL
            else
            {
                ans.append(to_string(node->val) + ',');
                q.push(node->left);
                q.push(node->right);
            }
        }
        return ans;
    }

    TreeNode *deserialize(string data)
    {
        if (data.length() == 0)
            return NULL;

        stringstream s(data); // associates a string object with a string allowing you to read string as if it were a stream
        string str;

        getline(s, str, ','); // first value -> root

        TreeNode *root = new TreeNode(stoi(str)); // string to integer

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {

            TreeNode *node = q.front();
            q.pop();

            getline(s, str, ','); // extracts char from i/p stream and append it to string object until delimiting char encountered

            if (str == "*")
                node->left = NULL;
            else
            {
                TreeNode *l = new TreeNode(stoi(str)); // root->left
                node->left = l;
                q.push(l);
            }

            getline(s, str, ',');

            if (str == "*")
                node->right = NULL;
            else
            {
                TreeNode *r = new TreeNode(stoi(str)); // root->right
                node->right = r;
                q.push(r);
            }
        }
        return root;
    }
};
