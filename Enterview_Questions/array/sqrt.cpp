#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define long long int ll

int func(int n)
{
    int s=0;
    int e=n-1;
    int mid=(s+e)/2;

    while(s<=e)
    {
        mid=(s+e)/2;
        int sqr=mid*mid;
        if(sqr==n)
        {
            return mid;
        }
        else if(sqr<n)
        {
            s=mid+1;
        }
        else
        {
            e=mid-1;
        }
    }
    return -1;
}
int main(){
    int n;
    cout<<"Enter the numbers: ";
    cin>>n;
    cout<<"Answer: "<<func(n);
return 0;
}