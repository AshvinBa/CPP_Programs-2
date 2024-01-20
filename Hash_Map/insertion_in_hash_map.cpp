#include<iostream>
#include<unordered_map>
#include<map>
#include<bits/stdc++.h>
using namespace std;
int main(){
    
    // creation
    unordered_map<string,int>m;
    //map<string,int>m;



    // insertion

    // 1
    pair<string,int>p=make_pair("ashvin",1);
    m.insert(p);

    cout<<m["ashvin"]<<endl;

    // 2
    pair<string,int>pair2("love",2);
    m.insert(pair2);

    // 3
    // inserting the values in "m".
    m["tushar"]=3;
    cout<<m["tushar"]<<endl;


    m["tushar"]=5;
    cout<<m["tushar"]<<endl;

    // search
    cout<< m["ashvin"]<<endl;
    cout<< m.at("ashvin")<<endl;  // specialy for searching.  
    

    // cout<<m.at("unknown")<<endl;  // before insertion it will throws an errors.
    cout<<m["unknown"]<<endl;
    cout<<m.at("unknown")<<endl;  //remember that the value has been already inserted. 

    // size
    cout<<"SIZE: "<<m.size()<<endl;

    // count
    // The count is use for checking presence of character if present then 1 otherwise 0.
    cout<<"The number of counts of Ashvin is: "<<m.count("ashvin")<<endl;
    cout<<"If the value is not present then: "<<m.count("Tushar")<<endl;



    // erase.
    m.erase("love");
    cout<<"Size = "<<m.size()<<endl;


    // Traversing
    for(auto i:m)
    {
        cout<<i.first<<" "<<i.second<<endl;
    }


    //iterator  unorder iterator.
    cout<<"By unordered_map"<<endl;
    unordered_map<string,int> :: iterator it = m.begin();
    while(it != m.end())
    {
        cout<<it->first<<" "<<it->second<<" "<<endl;
        it++;
    }

/*
    cout<<"For map it require to store it first in map.";
    // map<string,int>mp;
    cout<<"By ordered_map"<<endl;
    map<string,int> :: iterator mp = m.begin();
    while(mp != m.end())
    {
        cout<<mp->first<<" "<<mp->second<<" "<<endl;
        mp++;
    }
*/
return 0;
}














