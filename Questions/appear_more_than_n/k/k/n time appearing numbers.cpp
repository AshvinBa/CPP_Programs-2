/*  find smallest sub array of given sum */

#include<bits/stdc++.h>
using namespace std;
    int smallestSubWithSum(int arr[], int n, int x)
    {
        int ans=0;
        int sum=arr[0];
        bool isfound=false;
        int l=0,r=l+1;
        while(l<n && r<n)
        {
            if(sum==x)
            {
                isfound=true;
                break;
            }
            else if(sum<x)
            {
                r++;
                if(r<n)
                {
                    sum+=arr[r];
                    ans++;
                }
            }
            else
            {
                sum-=arr[l];
                // ans--;
                l++;
            }
        }
        return ans;
    }
int main() {

    int x=51,n=6;
		int a[100]={1,4,45,6,0,9};
		cout<<smallestSubWithSum(a,n,x)<<endl;
	
	return 0;
}