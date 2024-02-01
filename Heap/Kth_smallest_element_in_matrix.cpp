/*
Kth element in Matrix

Given a N x N matrix, where every row and column is sorted in non-decreasing order. Find the kth smallest element in the matrix.

Example 1:
Input:
N = 4
mat[][] =     {{16, 28, 60, 64},
                   {22, 41, 63, 91},
                   {27, 50, 87, 93},
                   {36, 78, 87, 94 }}
K = 3
Output: 27
Explanation: 27 is the 3rd smallest element.

Example 2:
Input:
N = 4
mat[][] =     {{10, 20, 30, 40}
                   {15, 25, 35, 45}
                   {24, 29, 37, 48}
                   {32, 33, 39, 50}}
K = 7
Output: 30
Explanation: 30 is the 7th smallest element.

Your Task:
You don't need to read input or print anything. Complete the function kthsmallest() which takes the mat, N and K as input parameters and returns the kth smallest element in the matrix.
 
Expected Time Complexity: O(K*Log(N))
Expected Auxiliary Space: O(N)

Constraints:
1 <= N <= 50
1 <= mat[][] <= 10000
1 <= K <= N*N
*/

#include<bits/stdc++.h>
using namespace std;

int kthSmallest(vector<vector<int>>&mat, int n, int k){

    int low=mat[0][0];
    int high=mat[n-1][n-1];
    
    while(low < high)
    {
        int mid=low+(high-low)/2;
        int count=0;
        
        for(int i=0;i<n;i++)
        {
            count+=upper_bound(mat[i].begin(),mat[i].end(),mid)-mat[i].begin();
        }
        if(count<k)
        {
            low=mid+1;
        }
        else
        {
            high=mid;
        }
    }
    return low;
}


int main()
{
        int n;
        cout<<"Enter the size: ";
        cin>>n;
        vector<vector<int>>mat(n,vector<int>(n));
        cout<<"Enter the values: ";
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        int r;
        cout<<"Enter the value of K: ";
        cin>>r;
        cout<<"Answer: ";
        cout<<kthSmallest(mat,n,r)<<endl;
    
    return 0;
}


/*
int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    priority_queue<int>pq;
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            pq.push(mat[i][j]);
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
    }
    
    return pq.top();
}
*/

/*
TC=O(nlogK).
SC=O(K).

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    priority_queue<int>pq;
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            pq.push(mat[i][j]);
        }
    }
    
    int size=pq.size()-k;
    
    while(size--)
    {
        pq.pop();
    }
    return pq.top();
}
*/



/*
int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    vector<int>arr;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            arr.push_back(mat[i][j]);
        }
    }
    sort(arr.begin(),arr.end());
    int ans=arr[k-1];
    return ans;
}
*/