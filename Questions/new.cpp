//Three way Partision. 
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void threeWayPartition(vector<int>& array,int a, int b)
    {
        int l=0;
        int r=array.size()-1;
        
        for(int i=0;i<=r;i++)
        {
            if(array[i]<a)
            {
                swap(array[i],array[l]);
                l++;
            }
            else if(array[i]>b)
            {
                swap(array[i],array[r]);
                r--;
                i--;
            }
        }
    }
int main(){
    int a=1,b=3;
    vector<int>arr={1,2,3};
    cout<<"Answer: ";
    for(int i=0;i<arr.size();i++)
    {
        cout<<" "<<arr[i];
    }
return 0;
}