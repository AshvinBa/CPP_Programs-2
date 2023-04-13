#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int ans=0;
    int n=nums.size();
    int count=0;

    for(int i=0;i<n;i++)
    {
        if(nums[i]==1)
        {
            count++;
            ans=max(count,ans);
        }
        else if(nums[i]==0)
        {
            count=0;
        }
                
    }
    return ans;
        
    }


int main(){
    vector<int>vec{1,0,1,1,1,0,1};
    int n=vec.size();
    cout<<"The number of Ones: "<<findMaxConsecutiveOnes(vec);
return 0;
}

// Approach - 2.

/*
int subarr(vector<int> vec,int n)
{
    int ans=0;
    int min=INT16_MIN;
    int i=-1;
    int ans1=INT16_MIN;

    while(i<n)
    {
        ans1=max(ans1,ans);
        if(vec[i]==1)
        {
            ans++;
        }
        else if(vec[i]==0)
        {
            ans=0;
        }
        i++;        
    }
    return ans1;
}
*/
