#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> ascii(string s1)
{
    int sum=0;
    int j=0;
    vector<int>arr;
    for(int i=0;i<s1.length();i++)
    {
        int index=int(s1[i]);
        sum+=index;
        arr.push_back(index);
    }
    cout<<"Sum of ASCII Values: ";
    cout<<sum<<endl;
    return arr;
}

string convert_into_string(vector<int>&arr)
{
    string str="";
    for(int i=0;i<arr.size();i++)
    {
        char ch=char(arr[i]);
        str.push_back(ch);
    }
    return str;
}

int main(){

    string str1;
    cout<<"Enter the string: ";
    getline(cin,str1);

    vector<int>s=ascii(str1);

    for(auto i=s.begin();i!=s.end();i++)
    {
        cout<<*i<<" ";
    }
    
    cout<<"\nString = "<<convert_into_string(s);
return 0;
}