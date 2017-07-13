/**
224[H]. Basic Calculator
Implement a basic calculator to evaluate a simple expression string.
The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .
You may assume that the given expression is always valid.
Some examples:
"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23
Note: Do not use the eval built-in library function.
**/

class Solution {
public:
    int calculate(string s) {
        int res=0;
        int sign=1;
        int pt=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>='0'&&s[i]<='9')
            {
                int num=0;
                while(i<s.size()&&s[i]>='0'&&s[i]<='9') num=num*10+(s[i++]-'0');
                res+=sign*num;
                i--;
            }
            else if(s[i]=='+'||s[i]=='-')
            {
                sign=(s[i]=='+')?1:-1;
            }
            else if(s[i]=='(')
            {
                int cnt=0, j=0;
                for(j=i;j<s.size();j++)
                {
                    if(s[j]=='(') cnt++;
                    else if(s[j]==')') cnt--;
                    if(cnt==0) break;
                }
                res+=sign*calculate(s.substr(i+1, j-i-1));
                i=j;
            }
        }
        return res;
    }
};

