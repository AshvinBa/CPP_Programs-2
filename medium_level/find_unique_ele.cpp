#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>vec{11,12,13,15,15,13,17,11,12,12};
    int n=vec.size();
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(vec[i]==vec[j])
            {
                vec[i]=vec[j]=-1;
            }
        }
    }
    cout<<"The Unique element is: "<<endl;
    for(int i=0;i<n;i++)
    {
        if(vec[i]>=0)
        {
            cout<<vec[i]<<endl;
        }
    }
return 0;
}