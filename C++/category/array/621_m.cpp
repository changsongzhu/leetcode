/**
621[M]. Task Schedule
Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters represent different tasks.Tasks could be done without original order. Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.
However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n intervals that CPU are doing different tasks or just be idle.
You need to return the least number of intervals the CPU will take to finish all the given tasks.
Example 1:
Input: tasks = ['A','A','A','B','B','B'], n = 2
Output: 8
Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
Note:
The number of tasks is in the range [1, 10000].
The integer n is in the range [0, 100].
**/

class Solution {
public:
        int leastInterval(vector<char>& tasks, int n) {
            if(n==0) return tasks.size();
            vector<int> t(26, 0);
            int res=0;
            int total=tasks.size();
            for(auto a:tasks) t[a-'A']++;
            int cnt=0;
            sort(t.rbegin(), t.rend());
            while(cnt<total)
            {
                int diff=0;
                for(int i=0;i<t.size();i++)
                {
                   if(t[i]!=0)
                   {
                      diff++;
                      t[i]--;
                   }
                   if(diff==n+1) break;
                }
                sort(t.rbegin(),t.rend());
                cnt+=diff;
                if(diff>n) res+=diff;
                else res+=(cnt==total?diff:n+1);
            }
            return res;
        
        }
};

