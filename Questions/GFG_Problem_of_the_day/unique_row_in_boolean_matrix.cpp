/*
Unique rows in boolean matrix

Given a binary matrix your task is to find all unique rows of the given matrix in the order of their appearance in the matrix.

Example 1:
Input:
row = 3, col = 4 
M[][] = {{1 1 0 1},{1 0 0 1},{1 1 0 1}}
Output: $1 1 0 1 $1 0 0 1 $
Explanation: Above the matrix of size 3x4
looks like
1 1 0 1
1 0 0 1
1 1 0 1
The two unique rows are R1: {1 1 0 1} and R2: {1 0 0 1}. 
As R1 first appeared at row-0 and R2 appeared at row-1, in the resulting list, R1 is kept before R2.

Example 2:
Input:
row = 2, col = 4 
M[][] = {{0 0 0 1}, {0 0 0 1}}
Output: $0 0 0 1 $
Explanation: Above the matrix of size 2x4
looks like
0 0 0 1
0 0 0 1
Only unique row is $0 0 0 1 $

*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define max 1000

vector<vector<int>> uniqueRow(vector<vector<int>>A,int col,int row)
{
    unordered_map<string,int>mm;
    
    vector<vector<int>>ans;
    for(int i=0;i<row;i++)
    {
        vector<int>temp;
        string s="";
        for(int j=0;j<col;j++)
        {
            s.push_back('0'+A[i][j]);
            temp.push_back(A[i][j]);
        }
        if(!mm[s])
        {
            mm[s]++;
            ans.push_back(temp);
        }
    }
    return ans;
}

int main(){
    int col,row;
    
    cout<<"Enter the value of row and col: ";
    cin>>row>>col;
    vector<vector<int>>A(col,vector<int>(row));
    cout<<"Enter the values: ";
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin>>A[i][j];
        }
    }
    vector<vector<int>>res=uniqueRow(A,col,row);
    cout<<"\nAnswer: ";
    for(int i=0;i<res.size();i++)
    {
        for(int j:res[i])
        {
            cout<<j<<" ";
        }
        cout<<"$";
    }
return 0;
}