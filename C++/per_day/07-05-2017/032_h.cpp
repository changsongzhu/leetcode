/**
32[H]. Longest Valid Parentheses
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
For "(()", the longest valid parentheses substring is "()", which has length = 2.
Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
**/
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

