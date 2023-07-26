#include<iostream>
using namespace std;

void print(string str1,string str2,string str3,string str4)
{
    cout<<str1<<endl;
    cout<<str2<<endl;
    cout<<str3<<endl;
    cout<<str4<<endl;
}

int main(){
    string str1{"Answin"};
    string str2="sudhir";
    string str3;
    string str4;
    cout<<"Enter the string-3 and string-4: ";
    cin>>str3;
    getline(cin,str4);
    print(str1,str2,str3,str4);
return 0;
}