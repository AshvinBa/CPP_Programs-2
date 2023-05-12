#include<bits/stdc++.h>
using namespace std;

int arrayOperations(int n, vector<int> &arr) 
    {
        int ans=0,l=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]==0)
            {
                if(l!=0) {
                    ans++;
                }
                l=0;
            }
            else
            {
                l++;
            }
        }
        if(l==n)
        return -1;
        
        if(l!=0)ans++;
        return ans;
    }

int main(){

    vector<int>arr{3,0,4,5};
    int n=arr.size();
    cout<<"Answer: "<<arrayOperations(n, arr)<<endl;
return 0;
}