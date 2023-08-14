/*
1) Squre Pattern
*/

/*

#include<iostream>
using namespace std;

int pattern(int row,int col)
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
    cout<<" "<<endl;
}

int main(){
    int row,col;
    cout<<"Enter the row and colom: ";
    cin>>row>>col;
    pattern(row,col);
return 0;
}
*/

//Rectangular Pattern.
/*
#include<iostream>
using namespace std;

void pattern(int row,int col)
{
    cout<<"\nPattern Print: ";
    cout<<endl;

    for(int i=1;i<=row;i++)
    {
        for(int j=1;j<=col;j++)
        {
            if(i==1||j==1||i==row||j==col)
            {
                cout<<"*";
            }
            else
            {
                cout<<" ";
            }
        }
        cout<<endl;
    }
}

int main(){
    int row,col;
    cout<<"Enter the row and col: ";
    cin>>row>>col;
    pattern(row,col);
return 0;
}
*/

//Tringular Pattern: 
/*
#include<iostream>
using namespace std;

int Pattern(int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cout<<"Enter the values: ";
    cin>>n;
    cout<<"The Pattern is: "<<endl;
    Pattern(n);
return 0;
}
*/

// Triangular Pattern
/*
#include<iostream>
using namespace std;

void pattern(int n)
{
    cout<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=(n-i);j++)
        {
            cout<<" ";
        }
        for(int j=1;j<=2*i-1;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cout<<"Enter the value: ";
    cin>>n;
    cout<<"Pattern: ";
    pattern(n);
return 0;
}
*/

//Numeric Rectangular Pattern.
/*
#include<iostream>
using namespace std;

void rectang(int n)
{
    cout<<"Pattern: "<<endl;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            cout<<j<<" ";
        }
        for(int j=1;j<=(i-1);j++)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }

}

int main(){
    int n;
    cout<<"Enter the digit: ";
    cin>>n;
    rectang(n);
return 0;
}
*/

/*

#include<iostream>
using namespace std;

void patter(int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    patter(n);
return 0;
}
*/

/*
#include<iostream>
using namespace std;

void pattern(int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(j==1 || j==n)
            {
                cout<<j<<" ";
            }
            else if(i==1 || i==n)
            {
                cout<<j<<" ";
            }
            else
            {
                cout<<"  ";
            }
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cout<<"Enter the values: ";
    cin>>n;
    pattern(n);
return 0;
}
*/
/*
#include<iostream>
using namespace std;

void pattern(int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(j%2==0 ||i%2==0)
            {
                cout<<"2 ";
            }
            else if(j%2==1 || j%2==1)
            {
                cout<<"1 ";
            }
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cout<<"Enter the values: ";
    cin>>n;
    pattern(n);                           
return 0;
}
*/

/*
#include<iostream>
using namespace std;

void pattern(int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if((i+j)%2==0)
            {
                cout<<"1 ";
            }
            else
            {
                cout<<"2 ";
            }
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    pattern(n);
return 0;
}
*/
/*
#include<iostream>
using namespace std;

int count(int n)
{
    int last;
    int ans=0;

    while(n)
    {
        last=n%10;
        ans+=last;
        n=n/10;
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter the digit: ";
    cin>>n;
    cout<<"The sum of number is: ";
    cout<<count(n);
return 0;
}
*/

#include<iostream>
using namespace std;

int reverse(int n)
{
    int last;
    int ans=0;
    while(n)
    {
        last=n%10;
        ans=ans*10+last;
        n=n/10;
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter the digit: ";
    cin>>n;
    cout<<reverse(n);
return 0;
}
























