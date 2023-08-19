#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> leader(int arr[],int n)
{
    stack<int>s;
    int max=arr[n-1];

    for(int i=n-1;i>=0;i--)
    {
        if(max<=arr[i])
        {
            s.push(arr[i]);
            max=arr[i];
        }
    }
    vector<int>ans;
    while(!s.empty())
    {
        int num=s.top();
        s.pop();
        ans.push_back(num);
    }
    return ans;   
}

int main(){
    int arr[]={16,17,4,3,5,3,2,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int>ans=leader(arr,n);
    for(auto i=ans.begin();i!=ans.end();i++)
    {
        cout<<*i<<" ";
    }

return 0;
}