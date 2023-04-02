#include<iostream>
using namespace std;
int getcount(int start,int end,int digit)
{
    int num;
    int count=0,lastdigit=0;
    for(int i=start;i<=end;i++)
    {
        num=i;
        while(num!=0)
        {
            lastdigit=num%10;
            if(lastdigit==digit)
            {
                count++;
            }
            num=num/10;
        }
    }
    return count;
}

int main(){
    int start,end,digit;
    cout<<"Enter the start: ";
    cin>>start;
    cout<<"Enter the end: ";
    cin>>end;
    cout<<"Enter the digit for counting: ";
    cin>>digit;
    int x=getcount(start,end,digit);
    cout<<"The Occurence of the digit: "<<x;
return 0;
}