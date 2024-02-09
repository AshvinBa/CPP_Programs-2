/*
Detect cycle in an undirected graph

Given an undirected graph with V vertices labelled from 0 to V-1 and E edges, check whether it contains any cycle or not. Graph is in the form of adjacency list where adj[i] contains all the nodes ith node is having edge with.

Example 1:
Input:  
V = 5, E = 5
adj = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}} 
Output: 1
Explanation: 
1->2->3->4->1 is a cycle.

Example 2:
Input: 
V = 4, E = 2
adj = {{}, {2}, {1, 3}, {2}}
Output: 0
Explanation: 
No cycle in the graph.
 
Your Task:
You don't need to read or print anything. Your task is to complete the function isCycle() which takes V denoting the number of vertices and adjacency list as input parameters and returns a boolean value denoting if the undirected graph contains any cycle or not, return 1 if a cycle is present else return 0.

NOTE: The adjacency list denotes the edges of the graph where edges[i] stores all other vertices to which ith vertex is connected.

Expected Time Complexity: O(V + E)
Expected Space Complexity: O(V)

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    bool isCyclicBFS(int src, unordered_map<int,bool>&visited, vector<int>adj[])
    {
        unordered_map<int,int>parent;
        
        parent[src]=-1;
        visited[src]=1;
        queue<int>q;
        q.push(src);
        
        while(!q.empty())
        {
            int front=q.front();
            q.pop();
            
            for(auto neighbour:adj[front])
            {
                if(visited[neighbour]==true && neighbour!=parent[front])
                {
                    return true;
                }
                else if(!visited[neighbour])
                {
                    q.push(neighbour);
                    visited[neighbour]=1;
                    parent[neighbour]=front;
                }
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        
        unordered_map<int,bool>visited;
        
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                bool ans=isCyclicBFS(i,visited,adj);
                if(ans==1)
                {
                    return 1;
                }
            }
            
        }
        return 0;
    }
};

int main() {
        int V, E;
        cout<<"Enter the nuber of vertices and edges: ";
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cout<<"Enter the values of u and v: ";
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "\nYes! The Graph is cyclic.\n\n";
        else
            cout << "\nNo! The Graph is Not Cyclic.\n\n";
    return 0;
}