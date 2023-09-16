/*
Maximum no of 1's row
Given a boolean 2D array, where each row is sorted. Find the row with the maximum number of 1s.

Example 1:
Input:
N = 3, M = 4
Mat[] = {{0 1 1 1},
         {0 0 1 1},
         {0 0 1 1}}
Output: 0
Explanation: Row 0 has 3 ones whereas
rows 1 and 2 have just 2 ones.

Example 2:
Input: 
N = 2, M = 2
Mat[] = {{0 1},
         {1 1}}
Output: 1
Explanation: Row 1 has 2 ones whereas
row 0 has just a single one. 

Your Task:
You don't need to read input or print anything. Your task is to complete the function maxOnes () which takes a 2D array Mat[][] and its dimensions N and M as inputs and returns the row index with the maximum number of 1s (0-based index). If there are multiple rows with the maximum number of ones, then return the row with the smaller index.

Expected Time Complexity: O(NLogM).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N, M <= 40
0 <= M[ ][ ] <= 1


*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

 int maxOnes (vector <vector <int>> &arr, int N, int M)
        {
            int maxi=0;
            int cnt=0;
            int index;
            
            for(int i=0;i<N;i++)
            {
                for(int j=0;j<M;j++)
                {
                    if(arr[i][j]==1)
                    {
                        cnt++;
                    }
                }
                if(maxi<cnt)
                {
                    maxi=cnt;
                    index=i;
                }
                cnt=0;
            }
            return index;
        }
int main()
{
    int n,m;
    vector<vector<int>>arr(n,vector<int>m);
    cout<<"Inset values: ";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }
    cout<<"Answer: "<<maxOnes (arr, n,m);
    return 0;

}