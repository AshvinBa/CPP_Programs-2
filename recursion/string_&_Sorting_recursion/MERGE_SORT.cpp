#include <iostream>
using namespace std;

void merge_the_arrays(int *arr, int s, int e)
{
    int mid = (s + e) / 2;

    int l1 = mid - s + 1;
    int l2 = e - mid;

    int *first = new int[l1];
    int *second = new int[l2];

    int mainArrayindex = s;
    for (int i = 0; i < l1; i++)
    {
        first[i] = arr[mainArrayindex++];
    }

    mainArrayindex = mid + 1;
    for (int i = 0; i < l2; i++)
    {
        second[i] = arr[mainArrayindex++];
    }

    int index1 = 0;
    int index2 = 0;
    mainArrayindex = s;

    while (index1 < l1 && index2 < l2)
    {
        if (first[index1] < second[index2])
        {
            arr[mainArrayindex++] = first[index1++];
        }
        else
        {
            arr[mainArrayindex++] = second[index2++];
        }
    }
    while (index1 < l1)
    {
        arr[mainArrayindex++] = first[index1++];
    }
    while (index2 < l2)
    {
        arr[mainArrayindex++] = second[index2++];
    }

    delete[] first;
    delete[] second;
}

void merge_sorting(int *arr, int s, int e)
{
    int mid = (s + e) / 2;

    if (s >= e)
        return;

    merge_sorting(arr, s, mid);

    merge_sorting(arr, mid + 1, e);

    merge_the_arrays(arr, s, e);
}

int main()
{
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    merge_sorting(arr, 0, n - 1);

    cout << "\nThe sorted array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
    return 0;
}

/*
TIME COMPLEXITY = O(NlogN).
SPACE COMPLEXITY = O(N).
*/