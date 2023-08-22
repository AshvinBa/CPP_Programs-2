/*
Maximum of all subarrays of size k

Given an array arr[] of size N and an integer K. Find the maximum for each and every contiguous subarray of size K.

Example 1:
Input:
N = 9, K = 3
arr[] = 1 2 3 1 4 5 2 3 6
Output:
3 3 4 5 5 5 6
Explanation:
1st contiguous subarray = {1 2 3} Max = 3
2nd contiguous subarray = {2 3 1} Max = 3
3rd contiguous subarray = {3 1 4} Max = 4
4th contiguous subarray = {1 4 5} Max = 5
5th contiguous subarray = {4 5 2} Max = 5
6th contiguous subarray = {5 2 3} Max = 5
7th contiguous subarray = {2 3 6} Max = 6

Example 2:
Input:
N = 10, K = 4
arr[] = 8 5 10 7 9 4 15 12 90 13
Output:
10 10 10 15 15 90 90
Explanation:
1st contiguous subarray = {8 5 10 7}, Max = 10
2nd contiguous subarray = {5 10 7 9}, Max = 10
3rd contiguous subarray = {10 7 9 4}, Max = 10
4th contiguous subarray = {7 9 4 15}, Max = 15
5th contiguous subarray = {9 4 15 12},
Max = 15
6th contiguous subarray = {4 15 12 90},
Max = 90
7th contiguous subarray = {15 12 90 13},
Max = 90

*/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// Approach is give the error as TLE at (67/166) Test Case.

int cnt_max(int arr[], int n, int k, int index)
{
    int cnt = 0;
    int i = index;
    int maxi = INT_MIN;
    while (cnt < k)
    {
        maxi = max(maxi, arr[i]);
        i++;
        cnt++;
    }
    return maxi;
}

vector<int> max_of_subarrays(int *arr, int n, int k)
{
    vector<int> add;
    for (int i = 0; i <= n - k; i++)
    {
        int ans = cnt_max(arr, n, k, i);
        add.push_back(ans);
    }
    return add;
}


int main() {
	
	    cout<<"Enter the limit and value of subarray: ";
	    int n, k;
	    cin >> n >> k;
        cout<<"Enter the values of array: ";	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    vector <int> res = max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	
	return 0;
}

/*

static ArrayList <Integer> max_of_subarrays(int arr[], int n, int k)
    {
        ArrayList<Integer> ans=new ArrayList<>();
        Deque<Integer> q=new ArrayDeque<>();
        
        for(int i=0;i<k;i++)
        {
            while(q.size()>0 && q.peekLast()<arr[i])
            {
                q.removeLast();
            }
            q.add(arr[i]);
        }
        ans.add(q.peek());
        int x=0;
        for(int i=k;i<n;i++)
        {
            if(q.peek()==arr[x])
            {
                q.remove();
            }
            x++;
            while(q.size()>0 && q.peekLast()<arr[i])
            {
                q.removeLast();
            }
            q.add(arr[i]);
            
            ans.add(q.peek());
        }
        return ans;
    }

*/