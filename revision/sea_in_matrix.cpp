#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool search(vector<vector<int>>mat,int n,int x)
{
    int col=mat[0].size();
    int row=mat.size();
    // cout<<col<<" "<<row;
    int start=0,end=row*col-1;

    int mid=start+(end-start)/2;
    
    while(start<=end)
    {
    int ele=mat[mid/col][mid%col];
    if(ele==x)
    {
        return 1;
    }
    else if(ele<x)
    {
        start=mid+1;
    }
    else if(ele>x)
    {
        end=mid-1;
    }
    mid=start+(end-start)/2;
    }
    return -1;
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
    cout<<search(mat,n,x);
return 0;
}