/*
Rotate by 90 degree

Given a square matrix of size N x N. The task is to rotate it by 90 degrees
in anti-clockwise direction without using any extra space. 

Example 1:
Input:
N = 3 
matrix[][] = {{1, 2, 3},
              {4, 5, 6}
              {7, 8, 9}}
Output: 
Rotated Matrix:
3 6 9
2 5 8
1 4 7

Example 2:
Input:
N = 2
matrix[][] = {{1, 2},
              {3, 4}}
Output: 
Rotated Matrix:
2 4
1 3

Your Task:
You dont need to read input or print anything. Complete the function rotateby90() 
which takes the matrix as input parameter and rotates it by 90 degrees in anti-clockwise
direction without using any extra space. You have to modify the input matrix in-place. 

Expected Time Complexity: O(N2)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ 100
1 <= matrix[][] <= 1000
*/

#include <bits/stdc++.h> 
using namespace std; 
class Solution
{   
    public:
    //Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int> >& matrix, int n) 
    { 
        //transpose of matrix.
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<(n/2);i++)
        {
            for(int j=0;j<n;j++)
            {
                swap(matrix[i][j],matrix[n-1-i][j]);
            }
        }
        
        return;
    } 
};

int main() {
    int t;
    cout<<"Enter the number of test cases: ";
    cin>>t;
    
    while(t--) 
    {
        int n;
        cout<<"Enter the size: ";
        cin>>n;
        vector<vector<int> > matrix(n); 
        cout<<"Enter the values: ";
        for(int i=0; i<n; i++)
        {
            matrix[i].assign(n, 0);
            for( int j=0; j<n; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        ob.rotateby90(matrix, n);
        cout<<endl;
        cout<<"The matrix is: ";
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
