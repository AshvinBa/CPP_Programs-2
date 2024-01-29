/*
N-Queen Problem

The n-queens puzzle is the problem of placing n queens on a (n×n) chessboard such that no two queens can attack each other.
Given an integer n, find all distinct solutions to the n-queens puzzle. Each solution contains distinct board configurations of the n-queens’ placement, where the solutions are a permutation of [1,2,3..n] in increasing order, here the number in the ith place denotes that the ith-column queen is placed in the row with that number. For eg below figure represents a chessboard [3 1 4 2].


Example 1:
Input:
1
Output:
[1]
Explaination:
Only one queen can be placed 
in the single cell available.

Example 2:
Input:
4
Output:
[2 4 1 3 ] [3 1 4 2 ]
Explaination:
These are the 2 possible solutions.
 
Your Task:
You do not need to read input or print anything. Your task is to complete the function nQueen() which takes n as input parameter and returns a list containing all the possible chessboard configurations in sorted order. Return an empty list if no solution exists.

Expected Time Complexity: O(n!)
Expected Auxiliary Space: O(n2) 
Constraints:
1 ≤ n ≤ 10 

*/


// Approch-1
/*
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:

    void addSolution(vector<vector<int>>&ans,vector<vector<int>>&board,int n)
    {
        vector<int>temp;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                temp.push_back(board[i][j]);
            }
        }
        ans.push_back(temp);
    }

    bool isSafe(int row,int col,vector<vector<int>>&board,int n){
        int x=row;
        int y=col;        
        // check for same row
        while(y>=0)
        {
            if(board[x][y]==1)
            return false;
            y--;
        }
        
        x=row;
        y=col;
        // checking for diagonal
        while(x>=0 && y>=0)
        {
            if(board[x][y]==1)
            return false;
            y--;
            x--;
        }
        
        x=row;
        y=col;
        // check for diagonal
        while(x<n && y>=0)
        {
            if(board[x][y]==1)
            return false;
            y--;
            x++;
        }
        
        return true;
    }

    void solve(int col,vector<vector<int>>&ans,vector<vector<int>>&board,int n)
    {
        // base cases.
        if(col==n)
        {
            addSolution(ans,board,n);
            return;
        }
        
        // solve 1 case and rest Recursion will handle.
        for(int row=0;row<n;row++)
        {
            if(isSafe(row,col,board,n))
            {
                // if placing queen is safe
                board[row][col]=1;
                solve(col+1,ans,board,n);
                // backtrack
                board[row][col]=0;
            }
        }
    }

    vector<vector<int>> nQueen(int n) {
        vector<vector<int>>board(n,vector<int>(n,0));
        vector<vector<int>>ans;
        
        solve(0,ans,board,n);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cout<<"Enter the number of test cases: ";
    cin>>t;
    while(t--){
        int n;
        cout<<"Enter the digit: ";
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
*/

// Approach-2

#include <bits/stdc++.h>
using namespace std;

class NQueensSolver {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));  // Initialize empty board

        solveNQueensHelper(board, 0, result);

        return result;
    }

private:
    void solveNQueensHelper(vector<string>& board, int row, vector<vector<string>>& result) {
        int n = board.size();

        if (row == n) {
            result.push_back(board);
            return;
        }

        for (int col = 0; col < n; ++col) {
            if (isSafe(board, row, col)) {
                board[row][col] = 'Q';  // Place queen

                solveNQueensHelper(board, row + 1, result);  // Recur for the next row

                board[row][col] = '.';  // Backtrack
            }
        }
    }

    bool isSafe(const vector<string>& board, int row, int col) {
        int n = board.size();

        // Check in the same column
        for (int i = 0; i < row; ++i) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }

        // Check upper-left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        // Check upper-right diagonal
        for (int i = row, j = col; i >= 0 && j < n; --i, ++j) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }
};
class Solution{
public:

    
    vector<vector<int>> nQueen(int n) {
    
    NQueensSolver solver;
    vector<vector<string>> solutions = solver.solveNQueens(n);
    vector<vector<int>> result;
    for (const auto& solution : solutions) {
        vector<int> current;
        for (const string& row : solution) {
            int queenPos = row.find('Q') + 1;  // Find position of the queen in the row
            current.push_back(queenPos);
        }
        result.push_back(current);
    }

    return result;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}