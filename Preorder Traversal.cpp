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
        left = right = NULL;
    }
};

class Solution
{
public:
    vector<int> preOrder(Node *root)
    {
        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }

        stack<Node *> st;
        st.push(root);

        while (!st.empty())
        {
            Node *node = st.top();
            st.pop();

            ans.push_back(node->data);
            if (node->right != NULL)
            {
                st.push(node->right);
            }
            if (node->left != NULL)
            {
                st.push(node->left);
            }
        }

        return ans;
    }
};