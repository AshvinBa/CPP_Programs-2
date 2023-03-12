// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int idx=0;
//     vector<int> vec;
//     cout<<"Enter the values: ";
//     for(int i=0;i<10;i++)
//     {
//         int ele;
//         cin>>ele;
//         vec.push_back(ele);
//     }
//     cout<<"\nBefore erasing: \n";
//     while(idx<vec.size())
//     {
//         cout<<vec[idx++]<<" ";
//     }

//     vec.erase(vec.end()-2);
//     cout<<"\nAfter erase: ";
//     for(int i=0;i<vec.size();i++)
//     {
//         cout<<vec[i]<<" ";
//     }
    

//     vec.erase(vec.end()-4);
//     cout<<"\nAfter erase: ";
//     for(int i=0;i<vec.size();i++)
//     {
//         cout<<vec[i]<<" ";
//     }

//     vec.erase(vec.end()-7);
//     cout<<"\nAfter erase: ";
//     for(int i=0;i<vec.size();i++)
//     {
//         cout<<vec[i]<<" ";
//     }
// return 0;
// }


// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n,m;
//     cout<<"\nEnter the rows: ";
//     cin>>n;
//     cout<<"\nEnter the coloum: ";
//     cin>>m;
//     vector<vector<int>>vec(n,vector<int>(m));
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<m;j++)
//         {
//             cin>>vec[i][j];
//         }
//     }

//     cout<<"\nEnter the rows: ";
//     cin>>n;
//     cout<<"\nEnter the coloum: ";
//     cin>>m;
//     vector<vector<int>>vec1(n,vector<int>(m));
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<m;j++)
//         {
//             cin>>vec1[i][j];
//         }
//     }

//     cout<<"\nThe matrix 1 is: "<<endl;
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<m;j++)
//         {
//             cout<<vec[i][j]<<" ";
//         }
//         cout<<endl;
//     }

//     cout<<"\nThe matrix 2 is: "<<endl;
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<m;j++)
//         {
//             cout<<vec1[i][j]<<" ";
//         }
//         cout<<endl;
//     }


//     cout<<"\n\nThe sum of the matrix is: \n";
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<m;j++)
//         {
//             cout<<vec[i][j]+vec1[i][j]<<" ";
//         }
//         cout<<endl;
//     }
// return 0;
// }

















