/*
Sort an array of 0s, 1s and 2s
EasyAccuracy: 50.58%Submissions: 597K+Points: 2
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
#include<iostream>
using namespace std;

void sort012(int a[], int n)
    {
        int cnt0=0,cnt1=0,cnt2=0;
        
        for(int i=0;i<n;i++)
        {
            switch(a[i])
            {
                case 0:
                {
                    cnt0++;
                }
                break;
                case 1:
                {
                    cnt1++;
                }
                break;
                case 2:
                {
                    cnt2++;
                }
                break;
            }
        }
        int k=0;
        while(cnt0--)
        {
            a[k++]=0;
        }
        while(cnt1--)
        {
            a[k++]=1;
        }
        while(cnt2--)
        {
            a[k++]=2;
        }
    }
int main(){
    int n=5;
    int a[]={2,2,1,0,1};
    sort012(a,n);
    cout<<"Answer: ";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
return 0;
}