#include <iostream>
#include <bits/stdc++.h>
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

void sorting(stack<int> &s, int num)
{
    if (s.empty() || (!s.empty() && s.top() < num))
    {
        s.push(num);
        return;
    }

    int ele = s.top();
    s.pop();

    sorting(s, num);

    s.push(ele);
}

void sort_Stack(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }

    int num = s.top();
    s.pop();

    sort_Stack(s);

    sorting(s, num);
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
    sort_Stack(s);
    reverse_st(s);
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}