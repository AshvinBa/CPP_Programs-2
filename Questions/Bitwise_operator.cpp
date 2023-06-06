#include<iostream>
using namespace std;

void bitwiseOperator(int a,int b,int c)
{
    int d=a^a;
    int e=c^b;
    int f=a&b;
    int g=c|(a^a);
    int h=~e;
    cout<<"d= "<<d<<endl<<"e= "<<e<<endl<<"f= "<<f<<endl<<"g= "<<g<<endl<<"h= "<<h<<endl;
}

int main(){
    int a,b,c;
    cout<<"Enter the value of A,B and C: ";
    cin>>a>>b>>c;
    bitwiseOperator(a,b,c);
return 0;
}