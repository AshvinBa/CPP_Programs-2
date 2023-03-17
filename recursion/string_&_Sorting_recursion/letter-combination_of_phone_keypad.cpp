// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;

// void solve(string digit, string output, int index, vector<string> &ans, string mapping[])
// {
//     if (index >= digit.length())
//     {   
//         ans.push_back(output);
//         return;
//     }
//     int number = digit[index] - '0';
//     string value = mapping[number];

//     for (int i = 0; i < value.length(); i++)
//     {
//         output.push_back(value[i]);
//         solve(digit, output, index + 1, ans, mapping);
//         output.pop_back();
//     }
// }
// vector<string> letterCombination(string digit)
// {
//     vector<string> ans;
//     if (digit.length() == 0)
//         return ans;

//     string output = "";
//     int index = 0;
//     string mapping[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
//     solve(digit, output, index, ans, mapping);
//     return ans;
// }
// int main()
// {
//     string digit ="45";
//     vector<string> vec;
//     vec = letterCombination(digit);
//     for (auto i = vec.begin(); i != vec.end(); i++)
//     {
//         cout << *i << " ";
//     }
//     return 0;
// }



#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void solve(string str,vector<string>&ans,string output,int index,string mapping[])
{
    if(index>=str.length())
    {
        ans.push_back(output);
        return;
    }

    int number=str[index]-'0';
    string value=mapping[number];

    for(int i=0;i<value.size();i++)
    {
        output.push_back(value[i]);
        solve(str,ans,output,index+1,mapping);
        output.pop_back();
    }
}
vector<string> combination(string str)
{
    vector<string> ans;
    string output="";
    int index=0;
    string mapping[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    solve(str,ans,output,index,mapping);
    return ans;
}
int main(){
    string str="23";
    vector<string> vec;
    vec=combination(str);
    for(auto i=vec.begin();i!=vec.end();i++)
    {
        cout<<*i<<" ";
    }
return 0;
}













































