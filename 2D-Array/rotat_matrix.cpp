#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int func(vector<vector<int>>&vec)
{
    int n=vec.size();
    int m=vec[0].size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            swap(vec[i][j],vec[j][i]);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            reverse(vec[i].begin(),vec[i].end());
        }
    }
}
int main(){
    int n,m;
    cout<<"Enter the row and colomn: ";
    cin>>n>>m;

    vector<vector<int>>vec(n,vector<int>(m));
    cout<<"Enter the values: ";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>vec[i][j];
        }
    }
    cout<<"\nThe matrix is: "<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
    func(vec);
    cout<<"\nThe matrix is:\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
return 0;
}



/*pascals Triangle*/
// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;
// vector<vector<int>>func(int n)
// {
//     vector<vector<int>>ans(n);
//     for(int i=0;i<n;i++)
//     {
//         ans[i].resize(i+1);
//         for(int j=0;j<=i;j++)
//         {
//             if(j==0 || j==i)
//             {
//                 ans[i][j]=1;
//             }
//             else
//             {
//                 ans[i][j]=ans[i-1][j]+ans[i-1][j-1];
//             }
//         }
//     }
//     return ans;
// }

// int main(){
//     int n;
//     cout<<"Enter the values: ";
//     cin>>n;
//     vector<vector<int>>vec;
//     vec=func(n);
//     cout<<"\nPascals Triangle:\n";
//     for(int i=0;i<vec.size();i++)
//     {
//         for(int j=0;j<vec[i].size();j++)
//         {
//             cout<<setw(3)<<vec[i][j]<<" ";
//         }
//         cout<<endl;
//     }
// return 0;
// }
















