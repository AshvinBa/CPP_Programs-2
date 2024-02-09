/*
BFS of graph

Given a directed graph. The task is to do Breadth First Traversal of this graph starting from 0.
Note: One can move from node u to node v only if there's an edge from u to v. Find the BFS traversal of the graph starting from the 0th vertex, from left to right according to the input graph. Also, you should only take nodes directly or indirectly connected from Node 0 in consideration.


Example 1:
Input:
V = 5, E = 4
adj = {{1,2,3},{},{4},{},{}}
Output: 
0 1 2 3 4
Explanation: 
0 is connected to 1 , 2 , 3.
2 is connected to 4.
so starting from 0, it will go to 1 then 2
then 3. After this 2 to 4, thus bfs will be
0 1 2 3 4.

Example 2:
Input:
V = 3, E = 2
adj = {{1,2},{},{}}
Output: 
0 1 2
Explanation:
0 is connected to 1 , 2.
so starting from 0, it will go to 1 then 2,
thus bfs will be 0 1 2. 

Your task:
You dont need to read input or print anything. Your task is to complete the function bfsOfGraph() which takes the integer V denoting the number of vertices and adjacency list as input parameters and returns  a list containing the BFS traversal of the graph starting from the 0th vertex from left to right.

Expected Time Complexity: O(V + E)
Expected Auxiliary Space: O(V)

Constraints:
1 ≤ V, E ≤ 104

*/

/* BFS for directed Graph.*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int>ans;
        queue<int>q;
        q.push(0);
        vector<int>vis(V,0);
        vis[0]=1;
        while(!q.empty())
        {
            int frontNode=q.front();
            q.pop();
            ans.push_back(frontNode);
            
            for(auto x:adj[frontNode])
            {
                if(!vis[x])
                {
                    vis[x]=1;
                    q.push(x);
                }
            }
        }
        return ans;
    }
};

int main() {
        int V, E;
        cout<<"Enter the Number of vertices and Number of Edges: ";
        cin >> V >>E;
        vector<int> adj[V];
        cout<<"Entre the value of u and v: ";
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        cout<<"Breadth first search traversal of graph is: "<<endl;
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    return 0;
}
