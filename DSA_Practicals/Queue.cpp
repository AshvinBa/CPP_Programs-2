#include <iostream>
using namespace std;
int queue[100], n = 10, rear = -1, front = -1;

int insertion()
{
    int ele;
    if (rear == n - 1)

        cout << "Queue is Full.";
    else
    {
        if (front == -1)
            front = 0;
        cout << "Enter the element: ";
        cin >> ele;
        rear++;
        queue[rear] = ele;
    }
}

int deletion()
{
    if (front == -1 || front > rear)
    {
        cout << "The Queue is Underflow.";
    }
    else
    {
        cout << "Your Deleted element is: " << queue[front] << endl;
        front++;
    }
}

int display()
{
    if (front == -1 || front > rear)
    {
        cout << "OOP!,No elemnt preasent in Queue";
    }
    else
    {
        cout << "The element preasent: ";
        for (int i = front; i <= rear; i++)
        {
            cout << queue[i] << " ";
        }
    }
}

int main()
{
    int s;
    cout << "1) Enter-1 for Insert the element." << endl;
    cout << "2) Enter-2 for Delete the element." << endl;
    cout << "3) Enter-3 for Display the element." << endl;
    cout << "4) Enter-4 for Exit." << endl;
    do
    {
        cout << "\n\nEnter Your choice: ";
        cin >> s;
        switch (s)
        {
        case 1:
            insertion();
            break;
        case 2:
            deletion();
            break;
        case 3:
            display();
            break;
        case 4:
            cout << "Exit";
            break;
        }
    } while (s != 4);
}
