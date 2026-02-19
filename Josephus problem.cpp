#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
public:
    int data;
    ListNode *prev;
    ListNode *next;

    ListNode(int x, ListNode *p = nullptr, ListNode *n = nullptr)
    {
        data = x;
        prev = p;
        next = n;
    }
};

class Solution
{
public:
    int josephus(int n, int k)
    {
        ListNode *head = new ListNode(1);
        ListNode *ptr = head;

        for (int i = 2; i <= n; i++)
        {
            ptr->next = new ListNode(i, ptr);
            ptr = ptr->next;
        }

        ptr->next = head;
        head->prev = ptr;

        while ((ptr->prev != ptr) && (ptr->next != ptr))
        {
            for (int i = 0; i < k; i++)
            {
                ptr = ptr->next;
            }

            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
        }

        return ptr->data;
    }
};