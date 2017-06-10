/**
372[M]. Super Pow
Your task is to calculate ab mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.
Example1:
a = 2
b = [3]
 
Result: 8
Example2:
a = 2
b = [1,0]
 
Result: 1024
**/
 
class Solution {
public:
    int superPow(int a, vector<int>& b) {
        int res=1;
        for(int i=0;i<b.size();i++)
        {
            res=mypow(res,10)*mypow(a, b[i])%1337;
        }
        return res;
    }
    int mypow(int a, int n)
    {
        if(n==0) return 1;
        if(n==1) return a%1337;
        return mypow(a%1337, n/2)*mypow(a%1337, n-n/2)%1337;
    }
};

