/*
Smallest subarray with sum greater than x
Given an array of integers (A[])  and a number x, find the smallest subarray with sum greater than the given value. If such a subarray do not exist return 0 in that case.

Example 1:
Input:
A[] = {1, 4, 45, 6, 0, 19}
x  =  51
Output: 3
Explanation:
Minimum length subarray is 
{4, 45, 6}

Example 2:
Input:
A[] = {1, 10, 5, 2, 7}
   x  = 9
Output: 1
Explanation:
Minimum length subarray is {10}

*/


/*
int Subarray(int arr[],int n,int x)
{
    int ans=0;
    int mi=INT16_MAX;
    for(int i=0;i<n;i++)
    {
        ans=0;
        for(int j=i;j<n;j++)
        {
            ans+=arr[i];
            if(ans>x)
            {
                mi=min(mi,j-i+1);
            }
        }
    }
    return mi;
}
*/

 //Bugs Occure at test case '139'.
/*
int smallestSubWithSum(int arr[], int n, int x)
    {
    int i=0;
    int j=0;
    int ans=0;
    int mi=INT_MAX;
    
    while(i<=j and j<n)
    {
        while(ans<=x and j<n)
        {
            ans+=arr[j++];
        }
        while(ans>x and i<j)
        {
            mi=min(mi,j-i);
            ans-=arr[i];
            i++;
        }
    }
    return mi;
    }

*/
/*
int Subarray(int arr[],int n,int x)
{
    int i=0;
    int j=0;
    int ans=0;
    while(j<n)
    {
        if(ans>x)
        {
            ans-=arr[i];
            i++;
        }
        else if(ans==x)
        {
            return j-i+1;
        }
        else if(ans<x)
        {
            ans+=arr[j];
            j++;
        }
    }
    return 0;
}
*/


#include<iostream>
using namespace std;
int smallestSubWithSum(int arr[], int n, int x)
    {
    int i=0;
    int j=0;
    int sum=0;
    int ans=INT_MAX;
    
    while(j<n)
    {
        sum+=arr[j];
        
        while(sum>x)
        {
            ans=min(ans,j-i+1);
            sum-=arr[i];
            i++;
        }
        j++;
    }
    if(ans>100)
    {
        return 0;
    }
    else
    {
        return ans;
    }
    }

int main(){
    int n=6;
    int arr[n]={1, 4, 45, 6, 0, 19};
    int x=51;
    int size=Subarray(arr,n,x);
    cout<<"The Answer is: "<<size<<endl;
return 0;
}
