#include<iostream>
using namespace std;
int main(){
    int n,m;
    cout<<"\nEnter the numbers: ";
    cin>>n>>m;

    for(int i=n;i<=m;i++)
    {
        if(i==1)
        {
            cout<<"\nOne.";
        }
        else if(i==2)
        {
            cout<<"\nTwo.";
        }
        else if(i==3)
        {
            cout<<"\nThree.";
        }
        else if(i==4)
        {
            cout<<"\nFour.";
        }

        else if(i==5)
        {
            cout<<"\nFive.";
        }
        else if(i==6)
        {
            cout<<"\nSix.";
        }
        else if(i==7)
        {
            cout<<"\nSeven.";
        }
        else if(i==8)
        {
            cout<<"\nEight.";
        }
        else if(i==9)
        {
            cout<<"\nNine.";
        }
        else if(i>9)
        {
            if(i%2==0)
            {
                cout<<"\nEven.";
            }
            else
            {
                cout<<"\nOdd.";
            }
        }
    } 
return 0;
}