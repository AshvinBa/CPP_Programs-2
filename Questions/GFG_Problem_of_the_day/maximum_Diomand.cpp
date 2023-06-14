#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int max_Dimond(int arr[],int n,int k)
{
    priority_queue<int> pq;

    for(int i=0;i<n;i++)
    {
        pq.push(arr[i]);
    }
    long long ans=0;

    while(k-- and pq.size())
    {
        int cur=pq.top();
        pq.pop();

        ans+=cur;

        if(cur>1)
        {
            pq.push(cur/2);
        }
    }
    return ans;
}

int main(){
    int n;
    int k=3;
    int arr[]={2,1,7,4,2};
    n=sizeof(arr)/sizeof(arr[0]);
    cout<<"\nAnswer: "<<max_Dimond(arr,n,k);
return 0;
}