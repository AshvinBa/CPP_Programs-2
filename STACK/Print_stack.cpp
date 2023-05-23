#include<stack>
#include<Vector>
#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the limit: ";
    cin>>n;
    vector<int>ans(n);
    stack<int>s;
    for(int i=1;i<=n;i++)
    {
        s.push(i);
    }
    int num=s.top();
    s.pop();
    reverseEle(s,)
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
return 0;
}











