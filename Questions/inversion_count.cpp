/*
Count Inversions
Given an array of integers. Find the Inversion Count in the array. 

Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If the array is already sorted then the inversion count is 0.
If an array is sorted in the reverse order then the inversion count is the maximum. 
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

Example 1:
Input: N = 5, arr[] = {2, 4, 1, 3, 5}
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 
has three inversions (2, 1), (4, 1), (4, 3).

Example 2:
Input: N = 5
arr[] = {2, 3, 4, 5, 6}
Output: 0
Explanation: As the sequence is already 
sorted so there is no inversion count.

Example 3:
Input: N = 3, arr[] = {10, 10, 10}
Output: 0
Explanation: As all the elements of array 
are same, so there is no inversion count.

Your Task:
You don't need to read input or print anything.
Your task is to complete the function inversionCount() which takes the array arr[] and the size of the array as inputs and returns the inversion count of the given array.

Expected Time Complexity: O(NLogN).
Expected Auxiliary Space: O(N).
Constraints:
1 ≤ N ≤ 5*105
1 ≤ arr[i] ≤ 1018

*/

#include<iostream>
using namespace std;

/*
//Approach = 1.
long long int inversionCount(long long arr[], long long N)
    {
        long long int cnt=0;
        
        for(long long int i=0;i<N;i++)
        {
            for(long  long int j=i+1;j<N;j++)
            {
                if(arr[i]>arr[j])
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
*/

long long int  merge1(long long arr[],long long temp[],int left,int mid,long long right)
    {
        long long int i,j,k,inv=0;
        i=left;
        j=mid;
        k=left;
        
        while((i<=mid-1)and(j<=right))
        {
            if(arr[i]<=arr[j])
            {
                temp[k++]=arr[i++];
            }
            else
            {
                temp[k++]=arr[j++];
                inv+=(mid-i);
            }
            
        }
        while(i<=mid-1)
        {
            temp[k++]=arr[i++];
        }
        while(j<=right)
        {
            temp[k++]=arr[j++];
        }
        for(int m=left;m<=right;m++)
        {
            arr[m]=temp[m];
        }
        return inv;
    }
    
    long long int mergeSort(long long arr[],long long temp[],int left,long long right)
    {
        long long int inv=0;
        
        if(left<right)
        {
            int mid=(left+right)/2;
            inv+=mergeSort(arr,temp,left,mid);
            inv+=mergeSort(arr,temp,mid+1,right);
            inv+=merge1(arr,temp,left,mid+1,right);
        }
        return inv;
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        long long temp[N];
        long long int n=mergeSort(arr,temp,0,N-1);
        return n;
    }

int main(){
    long long N=5;
    long long arr[]={2,4,1,3,5};
    cout<<"Answer: "<<inversionCount( arr, N);
return 0;
}