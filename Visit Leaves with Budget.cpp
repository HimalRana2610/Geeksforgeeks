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
        left = nullptr;
        right = nullptr;
    }
};

class Solution
{
public:
    int getCount(Node *root, int k)
    {
        int level = 1, ans = 0;
        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            int n = q.size();
            while (n--)
            {
                Node *node = q.front();
                q.pop();

                if (!node->left && !node->right)
                {
                    if (level <= k)
                    {
                        ans++;
                        k -= level;
                    }
                    else
                    {
                        return ans;
                    }
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
            level++;
        }

        return ans;
    }
};