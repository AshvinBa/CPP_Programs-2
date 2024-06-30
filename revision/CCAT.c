// CCAT

// 1)
/*
#include<stdio.h>
int main()
{
    int a,b=2,c=5;
    a=(a++,++c,b+c+a);
    printf("%d",a);
    return 0;
}
*/

// 2)
/*
#include<stdio.h>
int main()
{
    int a=2,b=1;
    if(a && ++b);
    printf("%d",b);
    return 0;
}
*/

// 3)
/*
#include<stdio.h>
#define MULS(x) x*5
int main()
{
    int y;
    y=MULS(2+4);
    printf("%d",y);
    return 0;
}
*/

// 4)
/*
#include<stdio.h>
int main()
{
    int arr[]={10,1.1,2.6,20,30,4.0,50,60};
    printf("%d\n",*(arr+3));
    return 0;
}
*/

// 5
/*
#include<stdio.h>
int main()
{
    char *ptr;
    char str[]= "Hello";
    ptr=str;
    ptr+=2;
    printf("%s",ptr);
    return 0;
}
*/

// 6)
/*
#include<stdio.h>
int main()
{
    int a;
    a='b'-'a';
    printf("%d\n",a);
    return 0;
}
*/

#include<stdio.h>
int main()
{
    int a=023;
    printf("%d\n",a);
    return 0;
}






