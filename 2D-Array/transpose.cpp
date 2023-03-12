#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cout<<"Enter the row and coloumn: ";
    cin>>n>>m;
    vector<vector<int>>vec(n,vector<int>(m));
    cout<<"Enter the values: ";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>vec[i][j];
        }
    }
    cout<<"\nThe matrix is:\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"\nThere Transpose: \n";
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<vec[j][i]<<" ";
        }
        cout<<endl;
    }
return 0;
}