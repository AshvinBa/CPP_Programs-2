// #include<bits/stdc++.h>
// #define MAXSIZE 100
// using namespace std;

// int main()
// {
//     char *p,*q;
//     char temp;
//     char in[MAXSIZE];
//     char stuff[MAXSIZE];
//     char destuff[MAXSIZE];
//     int count=0;

//     cout<<"Enter the values (0 and 1 form): ";
//     cin>>in;

//     p=in;
//     q=stuff;

//     while(*p!='\0')
//     {
//         if(*p=='0')
//         {
//             *q=*p;
//             p++;
//             q++;
//         }
//         else
//         {
//             while(*p=='1' && count!=5)
//             {
//                 count++;
//                 *q=*p;
//                 q++;
//                 p++;
//             }
//             if(count==5)
//             {
//                 *q='0';
//                 q++;
//             }
//             count=0;
//         }
//     }
//     *q='\0';

//     cout<<"The value after stuff: "<<endl;
//     cout<<stuff<<endl;

//     q=destuff;
//     p=stuff;

//     while(*p!='\0')
//     {
//         if(*p=='0')
//         {
//             *q=*p;
//             p++;
//             q++;
//         }
//         else
//         {
//             while(*p=='1' && count!=5)
//             {
//                 count++;
//                 *q=*p;
//                 q++;
//                 p++;
//             }
//             if(count==5)
//             {
//                 p++;
//             }
//             count=0;
//         }
//     }
//     *q='\0';
    
//     cout<<"The destuff valu: "<<endl;
//     cout<<destuff;

//     return 0;
// }



#include<bits/stdc++.h>
#define MAXSIZE 100
using namespace std;
int main()
{
    int count=0;
    char *p,*q;
    char in[MAXSIZE];
    char stuff[MAXSIZE];
    char destuff[MAXSIZE];

    cout<<"Enter the values: ";
    cin>>in;

    p=in;
    q=stuff;

    while(*p!='\0')
    {
        if(*p=='0')
        {
            *q=*p;
            *p++;
            *q++;
        }
        else
        {
            while(*p=='1' && count!=5)
            {
                *q=*p;
                count++;
                p++;
                q++;
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

    cout<<"\nThe stuff values: "<<endl;
    cout<<stuff;

    p=stuff;
    q=destuff;

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
                *q=*p;
                p++;
                q++;
                count++;
            }
            if(count==5)
            {
                p++;
            }
            count=0;
        }
    }
    *q='\0';

    cout<<"\nThe Destuff values are: ";
    cout<<destuff;
    return 0;
}

























