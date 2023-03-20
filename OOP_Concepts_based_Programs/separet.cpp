#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class admission
{
    public:
    int c=0,m=0,i=0,t=0,e=0;
    char ch;
    
        void ++ (){
        cout<<"\nThe Following are Available Branches.\n\tPress C for Computer.\n\tPress M for Mechanical.\n\tPress E for Electronics.\n\tPress I for Information Teechnology.";
        cout<<"\nEnter the Code: ";
        cin>>ch;
        if(ch=='c'||ch=='C')
        {
            cout<<"\n\tYour Admission is confirm in Computer... ";
            c++;t++;
        }
        if(ch=='m'||ch=='M')
        {
            cout<<"\n\tYour Admission is confirm in Mechanical... ";
            m++;t++;
        }
        if(ch=='e'||ch=='E')
        {
            cout<<"\n\tYour Admission is confirm in Electronics... ";
            e++;t++;
        }
        if(ch=='i'||ch=='I')
        {
            cout<<"\n\tYour Admission is confirm in Computer... ";
            i++;t++;
        }
        else
        {
            cout<<"Enter Valid Code. ";
        }
    }
    void -- (){
        cout<<"\nThe Following are Available Branches.:\n\tPress C for Computer.\n\tPress M for Mechanical.\n\tPress E for Electronics.\n\tPress I for Information Teechnology.";
        cout<<"\nEnter the Code: ";
        cin>>ch;
        if(ch=='c'||ch=='C')
        {
            cout<<"\n\tYour Admission is canceled in Computer... ";
            c--;t--;
        }
        if(ch=='m'||ch=='M')
        {
            cout<<"\n\tYour Admission is canceled in Mechanical... ";
            m--;t--;
        }
        if(ch=='e'||ch=='E')
        {
            cout<<"\n\tYour Admission is canceled in Electronics... ";
            e--;t--;
        }
        if(ch=='i'||ch=='I')
        {
            cout<<"\n\tYour Admission is canceled in Information Technology... ";
            i--;t--;
        }
        else
        {
            cout<<"Enter Valid Code. ";
        }
    }
    void display()
    {
        cout<<"\n   Number of Admission Taken By the Student:";
        cout<<"\n\tComputer: "<<c;
        cout<<"\n\tElectronics: "<<e;
        cout<<"\n\tMechanical: "<<m;
        cout<<"\n\tInformation Technology: "<<i;
        cout<<"\n\n\tTotal Admissions: "<<t;
    }
};

int main(){
    admission a;
    int s;
    do{
    cout<<"\n\nClick here what to do";
    cout<<"\n\tPress 1.To Take Admission.\n\tPress 2.To Cancel Admission.\n\tPress 3.To Display Admission.\n\tPress 4.To Exit.";
    cout<<"\nEnter Your Choice: ";
    cin>>s;
    switch (s)
    {
    case 1:
    {
        a.++ ();
    }
        break;
    case 2:
    {
        a.-- ();
    }
        break;
    case 3:
    {
        a.display();
    }
        break;
    }
    }
    while(s<4);
    return 0;
    }