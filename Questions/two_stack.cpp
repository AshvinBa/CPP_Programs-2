#include<iostream>
using namespace std;

    int *arr;
    int size=100;
    int top1=-1, top2=size;
 
    //Function to push an integer into the stack1.
    void push1(int x)
    {
        if(top1==size)
        {
            return;
        }
        top1++;
        arr[top1]=x;
    }
    
    //Function to push an integer into the stack2.
    void push2(int x)
    {
      if(top2==-1)
      {
          return;
      }
       top2--;
       arr[top2]=x;
    }
    
    //Function to remove an element from top of the stack1.
    int pop1()
    {
        if(top1==-1) return -1;
        else return arr[top1--];
        
    }
    
    //Function to remove an element from top of the stack2.
    int pop2()
    {
       if(top2==size) return -1;
       else return arr[top2++];
    }

    

int main(){
    push1(1);
    push1(2);
    push1(3);
    push1(4);
    push1(5);
    push2(6);
    push2(7);
    push2(8);
    push2(9);
    push2(10);
    cout<<pop1();
    cout<<endl;
    cout<<pop1();
    cout<<endl;
    cout<<pop2();
    cout<<endl;
    cout<<pop2();
    cout<<endl;
return 0;
}