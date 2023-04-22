#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool search(vector<vector<int>> mat,int n,int x)
{
    int row=0;
    for(int i=0;i<n;i++)
    {
        if(mat[i][0]==x)
        return true;
        else if(mat[i][0]>x)
        {
            row=i-1;
            break;
        }
        else
        {
            row=i;
        }
    }
    if(row>=0)
    {
        for(int i=0;i<n;i++)
        {
            if(mat[row][i]==x)
            return true;
        }
    }
    return false;
}

int main(){
    int n;
    cout<<"Enter the limit: ";
    cin>>n;
    vector<vector<int>>mat(n,vector<int>(n));
    cout<<"Enter the values: ";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>mat[i][j];
        }
    }
    int x;
    cout<<"Enter the value for search: ";
    cin>>x;
    bool x1=search(mat,n,x);

    if(x1==1)
    {
        cout<<"Yes Present.";
    }
    else
    {
        cout<<"Not Present.";
    }
return 0;
}