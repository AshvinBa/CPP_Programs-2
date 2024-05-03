// // Aim: Implementation of RSA Asymmetric Cryptographic Algorithm
// #include <stdio.h>
// #include <math.h>
// int main()
// {
//     int p, q, n, phi, d, e, i, j, CT, PT;
//     printf("\nEnter First Primeno");
//     scanf("%d", &p);
//     printf("\nEnter Second Primeno");
//     scanf("%d", &q);
//     n = p * q;
//     phi = (p - 1) * (q - 1);
//     printf("\nchose e such thatit is relatively prime to\t %d", phi);
//     scanf("%d", &e);
//     for (d = 1; d < phi; d++)
//     {
//         if (((d * e) % phi) == 1)
//             break;
//     }
//     printf("\n Enter the plain text char");
//     scanf("%d", &PT);
//     CT = 1;
//     for (i = 0; i < e; i++)
//         CT = CT * PT % n;
//     printf("\n After Encryption %d", CT);
//     PT = 1;
//     for (i = 0; i < d; i++)
//         PT = PT * CT % n;
//     printf("\nAfter Decreption %d\n", PT);
//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int p,q,n,phi,d,e,i,ct,pt;
//     cout<<"Enter the First prime Number: ";
//     cin>>p;
//     cout<<"Enter the Second prime Number: ";
//     cin>>q;

//     n=p*q;
//     phi=(p-1)*(q-1);

//     cout<<"Choose e such that it is relatively prime to: "<<phi<<" : ";
//     cin>>e;

//     for(d=1;d<phi;d++)
//     {
//         if(((d*e)%phi)==1)
//         break;
//     }

//     cout<<"Enter the plain text char: ";
//     cin>>pt;

//     ct=1;
//     for(i=0;i<e;i++)
//     {
//         ct=ct*pt%n;
//     }
//     cout<<"After Encryption: "<<ct<<endl;
//     pt=1;
//     for(i=0;i<d;i++)
//     {
//         pt=pt*ct%n;
//     }
//     cout<<"After Decryption: "<<pt<<endl;
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
int main()
{
    int p,q,e,n,phi,pt,ct,i,d;

    cout<<"Enter the First prime Number: ";
    cin>>p;

    cout<<"Enter the second prime Number: ";
    cin>>q;

    n=p*q;
    phi=(p-1)*(q-1);

    cout<<"Choose e such that it is relatively prime to: "<<phi<<" : ";
    cin>>e;
    
    for(d=1;d<phi;d++)
    {
        if(((d*e)%phi)==1)
        break;
    }

    cout<<"Enter the plain text: ";
    cin>>pt;

    ct=1;
    for(i=0;i<e;i++)
    {
        ct=ct*pt%n;
    }
    cout<<"After Encryption: "<<ct<<endl;

    pt=1;
    for(i=0;i<d;i++)
    {
        pt=pt*ct%n;
    }
    cout<<"After Decryption: "<<pt<<endl;
    return 0;
}






















