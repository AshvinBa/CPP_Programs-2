/*
Sort an array of 0s, 1s and 2s
Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.

Example 1:
Input: 
N = 5
arr[]= {0 2 1 2 0}
Output:
0 0 1 2 2
Explanation:
0s 1s and 2s are segregated 
into ascending order.

Example 2:
Input: 
N = 3
arr[] = {0 1 0}
Output:
0 0 1
Explanation:
0s 1s and 2s are segregated 
into ascending order.

Your Task:
You don't need to read input or print anything. Your task is to complete the function sort012() that takes an array arr and N as input parameters and sorts the array in-place.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 <= N <= 10^6
0 <= A[i] <= 2

*/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    void sort012(int arr[], int n)
    {
        int low=0;
        int mid=0;
        int high=n-1;
        
        while(mid<=high)
        {
            switch(arr[mid])
            {
                case 0:
                {
                    swap(arr[low++],arr[mid++]);
                }
                break;
                
                case 1:
                {
                    mid++;
                }
                break;
                
                case 2:
                {
                    swap(arr[mid],arr[high--]);
                }
                break;
            }
        }
    }
};
int main() {

    int t;

    cout<<"Enter the Number of test cases: ";
    cin >> t;

    while(t--){
        int n;
        cout<<"Enter the size: ";
        cin >>n;
        int a[n];
        cout<<"Enter the values: ";
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);
        cout<<"Answer: ";
        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }
        cout << endl;
    }
    return 0;
}


/*

void sort012(int arr[], int n)
    {
        long long a0[n],a1[n],a2[n];
        
        long long x=0,b=0,c=0;
        for(long long i=0;i<n;i++)
        {
            switch(arr[i])
            {
                case 0:
                {
                    a0[x++]=0;
                }
                break;
                case 1:
                {
                    a1[b++]=1;
                }
                break;
                case 2:
                {
                    a2[c++]=2;
                }
                break;
            }
        }
        
        long long i=0;
        while(x>0)
        {
            arr[i]=0;
            i++;
            x--;
        }
        while(b>0)
        {
            arr[i]=1;
            i++;
            b--;
        }
        while(c>0)
        {
            arr[i]=2;
            i++;
            c--;
        }
    }

*/