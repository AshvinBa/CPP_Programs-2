/*
Find all pairs with a given sum

Given two unsorted arrays A of size N and B of size M of distinct elements, the task is to find all pairs from both arrays whose sum is equal to X.

Note: All pairs should be printed in increasing order of u. For eg. for two pairs (u1,v1) and (u2,v2), if u1 < u2 then
(u1,v1) should be printed first else second.

Example 1:
Input:
A[] = {1, 2, 4, 5, 7}
B[] = {5, 6, 3, 4, 8} 
X = 9 
Output: 
1 8
4 5 
5 4
Explanation:
(1, 8), (4, 5), (5, 4) are the
pairs which sum to 9.

Example 2:
Input:
A[] = {-1, -2, 4, -6, 5, 7}
B[] = {6, 3, 4, 0} 
X = 8 
Output:
4 4 
5 3

*/
#include <bits/stdc++.h>
using namespace std;
    static bool cmp(pair<int,int>&a,pair<int,int>&b)
    {
        return a.first<b.first;
    }
    vector<pair<int,int>> allPairs(int A[], int B[], int N, int M, int X)
    {
        vector<pair<int,int>> ans;
        unordered_set<int>s;
        
        for(int i=0;i<N;i++)
        {
            s.insert(A[i]);
        }
        
        for(int i=0;i<M;i++)
        {
            if(s.find(X-B[i])!=s.end())
            {
                ans.push_back({X-B[i],B[i]});
            }
            
        }
        sort(ans.begin(),ans.end(),cmp);
        return ans;
    }
int main() {
    int N, M, X;
    cout<<"Enter the value of first size: ";
	    cin >> N;
    cout<<"Enter the value of second size: ";
        cin >> M;
    cout<<"Enter the value: ";    
        cin >> X;
        int A[N], B[M];
    cout<<"Enter the values of 1st: ";    
	    for(int i = 0;i<N;i++)
	        cin >> A[i];
    cout<<"Enter the values of 2st: ";
	    for(int i = 0;i<M;i++)
	        cin >> B[i];
	        
	   vector<pair<int,int>> vp = allPairs(A, B, N, M, X);
	   int sz = vp.size();
        if(sz==0)
        cout<<-1<<endl;
        else{
            for(int i=0;i<sz;i++){
                if(i==0)
                cout<<vp[i].first<<" "<<vp[i].second;
                else
                cout<<", "<<vp[i].first<<" "<<vp[i].second;
            }
            cout<<endl;
        }
	
	return 0;
}

/*
APPROACH -1 

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

vector<int> allPairs(int A[], int B[], int N, int M, int X)
{
    vector<int>ans;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(A[i]+B[j]==X)
            {
                ans.push_back(A[i]);
                ans.push_back(B[j]);
            }
        }
    }        
    if(ans.size()>0)
    {
        return ans;
    }
    else
    {
        return {-1};
    }
}

int main(){
    int N, M, X;
    cout<<"Enter the value of first size: ";
	    cin >> N;
    cout<<"Enter the value of second size: ";
        cin >> M;
    cout<<"Enter the value: ";    
        cin >> X;
        int A[N], B[M];
    cout<<"Enter the values of 1st: ";    
	    for(int i = 0;i<N;i++)
	        cin >> A[i];
    cout<<"Enter the values of 2st: ";
	    for(int i = 0;i<M;i++)
	        cin >> B[i];
	        
	    vector<int> vp = allPairs(A, B, N, M, X);
	    for(auto i=vp.begin();i<vp.end();i++)
        {
            cout<<*i<<" ";
        }
	
return 0;
}*/