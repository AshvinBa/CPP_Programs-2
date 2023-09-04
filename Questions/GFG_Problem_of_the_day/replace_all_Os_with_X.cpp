/*
Replace O's with X's
Given a matrix mat of size N x M where every element is either 'O' or 'X'. Replace all 'O' with 'X' that are surrounded by 'X'.

A 'O' (or a set of 'O') is considered to be surrounded by 'X' if there are 'X' at locations just below, just above, just left and just right of it.

Example 1:
Input: 
n = 5, m = 4
mat = {{'X', 'X', 'X', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'O', 'O', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'X', 'O', 'O'}}
Output: 
ans = {{'X', 'X', 'X', 'X'}, 
       {'X', 'X', 'X', 'X'}, 
       {'X', 'X', 'X', 'X'}, 
       {'X', 'X', 'X', 'X'}, 
       {'X', 'X', 'O', 'O'}}
Explanation: 
Following the rule the above matrix is the resultant matrix. 

Example 2:
Input: 
n = 5, m = 4
mat = {{'X', 'O', 'X', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'O', 'O', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'X', 'O', 'O'}}
Output: 
ans = {{'X', 'O', 'X', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'O', 'O', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'X', 'O', 'O'}}
Explanation: 
Following the rule the above matrix is the resultant matrix.

*/
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    
    bool isSafe(int i,int j,vector<vector<char>>&mat,vector<vector<bool>>&vis)
    {
        return (i>=0 && j>=0 and i<mat.size() and j<mat[0].size() and !vis[i][j] and mat[i][j]=='O');
    }
    
    void dfs(int i,int j,vector<vector<char>>&mat,vector<vector<bool>>&vis)
    {
        vis[i][j]=1;
        for(int k=0;k<4;k++)
        {
            if(isSafe(i+dx[k],j+dy[k],mat,vis))
            {
                dfs(i+dx[k],j+dy[k],mat,vis);
            }
        }
    }


    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        //doing dfs for zeros in first row
        for(int i=0;i<m;i++)
        {
            if(!vis[0][i] && mat[0][i]=='O')
            {
                dfs(0,i,mat,vis);
            }
        }
        
        //doing dfs for zeros in last row
        for(int i=0;i<m;i++)
        {
            if(!vis[n-1][i] && mat[n-1][i]=='O')
            {
                dfs(n-1,i,mat,vis);
            }
        }
        
        //doing dfs for in first column
        for(int i=0;i<n;i++)
        {
            if(!vis[i][0] && mat[i][0]=='O')
            {
                dfs(i,0,mat,vis);
            }
        }
        
        //doing dfs for last column
        for(int i=0;i<n;i++)
        {
            if(!vis[i][m-1] && mat[i][m-1]=='O')
            {
                dfs(i,m-1,mat,vis);
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]=='O' && !vis[i][j])
                {
                    mat[i][j]='X';
                }
            }
        }
        return mat;
    }

int main(){
    cout<<"Enter the row and columns: ";
        int n, m;
        cin>>n>>m;
        cout<<"Enter the values: ";
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        vector<vector<char>> ans = fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    
    return 0;
}