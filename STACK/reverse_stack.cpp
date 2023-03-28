#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void rev(stack<int> &s, int num)
{
    if (s.empty())
    {
        s.push(num);
        return;
    }

    int ele = s.top();
    s.pop();

    rev(s, num);

    s.push(ele);
}

void reverse_st(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }

    int n = s.top();
    s.pop();

    reverse_st(s);

    rev(s, n);
}

int main()
{
    int n;
    cout << "Enter the limit: ";
    cin >> n;
    stack<int> s;
    int ele;
    cout << "Enter an element: ";
    for (int i = 0; i < n; i++)
    {
        cin >> ele;
        s.push(ele);
    }
    reverse_st(s);
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}