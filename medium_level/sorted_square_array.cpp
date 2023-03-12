#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int func(vector<int> &vec,int n)
{
    vector<int>ans;
    int i=0;
    int j=n-1;
    while(i<=j)
    {
        if(vec[i]<vec[j])
        {
            ans.push_back(vec[i]*vec[i]);
            i++;            
        }
        else
        {
            ans.push_back(vec[j]*vec[j]);
            j--;
        }
    }
    cout<<"The array is: ";
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
}
int main(){
    vector<int>vec{3,10,12,5,3,2};
    int n=vec.size();
    func(vec,n);
return 0;
}