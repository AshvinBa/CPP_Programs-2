/*
0 - 1 Knapsack Problem

You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
Note that we have only one quantity of each item.
In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and weights associated with N items respectively. 
Also given an integer W which represents knapsack capacity, find out the maximum
value subset of val[] such that sum of the weights of this subset is smaller than or equal to W.
You cannot break an item, either pick the complete item or dont pick it (0-1 property).

Example 1:
Input:
N = 3
W = 4
values[] = {1,2,3}
weight[] = {4,5,1}
Output: 3
Explanation: Choose the last item that weighs 1 unit and holds a value of 3. 

Example 2:
Input:
N = 3
W = 3
values[] = {1,2,3}
weight[] = {4,5,6}
Output: 0
Explanation: Every item has a weight exceeding the knapsack's capacity (3).
Your Task:
Complete the function knapSack() which takes maximum capacity W, weight array wt[], 
value array val[], and the number of items n as a parameter and returns the maximum possible value you can get.

Expected Time Complexity: O(N*W).
Expected Auxiliary Space: O(N*W)

Constraints:
1 ≤ N ≤ 1000
1 ≤ W ≤ 1000
1 ≤ wt[i] ≤ 1000
1 ≤ v[i] ≤ 1000
*/


#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int solve(int wt[],int val[],int n,int capacity)
    {
        vector<int>prev(capacity+1,0);
        vector<int>curr(capacity+1,0);
        
        for(int w=wt[0];w<=capacity;w++)
        {
            if(wt[0]<=capacity)
            curr[w]=val[0];
            else
            curr[w]=0;
        }
        
        for(int index = 1; index<n; index++)
        {
            for(int w=capacity; w>=0; w--)
            {
                int include=0;
                
                if(wt[index]<=w)
                include=val[index]+curr[w-wt[index]];
                int exclude = 0 + curr[w];
                curr[w]=max(exclude,include);
            }
        }
        return curr[capacity];
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        return solve(wt,val,n,W);
    }
};

int main()
 {
    int t;
    cout<<"Enter the number of test cases: ";
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cout<<"Enter the value of n and m: ";
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        cout<<"Enter the values: ";
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        cout<<"Enter the weights: ";
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<"Answer: ";
        cout<<ob.knapSack(w, wt, val, n)<<endl;
    }
	return 0;
}

















