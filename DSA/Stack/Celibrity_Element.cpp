#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool knows(int a,int b,int n,vector<vector<int>>& m)
{
    if(m[a][b]==1)
    {
        return true;
    }    
    else
    {
        return false;
    }
}
int celebrity(vector<vector<int>>& vec1,int n)
{
    stack<int>s;
    for(int i=0;i<n;i++)
    {
        s.push(i);
    }
    
    while(s.size()>1)
    {
        int a=s.top();
        s.pop();

        int b=s.top();
        s.pop();

        if(knows(a,b,n,vec1))
        {
            s.push(b);
        }
        else
        {
            s.push(a);
        }
    }
    int ans=s.top();

    int zeroCount=0;

    for(int i=0;i<n;i++)
    {
        if(vec1[ans][i]==0)
        {
            zeroCount++;
        }
    }

    if(zeroCount==n)
    return -1;

    int oneCount=0;

    for(int i=0;i<n;i++)
    {
        if(vec1[i][ans]==1)
        {
            oneCount++;
        }
    }
    if(oneCount!=n-1)
    {
        return -1;
    }
    return ans;
}
int main(){
    int n;
    cout<<"Enter the values for vector: ";
    cin>>n;
    vector<vector<int>>vec1(n,vector<int>(n));
    cout<<"Enter the element: ";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>vec1[i][j];
        }
    }
    cout<<"\nThe array is:\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<vec1[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"The Celibrity element: "<<celebrity(vec1,n);
return 0;
}