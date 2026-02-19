#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    Node *mergeKLists(vector<Node *> &arr)
    {
        vector<int> nums;
        for (int i = 0; i < arr.size(); i++)
        {
            while (arr[i])
            {
                nums.push_back(arr[i]->data);
                arr[i] = arr[i]->next;
            }
        }

        sort(nums.begin(), nums.end());
        Node *ans = new Node(nums[0]);
        Node *ptr = ans;

        for (int i = 1; i < nums.size(); i++, ptr = ptr->next)
        {
            ptr->next = new Node(nums[i]);
        }

        return ans;
    }
};