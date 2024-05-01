/*
#include<iostream>
#include<string>
#define MAXSIZE 100

using namespace std;

int main()
{
    char *p,*q;
    char temp;
    char in[MAXSIZE];
    char stuff[MAXSIZE];
    char destuff[MAXSIZE];
    int count=0;

    cout << "Enter the input character string (0's & 1's only):" << endl;
    cin >> in;

    p = in;
    q = stuff;

    while (*p != '\0')
    {
        if (*p == '0')
        {
            *q = *p;
            q++;
            p++;
        }
        else
        {
            while (*p == '1' && count != 5)
            {
                count++;
                *q = *p;
                q++;
                p++;
            }
            if (count == 5)
            {
                *q = '0';
                q++;
            }
            count = 0;
        }
    }
    *q = '\0';

    cout << "\nThe stuffed character string is: " << endl;
    cout << stuff << endl;

    p = stuff;
    q = destuff;

    while (*p != '\0')
    {
        if (*p == '0')
        {
            *q = *p;
            q++;
            p++;
        }
        else
        {
            while (*p == '1' && count != 5)
            {
                count++;
                *q = *p;
                q++;
                p++;
            }
            if (count == 5)
            {
                p++;
            }
            count = 0;
        }
    }
    *q = '\0';

    cout << "\nThe destuffed character string is: " << endl;
    cout << destuff << endl;

    return 0;
}
*/


/*
#include<bits/stdc++.h>
#define MAXSIZE 100
using namespace std;

int main()
{
    char *p,*q;
    char temp;
    char in[MAXSIZE];
    char stuff[MAXSIZE];
    char destff[MAXSIZE];
    int count=0;

    p=in;
    q=stuff;

    cout << "Enter the input character string (0's & 1's only):" << endl;
    cin >> in;


    while(*p!='\0')
    {
        if(*p=='0')
        {
            *q=*p;
            q++;
            p++;
        }
        else
        {
            while(*p=='1' && count!=5)
            {
                count++;
                *q=*p;
                q++;
                p++;
            }
            if(count==5)
            {
                *q='0';
                q++;
            }
            count=0;
        }
    }
    *q='\0';

    cout << "\nThe stuffed character string is: " << endl;
    cout << stuff << endl;

    p=stuff;
    q=destff;

    while(*p!='\0')
    {
        if(*p=='0')
        {
            *q=*p;
            q++;
            p++;
        }
        else
        {
            while(*p=='1' && count!=5)
            {
                count++;
                *q=*p;
                q++;
                p++;
            }
            if(count==5)
            {
                p++;            
            }
            count++;
        }
    }
    *q='\0';

    cout << "\nThe stuffed character string is: " << endl;
    cout << destff << endl;

    return 0;
}
*/



#include<bits/stdc++.h>
#define MAXSIZE 100
using namespace std;

int main()
{
    char *p,*q;
    char temp;
    char in[MAXSIZE];
    char stuff[MAXSIZE];
    char destuff[MAXSIZE];
    int count=0;

    cout<<"Enter the values (0 and 1 form): ";
    cin>>in;

    p=in;
    q=stuff;

    while(*p!='\0')
    {
        if(*p=='0')
        {
            *q=*p;
            p++;
            q++;
        }
        else
        {
            while(*p=='1' && count!=5)
            {
                count++;
                *q=*p;
                q++;
                p++;
            }
            if(count==5)
            {
                *q='0';
                q++;
            }
            count=0;
        }
    }
    *q='\0';

    cout<<"The value after stuff: "<<endl;
    cout<<stuff<<endl;

    q=destuff;
    p=stuff;

    while(*p!='\0')
    {
        if(*p=='0')
        {
            *q=*p;
            p++;
            q++;
        }
        else
        {
            while(*p=='1' && count!=5)
            {
                count++;
                *q=*p;
                q++;
                p++;
            }
            if(count==5)
            {
                p++;
            }
            count=0;
        }
    }
    *q='\0';
    
    cout<<"The destuff valu: "<<endl;
    cout<<destuff;

    return 0;
}





























