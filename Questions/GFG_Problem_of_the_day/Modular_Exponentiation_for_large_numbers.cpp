/*
Modular Exponentiation for large numbers

Implement pow(x, n) % M.
In other words, for a given value of x, n, and M, find  (xn) % M.
 
Example 1:
Input:
x = 3, n = 2, m = 4
Output:
1
Explanation:
32 = 9. 9 % 4 = 1.

Example 2:
Input:
x = 2, n = 6, m = 10
Output:
4
Explanation:
26 = 64. 64 % 10 = 4.

Your Task:
You don't need to read or print anything. Your task is to complete the function PowMod() which takes integers x, n, and M as input parameters and returns xn % M.
 
Expected Time Complexity: O(log(n))
Expected Space Complexity: O(1)

Constraints:
1 ≤ x, n, M ≤ 109
*/


#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
		long long int PowMod(long long int x,long long int n,long long int M)
		{
		    long long int ans=1;
		    
		    while(n)
		    {
		        if(n%2==1)
		        ans=(ans*x)%M;
		        
		        x=(x*x)%M;
		        n/=2;
		    }
		    return ans;
		}
};

int main(){
    int T;
    cout<<"Enter the Number of testcases: ";
    cin >> T;
    while(T--)
    {
        cout<<"Entee the value of x , n , m: ";
    	long long int x, n, m;
    	cin >> x >> n >> m;
    	Solution ob;
    	long long int ans = ob.PowMod(x, n, m);
        cout<<"\nAnswer: ";
    	cout << ans <<"\n";
    }
	return 0;
}
