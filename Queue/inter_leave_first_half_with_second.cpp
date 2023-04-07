// Approach 1.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void rotate(queue<int> q, int n)
{
    queue<int> q1;
    for (int i = 0; i < n / 2; i++)
    {
        int ele = q.front();
        q.pop();
        q1.push(ele);
    }

    while (!q1.empty())
    {
        int val1 = q1.front();
        q1.pop();
        q.push(val1);

        int val2 = q.front();
        q.pop();
        q.push(val2);
    }

    while (!q.empty())
    {
        int val = q.front();
        q.pop();
        cout << val << " ";
    }
}

int main()
{
    queue<int> q;
    int n;
    cout << "Enter the limit: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        q.push(ele);
    }
    rotate(q, n);

    return 0;
}

// Approach 2.

/*
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int rotate(queue<int> q, int n)
{
    stack<int> s;
    for (int i = 0; i < n / 2; i++)
    {
        int val = q.front();
        q.pop();
        s.push(val);
    }

    while (!s.empty())
    {
        int val = s.top();
        s.pop();
        q.push(val);
    }

    for (int i = 0; i < n / 2; i++)
    {
        int val = q.front();
        q.pop();
        q.push(val);
    }

    for (int i = 0; i < n / 2; i++)
    {
        int val = q.front();
        q.pop();
        s.push(val);
    }

    while (!s.empty())
    {
        int val1 = s.top();
        s.pop();
        q.push(val1);

        int val2 = q.front();
        q.pop();
        q.push(val2);
    }

    while (!q.empty())
    {
        int val = q.front();
        q.pop();
        cout << val << " ";
    }
}
int main()
{
    queue<int> q;
    int n;
    cout << "Enter the limit: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        q.push(ele);
    }
    rotate(q, n);
    return 0;
}

*/