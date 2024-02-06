// #include<bit/stc++.h>
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class graph
{
    public:

    unordered_map<int,list<int>>adj;
    
    void addEdge(int u,int v,bool direction)
    {
        //direction =0 -> undirected.
        //direction =1 -> directed graph.

        // create an edge from u to v.

        adj[u].push_back(v);
        if(direction==0)
        {
            adj[v].push_back(u);
        }
    }

    void printAdjList()
    {
        for(auto i:adj)
        {
            cout<<i.first<<" -> ";
            for(auto j:i.second)
            {
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }
};

int main(){

    int n;
    cout<<"Enter the number of node: ";
    cin>>n;

    int m;
    cout<<"Enter the number og edges: ";
    cin>>m;

    graph g;
    
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        //creating an undirected graph.
        g.addEdge(u,v,0);
    }
    cout<<"\nThe Adjecent List is: "<<endl;
    g.printAdjList();
return 0;
}