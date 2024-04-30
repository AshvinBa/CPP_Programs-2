/*
Prime Number
For a given number N check if it is prime or not. A prime number is a number which is only divisible by 1 and itself.

Example 1:
Input:
N = 5
Output:
1
Explanation:
5 has 2 factors 1 and 5 only.

Example 2:
Input:
N = 25
Output:
0
Explanation:
25 has 3 factors 1, 5, 25

Your Task:
You don't need to read input or print anything. Your task is to complete the function isPrime() 
which takes an integer N as input parameters and returns an integer, 1 if N is a prime number or 0 otherwise.
 
Expected Time Complexity: O(sqrt(N))
Expected Space Complexity: O(1)
*/

//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int isPrime(int N){
    if (N <= 1) {
        return 0;
    }
    if (N <= 3) {
        return 1;
    }
    if (N % 2 == 0 || N % 3 == 0) {
        return 0;
    }
    int i = 5;
    while (i * i <= N) {
        if (N % i == 0 || N % (i + 2) == 0) {
            return 0;
        }
        i += 6;
    }
    return 1;
    }
};

int main() 
{ 
    int t;
    cout<<"Number of test cases: ";
    cin>>t;
    while(t--)
    {
        int N;
        cout<<"Enter the values of N: ";
        cin>>N;
        Solution ob;
        cout<<"Answer: ";
        cout << ob.isPrime(N) << endl;
    }
    return 0; 
}
















