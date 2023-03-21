/* 
Using Parameterized Constructor.
*/

#include<iostream>
using namespace std;

class Queue        /* Declairation of Class.*/
{
    // public:    /* Variable declaired as public.*/

    int *arr;
    int front;
    int rear;
    int size;

    public:    /* Variable declaired as public.*/

    Queue(int size)   /*Using Paramiterized constructor*/
    {
        this->size=size;
        int front=-1;
        int rear=-1;
        int *arr=new int[size];
    }

    void insertion();
    void deletion();
    void Display();
};


void Queue::insertion()   /* Function to insert the element.*/
{
    int ele;
    cout<<"Enter the element: ";
    cin>>ele;
    
    if(front==size-1)
    {
        cout<<"The Queue is Full.";
    }
    else
    {
        if(front==-1)
        front=0;

        rear++;
        arr[rear]=ele;
    }
};

void Queue::deletion()   /* For deleating element.*/
{
    if((front>rear) || (rear<0))
    {
        cout<<"The Queue is Full.";
    }
    else
    {
        cout<<"Your Deleated element is: "<<arr[front]<<endl;
        front++;
    }
};

void Queue::Display()   /* To display element.*/
{
    if((front>rear)||(front==size))
    {
        cout<<"The Queue is Empty.";
    }
    else
    {
        for(int i=front;i<=rear;i++)
        {
            cout<<arr[i]<<" ";
        }
    }    
};

int main()
{
    int n;
    cout << "Enter the size of Queue: ";
    cin >> n;
    int s;
    Queue Q(n);   /* created object of parameterize constructor and argument also passed.*/
    int ele;
    do        /* do while loop for oprate all the operations.*/
    {
        cout << "\n"
             << endl;
        cout << "     ***OPERATION***" << endl;
        cout << "\t1)Insertion" << endl;
        cout << "\t2)Deletion" << endl;
        cout << "\t3)Display" << endl;
        cout << "\t4)Exit" << endl;
        cout << "\nEnter any operation: ";
        cin >> s;
        switch (s)    /* switch case to select operation one by one.*/
        {
        case 1:
        {
            cout << "Enter the integer: ";
            cin >> ele;
            Q.insertion();
        }
        break;

        case 2:
        {
            Q.deletion();
        }
        break;

        case 3:
        {
            Q.Display();
        }
        break;

        case 4:
        {
            cout << "Exit.";
        }
        }
    } 
    while (s != 4);
    
    return 0;
}