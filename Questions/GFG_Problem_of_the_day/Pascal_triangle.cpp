/*
Pascal Triangle

Given a positive integer N, return the Nth row of pascal's triangle.
Pascal's triangle is a triangular array of the binomial coefficients formed by summing up the elements of previous row.
The elements can be large so return it modulo 109 + 7.

File:PascalTriangleAnimated2.gif

Example 1:
Input:
N = 4
Output: 
1 3 3 1
Explanation: 
4th row of pascal's triangle is 1 3 3 1.

Example 2:
Input:
N = 5
Output: 
1 4 6 4 1
Explanation: 
5th row of pascal's triangle is 1 4 6 4 1.
Your Task:
Complete the function nthRowOfPascalTriangle() which takes n, as input parameters and returns an array representing the answer. You don't to print answer or take inputs.

Expected Time Complexity: O(N2)
Expected Auxiliary Space: O(N2)

Constraints:
1 ≤ N ≤ 103

*/

/*
//Approach - 1.
Faild in Test cases-no.11.

vector<vector<int>>pascalsTriangle(int n)
    {
  
        vector<vector<int>>pascal(n);
        
        for(int i=0;i<n;i++)
        {
            pascal[i].resize(i+1);
            for(int j=0;j<i+1;j++)
            {
                if(j==0||j==i)
                {
                    pascal[i][j]=1;
                }
                else
                {
                    pascal[i][j]=pascal[i-1][j]+pascal[i-1][j-1];
                }
            }
        }
        return pascal;
    }
    

    vector<long long> nthRowOfPascalTriangle(int n) {
        
        vector<vector<int>>vec=pascalsTriangle(n);
        vector<long long>ans;
        for(int i=vec.size()-1;i<=vec.size()-1;i++)
        {
            for(int j=0;j<vec[i].size();j++)
            {
                ans.push_back(vec[i][j]);
            }
        }
        return ans;
        
    }

*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public: 

    vector<long long> nthRowOfPascalTriangle(int n) {

        vector<long long>prev;        
        int mod=1e9+7;
        for(int i=0;i<n;i++)
        {
            vector<long long>curr(i+1,1);
            
            for(int j=1;j<i;j++)
            {
                curr[j]=(prev[j-1]+prev[j])%mod;
            }
            prev=curr;
        }
        return prev;
        
    }
};
void printAns(vector<long long> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cout<<"Enter the number of test cases: ";
    cin >> t;
    while (t--) {
        int n;
        cout<<"Enter the digit: ";
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}
