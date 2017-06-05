/**227[M]. Basic Calculator II
Implement a basic calculator to evaluate a simple expression string.
The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.
You may assume that the given expression is always valid.
Some examples:
"3+2*2" = 7
" 3/2 " = 1
" 3+5 / 2 " = 5
Note: Do not use the eval built-in library function.
 **/

class Solution {
public:
    int calculate(string s) {
        if(s.size()==0) return 0;
        int index=0;
        stack<int> stk;
        for(int i=0;i<s.size();i++){
            if(s[i]!='')
               s[index++]=s[i];
        }
        s.resize(index);
        char sign='+';
        for(int i=0;i<s.size();i++){
           if(s[i]>='0'&&s[i]<='9'){
              int val=0;
              while(s[i]>='0'&&s[i]<='9'&&i<s.size())
                  val=val*10+s[i++]-'0';
              i--;
              if(sign=='+')
                  stk.push(val);
              else if(sign=='-')
                  stk.push(-1*val);
              else if(sign=='*'){
                  val=stk.top()*val;stk.pop();
                  stk.push(val);
              }
              else if(sign=='/'){
                  val=stk.top()/val;stk.pop();
                  stk.push(val);
              }
           }
           else if(s[i]=='+') sign='+';
           else if(s[i]=='-') sign='-';
           else if(s[i]=='*') sign='*';
           else if(s[i]=='/') sign='/';
        }
        int res=0;
        while(!stk.empty()){
            res+=stk.top();stk.pop();
        }
        return res;
    }
};
