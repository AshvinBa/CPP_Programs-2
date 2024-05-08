// #include<stdio.h>
// #include<conio.h>
// struct fileTable
// {
// char name[20];
// int sb, nob;
// }ft[30];
// void main()
// {
// int i, j, n;
// char s[20];
// printf("Enter no of files :");
// scanf("%d"
// ,&n);
// for(i=0;i<n;i++)
// {
// printf("\nEnter file name %d :"
// ,i+1); scanf("%s"
// ,ft[i].name);
// printf("Enter starting block of file %d :"
// ,i+1); scanf("%d"
// ,&ft[i].
// sb);
// printf("Enter no of blocks in file %d :"
// ,i+1);
// scanf("%d"
// ,&ft[i].nob);
// }
// printf("\nEnter the file name to be searched-- ");
// scanf("%s"
// ,s);
// for(i=0;i<n;i++) if(strcmp(s,
// ft[i].name)==0) break;
// if(i==n)
// printf("\nFile Not Found"); else
// {
// printf("\nFILE NAME START BLOCK NO OF BLOCKS BLOCKS
// OCCUPIED\n");
// printf("\n%s\t\t%d\t\t%d\t"
// ,ft[i].name,ft[i].sb,ft[i].nob);
// for(j=0;j<ft[i].nob;j++)
// printf("%d,
// "
// ,ft[i].sb+j);
// }
// getch();
// }


// #include<iostream>
// #include<string>
// #include<vector>
// using namespace std;
// // Define a structure to hold file information

// struct FileTable {
//     string name; // File name
//     int sb;           // Starting block of the file
//     int nob;          // Number of blocks the file occupies
// };

// int main() {
//     int n; // Number of files
//     cout << "Enter no of files: ";
//     cin >> n;

//     vector<FileTable> ft(n); // Create a vector of FileTable structures

//     // Input file details from the user
//     for(int i = 0; i < n; i++) {
//         cout << "\nEnter file name " << i+1 << ": ";
//         cin >> ft[i].name;
//         cout << "Enter starting block of file " << i+1 << ": ";
//         cin >> ft[i].sb;
//         cout << "Enter no of blocks in file " << i+1 << ": ";
//         cin >> ft[i].nob;
//     }

//     string s; // File name to search
//     cout << "\nEnter the file name to be searched: ";
//     cin >> s;

//     // Search for the file
//     int i = 0;
//     for(; i < n; i++) {
//         if(s == ft[i].name) break;
//     }

//     // Output the result
//     if(i == n) {
//         cout << "\nFile Not Found";
//     } else {
//         cout << "\nFILE NAME\tSTART BLOCK\tNO OF BLOCKS\tBLOCKS OCCUPIED\n";
//         cout << "\n" << ft[i].name << "\t\t" << ft[i].sb << "\t\t" << ft[i].nob << "\t";
//         for(int j = 0; j < ft[i].nob; j++)
//             cout << ft[i].sb + j << ", ";
//     }

//     return 0; // Return statement added for main
// }


#include<bits/stdc++.h>
using namespace std;

struct FileTable
{
    string name;
    int sf;
    int npb;
};

int main()
{
    int n;
    cout<<"Enter the number of files: ";
    cin>>n;

    vector<FileTable>ft(n);

    for(int i=0;i<n;i++)
    {
        cout<<"Enter the name of file: "<<i+1<<" : ";
        cin>>ft[i].name;
        cout<<"Enter the size of block "<<i+1<<" : ";
        cin>>ft[i].sf;
        cout<<"Enter the number of block: "<<i+1<<" : ";
        cin>>ft[i].npb;
    }

    string s;
    cout<<"Enter the string: ";
    cin>>s;

    int i=0;
    for(;i<n;i++)
    {
        if(ft[i].name==s)
        break;
    }

    if(i==n)
    {
        cout<<"The file is not found."<<endl;
    }    
    else
    {
        cout<<"\nFile Name \t Start Block \t No. of Block \t Block Occupide\n";
        cout<<"\n"<<ft[i].name<<"\t\t"<<ft[i].sf<<"\t\t"<<ft[i].npb<<"\t\t";
        
        for(int i=0;i<ft[i].npb;i++)
        {
            cout<<ft[i].sf+i<<"";
        }
    }
    return 0;
}










































