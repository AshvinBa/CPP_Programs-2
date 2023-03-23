/*
remaining number aftre intersection.
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int func(int arr1[], int arr2[], int n, int m)
{
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        s.insert(arr1[i]);
    }
    for (int j = 0; j < m; j++)
    {
        s.insert(arr2[j]);
    }
    cout << "\nNumber of Elements remain after insertion:\n";
    cout << s.size() << endl;
    cout << "\nUnion is: ";
    for (auto i = s.begin(); i != s.end(); i++)
    {
        cout << *i << " ";
    }
}
int main()
{
    int arr1[] = {2, 5, 6, 9, 5, 2, 2};
    int arr2[] = {5, 2, 3, 6, 8, 9, 5};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);
    func(arr1, arr2, n, m);
    return 0;
}
