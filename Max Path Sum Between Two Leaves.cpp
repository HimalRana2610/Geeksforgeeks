#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

class Solution
{
public:
    int solve(Node *root, int &ans)
    {
        if (!root)
        {
            return 0;
        }
        if (!root->left && !root->right)
        {
            return root->data;
        }

        int left = solve(root->left, ans), right = solve(root->right, ans);
        if (root->left != NULL && root->right != NULL)
        {
            ans = max(ans, left + right + root->data);
            return max(left, right) + root->data;
        }

        if (root->left != NULL)
        {
            return left + root->data;
        }
        if (root->right != NULL)
        {
            return right + root->data;
        }
    }

    int maxPathSum(Node *root)
    {
        int ans = INT_MIN;
        solve(root, ans);

        if (ans == INT_MIN)
        {
            return -1;
        }

        return ans;
    }
};