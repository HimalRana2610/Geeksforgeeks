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
    void traverse(Node *node, vector<int> &inorder)
    {
        if (!node)
        {
            return;
        }

        traverse(node->left, inorder);
        inorder.push_back(node->data);
        traverse(node->right, inorder);
    }

    vector<int> getKClosest(Node *root, int target, int k)
    {
        vector<int> inorder;
        traverse(root, inorder);

        int index = lower_bound(inorder.begin(), inorder.end(), target) - inorder.begin();
        vector<int> ans;

        int left = index - 1, right = index;
        while (k--)
        {
            if (left < 0)
            {
                ans.push_back(inorder[right++]);
            }
            else if (right >= inorder.size())
            {
                ans.push_back(inorder[left--]);
            }
            else if (abs(inorder[left] - target) <= abs(inorder[right] - target))
            {
                ans.push_back(inorder[left--]);
            }
            else
            {
                ans.push_back(inorder[right++]);
            }
        }

        return ans;
    }
};