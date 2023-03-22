#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> vec{11,12,13,14,15,16,17};
    bool sortflag=true;
    for(int i=0;i<vec.size();i++)
    {
        if(vec[i+1]<vec[i])
        sortflag=false;        
    }
    if(sortflag==1)
    {
        cout<<"Yes! it is Sorted.";
    }
    else
    {
        cout<<"No! Not Sorted.";
    }
return 0;
}