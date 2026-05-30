#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int item)
    {
        data = item;
        left = nullptr;
        right = nullptr;
    }
};

class Solution
{
public:
    vector<int> verticalSum(Node *root)
    {
        queue<pair<Node *, int>> q;
        q.push({root, 0});

        unordered_map<int, int> sum;
        while (!q.empty())
        {
            int n = q.size();
            while (n--)
            {
                Node *node = q.front().first;
                int pos = q.front().second;
                q.pop();

                sum[pos] += node->data;
                if (node->left)
                {
                    q.push({node->left, pos - 1});
                }
                if (node->right)
                {
                    q.push({node->right, pos + 1});
                }
            }
        }

        vector<pair<int, int>> sum_vec(sum.begin(), sum.end());
        sort(sum_vec.begin(), sum_vec.end(), [](const pair<int, int> &a, const pair<int, int> &b)
             { return a.first < b.first; });

        vector<int> ans;
        for (int i = 0; i < sum_vec.size(); i++)
        {
            ans.push_back(sum_vec[i].second);
        }

        return ans;
    }
};