/*
Topological sort
Given a Directed Acyclic Graph (DAG) with V vertices and E edges, Find any Topological Sorting of that Graph.

Example 1:
Input:
Output:
1
Explanation:
The output 1 denotes that the order is
valid. So, if you have, implemented
your function correctly, then output
would be 1 for all test cases.
One possible Topological order for the
graph is 3, 2, 1, 0.

Example 2:
Input:
Output:
1
Explanation:
The output 1 denotes that the order is
valid. So, if you have, implemented
your function correctly, then output
would be 1 for all test cases.
One possible Topological order for the
graph is 5, 4, 2, 1, 3, 0.
Your Task:
You don't need to read input or print anything. Your task is to complete the function topoSort()  which takes the integer V denoting the number of vertices and adjacency list as input parameters and returns an array consisting of the vertices in Topological order. As there are multiple Topological orders possible, you may return any of them. If your returned topo sort is correct then the console output will be 1 else 0.

Expected Time Complexity: O(V + E).
Expected Auxiliary Space: O(V).

Constraints:
2 ≤ V ≤ 104
1 ≤ E ≤ (N*(N-1))/2

*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	void topoSort(int src,vector<bool>&visited,stack<int>&st,vector<int>adj[])
	{
	    visited[src]=1;
	    
	    for(auto neighbour:adj[src])
	    {
	        if(!visited[neighbour])
	        topoSort(neighbour,visited,st,adj);
	    }
	    //imp to push agter completing all the digit ,push inside the stack
	    st.push(src);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<bool>visited(V); // For more optimization we use here vector rather than unorderd_map.
	    stack<int>st;
	    
	    for(int i=0;i<V;i++)
	    {
	        if(!visited[i])
	        {
	            topoSort(i,visited,st,adj);
	        }
	    }
	    vector<int>ans;
	    while(!st.empty())
	    {
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
        int N, E;
        cout<<"Entre the number of vertices and edges: ";
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        cout<<"Enter the values of u and v: ";
        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);
        cout<<"\nAnswer: "<<endl;
        if(check(N, res, adj))
        {
            cout<<"Yes! It's Valid Sort.";
        }
        else
        {
            cout<<"No! It's Invalid Sort.";
        }
    
    return 0;
}




















