/*
Binary representation of next number

Given a binary representation in the form of a string(s) of a number n, the task is to find a binary representation of n+1.

Note: Output binary string should not contain leading zeros.

Example 1:
Input: s = "10"
Output: 11
Explanation: "10" is the binary representation of 2 and binary representation of 3 is "11"

Example 2:
Input: s = "111"
Output: 1000
Explanation: "111" is the binary representation of 7 and binary representation of 8 is "1000"
Your Task:  
You don't need to read input or print anything. Complete the function binaryNextNumber()which takes s as input parameter and returns the string.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n) to store resultant string  

Constraints:
1 <= n <= 105
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string binaryNextNumber(string s) {
        
        bool indication='true';
        
        for(int i=s.length();i>=0;i--)
        {
            if(s[i]=='0')
            {
                indication=false;
                s[i]='1';
                break;
            }
            else s[i]='0';
        }
        if(indication)
        {
            s='1'+s;
        }
        else
        {
            while(s[0]=='0')
            s.erase(s.begin());
        }
        return s;
        
    }
};

int main() {
        string s;
        cout<<"Enter the string: ";
        cin >> s;
        Solution ob;
        cout<<"the next nubmber: ";
        cout << ob.binaryNextNumber(s);
        cout << "\n";
    return 0;
}