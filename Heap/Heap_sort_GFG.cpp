/*

Heap Sort
MediumAccuracy: 53.06%Submissions: 107K+Points: 4
Fast-Track your resumes to top companies and get the job you deserve! Register for hiring challenge exclusively for working professionals 

banner
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
Your Task :
You don't have to read input or print anything. Your task is to complete the functions heapify(), buildheap() and heapSort() where heapSort() and buildheap() takes the array and it's size as input and heapify() takes the array, it's size and an index i as input. Complete and use these functions to sort the array using heap sort algorithm.
Note: You don't have to return the sorted list. You need to sort the array "arr" in place.

Expected Time Complexity: O(N * Log(N)).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ N ≤ 106
1 ≤ arr[i] ≤ 106

*/


#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i)  
    {
        int large=i;
        int left=2*i+1;
        int right=2*i+2;
        
        if(left<n && arr[left]>arr[large])
        large=left;
        
        if(right<n && arr[right]>arr[large])
        large=right;
        
        if(large!=i)
        {
            swap(arr[i],arr[large]);
            heapify(arr,n,large);
        }
    }
    //Function to build a Heap from array.
void buildHeap(int arr[], int n)  
    { 
        for(int i=(n-2)/2;i>=0;i--)
        heapify(arr,n,i);
    }
    //Function to sort an array using Heap Sort.
void heapSort(int arr[], int n)
    {
        buildHeap(arr,n);
        for(int i=n-1;i>=1;i--)
        {
            swap(arr[0],arr[i]);
            heapify(arr,i,0);
        }
    }

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main()
{
    int arr[1000000],n,T,i;
    cout<<"Teat cases: ";
    scanf("%d",&T);
    while(T--){
    cout<<"Size: ";    
    scanf("%d",&n);
    cout<<"Enter the values: ";
    for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
    
    heapSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}


















