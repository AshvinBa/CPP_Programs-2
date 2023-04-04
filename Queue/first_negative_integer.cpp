#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<long long> printfirst(long long int A[],long long int n,long long int k)
{
    deque<long long int>dq;
    vector<long long>ans;

    for(int i=0;i<k;i++)
    {
        if(A[i]<0)
        {
            dq.push_back(i);
        }
    }
    if(dq.size()>0)
    {
        ans.push_back(A[dq.front()]);
    }
    else
    {
        ans.push_back(0);
    }

    for(int i=k;i<n;i++)
    {
        if(!dq.empty() && i-dq.front() >= k)
        {
            dq.pop_front();
        }
        if(A[i]<0)
        {
            dq.push_back(i);
        }

        if(dq.size()>0)
        {
            ans.push_back(A[dq.front()]);
        }
        else
        {
            ans.push_back(0);
        }
    }
    return ans;
}
int main(){
    int n;
    long long int k;
    cout<<"Enter the limit: ";
    cin>>n;
    long long int A[n];
    cout<<"Enter the values: ";
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    cout<<"Enter the windows: ";
    cin>>k;
    vector<long long>ans1;
    ans1=printfirst(A,n,k);
    cout<<"\nAnswer: ";
    for(auto i=ans1.begin();i!=ans1.end();i++)
    {
        cout<<*i<<" ";
    }
return 0;
}