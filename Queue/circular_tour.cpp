#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int tour(int pet[], int dis[], int n)
{
    int deficit = 0;
    int balance = 0;
    int start = 0;

    for (int i = 0; i < n; i++)
    {
        balance += pet[i] - dis[i];
        if (balance < 0)
        {
            deficit += balance;
            start = i + 1;
            balance = 0;
        }
    }
    if (deficit + balance >= 0)
        return start;
    else
    {
        return -1;
    }
}
int main()
{
    int n;
    cout << "Enter the limit: ";
    cin >> n;
    int pet[n], dis[n];
    cout << "Enter the values for petrol: ";
    for (int i = 0; i < n; i++)
    {
        cin >> pet[i];
    }
    cout << "Enter the values for Distance: ";
    for (int i = 0; i < n; i++)
    {
        cin >> dis[i];
    }
    cout << "\nThe answer: " << tour(pet, dis, n);
    return 0;
}