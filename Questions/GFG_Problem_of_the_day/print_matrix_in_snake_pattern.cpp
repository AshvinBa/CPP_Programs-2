/*
Print Matrix in snake Pattern

Given a matrix of size N x N. Print the elements of the matrix in the snake like pattern depicted below.

Example 1:
Input:
N = 3 
matrix[][] = {{45, 48, 54},
             {21, 89, 87}
             {70, 78, 15}}
Output: 
45 48 54 87 89 21 70 78 15 
Explanation:
Matrix is as below:
45 48 54
21 89 87
70 78 15
Printing it in snake pattern will lead to 
the output as 45 48 54 87 89 21 70 78 15.

Example 2:
Input:
N = 2
matrix[][] = {{1, 2},
              {3, 4}}
Output: 
1 2 4 3
Explanation:
Matrix is as below:
1 2 
3 4
Printing it in snake pattern will 
give output as 1 2 4 3.
Your Task:
You dont need to read input or print anything. Complete the function snakePattern() that takes matrix as input parameter and returns a list of integers in order of the values visited in the snake pattern. 

Expected Time Complexity: O(N * N)
Expected Auxiliary Space: O(N * N) for the resultant list only.

Constraints:
1 <= N <= 103
1 <= mat[i][j] <= 109
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

  vector<int> snakePattern(vector<vector<int> > matrix)
    {
        vector<int>  arr;
        int n=matrix.size();
        for(int i=0;i<n;i++)
        {
                if(i%2==0)
                {
                    for(int j=0;j<n;j++)
                    {
                        arr.push_back(matrix[i][j]);
                    }
                }
                else
                {
                    for(int j=n-1;j>=0;j--)
                    {
                        arr.push_back(matrix[i][j]);
                    }
                }
        }
        return arr;
    }

int main(){
    int n;
    cout<<"Enter the value of row and column: ";
    cin>>n;
    vector<vector<int>>vec(n,vector<int>(n));
    cout<<"Enter the values: ";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>vec[i][j];
        }
    }
    vector<int>ans=snakePattern(vec);        
    for(auto i=ans.begin();i!=ans.end();i++)
    {
        cout<<*i<<" ";
    }

return 0;
}