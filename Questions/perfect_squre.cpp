#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter the values: ";
    cin >> n;
    int s = sqrt(n);
    int x = s * s;
    if (n == x)
    {
        cout << "Yes its perfect Squre.";
    }
    else
    {
        cout << "Not perfect Squre.";
    }
    return 0;
}