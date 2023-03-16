
#include <iostream>
using namespace std;
int func(int *arr, int n, int s, int e)
{

    if (s >= e)
    {
        return -1;
    }

    int m = (s + e) / 2;

    if (arr[m] < arr[m + 1])
    {
        return s = m + 1;
        return func(arr, n, s , e);
    }
    else if (arr[m] > arr[m + 1])
    {
        e = m;
        return func(arr, n, s, e );
    }
}
int main()
{
    int arr[] = {2, 3, 4, 6, 7, 8, 10, 7, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Index: " << func(arr, n, 0, n - 1);
    return 0;
}