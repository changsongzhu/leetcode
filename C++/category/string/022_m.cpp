/**
22[M]. Generate Parentheses
 
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
For example, given n = 3, a solution set is:
[  
"((()))",  
"(()())",  
"(())()",  
"()(())",  
"()()()"
]

**/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string path;
        helper(res, path, n, n);
        return res;
    }
    void helper(vector<string> &res, string path, int left, int right)
    {
       if(left==0&&right==0)
       {
          res.push_back(path);
          return;
       }
       if(left>right) return;
       if(left>0)
           helper(res, path+"(", left-1,right);
       if(right>0)
           helper(res, path+")", left, right-1);
    }
};

