#include <bits/stdc++.h>
using namespace std;
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int p1=m-1, p2=n-1, i=m+n-1;

    while( p2>=0)
    {
        if(p1>=0 && nums1[p1]>nums2[p2])
        {
            nums1[i--]=nums1[p1--];
        }
        else
        {
            nums1[i--]=nums2[p2--];
        }
    }

    for(int i=0;i<nums1.size();i++)
    {
        cout<<nums1[i]<<" ";
    }

}
int main()
{
    vector<int> vec1{1, 2, 3, 3, 4, 5};
    vector<int> vec2{1, 3, 3, 4, 5, 6};
    int n = sizeof(vec1);
    int m = sizeof(vec2);
    merge(vec1, n, vec2, m);
    return 0;
}