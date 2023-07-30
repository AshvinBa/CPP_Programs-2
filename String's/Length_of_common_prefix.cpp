#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int LongestCommanPrefix(vector<string>&str)
{
    string s1=str[0];
    int ans_length=s1.size();

    for(int i=1;i<str.size();i++)
    {
        int j=0;
    
        while(j<s1.size() && j<str[i].size() && s1[j]==str[i][j])
        {
            j++;
        }
        ans_length=min(ans_length,j);
    }
    string ans=s1.substr(0,ans_length);
    return ans.size();
}

int main(){
    vector<string> str{"flower","flowerpot","flowerest","flown"};
    cout<<"\nThe Longest Comman Prefix: "<<LongestCommanPrefix(str);
return 0;
}


// Approach 2
/*

int LongestCommanPrefix(vector<string>&str)
{
    sort(str.begin(),str.end());
    string s1=str[0];
    string s2=str[str.size()-1];
    string result;
    for(int i=0;i<s1.size();i++)
    {
        if(s1[i]==s2[i])
        {
            result+=s1[i];
        }
    }
    return result.length();
}

*/
