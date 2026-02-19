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
        next = nullptr;
    }
};

class Solution
{
public:
    Node *segregate(Node *head)
    {
        vector<int> freq(3, 0);
        Node *ptr = head;

        while (ptr)
        {
            freq[ptr->data]++;
            ptr = ptr->next;
        }

        ptr = head;
        while (ptr)
        {
            if (freq[0] > 0)
            {
                ptr->data = 0;
                freq[0]--;
            }
            else if (freq[1] > 0)
            {
                ptr->data = 1;
                freq[1]--;
            }
            else
            {
                ptr->data = 2;
                freq[2]--;
            }
            ptr = ptr->next;
        }

        return head;
    }
};