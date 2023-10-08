#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int>merge(vector<int>vec1,vector<int>vec2)
{
    int n=vec1.size();
    int m=vec2.size();
    vector<int>result(n+m);
    int i=0,j=0,k=0;
    while(i<n and j<m)
    {
        if(vec1[i]>=vec2[j])
        {
            result[k]=vec2[j];
            j++;
            k++;
        }
        else if(vec1[i]<=vec2[j])
        {
            result[k]=vec1[i];
            i++;
            k++;
        }
    }
    while(i<n)
    {
        result[k]=vec1[i];
        i++;
        k++;
    }
    while(j<m)
    {
        result[k]=vec2[j];
        j++;
        k++;
    }
    return result;
}
int main(){
    int n,m;
    cout<<"\nEnter the limit for array-1 and array-2: ";
    cin>>n>>m;
    cout<<"\nEnter the values for a1: ";
    vector<int>vec1(n);
    for(int i=0;i<n;i++)
    {
        cin>>vec1[i];
    }
    cout<<"\nEnter the values for a2: ";
    vector<int>vec2(m);
    for(int i=0;i<m;i++)
    {
        cin>>vec2[i];
    }
    vector<int> mat;
    mat=merge(vec1,vec2);
    for(int i=0;i<mat.size();i++)
    {
        cout<<mat[i]<<" ";
    }
return 0;
}