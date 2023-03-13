// #include<iostream>
// using namespace std;
// int func(int arr[],int n)
// {
//     int s=0,e=n-1;
//     int m=(s+e)/2;
//     int ans;

//     while(s<e)
//     {
//         if(arr[m]<arr[m+1])
//         {
//             s=m+1;
//         }
//         else
//         {
//             e=m;
//         }
//         m=(s+e)/2;
//     }
//     return s;
// }
// int main(){

//     int arr[]={2,4,6,8,15,16,3};
//     // int arr[]={2,3,4,6,10,75,3};
//     int n=sizeof(arr)/sizeof(arr[0]);
//     cout<<func(arr,n);
// return 0;
// }



/*

#include<iostream>
using namespace std;
int func(int arr[],int n)
{
    int s=0,e=n-1;
    int m=(s+e)/2;
    int ans;

    while(s<e)
    {
        if(arr[m]<arr[m+1])
        {
            s=m+1;
            ans=arr[s];
            return ans;
        }
        else
        {
            e=m;
        }
        m=(s+e)/2;
    }
}
int main(){
    int arr[]={2,3,4,6,10,75,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<func(arr,n);
return 0;
}

*/


#include<iostream>
using namespace std;
int func(int *arr,int n,int s,int e)
{
    
    if(s>=e)
    {
        return -1;
    
    }

    int m=(s+e)/2;

    if(arr[m]<arr[m+1])
    {
        return s=m+1;
        return func(arr,n,s=m+1,e);
    }
    else if(arr[m]>arr[m+1])
    {
        e=m;
        return func(arr,n,s,e=m-1);
    }   
}
int main(){
    int arr[]={2,3,4,6,7,8,10,7,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"Index: "<<func(arr,n,0,n-1);
return 0;
}


















