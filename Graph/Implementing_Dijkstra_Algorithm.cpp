/*
Implementing Dijkstra Algorithm

Given a weighted, undirected and connected graph of V vertices and an adjacency list adj where adj[i] is a list of lists containing two integers where the first integer of each list j denotes there is edge between i and j , second integers corresponds to the weight of that  edge . You are given the source vertex S and You to Find the shortest distance of all the vertex's from the source vertex S. You have to return a list of integers denoting shortest distance between each node and Source vertex S.
 
Note: The Graph doesn't contain any negative weight cycle.

Example 1:
Input:
V = 2
adj [] = {{{1, 9}}, {{0, 9}}}
S = 0
Output:
0 9
Explanation:
The source vertex is 0. Hence, the shortest 
distance of node 0 is 0 and the shortest 
distance from node 1 is 9.
 

Example 2:
Input:
V = 3, E = 3
adj = {{{1, 1}, {2, 6}}, {{2, 3}, {0, 1}}, {{1, 3}, {0, 6}}}
S = 2
Output:
4 3 0
Explanation:
For nodes 2 to 0, we can follow the path-
2-1-0. This has a distance of 1+3 = 4,
whereas the path 2-0 has a distance of 6. So,
the Shortest path from 2 to 0 is 4.
The shortest distance from 0 to 1 is 1 .
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function dijkstra()  which takes the number of vertices V and an adjacency list adj as input parameters and Source vertex S returns a list of integers, where ith integer denotes the shortest distance of the ith node from the Source node. Here adj[i] contains a list of lists containing two integers where the first integer j denotes that there is an edge between i and j and the second integer w denotes that the weight between edge i and j is w.

Expected Time Complexity: O(V2).
Expected Auxiliary Space: O(V2).

Constraints:
1 ≤ V ≤ 1000
0 ≤ adj[i][j] ≤ 1000
1 ≤ adj.size() ≤ [ (V*(V - 1)) / 2 ]
0 ≤ S < V
*/


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {

        vector<int>dist(V);
        for(int i=0;i<V;i++)
        {
            dist[i]=INT_MAX;
        }
        
        set<pair<int,int>>st;
        dist[S]=0;
        st.insert(make_pair(0,S));
        
        while(!st.empty())
        {
            auto top=*(st.begin());
            
            int nodeDistance=top.first;
            int topNode=top.second;
            
            st.erase(st.begin());
            
            for(auto neighbour:adj[topNode])
            {
                if(nodeDistance + neighbour[1] < dist[neighbour[0]])
                {
                    auto record=st.find(make_pair(dist[neighbour[0]],neighbour[0]));
                    
                    if(record != st.end())
                    {
                        st.erase(record);
                    }
                    
                    dist[neighbour[0]]=nodeDistance + neighbour[1];
                    
                    st.insert(make_pair(dist[neighbour[0]] , neighbour[0]));
                }
            }
        }
        return dist; 
    }
    
    /*
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int>dist(V);
        for(int i=0;i<V;i++)
        {
            dist[i]=INT_MAX;
        }
        
        set<pair<int,int>>st;
        dist[S]=0;
        st.insert(make_pair(0,S));
        
        while(!st.empty())
        {
            auto top=*(st.begin());
            
            int nodeDistance=top.first;
            int topNode=top.second;
            
            st.erase(st.begin());
            
            for(auto neighbour:adj[topNode])
            {
                if(nodeDistance + neighbour.second < dist[neighbour.first])
                {
                    auto record=st.find(make_pair(dist[neighbour.first],neighbour.first));
                    
                    if(record != st.end())
                    {
                        st.erase(f);
                    }
                    
                    dist[neighbour.first]=nodeDistance + neighbour.second;
                    
                    st.insert(make_pair(dist[neighbour.first] , neighbour.first));
                }
            }
        }
        return dist;
    }
    */
};


//{ Driver Code Starts.


int main()
{
    int t;
    cout<<"Enter the number of test cases: ";
    cin >> t;
    while (t--) {
        int V, E;
        cout<<"Enter the values of V and E: ";
        cin >> V >> E;
        
        vector<vector<int>> adj[V];

        int i=0;
        while (i++<E) {
            int u, v, w;
            cout<<"Enter the value u,v and weight: ";
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cout<<"Entre the source: ";
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
        cout<<"The Shortes Path is: ";
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

