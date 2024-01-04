/*

Merge k Sorted Arrays

Given K sorted arrays arranged in the form of a matrix of size K*K. The task is to merge them into one sorted array.
Example 1:
Input:
K = 3
arr[][] = {{1,2,3},{4,5,6},{7,8,9}}
Output: 1 2 3 4 5 6 7 8 9
Explanation:Above test case has 3 sorted
arrays of size 3, 3, 3
arr[][] = [[1, 2, 3],[4, 5, 6], 
[7, 8, 9]]
The merged list will be 
[1, 2, 3, 4, 5, 6, 7, 8, 9].

Example 2:
Input:
K = 4
arr[][]={{1,2,3,4},{2,2,3,4},
         {5,5,6,6},{7,8,9,9}}
Output:
1 2 2 2 3 3 4 4 5 5 6 6 7 8 9 9 
Explanation: Above test case has 4 sorted
arrays of size 4, 4, 4, 4
arr[][] = [[1, 2, 2, 2], [3, 3, 4, 4],
[5, 5, 6, 6], [7, 8, 9, 9 ]]
The merged list will be 
[1, 2, 2, 2, 3, 3, 4, 4, 5, 5, 
6, 6, 7, 8, 9, 9].
Your Task:
You do not need to read input or print anything. Your task is to complete mergeKArrays() function which takes 2 arguments, an arr[K][K] 2D Matrix containing K sorted arrays and an integer K denoting the number of sorted arrays, as input and returns the merged sorted array ( as a pointer to the merged sorted arrays in cpp, as an ArrayList in java, and list in python)

Expected Time Complexity: O(K2*Log(K))
Expected Auxiliary Space: O(K2)

Constraints:
1 <= K <= 100

*/


//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;

/*
Approach - 1.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        int n=arr.size();
        vector<int>vec;
        
        for(int i=0;i<arr.size();i++)
        {
            for(int j=0;j<arr[0].size();j++)
            {
                vec.push_back(arr[i][j]);
            }
        }
        sort(vec.begin(),vec.end());
        
        return vec;
    }

*/


void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}
/* Approach 2 (Optimize approach and min heap is used.)*/
class node{
    public:
    int data;
    int i;
    int j;
    
    node(int data,int row,int col)
    {
        this->data=data;
        i=row;
        j=col;
    }
};

class compare
{
    public:
    bool operator() (node* a,node* b)
    {
        return a->data > b->data;
    }
};

class Solution
{
    public:
    
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        priority_queue<node*,vector<node*>,compare>minHeap;
        
        for(int i=0;i<k;i++)
        {
            node* tmp=new node(arr[i][0],i,0);
            minHeap.push(tmp);
        }
        vector<int>ans;
        
        while(minHeap.size()>0)
        {
            node* tmp=minHeap.top();
            ans.push_back(tmp->data);
            minHeap.pop();
            
            int i=tmp->i;
            int j=tmp->j;
            
            if(j+1<arr[i].size())
            {
                node* next=new node(arr[i][j+1],i,j+1);
                minHeap.push(next);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}
