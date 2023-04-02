#include <iostream>
using namespace std;

class CircularQueue
{
    int *arr;
    int front;
    int rear;
    int size;

public:
    CircularQueue(int n)
    {
        size = n;
        front = -1;
        rear = -1;
        arr = new int[size];
    }

    bool enqueue(int value)
    {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
        {
            return false;
        }
        else if (front == -1)
        {
            front = rear = 0;
        }
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = value;
        return true;
    }

    int dequeue()
    {
        if (front == -1)
        {
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;

        if (front == rear)
        {
            front = rear = -1;
        }

        else if (front == size - 1)
        {
            front = 0;
        }

        else
        {
            front++;
        }
        return ans;
    }

    void display()
    {
        if (rear == front)
        {
            cout << "The Queue is Empty.";
        }
        else
        {
            if (front < rear)
            {
                cout << "\nThe Elements: ";
                for (int i = front; i <= rear; i++)
                {
                    cout << arr[i] << " ";
                }
            }
            else if (front > rear)
            {
                for (int i = rear; i <= front; i++)
                {
                    cout << arr[i] << " ";
                }
            }
        }
    }
};

int main()
{
    CircularQueue cq(1000);
    int s;
    do
    {
        cout << "\n\n\n***OPOERATIONS***" << endl;
        cout << "1) Enqueue." << endl;
        cout << "2) Dequeue." << endl;
        cout << "3) Display." << endl;
        cout << "4) Exit." << endl;
        cout << "Enter the choice: ";
        cin >> s;

        switch (s)
        {
        case 1:
        {
            int x;
            cout << "Enter the number: ";
            cin >> x;
            int ans = cq.enqueue(x);
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
            cout << "\nThe deleted element is: " << cq.dequeue();
        }
        break;

        case 3:
        {
            cq.display();
        }
        break;

        case 4:
        {
            cout << "\nExit.";
        }
        break;
        }
    } 

    while (s != 3);
return 0;
}