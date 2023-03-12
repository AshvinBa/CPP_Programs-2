// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n;
//     cout<<"Enter the size: ";
//     cin>>n;
//     vector<int>vec(n);
//     cout<<"Enter the values: ";
//     for(int i=0;i<n;i++)
//     {
//         cin>>vec[i];
//     }
//     int x,pairs=0;
//     cout<<"Enter the numbers: ";
//     cin>>x;
//     for(int i=0;i<n;i++)
//     {
//         for(int j=i+1;j<n;j++)
//         {
//             if(vec[i]+vec[j]==x)
//             {
//                 pairs++;
//             }
//         }
//     }
//     cout<<"PAIRS ARE: "<<pairs<<endl;
// return 0;
// }



// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;
// int func(vector<int>vec,int i,int j,int n,int x,int pairs)
// {
//     if(vec[i]==n)
//     return 0;

//     if(vec[i]+vec[j]==x)
//     {
//         pairs++;
//     }
//     return pairs;
    
//     return func(vec,i+1,j,n,x,pairs);
//     return func(vec,i,j+i,n,x,pairs);
// }
// int main(){
//     vector<int>vec{11,12,13,14,15,16,17,18,19,20};
//     int i=0,j=i+1;
//     int n=vec.size();
//     // cout<<n;
//     int x;
//     cout<<"Enter the value of x: ";
//     cin>>x;
//     int pairs=0;
//     int m=func(vec,i,j,n,x,pairs);
//     cout<<m;
// return 0;
// }














