#include<iostream>
using namespace std;
void reachHome(int src,int dest)
{
    cout<<"Source: "<<src<<" Destination: "<<dest<<endl;

    if(src==dest)
    {
        cout<<"Both are equal.";
        return;
    }

    // src++;
    reachHome(src+1,dest);
}
int main(){
    int dest=10;
    int src=1;
    cout<<endl;
    reachHome(src,dest);
return 0;
}