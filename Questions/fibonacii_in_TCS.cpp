// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;

// int fibo(int n)
// {
//     if(n==0)return 0;

//     if(n==1)return 1;

//     return fibo(n-1)+fibo(n-2);
// }

// int main(){
//     int n=7;
//     cout<<"Answer: "<<fibo(n);
// return 0;
// }

// int fibo(int n)
//     {
//         if(n==1 || n==0)
//         {
//              return n;
//         }
//         else
//         {
//             return (fibo(n-1)+fibo(n-2));
//         }
//     }    
//     vector<int > printFibb(int n) 
//     {
//         vector<int >ans;
//         for(int i=1;i<=n;i++)
//         {
//             int num=fibo(i);
//             ans.push_back(num);
//         }
//         return ans;
//     }
// int main()
// {
//     int n=5;
//     vector<int>ans=printFibb(n);
//     for(auto i=ans.begin();i!=ans.end();i++)
//     {
//         cout<<*i<<" ";
//     }
//     return 0;
// }


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// vector<int> fibo(int n)
// {
//     vector<int>ans;
//     int a=0,b=1,s=0;
//     for(int i=0;i<n;i++)
//     {
//         // ans.push_back(s);
//         s=a+b;
//         a=b;
//         b=s;
//         ans.push_back(s);
//     }
//     return ans;
// }
//TCS Solution.
vector<long long> printFibb(int n) 
    {   vector<long long> ans;
        long long int a=1,b=1;
        if(n>=1)
            ans.push_back(1);
        if(n>=2) 
            ans.push_back(1);
            
        
        for(int i = 2 ; i < n ; ++ i ) 
        {
            ans.push_back(a+b);
            long long int c=a+b;
            a=b;
            b=c;
        }
        return ans;
    }
int main(){
    int n=5;
    vector<int>ans=fibo(n);    
    for(auto i=ans.begin();i!=ans.end();i++)
    {
        cout<<*i<<" ";
    }
return 0;
}













