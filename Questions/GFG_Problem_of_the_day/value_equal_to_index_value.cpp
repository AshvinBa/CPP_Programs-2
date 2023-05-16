#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int>check(int arr[],int n)
{
    vector<int>ans;
	    for(int i=1;i<n;i++)
	    {
	        if(arr[i]==i)
	        {
	            ans.push_back(i);
	        }
	    }
        if(ans.size()==0)
        {
            ans.push_back(-1);
        }
	    return ans;
}

int main(){
    int arr[]={15,2,45,12,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int>res=check(arr,n);
    for(auto i=res.begin();i!=res.end();i++)
    {
        cout<<*i<<" ";
    }
return 0;
}