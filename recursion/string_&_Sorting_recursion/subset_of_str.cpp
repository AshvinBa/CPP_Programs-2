#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
void solve(string str,vector<string>&ans,int index,string output)
{
    if(index>=str.length())
    {
        if(output.length()>0)
        {
            ans.push_back(output);
        }
        return;
    }

    solve(str,ans,index+1,output);

    char ele=str[index];
    output.push_back(ele);
    solve(str,ans,index+1,output);    
}

vector<string> subsequence(string str)
{
    vector<string>ans;
    string output="";
    int index=0;
    solve(str,ans,index,output);
    return ans;
}

int main(){
    string str="abc";
    vector<string>ans;
    ans=subsequence(str);
    for(auto i=ans.begin();i!=ans.end();i++)
    {
        cout<<*i<<" ";
    }
return 0;
}