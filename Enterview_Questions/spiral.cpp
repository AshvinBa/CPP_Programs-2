// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;
// void spiral_path(vector<vector<int>>&vec)
// {
//     int left=0;
//     int right=vec[0].size()-1;
//     int top=0;
//     int bottom=vec.size()-1;
//     int direction=0;

//     while(left<=right && top<=bottom)
//     {
//         if(direction==0)
//         {
//             for(int col=left;col<=right;col++)
//             {
//                 cout<<vec[top][col]<<" ";
//             }
//             top++;
//         }

//         else if(direction== 1)
//         {
//             for(int row=top;row<=bottom;row++)
//             {
//                 cout<<vec[row][right]<<" ";
//             }
//             right--;
//         }
//         else if(direction== 2)
//         {
//             for(int col=right;col>=left;col--)
//             {
//                 cout<<vec[bottom][col]<<" ";
//             }
//             bottom--;
//         }
//         else if(direction== 3)
//         {
//             for(int row=bottom;row>=top;row--)
//             {
//                 cout<<vec[row][left]<<" ";
//             }
//             left++;
//         }        


//         direction=(direction+1)%4;
//     }

// }
// int main(){
//     int n,m;
//     cout<<"Enter the Row and Coloumn: ";
//     cin>>n>>m;
//     vector<vector<int>>vec(n,vector<int>(m));
//     cout<<"Enter the values: ";
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<m;j++)
//         {
//             cin>>vec[i][j];
//         }
//     }
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<m;j++)
//         {
//             cout<<setw(2)<<vec[i][j]<<" ";
//         }
//         cout<<endl;
//     }
//     spiral_path(vec);
// return 0;
// }