
//complement of number: 
/*
#include<iostream>
using namespace std;

int complement(int n)
{
    return n>>1;
}

int main(){
    int n=10;
    cout<<"\nAnswer: "<<complement(n);
return 0;
}
*/

// Alternate array.
/*
#include<iostream>
using namespace std;

int func(int arr[],int n)
{
    for(int i=0;i<n;i+=2)
    {
        if(i+1<n)
        {
        swap(arr[i],arr[i+1]);
        }
    }

}
void print(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main(){
    int arr[]={10, 20, 30, 40, 50, 60};
    int n=sizeof(arr)/sizeof(arr[0]);
    func(arr,n);    
    print(arr,n);
return 0;
}
*/

//Unique Element.
/*
#include<iostream>
using namespace std;

int unique(int arr[],int n)
{
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans=ans^arr[i];
    }
    return ans;
}

int main(){
    int arr[]={10,20,30,10,20,30,80};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"\nAnswer: "<<unique(arr,n);
return 0;
}
*/

// if no are repeted then tru othewise false.
/*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool repeted(int arr[],int n)
{
    vector<int>v(128,0);
    for(int i=0;i<n;i++)
    {
        v[arr[i]]++;
    }

    for(int i=0;i<n;i++)
    {
        if(v[i]>1)
        {
            return true;
        }
    }
    return false;
}

int main(){
    int arr[]={1,2,3,4,5,6,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    if(repeted(arr,n))
    {
        cout<<"Digits Are Repeted.";
    }
    else
    {
        cout<<"Digits Are Not Repeated.";
    }
return 0;
}
*/
/*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool repeted(int arr[],int n)
{
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        mp[arr[i]]++;
    }
    for(auto i:mp)
    {
        if(i.second>1)
        return true;
    }
    return false;
}

int main(){
    int arr[]={1,2,3,4,5,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    if(repeted(arr,n))
    {
        cout<<"Digits Are Repeted.";
    }
    else
    {
        cout<<"Digits Are Not Repeated.";
    }
return 0;
}
*/

//Intersection of the array.
/*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int>intersection(vector<int>a1,vector<int>a2,int n)
{
    vector<int>ans;
    int i=0,j=0;
    while(i<n && j<n)
    {
        if(a1[i]==a2[j])
        {
            ans.push_back(a1[i]);
            i++;
            j++;
        }
        else if(a1[i]<a2[j])
        {
            i++;
        }
        else if(a1[i]>a2[j])
        {
            j++;
        }
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter the limit of array: ";
    cin>>n;
    vector<int>a1(n);
    vector<int>a2(n);
    cout<<"Enter the value of array:  ";
    for(int i=0;i<n;i++)
    {
        cin>>a1[i];
    }
    cout<<"Enter the valuees of array: ";
    for(int  i=0;i<n;i++)
    {
        cin>>a2[i];
    }

    vector<int>ans=intersection(a1,a2,n);
    cout<<"\nIntersection of array: ";
    for(auto i=ans.begin();i<ans.end();i++)
    {
        cout<<*i<<" ";
    }
return 0;
}
*/

//Binary Search.
/*
#include<iostream>
using namespace std;

int BinarySearch(int arr[],int n,int x)
{
    int s=0;
    int e=n-1;
    int mid=s+(e-s)/2;

    while(s<=e)
    {
        if(arr[mid]==x)
        {
            return mid;
        }
        else if(arr[mid]>x)
        {
            e=mid-1;
        }
        else
        {
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return -1;
}

int main(){
    int arr[]={10,20,30,40,50,60,70,80,90,100};
    int x;
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"Insert an element for search: ";
    cin>>x;
    cout<<"The index of the digit is: "<<BinarySearch(arr,n,x);    
return 0;
}
*/

// first and last element.
/*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int FirstIndex(int arr[],int n,int x)
{
    int ans=-1;
    int s=0;
    int e=n-1;
    int mid=s+(e-s)/2;

    while(s<=e)
    {
        if(arr[mid]==x)
        {
            ans=mid;
            e=mid-1;
        }
        else if(arr[mid]>x)
        {
            e=mid-1;
        }
        else
        {
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}

int LastIndex(int arr[],int n,int x)
{
    int ans=-1;
    int s=0;
    int e=n-1;
    int mid=s+(e-s)/2;

    while(s<=e)
    {
        if(arr[mid]==x)
        {
            ans=mid;
            s=mid+1;
        }
        else if(arr[mid]>x)
        {
            e=mid-1;
        }
        else
        {
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}

int main(){
    int arr[]={1,2,3,3,3,3,3,3,3,3,3,4,5,6,7,8};
    int n=sizeof(arr)/sizeof(arr[0]);
    int s;
    cout<<"Enter the digit for search:  ";
    cin>>s;
    cout<<"\nThe First Index is: "<<FirstIndex(arr,n,s);
    cout<<"\nThe Last Index is: "<<LastIndex(arr,n,s);
return 0;
}
*/

//Mountain Numbers.

#include<iostream>
using namespace std;

int mountain(int arr[],int n)
{
    int s=0;
    int e=n-1;
    int mid=(s+e)/2;
    int ans=-1;

    while(s<e)
    {
        if(arr[mid]<arr[mid+1])
        {
            s=mid+1;
            ans=arr[s];
        }
        else 
        {
            e=mid;
        }
        mid=(s+e)/2;
    }
    return ans;
}

int main(){
    int arr[]={2,3,4,6,15,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"\nThe Mountain Element is: "<<mountain(arr,n);
return 0;
}


































