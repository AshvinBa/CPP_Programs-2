#include<iostream>
using namespace std;

string reverseString(string str)
{
    string s="";
    int n=str.length();
    for(int i=n-1;i>=0;i--)
    {
        s+=str[i];
    }
    return s;
}
int main(){
    string str="Ashvin";
    cout<<"\nThe reverse String: "<<reverseString(str);
    cout<<"\n\n";
return 0;
}