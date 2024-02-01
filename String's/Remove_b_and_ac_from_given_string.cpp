/*
Remove b and ac from a given string
Given a string, eliminate all “b” and “ac” in the string, replace them in-place and iterate over the string once.

Example 1:
Input: str = "aacbacc"
Output: ac
Explanation: Iterate once and remove
occurrence of "b" and "ac".

Example 2:
Input: str = "aacb"
Output: a
Explanation: Iterate once and remove
occurrence of "b" and "ac".

Your task:
Your task is to complete the function stringFilter() which takes a single string as input and modify the string as mentioned above. You need not take any input or print anything.
 
Expected Time Complexity: O(|s|)
Expected Auxiliary Space: O(1)

Constraints:
1 <= |S| <= 105
String contains lower case alphabets
*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    string stringFilter(string str) 
    { 
        int n=str.size();
        int i=0;
        string ans="";
        while(i<n)
        {
            if(str[i]=='a' and str[i+1]=='c')
            {
                i+=2;
            }
            else if(str[i]=='b')
            {
                i++;
            }
            else
            {
                ans+=str[i];
                i++;
            }
        }
        return ans;
    } 
};

int main() 
{
   	int t;
    cout<<"Enter the number of string: ";
   	cin >> t;
   	while(t--)
   	{
   		string s;
        cout<<"Enter the string: ";
   		cin >> s;
   		Solution ob;
   		cout <<ob.stringFilter(s) << "\n";	
   	}
    return 0;
}
