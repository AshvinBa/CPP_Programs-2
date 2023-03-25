#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &vec,int k,int mid)
{
    int cowCount=1;
    int lastPos=vec[0];

    for(int i=0;i<vec.size();i++)
    {
        if( vec[i]-lastPos >= mid)
        {
            cowCount++;
            if(cowCount==k)
            {
                return true;
            }
            lastPos=vec[i];
        }
    }
    return false;
}

int aggresive(vector<int> &vec,int k)
{
    sort(vec.begin(),vec.end());
    int s=0;
    int maxi=-1;
    for(int i=0;i<vec.size();i++)
    {
        maxi=max(maxi,vec[i]);
    }
    int e=maxi;
    int ans=-1;
    int mid=(s+e)/2;

    while(s<=e)
    {
        if(isPossible(vec,k,mid))
        {
            ans=mid;
            s=mid+1;
        }
        else
        {
            e=mid-1;
        }
        mid=(s+e)/2;
    }
    return ans;
}

int main(){
    vector<int>vec{4,2,1,3,6};
    int k=2;
    int x;
    x=aggresive(vec,k);
    cout<<"The possible distance is: "<<x;
return 0;
}