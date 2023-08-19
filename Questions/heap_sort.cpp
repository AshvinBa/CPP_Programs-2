/*
Heap Sort
Given an array of size N. The task is to sort the array elements by completing functions heapify() and buildHeap() which are used to implement Heap Sort.

Example 1:
Input:
N = 5
arr[] = {4,1,3,9,7}
Output:
1 3 4 7 9
Explanation:
After sorting elements
using heap sort, elements will be
in order as 1,3,4,7,9.

Example 2:
Input:
N = 10
arr[] = {10,9,8,7,6,5,4,3,2,1}
Output:
1 2 3 4 5 6 7 8 9 10
Explanation:
After sorting elements
using heap sort, elements will be
in order as 1, 2,3,4,5,6,7,8,9,10.

*/

#include <iostream>
using namespace std;
void heapify(int arr[], int n, int i)
{
    int large = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[large] < arr[left])
        large = left;

    if (right < n && arr[large] < arr[right])
        large = right;

    if (large != i)
    {
        swap(arr[large], arr[i]);
        heapify(arr, n, large);
    }
}
void buildHeap(int arr[], int n)
{
    for (int i = (n - 2) / 2; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}
void heapSort(int arr[], int n)
{
    buildHeap(arr, n);
    for (int i = n - 1; i >= 1; i--)
    {
        swap(arr[i], arr[0]);
        heapify(arr, i, 0);
    }
}

void print(int arr[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int n;
    cout << "Enter the size: ";
    cin >> n;
    int arr[n];
    cout << "Enter the values: ";
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    cout << "The sorted array is: ";
    heapSort(arr, n);
    print(arr, n);
    return 0;
}
/*
Approach:2
start from index - 1.

void heapify(int arr[],int n,int i)
{
    int largest=i;
    int left=2*i;
    int right=2*i-1;

    if(left<=n && arr[left]>arr[largest])
    {
        largest=left;
    }

    if(right<=n && arr[right]>arr[largest])
    {
        largest=right;
    }

    if(largest!=i)
    {
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}

void build_heap(int arr[],int n)
{
    for(int i=n/2;i>0;i--)
    {
        heapify(arr,n,i);
    }
}

void heap_sort(int arr[],int n)
{
    build_heap(arr,n);

    int size=n;
    while(size>1)
    {
        swap(arr[size],arr[1]);
        size--;
        heapify(arr,size,1);
    }
}


*/