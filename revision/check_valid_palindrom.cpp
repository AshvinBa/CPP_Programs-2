#include<iostream>
using namespace std;

bool valid(char s)
{
    if((s>='a' && s<='z')||(s>='A' && s<='Z')||('0'<=s && s<='9')||(s==' '))
    {
        return true;
    }
    else
    {
        return false;
    }
}

char To_lower_case(char ch)
{
    if(ch<='a' && ch>='z' || ch<='0' && ch>='9')
    {
        return ch;
    }
    else
    {
        char temp=ch-'A'+'a';
        return temp;
    }
}

bool is_palindrom(string str)
{
    int s=0;
    int e=str.length()-1;

    while(s<=e)
    {
        if(str[s++]!=str[e--])
        {
            return false;
        }
        else
        {
            s++;
            e--;
        }
    }
    return true;
}

bool check_palindrom(string str)
{
    string temp="";

    for(int i=0;i<str.length();i++)
    {
        if(valid(str[i]))
        {
            temp.push_back(str[i]);
        }
    }

    for(int i=0;i<str.length();i++)
    {
        temp[i]=To_lower_case(temp[i]);
    }

    return is_palindrom(temp);
}

int main(){
    string str="aaa@@aaa";
    bool x=check_palindrom(str);
    if(x)
    {
        cout<<"Its Palindrom.";
    }
    else
    {
        cout<<"Not Palindrom.";
    }
return 0;
}