//Median in a row-wise sorted Matrix
 
/*
Given a row wise sorted matrix of size R*C where R and C are always odd, find the median of the matrix.

Example 1:

Input:
R = 3, C = 3
M = [[1, 3, 5], 
     [2, 6, 9], 
     [3, 6, 9]]
Output: 5
Explanation: Sorting matrix elements gives 
us {1,2,3,3,5,6,6,9,9}. Hence, 5 is median. 
*/







//Approach - 1.
/*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int matrix_mid(vector<vector<int>>vec,int n)
{
    vector<int>ans;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            ans.push_back(vec[i][j]);
        }
    }
    int n1=ans.size();
    for(int i=0;i<n1-1;i++)
    {
        for(int j=0;j<n1-i-1;j++)
        {
            if(ans[j]>ans[j+1])
            {
                swap(ans[j],ans[j+1]);
            }
        }
    }
    int index=n1/2;
    
    return ans[index];
}

int main(){
    int n;
    cout<<"Enter the Limit: ";
    cin>>n;
    vector<vector<int>>vec(n,vector<int>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>vec[i][j];
        }
    }
    matrix_mid(vec,n);
return 0;
}
*/



















