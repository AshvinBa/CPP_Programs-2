
// # HEAP STL
/*
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
    priority_queue<int>pq;
    priority_queue<int,vector<int>,greater<int>>min;

    int n=6;
    int arr[]={7,10,4,3,20,15};

    for(int i=0;i<n;i++)
    {
        pq.push(arr[i]);
        min.push(arr[i]);
    }

    cout<<"The values of MaxHeap are: ";
    while(0 < pq.size())
    {
        int f=pq.top();
        pq.pop();
        cout<<f<<" ";
    }
    cout<<endl;
    cout<<"The values of MinHeap are: ";
    while(min.size() > 0)
    {
        int mi=min.top();
        min.pop();
        cout<<mi<<" ";
    }
return 0;
}
*/


// # Heapify the array: 
/*
#include<iostream>
using namespace std;

void heapify(int arr[],int n,int i)
{
    int large=i;
    int left=2*i;
    int right=2*i+1;

    if( left < n && arr[large] < arr[left])
    {
        large=left;
    }

    if( right < n && arr[large] < arr[right])
    {
        large=right;
    }

    if(large!=i)
    {
        swap(arr[large],arr[i]);
        heapify(arr,n,i);
    }

}

int main(){
    int arr[]={-1,55,54,23,25,52,51,53};
    int n=7;

    for(int i=n/2;i>0;i--)
    {
        heapify(arr,n,i);
    }
    cout<<"The array after Heapify: ";
    for(int i=0;i<=n;i++)
    {
        cout<<arr[i]<<" ";
    }
return 0;
}
*/


// Kth smallest
#include<bits/stdc++.h>
#include<iostream>
using namespace std;


int Kth_smallest(int arr[],int k,int l,int r)
{
    priority_queue<int>pq;
    for(int i=0;i<k;i++)
    {
        pq.push(arr[i]);
    }
    for(int i=k;i<r;i++)
    {
        if(pq.top()>arr[i])
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    int ans=pq.top();
    return ans;
}

int Kth_largest(int arr[],int k,int l,int r)
{
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<k;i++)
    {
        pq.push(arr[i]);
    }
    for(int i=k;i<r;i++)
    {
        if(pq.top()<arr[i])
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    int ans=pq.top();
    return ans;
}
int main(){
    int n=15;
    int arr[]={7,10,4,3,20,15,45,85,11,77,5,6,12,35,24};
    int k=3;
    int l=0;
    int r=14;
    int ans1=Kth_smallest(arr,k,l,r);
    int ans2=Kth_largest(arr,k,l,n);
    cout<<"Kth Smallest Digit: "<<ans1<<endl;    
    cout<<"Kth Largest Digit: "<<ans2;
return 0;
}


















