/**
385[M]. Mini Parser

Given a nested list of integers represented as a string, implement a parser to deserialize it.
Each element is either an integer, or a list -- whose elements may also be integers or other lists.
Note: You may assume that the string is well-formed:
•	String is non-empty.
•	String does not contain white spaces.
•	String contains only digits 0-9, [, - ,, ].
Example 1:
Given s = "324",

You should return a NestedInteger object which contains a single integer 324.
Example 2:
Given s = "[123,[456,[789]]]",

Return a NestedInteger object containing a nested list with 2 elements:

1. An integer containing value 123.
2. A nested list containing two elements:
    i.  An integer containing value 456.
    ii. A nested list with one element:
         a. An integer containing value 789.
**/

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
       stack<NestedInteger> stk;
       for(int i=0;i<s.size();)
       {
           if(s[i]=='[')
           {
               NestedInteger ni;
               stk.push(ni);
               i++;
           }
           else if((s[i]>='0'&&s[i]<='9')||s[i]=='-')
           {
               int val=0;
               int sign=1;
               if(s[i]=='-'){sign=-1;i++;}
               while(i<s.size()&&s[i]>='0'&&s[i]<='9')
               {
                   val=val*10+s[i]-'0';
                   i++;
               }
               val=sign*val;
               if(stk.empty())
               {
                  stk.push(NestedInteger(val));
               }
               else
               {
                  NestedInteger ni=stk.top();stk.pop();
                  ni.getList().push_back(val);
                  stk.push(ni);
               }
           }
           else if(s[i]==']')
           {
               NestedInteger ni=stk.top();stk.pop();
               if(stk.empty())
               {
                   stk.push(ni);
               }
               else
               {
                   NestedInteger ni2=stk.top();stk.pop();
                   ni2.getList().push_back(ni);
                   stk.push(ni2);
               }
               i++;
           }
           else
           {
               i++;
           }
       }
       return stk.empty()?NestedInteger():stk.top();
    }
};

