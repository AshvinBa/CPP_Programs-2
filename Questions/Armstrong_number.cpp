#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter the number: ";
    cin >> n;
    int t = n;
    int ans = 0;
    int count = 0;
    int digit = 0;
 
    while (t != 0)
    {
        digit = t % 10;
        count++;
        t = t / 10;
    }
    t = n;
    if (count > 3)
    {
        while (t != 0)
        {
            digit = t % 10;
            ans = ans + pow(digit, count);
            t = t / 10;
        }
    }
    else
    {
        while (t != 0)
        {
            digit = t % 10;
            ans += digit * digit * digit;
            t = t / 10;
        }
    }
    if (ans == n)
    {
        cout << "\nArmstrog number.";
    }
    else
    {
        cout << "\nNot Armstrong number.";
    }
    return 0;
}