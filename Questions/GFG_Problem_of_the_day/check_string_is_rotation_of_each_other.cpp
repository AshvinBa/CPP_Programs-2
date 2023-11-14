/*

Check if strings are rotations of each other or not
You are given two strings of equal lengths, s1 and s2. The task is to check if s2 is a rotated version of the string s1.

Note: The characters in the strings are in lowercase.

Example 1:
Input:
geeksforgeeks
forgeeksgeeks
Output: 
1
Explanation: s1 is geeksforgeeks, s2 is
forgeeksgeeks. Clearly, s2 is a rotated
version of s1 as s2 can be obtained by
left-rotating s1 by 5 units.

Example 2:
Input:
mightandmagic
andmagicmigth
Output: 
0
Explanation: Here with any amount of
rotation s2 can't be obtained by s1.
Your Task:
You don't have to read or print anything. The task is to complete the function areRotations() which takes two strings, s1 and s2 as inputs and checks if the two strings are rotations of each other. The function returns true if s1 can be obtained by rotating s2, else it returns false.

Expected Time Complexity: O( |s1| ).
Expected Space Complexity: O( |s1| ).

Constraints:
1 <= |s1|, |s2| <= 105

*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool areRotations(string s1,string s2)
    {
        string ans=s1;
        int n1=s1.size();
        int n2=s2.size();
        
        if(n1!=n2)
        {
            return false;
        }
        
        if(s1==s2)
        {
            return true;
        }
        
        for(int i=0;i<n1;i++)
        {=ans.back();
            ans.pop_back();
            ans.insert(ans.begin(),end);
            
            if(ans==s2)
            {
                return true;
            }
        }
        return false;
    }

    int main()
    {
        string s1="amazon";
        string s2="zonama";
        if(areRotations(s1,s2))
        {
            cout<<"1"<<endl;
        }
        else
        {
            cout<<"0"<<endl;
        }
        return 0;
    }























