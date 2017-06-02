/**
402[M]. Remove K Digits
Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.
Note:
The length of num is less than 10002 and will be ≥ k.
The given num does not contain any leading zero.
Example 1:
Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:
Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:
Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
**/
 
class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k>=num.size()) return "0";
        stack<char> stk;
        int keep=num.size()-k;
        for(int i=0;i<num.size();i++)
        {
            while(!stk.empty()&&k&&num[i]<stk.top())
            {
                stk.pop();
                --k;
            }
            stk.push(num[i]);
        }
        while(stk.size()!=keep) stk.pop();
        stack<char> s1;
        while(!stk.empty()){s1.push(stk.top()); stk.pop();}
        //remove the zero
        while(!s1.empty()&&s1.top()=='0') s1.pop();
        if(s1.empty()) return "0";
        else
        {
           string res;
           while(!s1.empty())
           {
               res.append(1, s1.top());
               s1.pop();
           }
           return res;
        }
    }
};
