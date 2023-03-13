#include <iostream>
using namespace std;
int search(int *arr, int n, int x)
{
    int low = 0;
    int high = n - 1;
    int mid = (low + high) / 2;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (arr[mid] == x)
        {
            return mid;
        }
        else if (arr[mid] < x)
        {
            low = mid + 1;
        }
        else if (arr[mid] > x)
        {
            high = mid - 1;
        }
    }
}
int main()
{
    int n, arr[100];
    cout << "Enter the size: ";
    cin >> n;
    cout << "Enter the values: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int x;
    cout << "\nEnter the Element for search: ";
    cin >> x;
    int ans = search(arr, n, x);
    cout << "\nThe index is: " << ans;
    return 0;
}