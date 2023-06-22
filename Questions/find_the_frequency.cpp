/*
Find the Frequency
Given a vector of N positive integers and an integer X. The task is to find the frequency of X in vector.

Example 1:
Input:
N = 5
vector = {1, 1, 1, 1, 1}
X = 1
Output: 
5
Explanation: Frequency of 1 is 5.

*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Approch 1

/*
int find_freq(vector<int> vec,int x)
{
    unordered_map<int,int>mp;
    for(int i=0;i<vec.size();i++)
    {
        mp[vec[i]]++;
    }
    for(auto it:mp)
    {
        if(it.first==x)
        {
            if(it.second>0)
            {
                return it.second;
            }
        }
    }
    return 0;
} 
*/


// Approach 2

int find_freq(vector<int> vec,int x)
{
    int cnt=0;
    for(int i=0;i<vec.size();i++)
    {
        if(vec[i]==x)
        {
            cnt++;
        }
    }
    return cnt;
}

int main(){
    vector<int>vec{1,1,1,1,1};
    int x=1;
    cout<<"The frequenc of x is: ";
    cout<<find_freq(vec,x);
return 0;
}