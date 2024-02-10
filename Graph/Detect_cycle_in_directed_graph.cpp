/*
Detect cycle in a directed graph

Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
Example 1:
Input:
Output: 1
Explanation: 3 -> 3 is a cycle

Example 2:
Input:
Output: 0
Explanation: no cycle in the graph

Your task:
You dont need to read input or print anything. Your task is to complete the function isCyclic() which takes the integer V denoting the number of vertices and adjacency list adj as input parameters and returns a boolean value denoting if the given directed graph contains a cycle or not.
In the adjacency list adj, element adj[i][j] represents an edge from i to j.

Expected Time Complexity: O(V + E)
Expected Auxiliary Space: O(V)

Constraints:
1 ≤ V, E ≤ 105

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to detect cycle in a directed graph.
    bool checkCycleDFS(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited,
                       vector<int> adj[])
    {
        visited[node] = true;
        dfsVisited[node] = true;

        for (auto neighbour : adj[node])
        {
            if (!visited[neighbour])
            {
                bool cycleDetected = checkCycleDFS(neighbour, visited, dfsVisited, adj);
                if (cycleDetected)
                    return true;
            }
            else if (dfsVisited[neighbour])
            {
                return true;
            }
        }
        dfsVisited[node] = false;
        return false;
    }

    bool isCyclic(int V, vector<int> adj[])
    {
        unordered_map<int, bool> visited;
        unordered_map<int, bool> dfsVisited;
        for (int i = 0; i <= V - 1; i++)
        {
            if (!visited[i])
            {
                bool cycleFound = checkCycleDFS(i, visited, dfsVisited, adj);
                if (cycleFound)
                    return true;
            }
        }
        return false;
    }
};

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
