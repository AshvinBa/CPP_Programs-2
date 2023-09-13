/*
Index Of an Extra Element

Given two sorted arrays of distinct elements. There is only 1 difference between the arrays. First array has one element extra added in between. Find the index of the extra element.

Example 1:

Input:
N = 7
A[] = {2,4,6,8,9,10,12}
B[] = {2,4,6,8,10,12}
Output: 4
Explanation: In the second array, 9 is
missing and it's index in the first array
is 4.
Example 2:

Input:
N = 6
A[] = {3,5,7,9,11,13}
B[] = {3,5,7,11,13}
Output: 3
Your Task:
You don't have to take any input. Just complete the provided function findExtra() that takes array A[], B[] and size of A[] and return the valid index (0 based indexing).

Expected Time Complexity: O(log N).
Expected Auxiliary Space: O(1).

Constraints:
2<=N<=104
1<=Ai<=105
*/

#include<iostream>
using namespace std;
  int findExtra(int a[], int b[], int n) {
    
    if(n==1)
    return 0;
    if(a[0]!=b[0])
    return 0;
    
        int s=0;
        int e=n-1;
        int mid=(s+e)/2;
        
        while(s<=e)
        {
         
         mid=(s+e)/2;
         
         if(a[mid]!=b[mid] && a[mid-1] == b[mid-1])
         {
             return mid;
         }
         else if(a[mid]==b[mid])
         {
             s=mid+1;
         }
         else
         {
             e=mid-1;
         }
         
        }
        return -1;
    }
int main(){
    int N = 7;
    int A[] = {2,4,6,8,9,10,12};
    int B[] = {2,4,6,8,10,12};
    cout<<"Answer: "<<findExtra(A, B, N);
return 0;
}