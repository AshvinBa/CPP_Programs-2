#include <bits/stdc++.h> 
#include<iostream>
using namespace std;

// Approach-1.
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
     //create adj list
     unordered_map<int,list<pair<int,int>>>adj;

     for(int i=0;i<g.size();i++)
     {
         int u=g[i].first.first;
         int v=g[i].first.second;
         int w=g[i].second;
         adj[u].push_back(make_pair(v,w));
         adj[v].push_back(make_pair(u,w));
     }
     vector<int>key(n+1);
     vector<bool>mst(n+1);
     vector<int>parent(n+1);


     for(int i=0;i<=n;i++)
     {
         key[i]=INT_MAX;
         parent[i]=-1;
         mst[i]=false;
     }    

     key[1]=0;
     parent[1]=-1;
         for(int i=1;i<n;i++)
         {
             int mini=INT_MAX;
             int u;
             for(int v=1;v<=n;v++)
             {
                 if(mst[v]==false && key[v]<mini)
                 {
                     u=v;
                     mini=key[v];
                 }
             }
         
         mst[u]=true;

         for(auto it:adj[u])
         {
             int v=it.first;
             int w=it.second;
             if (mst[v] == false && w < key[v]) {
                     parent[v] = u;
                     key[v] = w;
             }
         }
        }

     vector<pair<pair<int,int>,int>>result;
     for(int i=2;i<=n;i++)
     {
         result.push_back({{parent[i],i},key[i]});
     }
     return result;
}

int main(){
    int n = 4;  
    int m = 5;  
    vector<pair<pair<int, int>, int>> graph = {
        {{1, 2}, 2},
        {{1, 3}, 1},
        {{2, 3}, 3},
        {{2, 4}, 4},
        {{3, 4}, 5}
    };
    vector<pair<pair<int, int>, int>> result = calculatePrimsMST(n, m, graph);
    cout << "Edges in Minimum Spanning Tree:" << endl;
    for (auto edge : result) {
        cout << edge.first.first << " - " << edge.first.second << " : " << edge.second << endl;
    }

    return 0;
}


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
 
Constraints:
2 ≤ V ≤ 1000
V-1 ≤ E ≤ (V*(V-1))/2
1 ≤ w ≤ 1000
The graph is connected and doesn't contain self-loops & multiple edges.
*/

#include<bits/stdc++.h>
using namespace std;
class Solution
{
	public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        vector<int>vis(V,0);
        pq.push({0,0});
        int sum=0;
        
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            int node=it.second;
            int wt=it.first;
            
            if(vis[node]==1)
            continue;
            
            vis[node]=1;
            sum+=wt;
            for(auto it:adj[node])
            {
                int adjNode=it[0];
                int edW=it[1];
                if(!vis[adjNode])
                {
                    pq.push({edW,adjNode});
                }
            }
        }
        return sum;
    }
};


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
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
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}
