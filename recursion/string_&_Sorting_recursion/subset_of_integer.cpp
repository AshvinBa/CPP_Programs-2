#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>&nums,vector<int>&output,int index,vector<vector<int>>&ans)
{
    if(index>=nums.size())
    {
        ans.push_back(output);
        return;
    }

    solve(nums,output,index+1,ans);

    int ele=nums[index];
    output.push_back(ele);
    solve(nums,output,index+1,ans);
}

vector<vector<int>> subset(vector<int>&nums)
{
    vector<vector<int>>ans;
    vector<int>output;

    int index=0;

    solve(nums,output,index,ans);
    return ans;
}

int main(){
    vector<int>nums{1,2,3};
    vector<vector<int>>ans=subset(nums);

    for(int i=0;i<ans[0].size();i++)
    {
        for(int j=0;j<ans.size();j++)
        {
            cout<<ans[i][j]<<" ";
            // cout<<*ans<<" ";
        }
    }

return 0;
}