#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int insertion(int arr[], int n, int index, int ele, int capacity)
{
    if (capacity < n)
        return -1;

    for (int i = n; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = ele;
    return 1;
}

int display(int arr[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[100];
    int n, ele, index;
    cout << "Enter the size of array: ";
    cin >> n;
    cout << "Enter the values: ";

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the element for insert: ";
    cin >> ele;
    cout << "Enter at what index want to insert: ";
    cin >> index;

    insertion(arr, n, index, ele, 100);
    n++;
    display(arr, n);
    return 0;
}