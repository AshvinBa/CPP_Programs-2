#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int minIndexChar(string str, string patt)
    {
        map<char,int>mp;
        for(int i=0;i<patt.size();i++)
        {
            mp[patt[i]]=1;
        }
        for(int i=0;i<str.size();i++)
        {
            if(mp[str[i]]==1)
            {
                return i;
            }
        }
        return -1;
    }
int main(){
    string str="ike";
    string ptr="beb";
    cout<<"Index: "<<minIndexChar(str,ptr);    
return 0;
}

/*
//Approach - 1
T.C = O(N);

int minIndexChar(string str,string ptr)
{
    int ans=INT16_MAX;
    for(int i=0;i<ptr.size();i++)
    {
        for(int j=0;j<str.size();j++)
        {
            if(ptr[i]==str[j])
            {
                if(j<ans)
                {
                    ans=j;
                }
            }
        }
    }
    if(ans>100)
    {
        return -1;
    }
    else
    {
        return ans;
    }
}
*/