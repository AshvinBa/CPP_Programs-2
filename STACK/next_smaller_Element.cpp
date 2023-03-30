#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int>nextSmallerElement(vector<int>&vec,int n)
{
    
    stack<int>s;
    s.push(-1);

    vector<int>ans(n);

    for(int i=n-1;i>=0;i--)
    {
        int curr=vec[i];

        while(s.top()>=curr)
        {
            s.pop();
        }
        ans[i]=s.top();
        s.push(curr);
    }
    return ans;
}
int main(){
    int n;
    cout<<"Enter the limit: ";
    cin>>n;
    vector<int>vec(n);
    cout<<"Enter the element: ";
    for(int i=0;i,i<n;i++)
    {
        cin>>vec[i];
    }
    vector<int>ans=nextSmallerElement(vec,n);
    cout<<"\nThe array is: ";
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
return 0;
}