#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int>modifyQueue(queue<int> &q,int k)
{
    int n=q.size();
    stack<int>s;
    vector<int>ans;

    for(int i=0;i<k;i++)
    {
        int val=q.front();
        q.pop();        
        s.push(val);
    }

    while(!s.empty())
    {
        int val=s.top();
        s.pop();
        ans.push_back(val);
    }
    
    for(int i=k;i<n;i++)
    {
        int val=q.front();
        q.pop();
        ans.push_back(val);
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter the limit: ";
    cin>>n;
    queue<int>q;
    cout<<"Enter the element: ";
    for(int i=0;i<n;i++)
    {
        int val;
        cin>>val;
        q.push(val);
    }
    int k;
    cout<<"Enter the element for rotate: ";
    cin>>k;

    vector<int> res=modifyQueue(q,k);
    cout<<"\nAnswer: ";
    for(auto i=res.begin();i!=res.end();i++)
    {
        cout<<*i<<" ";
    }
return 0;
}


/*
#include<iostream>
using namespace std;

int kth_move(int arr[],int n,int k)
{
    int result[100],r=0;
    for(int i=k;i>=0;i--)
    {
        result[r++]=arr[i];
    }
    for(int i=k+1;i<n;i++)
    {
        result[r++]=arr[i];
    }
    for(int i=0;i<r;i++)
    {
        cout<<result[i]<<" ";
    }
}

int main(){
    int n;
    cout<<"Enter the limit: ";
    cin>>n;
    int k;
    cout<<"Enter the value of K: ";
    cin>>k;
    int arr[n];
    cout<<"Entre the values: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    kth_move(arr,n,k);
return 0;
}

*/