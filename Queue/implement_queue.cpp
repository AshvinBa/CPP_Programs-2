#include <iostream>
using namespace std;
class Queue
{
    int *arr;
    int front;
    int rear;
    int size;

public:
    Queue(int n)
    {
        front = 0;
        rear = 0;
        size = n;
        arr = new int[size];
    }

    bool isEmpty()
    {
        if (front == rear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void enqueue(int data)
    {
        if (rear == size)
        {
            cout << "\nThe Queue is Full.";
        }
        else
        {
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue()
    {
        if (front == rear)
        {
            cout << "\nThe Queue is Empty.";
        }
        else
        {
            int ans = arr[front];
            front++;

            if (front == rear)
            {
                front = 0;
                rear = 0;
            }
            return ans;
        }
    }

    int qfront()
    {
        if (front == rear)
        {
            return -1;
        }
        else
        {
            return arr[front];
        }
    }

    int display()
    {
        if (isEmpty())
        {
            return -1;
        }
        else
        {
            cout << "Your element is: ";
            for (int i = front; i < rear; i++)
            {
                cout << arr[i] << " ";
            }
        }
    }
};

int main()
{
    Queue q(1000);
    int s;
    do
    {
        cout << "\n\n\n***OPOERATIONS***" << endl;
        cout << "1) isEmpty." << endl;
        cout << "2) Enqueue." << endl;
        cout << "3) Dequeue." << endl;
        cout << "4) Front." << endl;
        cout << "5) Display." << endl;
        cout << "6) Exit." << endl;
        cout << "Enter the choice: ";
        cin >> s;

        switch (s)
        {
        case 1:
        {
            int x = q.isEmpty();
            if (x == 1)
            {
                cout << "Yes! it's an Empty.";
            }
            else
            {
                cout << "No! it's not Empty.";
            }
        }
        break;

        case 2:
        {
            int x;
            cout << "\nEnter the value: ";
            cin >> x;
            q.enqueue(x);
        }
        break;

        case 3:
        {
            cout << "\nDeleted element: ";
            cout << q.dequeue();
        }
        break;

        case 4:
        {
            cout << "The Front element is: " << q.qfront();
        }
        break;

        case 5:
        {
            q.display();
        }
        break;

        case 6:
        {
            cout << "Exit.";
        }
        }
    } while (s != 6);

    return 0;
}
