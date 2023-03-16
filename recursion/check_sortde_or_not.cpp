#include <iostream>
using namespace std;
bool func(int *arr, int n)
{
    if (n == 0 || n == 1)
        return true;

    if (arr[0] > arr[1])
    {
        return false;
    }
    else
    {
        bool remain = func(arr + 1, n - 1);
    }
}
int main()
{
    int arr[] = {2, 4, 51, 16, 27, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    bool ans = func(arr, n);
    if (ans)
    {
        cout << "Sorted.";
    }
    else
    {
        cout << "Unsortde.";
    }
    return 0;
}