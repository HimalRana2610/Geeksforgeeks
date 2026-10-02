#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int x)
    {
        data = x;
        left = right = nullptr;
    }
};

class Solution
{
public:
    bool areAnagrams(Node *root1, Node *root2)
    {
        if (!root1 || !root2)
        {
            return root1 == root2;
        }

        queue<Node *> q1, q2;
        q1.push(root1);
        q2.push(root2);

        while (!q1.empty() && !q2.empty())
        {
            int n1 = q1.size(), n2 = q2.size();
            if (n1 != n2)
            {
                return false;
            }

            unordered_map<int, int> freq;
            for (int i = 0; i < n1; i++)
            {
                Node *node1 = q1.front();
                Node *node2 = q2.front();

                q1.pop();
                q2.pop();

                freq[node1->data]++;
                freq[node2->data]--;

                if (node1->left != nullptr)
                {
                    q1.push(node1->left);
                }
                if (node1->right != nullptr)
                {
                    q1.push(node1->right);
                }
                if (node2->left != nullptr)
                {
                    q2.push(node2->left);
                }
                if (node2->right != nullptr)
                {
                    q2.push(node2->right);
                }
            }

            for (auto &f : freq)
            {
                if (f.second != 0)
                {
                    return false;
                }
            }
        }

        return q1.empty() && q2.empty();
    }
};