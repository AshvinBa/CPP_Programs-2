//Approach - 1 
//TC = O(n1+n2+n3)
//SC = O(n1+n2+n3)

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> common_num(int A[], int B[], int C[], int n1, int n2, int n3)
{

    unordered_map<int, int> m1, m2, m3;

    for (int i = 0; i < n1; i++)
        m1[A[i]]++;
    for (int i = 0; i < n2; i++)
        m2[B[i]]++;
    for (int i = 0; i < n3; i++)
        m3[C[i]]++;

    vector<int> vec;

    for (int i = 0; i < n1; i++)
    {
        if (m1[A[i]] == m2[A[i]] && m2[A[i]] == m3[A[i]])
            vec.push_back(A[i]);
        m1[A[i]] = 0;
    }
    return vec;
}
int main()
{
    int arr1[] = {10, 20, 30, 40, 50};
    int arr2[] = {25, 30, 35, 40, 55};
    int arr3[] = {15, 22, 30, 40, 58};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);
    int k = sizeof(arr3) / sizeof(arr3[0]);
    vector<int> ans = common_num(arr1, arr2, arr3, n, m, k);
    cout << "Answer: ";
    for (auto i = ans.begin(); i != ans.end(); i++)
    {
        cout << *i << " ";
    }
    return 0;
}


//Approach - 2 
//TC = O(n1+n2+n3)
//SC = O(1)

/*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> common_num(int arr1[],int arr2[],int arr3[],int n1,int n2,int n3)
{
    vector<int>vec;
    int i=0,j=0,k=0;

    while(i<n1 && j<n2 && k<n3)
    {
        if(arr1[i]==arr2[j] && arr2[j]==arr3[k])
        {
            vec.push_back(arr1[i]);
            i++;
            j++;
            k++;
        }
        else if(arr1[i]<arr2[j])
        {
            i++;
        }
        else if(arr2[j]<arr3[k])
        {
            j++;
        }
        else
        {
            k++;
        }
        int x=arr1[i-1];
        while(x==arr1[i])
        {
            i++;
        }

        int y=arr2[j-1];
        while(y==arr2[j])
        {
            j++;
        }

        int z=arr3[k-1];
        while(z==arr3[k])
        {
            k++;
        }
    }

    // cout<<"Answer: ";
    // for(int i=0;i<vec.size();i++)
    // {
    //     cout<<vec[i]<<" ";
    // }
    return vec;
}

int main()
{
    int arr1[] = {10, 20, 30, 40, 50};
    int arr2[] = {25, 30, 35, 40, 55};
    int arr3[] = {15, 22, 30, 40, 58};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);
    int k = sizeof(arr3) / sizeof(arr3[0]);
    cout << "Answer: ";
    vector<int>ans = common_num(arr1, arr2, arr3, n, m, k);
    for(auto i=ans.begin();i!=ans.end();i++)
    {
        cout<<*i<<" ";
    }
    return 0;
}
*/


