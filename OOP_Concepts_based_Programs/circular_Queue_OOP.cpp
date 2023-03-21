/*
parameterized constructors = The parameterized constructors can take argument to initialize an object when it created . The PArameterized constructors can be called implicity or explicity. 

*/

#include<iostream>
using namespace std;
class Cirque    /* Class declair as circular Queue*/
{
    // public: 

    int size;
    int *arr;
    int front;
    int rear;

    public:
    
    Cirque(int size)
    {
        this->size=size;
        front=-1;
        rear=-1;
        arr=new int[size];
    }

    void insertion();
    void deletion();
    void display();
};

void Cirque::insertion()
{
    int ele;
    cout << "Enter an Element: ";
    cin >> ele;
    if (front == -1 and rear == -1)
    {
        front = 0;
        rear = 0;
        arr[rear] = ele;
    }
    else if ((rear + 1) % size == front)
    {
        cout << "The Queue is full.";
    }
    else
    {
        rear = (rear + 1) % size;
        arr[rear] = ele;
    }
};

void Cirque::deletion()
{
    if (front > rear)
    {
        cout << "\nThe Queue is underflow.";
    }
    else
    {
        cout << "Deleted element is: " << arr[front];
        front = (front + 1) % size;
    }
};

void Cirque::display()
{
    if (front > rear || rear < 0)
    {
        cout << "\nNo Element in Queue.";
    }
    else
    {
        cout << "\nYour elements are: ";
        for (int i = front; i != rear + 1; i++)
        {
            cout << arr[i] << " ";
        }
    }
};


int main()
{
    int n;
    cout << "Enter the size of Circular Queue: ";
    cin >> n;
    int s;
    Cirque CQ(n);   /* created object of parameterize constructor and argument also passed.*/
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
            CQ.insertion();
        }
        break;

        case 2:
        {
            CQ.deletion();
        }
        break;

        case 3:
        {
            CQ.display();
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