/**
20[E]. Valid Parentheses
 
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 
Notes:
·      Use a stack to save the left parentheses. If meet a right one, check if the top of the stack is the matched one. If so, pop it and check the next one. Otherwise, it is not valid parentheses. 

**/
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='('||s[i]=='{'||s[i]=='[')
                stk.push(s[i]);
            else if((s[i]==')'&&!stk.empty()&&stk.top()=='(')||
                    (s[i]==']'&&!stk.empty()&&stk.top()=='[')||
                    (s[i]=='}'&&!stk.empty()&&stk.top()=='{'))
            {
                stk.pop();
            }
            else
                return false;
        }
        if(!stk.empty()) return false;
        return true;
    }
};

