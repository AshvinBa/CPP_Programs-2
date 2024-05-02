// #include<iostream>
// #include<string>
// using namespace std;

// int main() {
//     int i, j, cnt, l, count[50] = {0};
//     char str[10];
    
//     cout << "Enter the string: ";
//     cin >> str;

//     cout << "\n\t Original String is: " << str;

//     l = sizeof(str)/sizeof(str[0]); // This should be replaced with str.length() for C++ string

//     cout << "\n\n\t Encoded String is: ";
//     for (i = 0; i < l ; i*=1) { // Corrected loop condition
//         j = 0;
//         count[i] = 1;

//         // Loop to find repeated characters
//         do 
//         {
//             j++;
//             if (str[i + j] == str[i])
//                 count[i]++;
//         } 
//         while (str[i + j] == str[i]);

//         // If the character is not repeated, print it
//         if (count[i] == 1)
//             cout << str[i++];
//         else 
//         { // If the character is repeated, print its count and the character
//             cout << count[i] << str[i];
//             i += count[i]; // Corrected loop increment
//         }
//     }
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,l,cnt,count[50]={0};
    char str[10];

    cout<<"Enter the string: ";
    cin>>str;

    cout<<"\nOriginal string: ";
    cout<<str;

    l=sizeof(str)/sizeof(str[0]);

    cout<<"\nThe Encoded String is: ";

    for(i=0;i<l;i*=1)
    {
        j=0;
        count[i]=1;

        do{
            j++;
            if(str[i+j]==str[i])
            {
                count[i]++;
            }
        }
        while(str[i+j]==str[i]);

        if(count[i]==1)
        {
            cout<<str[i++];
        }
        else
        {
            cout<<count[i]<<str[i];
            i+=count[i];
        }
    }
    return 0;
}