/*
Stack has two top and performing two operation PUSH and POP.
*/
#include <iostream>
using namespace std;
class TwoStack
{

public:
    int *arr;
    int top1;
    int top2;
    int size;

    // public:

    TwoStack(int size)
    {
        this->size = size;
        top1 = -1;
        top2 = size;
        arr = new int[size];
    }
    int cnt = 0;

    void push1(int ele)
    {
        if (top2 - top1 > 1)
        {
            top1++;
            arr[top1] = ele;
        }
    }

    void push2(int ele)
    {
        if (top2 - top1 > 1)
        {
            top2--;
            arr[top2] = ele;
        }
    }

    int pop1()
    {
        if (top1 >= 0)
        {
            int ans = arr[top1];
            top1--;
            return ans;
        }
        else
        {
            return -1;
        }
    }

    int pop2()
    {
        if (top1 >= 0)
        {
            int ans = arr[top2];
            top2++;
            return ans;
        }
        else
        {
            return -1;
        }
    }
};

int main()
{
    int n;
    cout << "Enter the size of stack: ";
    cin >> n;
    TwoStack TS(n);
    int ele;
    int s;

    do
    {
        cout << "  ***OPERATION***"<<endl;
        cout << "\tPUSH1"<<endl;
        cout << "\tPUSH2"<<endl;
        cout << "\tPOP1"<<endl;
        cout << "\tPOP2"<<endl;

        cout << "\n Enter the choice: ";
        cin >> s;
        switch (s)
        {
        case 1:
        {
            cout << "Enter an element: ";
            cin >> ele;
            TS.push1(ele);
        }
        break;

        case 2:
        {
            cout << "Enter an element: ";
            cin >> ele;
            TS.push2(ele);
        }
        break;

        case 3:
        {
            cout << TS.pop1();
        }
        break;

        case 4:
        {
            cout << TS.pop2();
        }
        break;

        case 5:
        {
            cout << "Exit.";
        }
        }
    } while (s != 5);
    return 0;
}
