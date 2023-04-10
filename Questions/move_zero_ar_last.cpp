#include<bits/stdc++.h>
using namespace std;
void moveZeroes(vector<int>& nums) {
        int j=0;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=0)
            {
                swap(nums[i],nums[j]);
                j++;
            }
        }
    }
int main()
{
    vector<int>nums{0,2,3,0,0,3};
    moveZeroes(nums);
    for(int i=0;i<nums.size();i++)
    {
        cout<<nums[i]<<" ";
    }
}
