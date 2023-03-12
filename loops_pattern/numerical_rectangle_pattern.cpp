#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the digit: ";
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            cout<<j<<" ";
        }
        for(int j=1;j<=(i-1);j++)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
return 0;
}

/*
output: 
Enter the digit: 5
1 2 3 4 5 
2 3 4 5 1 
3 4 5 1 2 
4 5 1 2 3 
5 1 2 3 4 
*/