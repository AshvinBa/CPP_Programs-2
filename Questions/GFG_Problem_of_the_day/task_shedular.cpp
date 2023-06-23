/*
Task Scheduler

Given a character array tasks of size N, representing the tasks a CPU needs to do, where each letter represents a different task. Tasks could be done in any order. Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.
CPU has a cooldown period for each task. CPU can repeat a task only after atleast K units of time has passed after it did same task last time. It can perform other tasks in that time, can stay idle to wait for repeating that task.

Return the least number of units of times that the CPU will take to finish all the given tasks.

Example 1:
Input:
N = 6
K = 2
task[ ] = {'A', 'A', 'A', 'B', 'B', 'B'}
Output: 8
Explanation:
A -> B -> idle -> A -> B -> idle -> A -> B
There is atleast 2 units of time between any two same tasks.

Example 2:
Input:
N = 12
K = 2
task[ ] = {'A', 'A', 'A', 'A', 'A', 'A', 'B', 'C', 'D', 'E', 'F', 'G'}
Output: 16
Explanation:
One possible solution is
A -> B -> C -> A -> D -> E -> A -> F -> G -> A -> idle -> idle -> A -> idle -> idle -> A.

*/

#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int leastInterval(int N, int K, vector<char> &tasks)
{
    vector<int> f(26, 0);

    for (int i : tasks)
        ++f[i - 'A'];

    int max1 = -1;
    int count = 0;

    for (int i = 0; i < 26; i++)
    {
        if (f[i] == max1)
        {
            ++count;
        }
        else if (f[i] > max1)
        {
            max1 = f[i];
            count = 1;
        }
    }
    int ans = max(N, max1 + (max1 - 1) * K + count - 1);
    return ans;
}

int main()
{
    vector<char> tasks{'A', 'A', 'A', 'B', 'B', 'B'};
    int n = tasks.size();
    int k = 2;
    int ans = leastInterval(n, k, tasks);
    cout << "\nAnswer: " << ans;
    return 0;
}