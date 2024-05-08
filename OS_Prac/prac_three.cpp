// #include<stdio.h>
// #include<conio.h>
// #define max 25
// void main()
// {
// int frag[max],b[max],f[max],i,j,nb,nf,temp; static int
// bf[max],ff[max];
// printf("\n\tMemory Management Scheme - First Fit");
// printf("\nEnter the number of blocks:"); scanf("%d"
// ,&nb);
// printf("Enter the number of files:");
// scanf("%d"
// ,&nf);
// printf("\nEnter the size of the blocks:-\n");
// for(i=1;i<=nb;i++)
// {
// printf("Block %d:"
// ,i);
// scanf("%d"
// ,&b[i]);
// }
// printf("Enter the size of the files :-\n"); for(i=1;i<=nf;i++)
// {
// printf("File %d:"
// ,i);
// scanf("%d"
// ,&f[i]);
// }
// for(i=1;i<=nf;i++)
// {
// for(j=1;j<=nb;j++)
// { if(bf[j]!=1)
// { temp=b[j]-f[i]; if(temp>=0)
// { ff[i]=j;
// break;
// } } } frag[i]=temp;
// bf[ff[i]]=1;
// }
// printf("\nFile_no:\tFile_size
// :\tBlock_no:\tBlock_size:\tFragement"); for(i=1;i<=nf;i++)
// printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d"
// ,i,f[i],ff[i],b[ff[i]],fr
// ag[i]);
// getch();
// }

#include <iostream>
using namespace std;

int main() {
    int max = 25;
    int frag[max], b[max], f[max], i, j, nb, nf, temp;
    int bf[max], ff[max];

    cout << "\n\tMemory Management Scheme - First Fit";
    cout << "\nEnter the number of blocks: ";
    cin >> nb;
    cout << "Enter the number of files: ";
    cin >> nf;

    cout << "\nEnter the size of the blocks:\n";
    for (i = 1; i <= nb; i++) {
        cout << "Block " << i << ": ";
        cin >> b[i];
    }

    cout << "\nEnter the size of the files:\n";
    for (i = 1; i <= nf; i++) {
        cout << "File " << i << ": ";
        cin >> f[i];
    }

    for (i = 1; i <= nf; i++) {
        for (j = 1; j <= nb; j++) {
            if (bf[j] != 1) {
                temp = b[j] - f[i];
                if (temp >= 0) {
                    ff[i] = j;
                    break;
                }
            }
        }
        frag[i] = temp;
        bf[ff[i]] = 1;
    }

    cout << "\nFile_no:\tFile_size:\tBlock_no:\tBlock_size:\tFragment\n";
    for (i = 1; i <= nf; i++) {
        cout << i << "\t\t" << f[i] << "\t\t" << ff[i] << "\t\t" << b[ff[i]] << "\t\t" << frag[i] << "\n";
    }

    return 0;
}


// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int max=25;
//     int frag[max],b[max],f[max],i,j,nb,nf,temp;
//     int bf[max],ff[max];
    
//     cout<<"\n \tMemory management Scheme - First Fit: ";
//     cout<<"\nEnter the number of Block: ";
//     cin>>nb;
    
//     cout<<"Enter the number of Files: ";
//     cin>>nf;

//     cout<<"Enter the values of blocks: ";
//     for(i=1;i<=nb;i++)
//     {
//         cout<<"Block "<<i<<" : ";
//         cin>>b[i];
//     }

//     cout<<"Enter the values of files: ";
//     for(i=1;i<=nb;i++)
//     {
//         cout<<"Files "<<i<<" : ";
//         cin>>f[i];
//     }

//     for(i=1;i<=nf;i++)
//     {
//         for(j=1;j<=nb;j++)
//         {
//             if(bf[j]!=1)
//             {
//                 temp = b[j]-f[i];
//                 if(temp>=0)
//                 {
//                     ff[i]=j;
//                     break;
//                 }
//             }
//         }
//         frag[i]=temp;
//         bf[ff[i]]=1;
//     }

//     cout<<"\nFile_n\tFile size \t Block n \t Bloack size \t Fragment\n ";
//     for(int i=1;i<nb;i++)
//     {
//         cout << i << "\t\t" << f[i] << "\t\t" << ff[i] << "\t\t" << b[ff[i]] << "\t\t" << frag[i] << "\n";
//     }


//     return 0;
// }

























