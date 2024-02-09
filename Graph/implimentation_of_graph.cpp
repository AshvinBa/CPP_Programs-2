/*

// Implementation of Graph by using List.
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
*/



/* Implementation of Graph by using SET.*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Graph
{
    public:
    unordered_map<int,set<int>>adj;

    void addEdge(int u,int v,bool direction)
    {
        adj[u].insert(v);

        if(direction==0)
        {
            adj[v].insert(u);
        }
    }

    void printAdj()
    {
        for(auto x:adj)
        {
            cout<<x.first<<" -> ";
            for(auto i:x.second)
            {
                cout<<i<<" ,";
            }
            cout<<endl;
        }
    }

};

int main(){
    int n,m;
    cout<<"Enter the number of Nodes: ";
    cin>>n;

    cout<<"Enter the number of Edges: ";
    cin>>m;

    Graph g;
    cout<<"Enter the values of U and V: ";
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v,0);
    }
    cout<<"The Adjancy List is: "<<endl;

    g.printAdj();
return 0;
}
























