#include<iostream>
using namespace std;

struct Pair
{
    int min;
    int max;
};

Pair min_max(int arr[],int n)
{
    struct Pair minmax;
    int i;

    if(n==1)
    {
    minmax.min=arr[0];
    minmax.max=arr[0];
    return minmax;
    }

    if(arr[0]>arr[1])
    {
        minmax.min=arr[1];
        minmax.max=arr[0];
    }
    else
    {
        minmax.min=arr[0];
        minmax.max=arr[1];
    }

    for(int i=2;i<n;i++)
    {
        if(arr[i]>minmax.max)
        {
            minmax.max=arr[i];
        }
        else
        {
            minmax.min=arr[i];
        }
    }
    return minmax;
}

int main(){
    int arr[]={5,4,2,1,3,8,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    struct Pair minmax=min_max(arr,n);
    cout<<endl;
    cout<<"The maximum element of array: "<<minmax.max<<endl;
    cout<<"The minimum element of array: "<<minmax.min;
return 0;
}




/*
IT TAKE MORE TIME COMPLEXITY.
*/
/*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int min(vector<int>vec1,int n)
{
    int min=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(min>vec1[i])
        {
            min=vec1[i];
        }
    }
    return min;
}

int max(vector<int>vec1,int n)
{
    int max=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(max<vec1[i])
        {
            max=vec1[i];
        }
    }
    return max;
}
int main(){
    int n;
    cout<<"Enter the limit: ";
    cin>>n;
    vector<int>vec1(n);
    cout<<"Enter the values: ";
    for(int i=0;i<n;i++)
    {
        cin>>vec1[i];
    }
    cout<<"The array is: ";
    for(int i=0;i<n;i++)
    {
        cout<<vec1[i]<<" ";
    }
    cout<<endl;
    cout<<"Maximum: "<<max(vec1,n)<<endl;
    cout<<"Minimum: "<<min(vec1,n)<<endl;
return 0;
}
*/