/*

Kth smallest element

Given an array arr[] and an integer K where K is smaller than size of array, the task is to find the Kth smallest element in the given array. It is given that all array elements are distinct.

Note :-  l and r denotes the starting and ending index of the array.

Example 1:
Input:
N = 6
arr[] = 7 10 4 3 20 15
K = 3
L=0 R=5
Output : 7
Explanation :
3rd smallest element in the given 
array is 7.

Example 2:
Input:
N = 5
arr[] = 7 10 4 20 15
K = 4 L=0 R=4
Output : 15
Explanation :
4th smallest element in the given 
array is 15.
Your Task:
You don't have to read input or print anything. Your task is to complete the function kthSmallest() which takes the array arr[], integers l and r denoting the starting and ending index of the array and an integer K as input and returns the Kth smallest element.
 
 
Expected Time Complexity: O(n*log(n) )
Expected Auxiliary Space: O(log(n))
Constraints:
1 <= N <= 105
 L==0
 R==N-1
1<= arr[i] <= 105
1 <= K <= N

*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        
        priority_queue<int>pq;
        
        for(int i=l;i<k;i++)
        {
            pq.push(arr[i]);
        }
        
        for(int i=k;i<=r;i++)
        {
            if(pq.top()>arr[i])
            {
                pq.pop();
                pq.push(arr[i]);
            }
        }
        
        int ans=pq.top();
        return ans;
    }
};

int main()
{
    int test_case;
    cout<<"Enter the number of test cases: ";
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cout<<"Enter the limit values: ";
        cin>>number_of_elements;
        int a[number_of_elements];
        
        cout<<"Enter the values: ";
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cout<<"Enter the K values: ";
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}




























