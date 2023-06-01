#include <iostream>
#include <bits\stdc++.h>
using namespace std;

int minSwap(vector<int> &arr, int n)
{
    
    for (int i = 0; i < n; i++)
    {
        int l = 0;
        int r = l + 1;
        while (l < n)
        {
            if (arr[l] > arr[r])
            {
                swap(arr[l++], arr[r++]);
            }
            l++;
            r++;
        }
    }
}

int main()
{
    cout << "Array: ";
    vector<int> arr{10, 19, 6, 3, 5};
    int n = arr.size();

    minSwap(arr, n);
    cout << "\nArray: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
