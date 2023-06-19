#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int doUnion(int a[], int n, int b[], int m)  {
    
        unordered_map<int,int>mp;
      
        for(int i=0;i<n;i++)
        {
            mp[a[i]]++;
        }
        for(int i=0;i<m;i++)
        {
            mp[b[i]]++;
        }
        return mp.size();
    }

int main(){
    int n;
    int m;
    int a[]={1,2,3,4,5};
    int b[]={1,2,3};
    n=sizeof(a)/sizeof(a[0]);
    m=sizeof(b)/sizeof(b[0]);
    cout<<"Answer: "<<doUnion(a,n,b,m);
return 0;
}