#include<iostream>
using namespace std;
int main(){
    int num=5;
    int a=num;
    cout<<"a before "<<num<<endl;
    a++;
    cout<<"a after "<<num<<endl;

    int *p=&num;
    cout<<"P before "<<*p<<endl;
    (*p)++;
    cout<<"p after "<<*p<<endl;
  
    int *q=p;
    cout<<p<<" -- "<<q<<endl;
    cout<<*p<<" -- "<<*q<<endl;
return 0;
}