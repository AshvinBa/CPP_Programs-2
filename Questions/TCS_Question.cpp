#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter the value: ";
    cin >> n;
    if (n % 2 == 1)
    {
        int term = (n + 1) / 2;
        int ans = pow(2, term - 1);
        cout << "Answer: " << ans;
    }
    else
    {
        int term = n / 2;
        int ans = pow(3, term - 1);
        cout << "Answer: " << ans;
    }

    return 0;
}