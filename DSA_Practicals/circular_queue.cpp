#include <iostream>
using namespace std;
int queue[5], n = 5, front = -1, rear = -1;
int insertion()
{
    int ele;
    cout << "Enter an Element: ";
    cin >> ele;
    if (front == -1 and rear == -1)
    {
        front = 0;
        rear = 0;
        queue[rear] = ele;
    }
    else if ((rear + 1) % n == front)
    {
        cout << "The Queue is full.";
    }
    else
    {
        rear = (rear + 1) % n;
        queue[rear] = ele;
    }
}
int deletion()
{
    if (front > rear)
    {
        cout << "\nThe Queue is underflow.";
    }
    else
    {
        cout << "Deleted element is: " << queue[front];
        front = (front + 1) % n;
    }
}
int display()
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
            cout << queue[i] << " ";
        }
    }
}
int main()
{
    int s;
    do
    {
        cout << "\n";
        cout << "1-Insertion." << endl;
        cout << "2-Deletion." << endl;
        cout << "3-Display." << endl;
        cout << "Enter the choice: ";
        cin >> s;
        switch (s)
        {
        case 1:
        {
            insertion();
            break;
        }
        case 2:
        {
            deletion();
            break;
        }
        case 3:
        {
            display();
            break;
        }
        case 4:
        {
            cout << "Exit.";
        }
        }
    } while (s != 4);
}
