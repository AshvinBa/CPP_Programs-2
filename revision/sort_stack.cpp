#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void sorting(stack<int> &s, int ele)
{
    if (s.empty() || (!s.empty() && s.top() < ele))
    {
        s.push(ele);
        return;
    }
    int top = s.top();
    s.pop();

    sorting(s, ele);
    s.push(top);
}

void sortit(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }

    int ele = s.top();
    s.pop();

    sortit(s);

    sorting(s, ele);
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
    sortit(s);
    cout << "Answer: ";
    while (!s.empty())
    {
        int val = s.top();
        s.pop();
        cout << val << " ";
    }

    return 0;
}
