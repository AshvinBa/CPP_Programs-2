#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void solve( string digit, vector<string>&ans, string output, int index, string mapping[])
{

    if(index>=digit.length())
    {
        ans.push_back(output);
        return;
    }

    int number=digit[index]-'0';
    string value=mapping[number];

    for(int i=0;i<value.length();i++)
    {
        output.push_back(value[i]);
        solve(digit,ans,output,index+1,mapping);        
        output.pop_back();
    }
}

vector<string> letterCombination(string digit)
{
    vector<string>ans;

    if(digit.length()==0)
    return ans;

    string output="";
    int index=0;

    string mapping[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

    solve(digit,ans,output,index,mapping);

    return ans;
}
int main(){
    string digit="23";
    vector<string>st;
    st=letterCombination(digit);
    cout<<"Answer: ";
    for(auto i=st.begin();i!=st.end();i++)
    {
        cout<<*i<<" ";
    }
return 0;
}