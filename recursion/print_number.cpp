#include <iostream>
using namespace std;
void func(int n, string arr[])
{
    if (n == 0)
        return;

    int digit = n % 10;
    n /= 10;
    // cout << arr[digit] << " ";
    func(n, arr);
    cout << endl;
    cout << arr[digit] << " ";
}
int main()
{
    string arr[11] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE", "TEN"};
    int n;
    cout << "Enter the number: ";
    cin >> n;
    func(n, arr);
    return 0;
}

/*
***with even odd***


#include<iostream>
using namespace std;
void func(int n,string arr[])
{
    if(n==0)
    return;

    int digit=n%10;
    n/=10;
    func(n,arr);
    if(digit%2 == 0 )
    {
        cout<<"Even"<<" ";
    }
    else
    {
        cout<<"Odd"<<" ";
    }
    cout<<arr[digit]<<" ";
}
int main(){
    string arr[11]={ "ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE","TEN"};
    // int x=sizeof(arr)/sizeof(arr[0]);
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    func(n,arr);
return 0;
}*/