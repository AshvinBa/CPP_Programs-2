// #include<stdio.h>
// #include<conio.h>
// void main()
// {
// int buffer[10], bufsize, in, out, produce, consume,
// choice=0; in = 0;
// out = 0;
// bufsize = 10;
// while(choice !=3)
// {
// printf("\n 1. Produce \t 2. Consume \t 3. Exit");
// printf("\n Enter your choice: ");
// scanf("%d"
// , &choice);
// switch(choice)
// {
// case 1: if((in+1)%bufsize==out)
// printf("\nBuffer is Full");
// else
// {
// printf("\nEnter the value: ");
// scanf("%d"
// , &produce);
// buffer[in] = produce;
// in = (in+1)%bufsize;
// }
// break;
// case 2: if(in == out)
// printf("\nBuffer is Empty");
// else
// {
// consume = buffer[out];
// printf("\nThe consumed value is %d"
// , consume);
// out = (out+1)%bufsize;
// }
// break;
// }
// }
// }


// #include <iostream>
// using namespace std;

// int main() {
//     int buffer[10], bufsize, in = 0, out = 0, produce, consume, choice = 0;
//     bufsize = 10;

//     while (choice != 3) {
//         cout << "\n1. Produce \t 2. Consume \t 3. Exit";
//         cout << "\nEnter your choice: ";
//         cin >> choice;

//         switch (choice) {
//             case 1:
//                 if ((in + 1) % bufsize == out)
//                     cout << "\nBuffer is Full";
//                 else {
//                     cout << "\nEnter the value: ";
//                     cin >> produce;
//                     buffer[in] = produce;
//                     in = (in + 1) % bufsize;
//                 }
//                 break;
//             case 2:
//                 if (in == out)
//                     cout << "\nBuffer is Empty";
//                 else {
//                     consume = buffer[out];
//                     cout << "\nThe consumed value is " << consume;
//                     out = (out + 1) % bufsize;
//                 }
//                 break;
//         }
//     }
//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int in=0,out=0,produce,consume,buffer[10],bufsize,choice=0;

//     bufsize=10;

//     while(choice!=3)
//     {
//         cout<<"\n1)Produce. \t2)Consume. \t3)Exit.";
//         cout<<"\nEnter the Choice: ";
//         cin>>choice;

//         switch(choice)
//         {
//             case 1: 
//             {
//                 if((in + 1) % bufsize == out)
//                 {
//                     cout<<"The Buffer is Already Full.";
//                 }
//                 else
//                 {
//                     cout<<"Enter the value: ";
//                     cin>>consume;
//                     buffer[in]=consume;
//                     in = ( in + 1 ) % bufsize;
//                 }
//             }
//             break;

//             case 2:
//             {
//                 if(in==out)
//                 {
//                     cout<<"The Buffer is Already Empty.";
//                 }
//                 else
//                 {
//                     consume=buffer[out];
//                     cout<<"The Consume value is: "<<consume;
//                     out = ( out + 1 ) % bufsize;
//                 }
//             }
//             break;
//         }
//     }
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
int main()
{
    int in=0,out=0,choice=0,consume,produce,buffer[10],bufsize;
    bufsize=10;

    while(choice!=3)
    {
        cout<<"\n1)Producer.\n2)Consumer.\n3)Exit."<<endl;
        cout<<"Enter your Choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
            {
                if((in+1)%bufsize==out)
                {
                    cout<<"The Buffer is Full.";
                }
                else
                {
                    cout<<"Enter the values: ";
                    cin>>produce;
                    buffer[in]=produce;
                    in = (in+1)%bufsize;
                }
            }
            break;
            case 2:
            {
                if(out==in)
                {
                    cout<<"The Buffer is Empty.";
                }
                else
                {
                    consume=buffer[out];
                    cout<<"The consume value: "<<consume;
                    out=(out+1)%bufsize;
                }
            }
            break;
        }
    }
    return 0;
}




















