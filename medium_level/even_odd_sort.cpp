// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;
// int sorting(vector<int>&vec,int n)
// {
//     int i=0;
//     int j=n-1;
//     while(i<j)
//     {
//         if(vec[i]%2==0)
//         {
//             i++;
//         }
//         else if(vec[j]%2==1)
//         {
//             j--;
//         }
//         else if(vec[i]%2==1 and vec[j]%2==0)
//         {
//             swap(vec[i],vec[j]);
//             i++;j--;
//         }
//     }
// }
// int main(){
//     vector<int> vec{10,12,13,18,16,15};
//     int n=vec.size();
//     for(int i=0;i<n;i++)
//     {
//         cout<<vec[i]<<" ";
//     }
//     sorting(vec,n);
//     cout<<"\nThe array is: ";
//     for(int i=0;i<n;i++)
//     {
//         cout<<vec[i]<<" ";
//     } 
// return 0;
// }