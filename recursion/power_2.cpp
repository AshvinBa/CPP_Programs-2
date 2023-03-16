#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int func(int n)
{
    if (n == 0)
        return 1;

    return 2 * func(n - 1);
}
int main()
{
    int n;
    cout << "Enter the value: ";
    cin >> n;
    int power = func(n);
    cout << power;
    return 0;
}