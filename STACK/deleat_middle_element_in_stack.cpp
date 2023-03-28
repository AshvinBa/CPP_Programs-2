#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void solve(stack<int> &s, int count, int x)
{
    if (count == x / 2)
    {
        s.pop();
        return;
    }

    solve(s, count + 1, x);
}
int main()
{
    stack<int> s;
    vector<int> vec{1, 2, 3, 4, 5, 6, 7};
    for (int i = 0; i < vec.size(); i++)
    {
        s.push(vec[i]);
    }
    int x = s.size();
    cout << x;
    int count = 0;
    solve(s, count, x);
    cout << "\nAnswer: ";

    return 0;
}