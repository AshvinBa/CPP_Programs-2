// #include<bits/stdc++.h>
// #include<iostream>
// using namespace std;
// int main(){
//     int n;
//     cout<<"Entre the size: ";
//     cin>>n;
//     vector<int>vec(n);
//     cout<<"Enter the values: ";
//     for(int i=0;i<n;i++)
//     {
//         cin>>vec[i];
//     }
//     int N=1e5+10;
//     vector<int>freq(N,0);
//     for(int i=0;i<n;i++)
//     {
//         freq[vec[i]]++;
//     }
//     int q;
//     cout<<"Enter how many querys: ";
//     cin>>q;

//     while(q--)
//     {
//         int ele;
//         cout<<"Enter the query Element: ";
//         cin>>ele;
//         cout<<" The element is: "<<freq[ele]<<endl;
//     }    
// return 0;
// }


#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int func(vector<int>&vec,int n)
{
    int i=0,j=n-1;
    while(i<j)
    {
    if(vec[i]==0 & vec[j]==1)
    {
        i++;j--;
    }
    else if(vec[i]==1 and vec[j]==0)
    {
        reverse(vec[i],vec[j]);
        i++;j--;
    }
    }
}
int main(){
    vector<int> vec{0,0,1,1,0,1};
    int n=vec.size();
    func(vec,n);
    cout<<"Array is: ";
    for(int i=0;i<n;i++)
    {
        cout<<vec[i]<<" ";
    }
return 0;
}