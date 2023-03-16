#include <iostream>
using namespace std;

int func(int arr[], int n)
{
    if (n == 0)
        return 0;
    cout << arr[0] << " ";
    func(arr + 1, n - 1);
}

bool func(int *arr, int n, int x)
{

    if (n == 0)
    {
        return false;
    }

    if (arr[0] == x)
    {
        return true;
    }

    else
    {
        bool remain = func(arr + 1, n - 1, x);
    }
}

int main()
{
    int arr[] = {11, 21, 31, 51, 41, 61, 81, 71};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x;

    func(arr, n);

    cout << "\nEnter the no. for search: " << endl;
    cin >> x;
    bool ans = func(arr, n, x);
    if (ans)
    {
        cout << "yes found";
    }
    else
    {
        cout << "not found";
    }
    return 0;
}