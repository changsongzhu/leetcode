/**
600[H]. Non-negative Integers without Consecutive Ones
Given a positive integer n, find the number of non-negative integers less than or equal to n, whose binary representations do NOT contain consecutive ones.
Example 1:
Input: 5
Output: 5
Explanation:
Here are the non-negative integers <= 5 with their corresponding binary representations:
0 : 0
1 : 1
2 : 10
3 : 11
4 : 100
5 : 101
Among them, only integer 3 disobeys the rule (two consecutive ones) and the other 5 satisfy the rule.
Note: 1 <= n <= 109
**/

class Solution {
public:
    int findIntegers(int num) {
        int cnt=0,n=num;
        string t="";
        while(n)
        {
           cnt++;
           t+=(n&1)?"1":"0";
           n=n>>1;
        }
        vector<int>  one(cnt), zero(cnt);
        one[0]=zero[0]=1;
        for(int i=1;i<cnt;i++)
        {
            zero[i]=zero[i-1]+one[i-1];
            one[i]=zero[i-1];
        }
        int res= one[cnt-1]+zero[cnt-1];
        for(int i=cnt-2;i>=0;i--)
        {
            if(t[i]=='1'&&t[i+1]=='1') break;
            if(t[i]=='0'&&t[i+1]=='0') res-=one[i];
        }
        return res;
        
    }
};

