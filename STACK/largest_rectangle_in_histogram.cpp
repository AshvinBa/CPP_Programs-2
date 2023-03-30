#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> vec,int n)
{
    stack<int>s;
    s.push(-1);
    vector<int>ans(n);
    
    for(int i=n-1;i>=0;i--)
    {
        int curr=vec[i];
        while(s.top()>=curr && s.top()!=-1)
        {
            s.pop();
        }
        ans[i]=s.top();
        s.push(i);
    }
    return ans;
}

vector<int> prevSmallerElement(vector<int> vec,int n)
{
    stack<int>s;
    s.push(-1);

    vector<int>ans(n);

    for(int i=0;i<n;i++)
    {
        int curr=vec[i];
        while(s.top()!=-1 && vec[s.top()]>=curr)
        {
            s.pop();
        }
        ans[i]=s.top();
        s.push(i);
    }
    return ans;
}

int LargestRectangleArea(vector<int> &vec,int n)
{
    vector<int>next(n);
    next=nextSmallerElement(vec,n);

    vector<int>prev(n);
    prev=prevSmallerElement(vec,n);

    int area=INT16_MIN;

    for(int i=0;i<n;i++)
    {
        int l=vec[i];
        if(next[i]==-1)
        {
            next[i]=n;
        }
        int b=next[i]-prev[i]-1;
        int newArea=l*b;
        area=max(area,newArea);
    }
    return area;
}

int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int>vec(n);
    cout<<"Enter the values: ";
    for(int i=0;i<n;i++)
    {
        cin>>vec[i];
    }
    cout<<"\nThe largest Element is: "<<LargestRectangleArea(vec,n);
return 0;
}