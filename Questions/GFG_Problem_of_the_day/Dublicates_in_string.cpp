/*
Remove all duplicates from a given string

Given a string Str which may contains lowercase and uppercase chracters. The task is to remove all duplicate characters from the string and find the resultant string. The order of remaining characters in the output should be same as in the original string.

Example 1:

Input:
Str = geeksforgeeks
Output: geksfor
Explanation: After removing duplicate
characters such as e, k, g, s, we have
string as "geksfor".
Example 2:

Input:
Str = HappyNewYear
Output: HapyNewYr
Explanation: After removing duplicate
characters such as p, e, a, we have
string as "HapyNewYr".

*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

string removeDuplicates(string str) {	    
	    vector<int>freq(200,0);
	    string s;
	    int j=0;
	    for(int i=0;i<str.length();i++)
	    {
	        if(freq[str[i]]==0)
	        {
	            s.push_back(str[i]);
	            freq[str[i]]++;
	        }
	    }
	    return s;
	}
int main(){
    string str;
    cout<<"Enter the string: ";
    cin>>str;
    cout<<"The String is: "<<removeDuplicates(str);
return 0;
}
