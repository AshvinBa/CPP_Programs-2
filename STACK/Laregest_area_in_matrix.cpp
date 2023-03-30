#include<bits/stdc++.h>
#include<iostream>
using namespace std;

vector<int> nextSmallerElement(int *vec,int n)
{
    stack<int>s;
    s.push(-1);
    vector<int>ans(n);
    
    for(int i=n-1;i>=0;i--)
    {
        int curr=vec[i];
        while(vec[s.top()]>=curr && s.top()!=-1)
        {
            s.pop();
        }
        ans[i]=s.top();
        s.push(i);
    }
    return ans;
}

vector<int> prevSmallerElement(int *vec,int n)
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

int LargestRectangleArea(int *vec,int n)
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

int maxArea(int M[n][n],int n)
{
    int area=LargestRectangleArea(M[0],n);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(M[i][j]!=0)
            {
                M[i][j]=M[i][j]+M[i-1][j];
            }
            else
            {
                M[i][j]=0;
            }
        }
        int newArea=LargestRectangleArea(M[i],n);
        area=max(area,newArea);
    }
    return area;
}

int main(){
    int n;
    cout<<"Enter the size: ";
    cin>>n;

    int M[n][n];
    cout<<"Enter the element: ";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>M[i][j];
        }
    }
    cout<<"The Largest area in matrix is: "<<maxArea(M,n);
return 0;
}