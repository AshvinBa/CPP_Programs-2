#include<bits/stdc++.h>
#include<iostream>
using namespace std;

bool isSafe(int x,int y,int n,vector<vector<int>> visited,vector<vector<int>>vec)
{
    if((x>=0 && x<n) && (y>=0 && y<n) && visited[x][y]==0 && vec[x][y]==1)
    {
        return true;
    }
    else
    {
        return false;
    }
    cout<<"1)Yes"<<endl;
}

void solve(vector<vector<int>>&vec,vector<string>&ans,int n,vector<vector<int>>visited,int x,int y,string path)
{
    if(x==n-1 && y==n-1)
    {
        ans.push_back(path);
        return;
    }

    visited[x][y]=1;

    //down
    int newx=x+1;
    int newy=y;

    if(isSafe(newx,newy,n,visited,vec))
    {
        path.push_back('D');
        solve(vec,ans,n,visited,x,y,path);
        path.pop_back();
    }

    //left
    newx=x;
    newy=y-1;

    if(isSafe(newx,newy,n,visited,vec))
    {
        path.push_back('L');
        solve(vec,ans,n,visited,x,y,path);
        path.pop_back();
    }

    //Right
    newx=x;
    newy=y+1;

    if(isSafe(newx,newy,n,visited,vec))
    {
        path.push_back('R');
        solve(vec,ans,n,visited,x,y,path);
        path.pop_back();
    }

    //UP
    newx=x-1;
    newy=y;

    if(isSafe(newx,newy,n,visited,vec))
    {
        path.push_back('U');
        solve(vec,ans,n,visited,x,y,path);
        path.pop_back();
    }
    visited[x][y]=0;
    cout<<"2)Yes."<<endl;
}

vector<string>findpath(vector<vector<int>>&vec,int n)
{
    vector<string>ans;

    if(vec[0][0]==0)
    {
        return ans;
    }
    int srcx=0;
    int srcy=0;

    vector<vector<int>>visited=vec;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            visited[i][j]=0;
        }
    }

    string path="";
    solve(vec,ans,n,visited,srcx,srcy,path);
    sort(ans.begin(),ans.end());
    return ans;
    cout<<"3)Yes."<<endl;
}

int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    vector<vector<int>>vec(n,vector<int>(n));
    cout<<"Enter the values: ";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>vec[i][j];
        }
    }                 
    findpath(vec,n);                                                                      
    vector<string>res=findpath(vec,n);
    cout<<"Yes main"<<endl;
    if(res.size()==0)
    {
        cout<<"-1";
    }
    else
    {
        for(int i=0;i<res.size();i++)
        {
            cout<<res[i]<<" ";
        }
    }  
return 0;
}