// #include <iostream>
// #include <string>

// using namespace std;

// int main()
// {
//     string Msg = "SSBTCOETJALGAON";
//     char Key = '$';
//     string CTxt = "";
//     string DTxt = "";

//     // Encryption
//     for (int i = 0; i < Msg.length(); i++)
//     {
//         int xor_val = Msg[i] ^ Key;
//         char temp = static_cast<char>(xor_val);
//         CTxt += temp;
//     }

//     cout << "Encryption and Decryption using XOR Cryptography" << endl;
//     cout << "Original Message is: " << Msg << endl;
//     cout << "Encrypted Message is: " << CTxt << endl;

//     // Decryption
//     for (int i = 0; i < CTxt.length(); i++)
//     {
//         int xor1_val = CTxt[i] ^ Key;
//         char temp1 = static_cast<char>(xor1_val);
//         DTxt += temp1;
//     }

//     cout << "Decrypted Message is: " << DTxt << endl;

//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// int  main()
// {
//     string msg="SSBTCOETJALGAON";
//     char key='$';
//     string CTxt="";
//     string DTxt="";

//     for(int i=0;i<msg.length();i++)
//     {
//         int xor_val=key^msg[i];
//         char temp = static_cast<char>(xor_val);
//         CTxt+=temp;
//     }
//     cout<<"The Original string is: "<<msg<<endl;
//     cout<<"The Encrypted string is: "<<CTxt<<endl;

//     for(int i=0;i<CTxt.length();i++)
//     {
//         int xor_val=key^CTxt[i];
//         char temp = static_cast<char>(xor_val);
//         DTxt+=temp;
//     }
//     cout<<"The Decrypted string is: "<<DTxt<<endl;
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
int main()
{
    string msg="ASHVINSUDHIRBARI";
    char key='$';
    string CTxt="";
    string DTxt="";
    for(int i=0;i<msg.length();i++)
    {
        int xor_val=key^msg[i];
        char temp=static_cast<char>(xor_val);
        CTxt+=temp;
    }
    cout<<"The Original Message is: "<<msg<<endl;
    cout<<"The Encrypted Message is: "<<CTxt<<endl;
    for(int i=0;i<CTxt.length();i++)
    {
        int xor_val=key^CTxt[i];
        char temp=static_cast<char>(xor_val);
        DTxt+=temp;
    }
    cout<<"The Decryption Message is: "<<DTxt<<endl;
    return 0;
}




