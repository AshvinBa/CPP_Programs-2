/*
POTD

Seating Arrangement

You are given an integer n, denoting the number of people who needs to be seated, and a list of m integers seats, where 0 represents a vacant seat and 1 represents an already occupied seat.

Find whether all n people can find a seat, provided that no two people can sit next to each other.

Example 1:
Input:
n = 2
m = 7
seats[] = {0, 0, 1, 0, 0, 0, 1}
Output:
Yes
Explanation:
The two people can sit at index 0 and 4.
*/


#include<iostream>
using namespace std;

bool possibleseat(int n,int m,int arr[])
{
    int count=0;

    for(int i=0;i<m;i++)
    {
        bool left=false,right=false;

        if(i==0 || arr[i-1]==0)
        left=true;
        if(i==m-1 || arr[i+1]==0)
        right=true;

        if(arr[i]==0 && left && right)
        {
            count++;
            arr[i]=1;
        }
    }
    return count>=n;
}

int main(){
    int n=2;
    int arr[]={0,0,1,0,0,0,1};
    int m=sizeof(arr)/sizeof(arr[0]);
    bool x=possibleseat(n,m,arr);
    if(x)
    {
        cout<<"Yes.";
    }
    else
    {
        cout<<"No.";
    }
return 0;
}