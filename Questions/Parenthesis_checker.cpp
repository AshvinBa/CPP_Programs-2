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

Example 2:
Input: 
()
Output: 
true
Explanation: 
(). Same bracket can form balanced pairs, 
and here only 1 type of bracket is 
present and in balanced way.

Example 3:
Input: 
([]
Output: 
false
Explanation: 
([]. Here square bracket is balanced but 
the small bracket is not balanced and 
Hence , the output will be unbalanced.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool ispar(string x)
    {
        int n=x.size();
        stack<int>s;
        char a;
        for(int i=0;i<n;i++)
        {
            if(x[i]=='{'||x[i]=='('||x[i]=='[')
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
                a=s.top();
                s.pop();
                
                if(a=='{'||a=='[')
                return false;
            }
            break;
            
            case ']':
            {
                a=s.top();
                s.pop();
                
                if(a=='{'||a=='(')
                return false;
            }
            break;
            
            case '}':
            {
                a=s.top();
                s.pop();
                
                if(a=='['||a=='(')
                return false;
            }
            break;
        }
        }
        return (s.empty());
    }

int main(){
    string s="[[{()}]]";
    if(ispar(s))
    {
        cout<<"Yes.";
    }
    else
    {
        cout<<"No.";
    }
return 0;
}