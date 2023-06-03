#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maxEqualSum(int n1,int n2,int n3,vector<int>arr1,vector<int>arr2,vector<int>arr3)
{
    int i=0,j=0,k=0;
    int sum1=0,sum2=0,sum3=0;

    sum1=accumulate(arr1.begin(),arr1.end(),sum1);
    sum2=accumulate(arr2.begin(),arr2.end(),sum2);
    sum3=accumulate(arr3.begin(),arr3.end(),sum3);

    while(i<n1 && i<n2 && i<n3)
    {
        if(sum1==sum2 && sum2==sum3)
        {
            return sum1;
        }
        else if(sum1<=sum2 && sum1<=sum3)
        {
            if(sum1<sum2)
            {
                sum2-=arr2[j];
                j++;
            }
            if(sum1<sum3)
            {
                sum3-=arr3[k];
                k++;
            }
        }
        else if(sum2<=sum3 && sum2<=sum1)
        {
            if(sum2<sum1)
            {
                sum1-=arr1[i];
                i++;
            }
            if(sum2<sum3)
            {
                sum3-=arr3[k];
                k++;
            }
        }
        else
        {
            if(sum3<sum1)
            {
                sum1-=arr1[i];
                i++;
            }
            if(sum3<sum2)
            {
                sum2-=arr2[j];
                j++;
            }
        }
    }
    return 0;
}


int main(){
    vector<int>arr1{4,2,3};
    vector<int>arr2{1,1,2,3};
    vector<int>arr3{1,4};
    int n1=arr1.size();
    int n2=arr2.size();
    int n3=arr3.size();
    cout<<"Answer: "<<maxEqualSum(n1,n2,n3,arr1,arr2,arr3);
return 0;
}