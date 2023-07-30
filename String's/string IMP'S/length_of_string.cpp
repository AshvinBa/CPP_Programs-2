#include<iostream>
using namespace std;
int func(char *str)
{
    int count=0;
    for(char i=0;str[i]!='\0';i++)
    {
        count++;
    }
    return count;
}
int main(){
    char str[1000];
    cout<<"\nEnter the character: ";
    cin>>str;
    cout<<"The character is: ";
    cout<<str;
    cout<<"\nThe number of digit is: "<<func(str);
return 0;
}