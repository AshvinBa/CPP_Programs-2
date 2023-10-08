#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void spiral_path(vector<vector<int>>&vec)
{
    int left=0;
    int right=vec[0].size()-1;
    int top=0;
    int bottom=vec.size()-1;
    int direction=0;

    while(left<=right && top<=bottom)
    {
        if(direction=0)
        {
            for(int col=left;col<=right;col++)
            {
                cout<<vec[top][col]<<" ";
            }
            top++;
        }        
    }





}
int main(){
    int n,m;
    cout<<"Enter the Row and Coloumn: ";
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
    spiral_path(vec);
return 0;
}