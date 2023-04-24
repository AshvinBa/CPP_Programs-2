/*
Parenthesis Checker

Given an expression string x. Examine whether the pairs and the orders of {,},(,),[,] are correct in exp.
For example, the function should return 'true' for exp = [()]{}{[()()]()} and 'false' for exp = [(]).

Note: The drive code prints "balanced" if function return true, otherwise it prints "not balanced".

Example 1:

Input:
{([])}
Output:
true

Explanation:
{ ( [ ] ) }. Same colored brackets can form
balanced pairs, with 0 number of
unbalanced bracket.

*/
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

    //Function to check if brackets are balanced or not.
    bool check_Paranthesis(string x)
    {
        // Your code here
    stack<char> s;
    char x1;
    
    for(int i=0;i<x.length();i++)
    {
        if(x[i]=='(' ||x[i]=='{' ||x[i]=='[')
        {
            s.push(x[i]);
            continue;
        }
        
        if(s.empty())
        return false;
        
        switch(x[i])
        {
            case ')':
            {
            x1=s.top();
            s.pop();
            if(x1=='[' ||x1=='{')
            return false;
            break;
            }
            
            case '}':
            {
            x1=s.top();
            s.pop();
            if(x1==')' ||x1==']')
            return false;
            break;
            }
            
            case ']':
            {
            x1=s.top();
            s.pop();
            if(x1=='(' ||x1=='{')
            return false;
            break;
            }
        }
    }
    return (s.empty());
}

int main()
{
    string str = "{[[]}";
    cout<<check_Paranthesis(str);
    return 0;
}
