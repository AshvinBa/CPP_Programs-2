#include<iostream>
#include<bits/stdc++.h>
using namespace std;

long long maxProduct(vector<int> arr, int n) {
    int maxp=INT16_MIN;
    int prod=1;
    for(int i=0;i<n;i++)
    {
        prod*=arr[i];
        maxp=max(maxp,prod);
        if(prod==0)
        {
            prod=1;
        }
    }

    prod=1;
    for(int i=n-1;i>0;i--)
    {
        prod*=arr[i];
        maxp=max(maxp,prod);
        if(prod==0)
        {
            prod=1;
        }
    }
    return maxp;
    }

int main(){
    vector<int>vec{6, -3, -10, 0, 2};
    int n=vec.size();
    cout<<"Answer: "<<maxProduct(vec,n);
return 0;
}


