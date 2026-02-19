#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = right = nullptr;
    }
};

class Solution
{
public:
    int nodeSum(Node *root, int l, int r)
    {
        int ans = 0;
        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            int n = q.size();
            while (n--)
            {
                Node *node = q.front();
                q.pop();

                if (node->data >= l && node->data <= r)
                {
                    ans += node->data;
                }

                if (node->left)
                {
                    q.push(node->left);
                }
                if (node->right)
                {
                    q.push(node->right);
                }
            }
        }

        return ans;
    }
};