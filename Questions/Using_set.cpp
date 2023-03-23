#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int union_Of_set(vector<int> vec1,vector<int> vec2,int n,int m)
{
    set<int>s;
    for(int i=0;i<n;i++)
    {
        s.insert(vec1[i]);
    }
    for(int i=0;i<m;i++)
    {
        s.insert(vec2[i]);
    }
    cout<<"Number of element after union: ";
    cout<<s.size();
    cout<<endl;
    cout<<"The array is: "<<endl;
    for(auto i=s.begin();i!=s.end();i++)
    {
        cout<<*i<<" ";
    }
}
int main(){
    int n,m;
    vector<int>vec1{2,4,5,8,7,6,3,2};
    vector<int>vec2{12,4,15,81,7,16,3,12};
    n=vec1.size();
    m=vec2.size();
    union_Of_set(vec1,vec2,n,m);
return 0;
}