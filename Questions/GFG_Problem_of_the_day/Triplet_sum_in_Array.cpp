/*
Triplet Sum in Array

Given an array arr of size n and an integer X. Find if there's a triplet in the array which sums up to the given integer X.

Example 1:
Input:
n = 6, X = 13
arr[] = [1 4 45 6 10 8]
Output:
1
Explanation:
The triplet {1, 4, 8} in 
the array sums up to 13.
*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

bool Triplet(int A[],int n,int X)
{
    sort(A,A+n);
    
    for(int i=0;i<n-2;i++)
    {
        int j=i+1;
        int k=n-1;

        while(j<k)
        {
            int ans=A[i]+A[j]+A[k];

            if(ans<X)
            {
                j++;
            }
            else if(ans>X)
            {
                k--;
            }
            else
            {
                return true;
            }
        }
    }
return false;
}

int main(){
    int A[]={1,4,45,6,10,8};
    int n=sizeof(A)/sizeof(A[0]);
    int X=13;
    int x=Triplet(A,n,X);
    
    if(x==1)
    {
        cout<<"Yes.";
    }
    else
    {
        cout<<"No.";
    }
return 0;
}















