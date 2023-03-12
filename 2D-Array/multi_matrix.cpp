#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cout<<"\nEnter the rows: ";
    cin>>n;
    cout<<"\nEnter the coloumns: ";
    cin>>m;
    vector<vector<int>>vec(n,vector<int>(m));
    cout<<"Enter the values of M1=: ";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>vec[i][j];
        }
    }
    vector<vector<int>>vec2(n,vector<int>(m));
    cout<<"Enter the values of M2=: ";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>vec2[i][j];
        }
    }

    cout<<"\nThe Array No.1 is:\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"\nThe Array No.2 is: \n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<vec2[i][j]<<" ";
        }
        cout<<endl;
    }


    cout<<"The multiplication of matrix is:\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<setw(3)<<vec[i][j]*vec2[i][j]<<" ";
        }
        cout<<endl;
    }
return 0;
}