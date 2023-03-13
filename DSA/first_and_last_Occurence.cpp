#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int first_occurence(vector<int> &v1, int n, int x)
{
    int start = 0;
    int end = n - 1;
    int mid = (start + end) / 2;
    int ans = -1;

    while (start <= end)
    {

        if (v1[mid] == x)
        {
            ans = mid;
            end = mid - 1;
        }
        else if (v1[mid] > x)
        {
            end = mid - 1;
        }
        else if (v1[mid] < x)
        {
            start = mid + 1;
        }

        mid = (start + end) / 2;
    }
    return ans;
}


int last_occurence(vector<int> &v1, int n, int x)
{
    int start = 0;
    int end = n - 1;
    int mid = (start + end) / 2;
    int ans = -1;

    while (start <= end)
    {

        if (v1[mid] == x)
        {
            ans = mid;
            start = mid + 1;
        }
        else if (v1[mid] > x)
        {
            end = mid - 1;
        }
        else if (v1[mid] < x)
        {
            start = mid + 1;
        }

        mid = (start + end) / 2;
    }
    return ans;
}
int main(){
    vector<int> v1{1, 2, 3, 3, 3, 3, 4, 5, 6};
    int n = v1.size();
    int x;
    cout << "Enter the element for search: ";
    cin >> x;
    cout<<first_occurence(v1,n,x)<<" "<<endl;
    cout<<last_occurence(v1,n,x);
return 0;
}