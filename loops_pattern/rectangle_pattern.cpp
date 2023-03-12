#include<iostream>
using namespace std;
int main(){
    int n,m;
    cout<<"Enter the values of rows: ";
    cin>>n;
    cout<<"Enter the values of coloum: ";
    cin>>m;
    for(int i=0;i<n;i++)
    {
        for(int i=0;i<m;i++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
return 0;
}