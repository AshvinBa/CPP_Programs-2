/*Arithmetic Operation by using class and objects*/

#include<iostream>
using namespace std;

class Ari_On{       /* declaired class and its name is Ari_On*/
public:        
float x,y,z;
int Sum(){
    cout<<"\nEnter the no: "<<endl;
    cin>>x>>y;
    float z=x+y;
    cout<<"Addision is: "<<z<<endl;
}
int Sub(){
    cout<<"\nEnter the no: "<<endl;
    cin>>x>>y;
    float z=x-y;
    cout<<"Substraction is: "<<z<<endl;
}
int Mul(){
    cout<<"\nEnter the no: "<<endl;
    cin>>x>>y;
    float z=x*y;
    cout<<"Multiplication is: "<<z<<endl;
}
int Div(){
    cout<<"\nEnter the no: "<<endl;
    cin>>x>>y;
    float z=x/y;
    cout<<"Division is: "<<z<<endl;
}
int Mod(){
    cout<<"\nEnter the no: "<<endl;
    cin>>x>>y;
    float z=int(x)%int(y);
    cout<<"Remainder is: "<<z<<endl;
}
};

int main()
{
    Ari_On ari;     /*Object name is ari */
    int s;
    float z,x,y;
do{
    cout<<"\n\nThe choise: \n"<<endl;
    cout<<"\n\t1) Addition";
    cout<<"\n\t2) Substraction";
    cout<<"\n\t3) Multiplication";
    cout<<"\n\t4) Division";
    cout<<"\n\t5) Remainder";
    cout<<"\n\t6) Exit\n";
    cin>>s;

    switch (s)
    {
    case 1:
    ari.Sum();
    break;
    
    case 2:
    ari.Sub();
    break;
    
    case 3:
    ari.Mul();
    break;
    
    case 4:
    ari.Div();
    break;
    
    case 5:
    ari.Mod();
    break;
    }
}
    while (s<6);        
}