#include <bits/stdc++.h>
using namespace std;

class SpecialQueue
{
    queue<int> q;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;

public:
    void enqueue(int x)
    {
        q.push(x);
        minHeap.push(x);
        maxHeap.push(x);
    }

    void dequeue()
    {
        int x = q.front();
        q.pop();

        vector<int> temp;
        while (minHeap.top() != x)
        {
            temp.push_back(minHeap.top());
            minHeap.pop();
        }

        minHeap.pop();
        for (int i = 0; i < temp.size(); i++)
        {
            minHeap.push(temp[i]);
        }

        temp.clear();
        while (maxHeap.top() != x)
        {
            temp.push_back(maxHeap.top());
            maxHeap.pop();
        }

        maxHeap.pop();
        for (int i = 0; i < temp.size(); i++)
        {
            maxHeap.push(temp[i]);
        }
    }

    int getFront()
    {
        return q.front();
    }

    int getMin()
    {
        return minHeap.top();
    }

    int getMax()
    {
        return maxHeap.top();
    }
};