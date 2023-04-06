#include <bits/stdc++.h>
using namespace std;
bool sum(int arr[], int n)
{
    unordered_set<int> s;
    int pre_sum = 0;

    for (int i = 0; i < n; i++)
    {
        pre_sum += arr[i];

        if (pre_sum == 0)
            return true;

        if (s.find(pre_sum) != s.end())
            return true;

        s.insert(pre_sum);
    }
    return false;
}

int main()
{
    int n;
    int arr[] = {4, 2, -3, 1, 6};
    n = sizeof(arr) / sizeof(arr[0]);
    bool x = sum(arr, n);
    
    if (x == 1)
    {
        cout << "Yes.";
    }
    else
    {
        cout << "No.";
    }
    return 0;
}


/*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool sum(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==0)
        {
            return true;
        }
    }
    int ans;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<0)
        ans=arr[i];
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]+arr[j]==abs(ans))
            {
                return true;
            }
        }
    }
    return false;
}
int main(){
    int n;
    int arr[]={4, 2, -3, 1, 6};
    n=sizeof(arr)/sizeof(arr[0]);
    bool x=sum(arr,n);
    if(x==true)
    {
        cout<<"Yes.";
    }
    else
    {
        cout<<"No.";
    }
return 0;
}

*/