#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> nums,vector<vector<int>>& ans,int index)
{
    if(index>=nums.size())
    {
        ans.push_back(nums);
        return ;
    }

    for(int j=index;j<nums.size();j++)
    {
        swap(nums[index],nums[j]);
        solve(nums,ans,index+1);

        swap(nums[index],nums[j]);
    }
}  

vector<vector<int>>permute( vector<int>&nums)
{
    vector<vector<int>> ans;
    int index=0;
    solve(nums,ans,index);
    return ans;
}

int main(){
    vector<int>nums{1,2,3};
    // vector<vector<int>>res;
    vector<int>res;
    res=permute(nums);
    // for(int i=0;i<res.size();i++)
    // {
        for(int j=0;j<res.size();j++)
        {
        cout<<res[j]<<" ";
        // [j]<<" ";
        }
    // }
return 0;
}