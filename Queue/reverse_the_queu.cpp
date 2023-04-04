#include <iostream>
#include <bits/stdc++.h>
using namespace std;

queue<int> reverse_que(queue<int> &s, int n)
{
    stack<int> s1;

    while (!s.empty())
    {
        int ele = s.front();
        s.pop();
        s1.push(ele);
    }

    while (!s1.empty())
    {
        int ele1 = s1.top();
        s1.pop();
        s.push(ele1);
    }
    return s;
}
int main()
{
    queue<int> s;
    int n;
    cout << "Entre the limit: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        s.push(ele);
    }
    queue<int> i = reverse_que(s, n);

    while (!i.empty())
    {
        int t = i.front();
        cout << t << " ";
        i.pop();
    }
    return 0;
}
