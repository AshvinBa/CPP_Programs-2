/*
Armstrong Numbers

You are given a 3-digit number n, Find whether it is an Armstrong number or not.

An Armstrong number of three digits is a number such that the sum of the cubes of its digits is equal to the number itself. 371 is an Armstrong number since 33 + 73 + 13 = 371. 

Note: Return "true" if it is an Armstrong number else return "false".

Examples
Input: n = 153
Output: true
Explanation: 153 is an Armstrong number since 13 + 53 + 33 = 153. Hence answer is "true".

Input: n = 372
Output: false
Explanation: 372 is not an Armstrong number since 33 + 73 + 23 = 378. Hence answer is "false".

Expected Time Complexity: O(1)
Expected Auxiliary Space: O(1) 

Constraints:
100 ≤ n <1000 
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string armstrongNumber(int n) {
        
        int sum=0;
        
        int digit=n;
        
        while(digit!=0)
        {
            int lastNumber = digit%10;
            sum = sum + pow(lastNumber,3);
            digit = digit/10;
        }
        
        if( sum == n)
        {
            return "true"; 
        }
        else
        {
            return "false";
        }
    }
};

int main() {
    int t;
    cout<<"Enter the number of test cases: ";
    cin >> t;
    while (t--) {
        int n;
        cout<<"Enter the number: ";
        cin >> n;
        Solution ob;
        cout<<"The Number is Armstrong ? : ";
        cout << ob.armstrongNumber(n) << endl;
    }
    return 0;
}