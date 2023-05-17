/*
Trace Path

There is a rectangular path for a Train to travel consisting of n rows and m columns. The train will start from one of the grid's cells and it will be given a command in the form of string s consisting of characters L, R, D, U. Find if it is possible to travel the train inside the grid only.
Note:
If the train is at position (i,j)
on taking 'L' it goes to (i,j-1),
on taking 'R' it goes to (i,j+1),
on taking 'D' it goes to (i-1,j),
on taking 'U' it goes to (i+1,j).

Example 1:

Input: 
n = 1, m = 1
s = "R"
Output: 0
Explaination: There is only one cell(1,1). So train can only start from (1,1). On taking right(R) train moves to (1,2), which is out of grid.
Therefore there is no cell from where train can start and remain inside the grid after tracing the route.
*/

#include<iostream>
using namespace std;

 int isPossible(int n, int m, string s){
        int x,y;
        x=0;
        y=0;
        int minx,miny,maxx,maxy;
        minx=miny=maxx=maxy=0;
        
        for(auto i:s)
        {
            if(i == 'L')
            {
                --y;
            }
            else if(i == 'R')
            {
                ++y;
            }
            else if(i == 'D')
            {
                --x;
            }
            else
            {
                ++x;
            }
            
            maxx=max(x,maxx);
            maxy=max(y,maxy);
            
            minx=min(x,minx);
            miny=min(y,miny);
            
            if(maxx - minx >= n || maxy - miny >= m )
            return 0;
            
        }
        return 1;
    }

int main(){
    string s="LLRU";
    int n=2,m=3;
    cout<<"Answer: "<<isPossible(n, m, s);
return 0;
}