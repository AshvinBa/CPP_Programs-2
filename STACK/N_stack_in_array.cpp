#include<iostream>
using namespace std;
class Stack
{
    int n,s;
    int freespot;
    int *arr;
    int *top;
    int *next;

    public:

    void Nstack(int N,int S)
    {
        n=N;
        s=S;
        arr=new int[s];
        top=new int[n];
        next=new int[s];

        for(int i=0;i<n;i++)
        {
            top[i]=-1;
        }

        for(int i=0;i<s;i++)
        {
            next[i]=i+1;
        }

        next[s-1]=-1;

        freespot=0;        
    }

    bool push(int x,int m)
    {
        if(freespot == -1)
        {
            return false;
        }

        int index=freespot;

        arr[index]=x;

        freespot=next[index];
        
        next[index]=top[m-1];

        top[m-1]=index;

        return true;        
    }

    int pop(int m)
    {
        if(top[m-1]==-1)
        {
            return -1;
        }

        int index=top[m-1];
        
        top[m-1]=next[index]; 
        
        next[index]=freespot;   
        
        freespot=index;
        
        return arr[index];
    }
};


int main(){
    Stack s;

    int x;
    cout<<"\t***OPERATIONS***";
    cout<<"\n";
    cout<<"\t   1)PUSH."<<endl;
    cout<<"\t   2)POP."<<endl;
    cout<<"Enter the choice: ";
    cin>>x;
    switch(x)
    {
        case 1:
        {
            int w,y;
            cout<<"Enter the number: ";
            cin>>w;
            cout<<"Enter the index: ";
            cin>>y;
            int d=s.push(w,y);
            if(d==1)
            {
                cout<<"Yes.";
            }
            else
            {
                cout<<"No.";
            }
        }
        break;
        case 2:
        {
            int w;
            cout<<"Enter the index for pop: ";
            cin>>w;
            cout<<"The Poped element is: "<<s.pop(w);
        }
        break;
    }
return 0;
}