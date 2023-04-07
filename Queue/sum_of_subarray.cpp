//Approach - 1.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int max_sum(int arr[],int n,int k)
{
    deque<int>maxi(k);
    deque<int>mini(k);

    for(int i=0;i<k;i++)
    {
        while( !maxi.empty() && arr[maxi.back()] <= arr[i] )
        maxi.pop_back();

        while( !mini.empty() && arr[mini.back()] >= arr[i] )
        mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);        
    }
    int ans=0;
    for(int i=k;i<n;i++)
    {
        ans+=arr[maxi.front()]+arr[mini.front()];

        while(!maxi.empty() && i-maxi.front()>=k)
        {
            maxi.pop_front();
        }
        while(!mini.empty() && i-mini.front()>=k)
        {
            mini.pop_front();
        }

        while(!maxi.empty() && arr[maxi.back()] <= arr[i])
        maxi.pop_back();

        while(!mini.empty() && arr[mini.back()] >= arr[i])
        mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);
    }
    ans+=arr[maxi.front()]+arr[mini.front()];

    return ans;
}

int main(){
    int arr[]={2,5,-1,7,-3,-1,-2};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=4;
    cout<<"Answer: "<<max_sum(arr,n,k);
return 0;
}

/*
Approach - 2.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int max_sum(int arr[],int n)
{
    int k;
    cout<<"Enter the values of K: ";
    cin>>k;
    int max=INT16_MIN;
    int min=INT16_MAX;
    int ans=0;

    for(int i=0;i<=n-k;i++)
    {
        for(int j=i;j<k+i;j++)
        {
            if(arr[j]>max)
            {
                max=arr[j];
            }
            
            if(arr[j]<min)
            {
                min=arr[j];
            }
        }
        ans=ans+(max+min);
    }
    return ans;
}
int main(){
    int arr[]={2,5,-1,7,-3,-1,-2};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"Answer: "<<max_sum(arr,n);
return 0;
}
*/