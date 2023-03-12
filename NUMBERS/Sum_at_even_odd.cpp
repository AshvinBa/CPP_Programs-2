#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>vec{10,10,10,10,10,10};
    int n=vec.size();
    int sum=0;
    for(int i=0;i<n;i++)
    {
        if(i%2==0)
        {
            sum+=vec[i];
        }
        else
        {
            sum-=vec[i];
        }
    }
    cout<<"The Sum is: "<<sum;
return 0;
}