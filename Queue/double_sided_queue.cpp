#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Deque
{
    int *arr;
    int front;
    int rear;
    int size;

    public:

    Deque(int n)
    {
        size=n;
        front=-1;
        rear=-1;
        arr=new int[size];
    }

    bool pushfront(int x)
    {
        if(isfull())
        {
            return false;
        }
        else if(isEmpty())
        {
            front=rear=0;
        }
        else if(front==0 && rear!=size-1)
        {
            front=size-1;
        }
        else 
        {
            front--;
        }
        arr[front]=x;
        return true;
    }

    bool pushRear(int x)
    {
        if(isfull())
        {
            return false;
        }
        else if(isEmpty())
        {
            front=rear=0;
        }
        else if(rear==size-1 && front!=0)
        {
            rear=0;
        }
        else 
        {
            rear++;
        }
        arr[rear]=x;
        return true;
    }

    int popfront()
    {
        if(isEmpty())
        {
            return -1;
        }
        int ans=arr[front];
        arr[front]=-1;

        if(front==rear)
        {
            front=rear=-1;
        }
        else if(front==size-1)
        {
            front=0;
        }
        else
        {
            front++;
        }
        return ans;
    }

    int poprear()
    {
        if(isEmpty())
        {
            return -1;
        }
        int ans=arr[rear];
        arr[rear]=-1;
        if(front==rear)
        {
            front=rear=-1;
        }
        else if(rear==0)
        {
            rear=size-1;
        }
        else
        {
            rear--;
        }
        return ans;
    }
    
    int getfront()
    {
        if(isEmpty())
        {
            return -1;
        }
        return arr[front];
    }

    int getRear()
    {
        if(isEmpty())
        {
            return -1;
        }
        return arr[rear];
    }

    bool isfull()
    {
        if( (front==0 && rear==size-1) || (front!=0 && (rear=(front-1)%(size-1))))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isEmpty()
    {
        if(front==-1)
            return true;
        else
            return false;
    }
};

int main(){
    int n=1000;
    Deque d(n);
        int s;
    do
    {
        cout << "\n\n\n***OPOERATIONS***" << endl;
        cout << "1) PushRear." << endl;
        cout << "2) PushFront." << endl;
        cout << "3) Popfront." << endl;
        cout << "4) PopRear." << endl;
        cout << "5) GetRear." << endl;
        cout << "6) IsFull." << endl;
        cout << "7) IsEmpty." << endl;
        cout << "8) GetFront." <<endl;
        cout << "9) Exit." << endl;
        cout << "Enter the choice: ";
        cin >> s;

        switch (s)
        {
        case 1:
        {
            int x;
            cout << "Enter the number for Rear: ";
            cin >> x;
            int ans = d.pushRear(x);
            if (ans == true)
            {
                cout << "Yes!, Entered";
            }
            else
            {
                cout << "No!,not Enterd.";
            }
        }
        break;

        case 2:
        {
            int x;
            cout << "Enter the number for Front: ";
            cin >> x;
            int ans = d.pushRear(x);
            if (ans == true)
            {
                cout << "Yes!, Entered";
            }
            else
            {
                cout << "No!,not Enterd.";
            }
        }
        break;

        case 3:
        {
            cout<<"Your Front deleated element: "<<d.popfront()<<endl;
        }
        break;

        case 4:
        {
            cout<<"Your Rear deleated element: "<<d.poprear()<<endl;
        }
        break;

        case 5:
        {
            cout<<"Get Rear Element: "<<d.getRear()<<endl;
        }
        break;

        case 6:
        {
            int x=d.isfull();
            if(x==1)
            {
                cout<<"Empty.";
            }   
            else
            {
                cout<<"Not Empty.";
            }
        }
        break;

        case 7:
        {
            cout<<"It's Empty or not: "<<d.isEmpty()<<endl;
        }
        break;

        case 8:
        {
            cout<<"Get front Element: "<<d.getfront()<<endl;
        }
        break;

        case 9:
        {
            cout<<"Exit.";
        }
    } 
    }
    while (s != 9);
return 0;
}