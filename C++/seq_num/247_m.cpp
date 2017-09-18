/**
247[M]. Strobogrammatic Number 2
 
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
Find all strobogrammatic numbers that are of length = n.
For example,
Given n = 2, return ["11","69","88","96"].
Hint:
Try to use recursion and notice that it should recurse with n - 2 instead of n - 1.
**/
 
class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        vector<string> res;
        helper(res, n, n);
        return res;
    }
    
    void helper(vector<string>&res, int n, int m)
    {
        if(n<=0)
        {
            res.push_back("");
            return;
        }
        if(n==1)
        {
            res.push_back("1");
            res.push_back("8");
            res.push_back("0");
            return;
        }
        helper( res, n-2, m);
        int size=res.size();
        for(int i=0;i<size;i++)
        {
            string tmp=res[i];
            res[i]="1"+tmp+"1";
            if(m!=n) res.push_back("0"+tmp+"0");
            res.push_back("8"+tmp+"8");
            res.push_back("9"+tmp+"6");
            res.push_back("6"+tmp+"9");
        }
    }
};

