#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int spiralPath(vector<vector<int>>vec)
{
    vector<int> ans;
    int left=0;
    int right=vec[0].size()-1;
    int top=0;
    int bottom=vec.size()-1;
    int direction=0;

    while (left<=right and top<=bottom)
    {
        if(direction==0)
        {
            for(int col=left;col<=right;col++)
            {
                cout<<vec[top][col]<<" ";
            }
            top++;
        }
        else if(direction==1)
        {
            for(int row=top;row<=bottom;row++)
            {
                cout<<vec[row][right]<<" ";
            }
            right--;
        }
        else if(direction==2)
        {
            for(int col=right;col>=left;col--)
            {
                cout<<vec[bottom][col]<<" ";
            }
            bottom--;
        }
        else if(direction==3)
        {
            for(int row=bottom;row>=top;row--)
            {
                cout<<vec[row][left]<<" ";
            }
            left++;
        }

        direction=(direction+1)%4;
    }
}
int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    vector<vector<int>>vec (n,vector<int>(n));
    cout<<"Enter the numbers : ";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>vec[i][j];
        }
    }
    spiralPath(vec);
return 0;
}