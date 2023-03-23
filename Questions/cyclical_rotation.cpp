
#include<iostream>
using namespace std;
int func(int arr[],int n)
{
    int x=arr[n-1];
    for(int i=n-1;i>0;i--)
    {
        arr[i]=arr[i-1];
    }
    arr[0]=x;
}
int main(){
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    func(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
return 0;
}








/*
90 degree rotation of matrix
*/
/*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int display(vector<vector<int>>vec,int n)
{
    cout<<"The array is:\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
}

int rotate_array(vector<vector<int>>&vec,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            swap(vec[i][j],vec[j][i]);
        }
    }
    display(vec,n);
    for(int i=0;i<n;i++)
    {
    reverse(vec[i].begin(),vec[i].end());
    }
    display(vec,n);
}


int main(){
    int n=3;
    cout<<"Enter the values: ";    
    vector<vector<int>>vec(n,vector<int>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>vec[i][j];
        }
    }
    display(vec,n);
    rotate_array(vec,n);
return 0;
}
*/












































