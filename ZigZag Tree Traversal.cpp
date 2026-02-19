#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
public:
    vector<int> zigZagTraversal(Node *root)
    {
        queue<Node *> q;
        q.push(root);

        vector<vector<int>> traversal;
        while (!q.empty())
        {
            vector<int> current;
            int n = q.size();

            while (n--)
            {
                Node *node = q.front();
                q.pop();

                current.push_back(node->data);
                if (node->left)
                {
                    q.push(node->left);
                }
                if (node->right)
                {
                    q.push(node->right);
                }
            }
            traversal.push_back(current);
        }

        vector<int> ans;
        for (int i = 0; i < traversal.size(); i++)
        {
            if (i % 2 == 0)
            {
                for (int j = 0; j < traversal[i].size(); j++)
                {
                    ans.push_back(traversal[i][j]);
                }
            }
            else
            {
                for (int j = traversal[i].size() - 1; j >= 0; j--)
                {
                    ans.push_back(traversal[i][j]);
                }
            }
        }

        return ans;
    }
};