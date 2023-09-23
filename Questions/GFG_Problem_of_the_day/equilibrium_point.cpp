/*
Equilibrium Point
Given an array A of n positive numbers. The task is to find the first equilibrium point in an array. Equilibrium point in an array is a position such that the sum of elements before it is equal to the sum of elements after it.

Note: Return equilibrium point in 1-based indexing. Return -1 if no such point exists. 

Example 1:
Input: 
n = 5 
A[] = {1,3,5,2,2} 
Output: 
3 
Explanation:  
equilibrium point is at position 3 as sum of elements before it (1+3) = sum of elements after it (2+2). 

Example 2:
Input:
n = 1
A[] = {1}
Output: 
1
Explanation:
Since there's only element hence its only the equilibrium point.

Your Task:
The task is to complete the function equilibriumPoint() which takes the array and n as input parameters and returns the point of equilibrium. 

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 <= n <= 105
1 <= A[i] <= 109

*/

#include<iostream>
using namespace std;
int equilibriumPoint(long long a[], int n) {
    
    if(n==1)
    {
        return 1;
    }
    
    long long sum=0;
    
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
    }
    long long leftSum=0;
    long long rightSum;
    
    for(int i=1;i<n-1;i++)
    {
        leftSum+=a[i-1];
        rightSum=sum-a[i]-leftSum;
        if(leftSum == rightSum)
        {
            return i+1;
        }
    }
    return -1;
    }

int main(){
    long long a[]={1,3,5,2,2};
    int n=5;
    cout<<"Equilibrium Point: "<<equilibriumPoint(a,n);
return 0;
}
























