/*
K largest elements
Given an array of N positive integers, print k largest elements from the array. 
Example 1:
Input:
N = 5, k = 2
arr[] = {12,5,787,1,23}
Output: 787 23
Explanation: First largest element in
the array is 787 and the second largest
is 23.

Example 2:
Input:
N = 7, k = 3
arr[] = {1,23,12,9,30,2,50}
Output: 50 30 23
Explanation: Three Largest element in
the array are 50, 30 and 23.
Your Task:
Complete the function kLargest() that takes the array, N and K as input parameters and returns a list of k largest element in descending order. 

Expected Time Complexity: O(N log K)
Expected Auxiliary Space: O(K)

Constraints:
1 ≤ N ≤ 104
K ≤ N
1 ≤ array[i] ≤ 105

*/


#include<bits/stdc++.h>
using namespace std;
class Solution
{    public:
    //Function to return k largest elements from an array.
    vector<int> kLargest(int arr[], int n, int k)
    {
        priority_queue<int,vector<int>,greater<int>>pq;
        vector<int>ans;
    
        for(int i=0;i<k;i++)
        {
            pq.push(arr[i]);
        }
        for(int i=k;i<n;i++)
        {
            if(pq.top()<arr[i])
            {
                pq.pop();
                pq.push(arr[i]);
            }
        }   
        while(pq.size()>0)
        {
            int n1=pq.top();
            pq.pop();
            ans.push_back(n1);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

int main(){
    int t;
    cout<<"Enter the test cases: ";
    cin >> t;
    while(t--){
        int n, k;
        cout<<"Enter the size and K values: ";
        cin >> n >> k;
        
        int arr[n];
        cout<<"Enter the values: ";
        for(int i = 0; i < n;i++)
            cin>>arr[i];
        Solution ob;
        vector<int> result = ob.kLargest(arr, n, k);
        cout<<"\nThe Kth largest values are: ";
        for (int i = 0; i < result.size(); ++i)
            cout<<result[i]<<" ";
        cout << endl;
    }
    return 0;
}
