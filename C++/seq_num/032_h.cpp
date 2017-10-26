/**
32[H]. Longest Valid Parentheses
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
For "(()", the longest valid parentheses substring is "()", which has length = 2.
Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
**/


//DP Solution
class Solution{
public:
    int longestValidParentheses(string s){
        int n=s.size();
        vector<int> dp(n, 0);
        int res=0;
        for(int i=1;i<s.size();i++)
        {
            if(s[i]==')')
            {
                if(s[i-1]=='(') dp[i]=dp[i-2]+2;
                if(s[i-1]==')'&&s[i-dp[i-1]-1]=='(') dp[i]=dp[i-1]+dp[i-dp[i-1]-2]+2;
            }
            res=max(res, dp[i]);
        }
        return res;
    }
};


//Stack Solution
class Solution{
public:
    int longestValidParentheses(string s){
        stack<int> stk;
        int res=0;
        stk.push(-1);
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==')'&&s[stk.top()]=='(')
            {
                stk.pop();
                res=max(res, i-stk.top());
            }
            else
            {
                stk.push(i);
            }
        }
        return res;
    }
};

//Brute Force Solution
class Solution {
public:
    int longestValidParentheses(string s) {
        int res=0;
 
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==')') continue;
            int cnt=0;
            for(int j=i;j<s.size();j++)
            {
                if(s[j]=='(') cnt++;
                else cnt--;
                if(cnt<0) break;
                if(cnt==0) res=max(res, j-i+1);
            }
        }
        return res;
    }
};

