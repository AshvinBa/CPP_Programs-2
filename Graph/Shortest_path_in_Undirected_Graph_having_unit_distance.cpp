/*

Shortest path in Undirected Graph having unit distance
You are given an Undirected Graph having unit weight, Find the shortest path from src to all the vertex and if it is unreachable to reach any vertex, then return -1 for that vertex.

Example:

Input:
n = 9, m= 10
edges=[[0,1],[0,3],[3,4],[4 ,5]
,[5, 6],[1,2],[2,6],[6,7],[7,8],[6,8]] 
src=0
Output:
0 1 2 1 2 3 3 4 4
Your Task:

You don't need to print or input anything. Complete the function shortest path() which takes a 2d vector or array edges representing the edges of undirected graph with unit weight, an integer N as number nodes, an integer M as number of edges and an integer src as the input parameters and returns an integer array or vector, denoting the vector of distance from src to all nodes.

Constraint:
1<=n,m<=100
1<=edges[i][j]<=100

Expected Time Complexity: O(N + E), where N is the number of nodes and E is edges
Expected Space Complexity: O(N)
*/


#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        
        vector<int>adj[N];
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        int dist[N];
        for(int i=0;i<N;i++)
        dist[i]=1e9;
        dist[src]=0;
        queue<int>q;
        q.push(src);
        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto it:adj[node])
            {
                if(dist[node]+1<dist[it])
                {
                    dist[it]=1+dist[node];
                    q.push(it);
                }
            }
        }
        vector<int>ans(N,-1);
        for(int i=0;i<N;i++)
        {
            if(dist[i]!=1e9)
            {
                ans[i]=dist[i];
            }
        }
        return ans;
    }
};
/*

    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        
        //Create adjancy list.
        unordered_map<int,list<int>>adj;
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[1][i];
            int v=edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        // do bfs.
        unordered_map<int,bool>visited;
        unordered_map<int,int>parent;
        queue<int>q;
        q.push(src);
        visited[src]=true;
        parent[src]=-1;
        
        while(!q.empty())
        {
            int front=q.front();
            q.pop();
            
            for(auto i:adj[front])
            {
                if(!visited[i])
                {
                    visited[i]=true;
                    parent[i]=front;
                    q.push(i);
                }
            }
        }
        
        // prepare shortest path.
        int t=parent.size();
        vector<int>ans;
        int currentNode=t;
        ans.push_back(t);
        
        while(currentNode != src)
        {
            currentNode=parent[currentNode];
            ans.push_back(currentNode);
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }

*/


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}
