

#include<iostream>
using namespace std;

class Shares
{
    public:
    int acID,T_shares,P_shares,sel_shares,dis=0;
    int x=0,y=0;

    Shares(int a,int b)
    {
        acID=a;
        T_shares=b;
    }
    void selling_shares();
    void Purchasing_shares();
    void Display();
};

void Shares::selling_shares()
{
    cout<<"\nEnter the acoount ID number: ";
    cin>>acID;
    int P_amt,S_amt;

    cout<<"\nEnter How many shares you want to Sell: ";
    cin>>sel_shares;
    while(sel_shares>T_shares)
    {
        cout<<"\nYour available share is Only: "<<T_shares;
        cout<<"\nPlease Enter valid ammount...\n";        
        cin>>sel_shares;
    }
    cout<<"\nEnter the privious purchasing price of shares: ";
    cin>>P_amt;
    cout<<"\nEnter the selling price of shares: ";
    cin>>S_amt;
    if(P_amt<S_amt)
    {
        dis++;
        x=S_amt-P_amt;
        cout<<"\nYour Profit is: "<<x<<" rs per share."<<endl;
        cout<<"Congratulation!!! You sold it in profitable amount...";
    }
    else
    {
        dis++;
        y=P_amt-S_amt;
        cout<<"\nYour Loss is: "<<y<<" rs per share."<<endl;
        cout<<"Opp!!! You sold it in loss...";
    }
};

void Shares::Purchasing_shares()
{
    cout<<"\nEnter the Account ID: ";
    cin>>acID;

    cout<<"\nEnter How many Quantity of shares you want to purchase.";
    cin>>P_shares;

    cout<<"\nYour Total Quantity Before purchasing shares is: "<<T_shares;
    T_shares+=P_shares;
    cout<<"\nYour Total Quantity after purchasing shares is: "<<T_shares;
    cout<<endl;
};

void Shares::Display()
{
    cout<<"\nEnter your Account ID: ";
    cin>>acID;

    cout<<"\nYour Total Quantity of share is: "<<T_shares;

    if(dis>0)
    {
        cout<<"\nYour Profit is: "<<x;
        cout<<"\nYour Loss is: "<<y;
    }


};

int main()
{
    Shares S(1,1000);
    int s;
    do
    {
        cout<<"\n\n*****Welcome*****"<<endl;
        cout<<"1)Purchasing Of Shares."<<endl;
        cout<<"2)Selling Of Shares."<<endl;
        cout<<"3)Display Of Shares."<<endl;
        cout<<"4)Exit."<<endl;
        cout<<"\nEnter Your Choise: ";
        cin>>s;

        switch(s)
        {
            case 1:
            {
            S.Purchasing_shares();
            break;
            }

            case 2:
            {
            S.selling_shares();
            break;
            }
            
            case 3:
            {
            S.Display();
            break;
            }            
        }
    }
    while(s<4);
return 0;
}