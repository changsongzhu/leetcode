/**
150[M]. Evaluate Reverse Polish Notation

Evaluate the value of an arithmetic expression in Reverse Polish Notation.
Valid operators are +, -, *, /. Each operand may be an integer or another expression.
Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
**/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
       stack<string> stk;
       int res=0;
       for(int i=0;i<tokens.size();i++){
           if(tokens[i]=="+"){
               string t1=stk.top();stk.pop();
               string t2=stk.top();stk.pop();
               int val=stoi(t1)+stoi(t2);
               stk.push(to_string(val));
           }
           else if(tokens[i]=="-"){
               string t1=stk.top();stk.pop();
               string t2=stk.top();stk.pop();
               int val=stoi(t2)-stoi(t1);
               stk.push(to_string(val));

           }
           else if(tokens[i]=="*"){
               string t1=stk.top();stk.pop();
               string t2=stk.top();stk.pop();
               int val=stoi(t1)*stoi(t2);
               stk.push(to_string(val));

           }
           else if(tokens[i]=="/"){
               string t1=stk.top();stk.pop();
               string t2=stk.top();stk.pop();
               int val=stoi(t2)/stoi(t1);
               stk.push(to_string(val));

           }
           else{
               stk.push(tokens[i]);
           }
       }
       return stoi(stk.top());
    }
};

