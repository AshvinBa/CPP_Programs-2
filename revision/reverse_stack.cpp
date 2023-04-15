#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void reverse_Stack(stack<int> &s)
{
    stack<int>s1;
    while(!s.empty())
    {
        int ele=s.top();
        s.pop();
        s1.push(ele);
    }

    cout << "Answer: ";
    while (!s1.empty())
    {
        int val = s1.top();
        s1.pop();
        cout << val << " ";
    }
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

    reverse_Stack(s);
    return 0;
}

/*
Using recursion.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void insert_at_bottom(stack<int> &s, int ele)
{
    if (s.empty())
    {
        s.push(ele);
        return;
    }
    int top = s.top();
    s.pop();

    insert_at_bottom(s, ele);

    s.push(top);
}

void reverse_Stack(stack<int> &s)
{
    if(s.empty())
    return ;

    int ele=s.top();
    s.pop();

    reverse_Stack(s);
    insert_at_bottom(s,ele);
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

    reverse_Stack(s);

    cout << "Answer: ";
    while (!s.empty())
    {
        int val = s.top();
        s.pop();
        cout << val << " ";
    }
    return 0;
}
*/