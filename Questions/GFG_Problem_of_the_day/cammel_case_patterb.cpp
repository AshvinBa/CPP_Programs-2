/*
CamelCase Pattern Matching
You can earn more Geekbits by participating in GFG Weekly Coding Contest  

Given a dictionary of words where each word follows CamelCase notation, print all words (in lexicographical order) in the dictionary that match with a given pattern consisting of uppercase characters only.

Example: GeeksForGeeks matches the pattern "GFG", because if we combine all the capital letters in GeeksForGeeks they become GFG.

CamelCase is the practice of writing compound words or phrases such that each word or abbreviation begins with a capital letter. Common examples include PowerPoint and Wikipedia, GeeksForGeeks, CodeBlocks, etc.

Example 1:
Input:
N=3
Dictionary=["WelcomeGeek",
"WelcomeToGeeksForGeeks","GeeksForGeeks"]
Pattern="WTG"
Output:
WelcomeToGeeksForGeeks
Explanation:
Since only WelcomeToGeeksForGeeks matches 
the pattern, it is the only answer.
Example 2:

Input:
N=8
Dictionary=["Hi","Hello","HelloWorld",
"HiTech","HiGeek","HiTechWorld",
"HiTechCity","HiTechLab"]
Pattern="HA"
Output:
-1
Explanation:
Since the pattern matches none of the words
of the string,the output is -1
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<string> CamelCase(int N, vector<string> Dictionary, string Pattern) {
        
        vector<string> ans;
        for(auto dx:Dictionary)
        {
            int j=0;
            for(int i=0;i<dx.length();i++)
            {
                if(j<Pattern.length() and dx[i]==Pattern[j])
                j++;
                else if(isupper(dx[i]))break;
            }
            if(j==Pattern.length())
            ans.push_back(dx);
        }
        if(ans.size()==0)
        ans.push_back("-1");
        
        return ans;
};
int main() {
        int N;
        cout<<"Enter how many words to enter: ";
        cin >> N;
        vector<string> Dictionary(N);
        cout<<"Enter the words in Dictionary: ";
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cout<<"Enter the patterb: ";
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    
    return 0;
}
};
/*
CamelCase Pattern Matching
You can earn more Geekbits by participating in GFG Weekly Coding Contest  

Given a dictionary of words where each word follows CamelCase notation, print all words (in lexicographical order) in the dictionary that match with a given pattern consisting of uppercase characters only.

Example: GeeksForGeeks matches the pattern "GFG", because if we combine all the capital letters in GeeksForGeeks they become GFG.

CamelCase is the practice of writing compound words or phrases such that each word or abbreviation begins with a capital letter. Common examples include PowerPoint and Wikipedia, GeeksForGeeks, CodeBlocks, etc.

Example 1:
Input:
N=3
Dictionary=["WelcomeGeek",
"WelcomeToGeeksForGeeks","GeeksForGeeks"]
Pattern="WTG"
Output:
WelcomeToGeeksForGeeks
Explanation:
Since only WelcomeToGeeksForGeeks matches 
the pattern, it is the only answer.
Example 2:

Input:
N=8
Dictionary=["Hi","Hello","HelloWorld",
"HiTech","HiGeek","HiTechWorld",
"HiTechCity","HiTechLab"]
Pattern="HA"
Output:
-1
Explanation:
Since the pattern matches none of the words
of the string,the output is -1
*/

#include <bits/stdc++.h>
using namespace std;

 vector<string> CamelCase(int N, vector<string> Dictionary, string Pattern) {
        
        vector<string> ans;
        for(auto dx:Dictionary)
        {
            int j=0;
            for(int i=0;i<dx.length();i++)
            {
                if(j<Pattern.length() and dx[i]==Pattern[j])
                j++;
                else if(isupper(dx[i]))break;
            }
            if(j==Pattern.length())
            ans.push_back(dx);
        }
        if(ans.size()==0)
        ans.push_back("-1");
        
        return ans;
}
int main() {
        int N;
        cout<<"Enter how many words to enter: ";
        cin >> N;
        vector<string> Dictionary(N);
        cout<<"Enter the words in Dictionary: ";
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cout<<"Enter the patterb: ";
        cin >> Pattern;
        
        vector<string> ans = CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    
    return 0;
}

