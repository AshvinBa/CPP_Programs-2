/*

Cake Distribution Problem

Geek is organizing a birthday party, so his friends brought a cake for him. The cake consists of N chunks, whose individual sweetness is represented by the sweetness array. Now at the time of distribution, Geek cuts the cake into K + 1 pieces to distribute among his K friends. One piece he took for himself. Each piece consists of some consecutive chunks. He is very kind, so he left the piece with minimum sweetness for him.

You need to find the maximum sweetness that the Geek can get if he distributes the cake optimally.

Example 1:

Input:
N  = 6, K = 2
sweetness[] = {6, 3, 2, 8, 7, 5}
Output:
9
Explanation:
Geek can divide the cake to [6, 3], [2, 8], [7, 5] 
with sweetness level 9, 10 and 12 respectively.

*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define ll long long int

    bool check(ll mid,vector<int>& arr,int N,int K)
    {
        ll sum=0;
        int count=0;
        
        for(int i=0;i<N;i++)
        {
            sum+=arr[i];
            if(sum>=mid)
            {
                count++;
                sum=0;
            }
        }
        return count>=K+1;
    }
    
    
    int maxSweetness(vector<int>& sweetness, int N, int K) {
        ll start=1,end=(ll)(1e14);
        ll ans=-1;
        
        while(start<=end)
        {
            ll mid=(start+end)/2;
            if(check(mid,sweetness,N,K))
            {
                ans=mid;
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        return ans;
    }

int main(){
    vector<int>sweet{6,3,2,8,7,5};
    int n=sweet.size();
    int k=2;
    cout<<"\nAnswer: "<<maxSweetness(sweet,n,k);    
return 0;
}