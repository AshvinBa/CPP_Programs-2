#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int func(vector<int>vec,int n)
{
    int maxindex=-1;
    int max=vec[0];
    for(int i=1;i<=n;i++)
    {
        if(vec[i]>max)
        {
        max=vec[i];
        maxindex=i;
        }
    }
    return maxindex;

}
int main(){
    vector<int>vec{1,2,12,23,45,4,1,15,2,444};
    int n=vec.size();
    int max=func(vec,n);
    int erase=max;
    cout<<"The largest element is index: "<<vec[erase]<<endl;
return 0;
}

