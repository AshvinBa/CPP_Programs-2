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






#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int p, q, n, phi, d, e, i, CT, PT;

    // Input the first prime number
    cout << "Enter First Prime number: ";
    cin >> p;

    // Input the second prime number
    cout << "Enter Second Prime number: ";
    cin >> q;

    // Calculate n and phi
    n = p * q;
    phi = (p - 1) * (q - 1);

    // Choose e such that it is relatively prime to phi
    cout << "Choose e such that it is relatively prime to " << phi << ": ";
    cin >> e;

    // Calculate d (private key)
    for (d = 1; d < phi; d++)
    {
        if (((d * e) % phi) == 1)
            break;
    }

    // Input the plain text character
    cout << "Enter the plain text char: ";
    cin >> PT;

    // Encryption: CT = (PT^e) % n
    CT = 1;
    for (i = 0; i < e; i++)
        CT = (CT * PT) % n;

    cout << "After Encryption: " << CT << endl;

    // Decryption: PT = (CT^d) % n
    PT = 1;
    for (i = 0; i < d; i++)
        PT = (PT * CT) % n;

    cout << "After Decryption: " << PT << endl;

    return 0;
}