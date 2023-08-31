/*
Implement strstr

Your task is to implement the function strstr. The function takes two strings as arguments (s,x) and  locates the occurrence of the string x in the string s. The function returns an integer denoting the first occurrence of the string x in s (0 based indexing).
Note: You are not allowed to use inbuilt function.

Example 1:
Input:
s = GeeksForGeeks, x = Fr
Output: -1
Explanation: Fr is not present in the
string GeeksForGeeks as substring.
 

Example 2:
Input:
s = GeeksForGeeks, x = For
Output: 5
Explanation: For is present as substring
in GeeksForGeeks from index 5 (0 based
indexing).
*/

#include<iostream>
using namespace std;

int strstr(string s, string x)
{
    if(x.empty())
    {  
        return 0;
    }
    else
    {
        int fnd=s.find(x);
        if(fnd!=string::npos)
        {
            return fnd;
        }
        return -1;
    }
}
int main()
{
    string s="GeeksforGreek";
    string x="for";
    cout<<"The Index is: "<<strstr(s,x);
    return 0;
}