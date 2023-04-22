#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool search(vector<vector<int>>mat,int n,int x)
{
    int col=mat.size();
    int row=mat.size();
    cout<<col<<" "<<row<<endl;
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
    search(mat,n,x);
return 0;
}