/*

String Mirror

You are given a string str of length n. You want to choose a non-zero integer k (k<=n), such that you can perform the following operation:
Take the prefix of the string of length k and append the reverse of it to itself.
Your task is to find the lexicographically smallest string you can get.

Example 1:

Input:
str = "bvdfndkn"
Output:
bb
Explanation:
If we choose k=1, prefix of length k will be "b", reverse of
this prefix will be "b" itself, when we append both we get "bb",
"bb" is the lexicographically smallest string you can get.
If you choose k>1, the resulting string will not be 
lexicographically smaller than "bb".

*/


#include<iostream>
using namespace std;

string stringMirror(string str){
        string prefix="";
        prefix+=str[0];
        
        for(int i=1;i<str.length();i++)
        {
            char crntchr=str[i];
            char prevchr=str[i-1];
            if(crntchr>prevchr)
            {
                break;
            }
            if(crntchr==str[0])
            {
                break;
            }
            prefix+=crntchr;
        }
        string mirrorpref=prefix;
        string reversedpref=string(mirrorpref.rbegin(),mirrorpref.rend());
        mirrorpref+=reversedpref;
        
        return mirrorpref;
    }

int main(){
    string str="bvdfndkn";
    cout<<"\nAnswer: "<<stringMirror(str);    
return 0;
}  