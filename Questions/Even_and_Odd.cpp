/*
Even and Odd
Given an array arr[] of size N containing equal number of odd and even numbers. Arrange the numbers in such a way that all the even numbers get the even index and odd numbers get the odd index.
Note: There are multiple possible solutions, Print any one of them. Also, 0-based indexing is considered.
Example 1:
Input:
N = 6
arr[] = {3, 6, 12, 1, 5, 8}
Output:
1
Explanation:
6 3 12 1 8 5 is a possible solution.
The output will always be 1 if your
rearrangement is correct.

Example 2:
Input:
N = 4
arr[] = {1, 2, 3, 4}
Output :
1

*/

#include<iostream>
using namespace std;
void reArrange(int a[], int n) {
    
        int o=1;
        int e=0;
        while(1)
        {
            while(e<n && a[e]%2==0)
            {
                e+=2;
            }
            while(o<n && a[o]%2==1)
            {
                o+=2;
            }
            
            if(e<n && o<n)
            {
                swap(a[e],a[o]);
            }
            else
            {
                break;
            }
        }
    }
    int main()
    {
        int n = 6;
        int a[] = {3, 6, 12, 1, 5, 8};
        reArrange(a,n);
        cout<<"\n Answer: ";
        for(int i=0;i<n;i++)
        {
            cout<<a[i]<<" ";
        }
        return 0;
    }



/*
void reArrange(int arr[], int N) {
        int E[N];
        int O[N];
        int j=0,k=0;
        for(int i=0;i<N-1;i++)
        {
            if(arr[i]%2==0)
            {
                E[j++]=arr[i];
            }
            else
            {
                O[k++]=arr[i];
            }
        }
        j=0;k=0;
        for(int i=0;i<N;i++)
        {
            if(i%2==0)
            {
                arr[i]=E[j++];
            }
            else
            {
                arr[i]=O[k++];
            }
        }
    }

*/