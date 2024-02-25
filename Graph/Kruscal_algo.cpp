/*
Minimum Spanning Tree

Given a weighted, undirected and connected graph of V vertices and E edges. The task is to find the sum of weights of the edges of the Minimum Spanning Tree. Given adjacency list adj as input parameters . Here adj[i] contains vectors of size 2, where the first integer in that vector denotes the end of the edge and the second integer denotes the edge weight.


Example 1:
Input:
3 3
0 1 5
1 2 3
0 2 1
Output:
4
Explanation:
The Spanning Tree resulting in a weight
of 4 is shown above.

Example 2:
Input:
2 1
0 1 5

Output:
5
Explanation:
Only one Spanning Tree is possible
which has a weight of 5.
 

Your task:
Since this is a functional problem you don't have to worry about input, you just have to complete the function spanningTree() which takes a number of vertices V and an adjacency list adj as input parameters and returns an integer denoting the sum of weights of the edges of the Minimum Spanning Tree. Here adj[i] contains vectors of size 2, where the first integer in that vector denotes the end of the edge and the second integer denotes the edge weight.

Expected Time Complexity: O(ElogV).
Expected Auxiliary Space: O(V2).
 
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
	public:
	bool cmp(vector<int>& a, vector<int>& b)
    {
        return a[1] < b[1];
    }
    
    void makeset(vector<int>& parent, vector<int>& rank, int n)
    {
        for(int i = 0; i < n; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    
    int findParent(vector<int>& parent, int node)
    {
        if(parent[node] == node)
        {
            return node;
        }
        return parent[node] = findParent(parent, parent[node]);
    }
    
    void unionset(int u, int v, vector<int>& parent, vector<int>& rank)
    {
        u = findParent(parent, u);
        v = findParent(parent, v);
        
        if(rank[u] < rank[v])
        {
            parent[u] = v;
        }
        else if(rank[v] < rank[u])
        {
            parent[v] = u;
        }
        else
        {
            parent[v] = u;
            rank[u]++;
        }
    }

    int spanningTree(int V, vector<vector<int>> adj[])
    {int n = V;
    vector<vector<int>> edges;

    for (int i = 0; i < V; i++)
    {
        for (auto& neighbor : (*adj)[i]) // Use arrow operator to access the vector inside adj
        {
            int v = neighbor.first;
            int w = neighbor.second;
            edges.push_back({i, v, w});
        }
    }

    sort(edges.begin(), edges.end(), cmp);

    vector<int> parent(n);
    vector<int> rank(n);
    makeset(parent, rank, n);

    int minweight = 0;

    for (int i = 0; i < edges.size(); i++)
    {
        int u = findParent(parent, edges[i][0]);
        int v = findParent(parent, edges[i][1]);
        int wt = edges[i][2];

        if (u != v)
        {
            minweight += wt;
            unionset(u, v, parent, rank);
        }
    }
    return minweight;

        
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cout<<"Enter the number of test cases: ";
    cin >> t;
    while (t--) {
        int V, E;
        cout<<"Enter the number of vertices and edges: ";
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            cout<<"Enter the value of u,v,w: ";
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
        cout<<"Answer: ";
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}
