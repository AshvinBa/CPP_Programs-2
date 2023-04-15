#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void insert_at_bottom(stack<int> &s, int x, int n)
{
    if (s.empty())
    {
        s.push(x);
        return;
    }
    int top = s.top();
    s.pop();

    insert_at_bottom(s, x, n);

    s.push(top);
}
stack<int> bottom(stack<int> &s, int x, int n)
{
    insert_at_bottom(s, x, n);
    return s;
}

int main()
{
    stack<int> s;
    int n = 5;
    cout << "Enter the values: ";
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        s.push(ele);
    }
    int x = 0;

    insert_at_bottom(s, x, n);

    cout << "Answer: ";
    while (!s.empty())
    {
        int val = s.top();
        s.pop();
        cout << val << " ";
    }
    return 0;
}