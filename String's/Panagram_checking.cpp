/*
Panagram Checking
Given a string s check if it is "Panagram" or not.
A "Panagram" is a sentence containing every letter in the English Alphabet.
Example 1:
Input:
s = "Bawds jog, flick quartz, vex nymph"
Output: 
1
Explanation: 
In the given input, there
are all the letters of the English
alphabet. Hence, the output is 1.

Example 2:
Input:
s = "sdfs"
Output: 
0
Explanation: 
In the given input, there
aren't all the letters present in the
English alphabet. Hence, the output
is 0.
Your Task:
You do not have to take any input or print anything. You need to complete the function checkPangram() that takes a string as a parameter and returns true if the string is a Panagram, or else it returns false.

Expected Time Complexity: O( |s| )
Expected Auxiliary Space: O(1)
|s| denotes the length of the input string.

Constraints:
1 ≤ |s| ≤ 104
Both Uppercase & Lowercase are considerable
*/

//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to check if a string is Pangram or not.
    
    bool checkPangram (string s) {
        if(s.length()<26)
        {
            return false;
        }
        
        unordered_map<int,int>mp;
        for(auto x:s)
        {
            if(x>='A' and x<='Z')
            {
                mp[x-'A']++;
            }
            else if(x>='a' and x<='z')
            {
                mp[x-'a']++;
            }
        }
        return mp.size()==26;
    }
};
int main()
{
    int t;
    cout<<"Enter the number of test cases: ";
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--){
        string s;
        cout<<"enter the string: ";
        getline(cin, s);
        Solution obj; 
        if (obj.checkPangram(s) == true)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return(0);
}
