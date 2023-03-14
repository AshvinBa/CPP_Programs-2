#include<bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
    int arr[] = { 2 , 2 , 2 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int i = 0;
    int j = n - 1;
    int x;
    cout << "Enter the digit: ";
    cin >> x;
    int occurence = 0;
    while (i < j)
    {
        if (abs(arr[i] + arr[j]) < x)
        {
            i++;
        }
        else if (abs(arr[i] + arr[j]) > x)
        {
            j--;
        }
        else if (abs(arr[i] + arr[j]) == x)
        {
            i++;
            j--;
            occurence++;
        }
    }

    cout << "\nTHE OCCURENCE IS: " << occurence << endl;
    return 0;
}