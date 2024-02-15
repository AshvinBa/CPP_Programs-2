/*
Shortest path in Directed Acyclic Graph

Given a Directed Acyclic Graph of N vertices from 0 to N-1 and a 2D Integer array(or vector) edges[ ][ ] of length M, where there is a directed edge from edge[i][0] to edge[i][1] with a distance of edge[i][2] for all i.

Find the shortest path from src(0) vertex to all the vertices and if it is impossible to reach any vertex, then return -1 for that vertex.

Example1:
Input:
N = 4, M = 2
edge = [[0,1,2],[0,2,1]]
Output:
0 2 1 -1
Explanation:
Shortest path from 0 to 1 is 0->1 with edge weight 2. 
Shortest path from 0 to 2 is 0->2 with edge weight 1.
There is no way we can reach 3, so it's -1 for 3.

Example2:
Input:
N = 6, M = 7
edge = [[0,1,2],[0,4,1],[4,5,4],[4,2,2],[1,2,3],[2,3,6],[5,3,1]]
Output:
0 2 3 6 1 5
Explanation:
Shortest path from 0 to 1 is 0->1 with edge weight 2. 
Shortest path from 0 to 2 is 0->4->2 with edge weight 1+2=3.
Shortest path from 0 to 3 is 0->4->5->3 with edge weight 1+4+1=6.
Shortest path from 0 to 4 is 0->4 with edge weight 1.
Shortest path from 0 to 5 is 0->4->5 with edge weight 1+4=5.
Your Task:

You don't need to print or input anything. Complete the function shortest path() which takes an integer N as number of vertices, an integer M as number of edges and a 2D Integer array(or vector) edges as the input parameters and returns an integer array(or vector), denoting the list of distance from src to all nodes.

Expected Time Complexity: O(N+M), where N is the number of nodes and M is edges
Expected Space Complexity: O(N)

Constraint:
1 <= N <= 100
1 <= M <= min((N*(N-1))/2,4000)
0 <= edgei,0,edgei,1 < n
0 <= edgei,2 <=105
*/


#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    
    void dfs(int node,vector<bool>&vis,vector<int>&topo,vector<pair<int,int>>adj[])
    {
        vis[node]=true;
        
        for(auto x:adj[node])
        {
            if(!vis[x.first])
            dfs(x.first,vis,topo,adj);
        }
        topo.push_back(node);
    }
  
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<pair<int,int>>adj[N];
        
        for(auto x:edges)
        {
            adj[x[0]].push_back({x[1],x[2]});
        }
        vector<bool>vis(N,false);
        vector<int>topo;
        for(int i=0;i<N;i++)
        {
            if(!vis[i])
            {
                dfs(i,vis,topo,adj);
            }
        }
        
        reverse(topo.begin(),topo.end());
        vector<int>dis(N,INT_MAX);
        dis[0]=0;
        for(int i=0;i<N;i++)
        {
            if(dis[topo[i]]!=INT_MAX)
            {
                for(auto x:adj[topo[i]])
                {
                    if(dis[topo[i]]+x.second < dis[x.first])
                    {
                        dis[x.first]=dis[topo[i]]+x.second;
                    }
                }
            }
        }
        for(int i=0;i<N;i++)
        {
            if(dis[i]==INT_MAX)dis[i]=-1;
        }
        return dis;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}
