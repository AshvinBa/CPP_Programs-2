#include<iostream>
using namespace std;

int main(){
    int n,m;
    cout<<"Enter the value of Row and Coloumn: ";
    cin>>n>>m;
    int **arr1=new int*[n];

    for(int i=0;i<n;i++)
    {
        arr1[i]=new int[n];
    }

    cout<<"Enter the value of matrix-1: ";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr1[i][j];
        }
    }

    int **arr2=new int*[n];

    for(int i=0;i<n;i++)
    {
        arr2[i]=new int[n];
    }

    cout<<"Enter the value of matrix-2: ";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr2[i][j];
        }
    }

    cout<<"The sum of the matrix: \n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<arr1[i][j]+arr2[i][j]<<" ";
        }
        cout<<endl;
    }
return 0;
}