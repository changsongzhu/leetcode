/**
201[M]. Bitwise AND of Numbers Range
Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.
For example, given the range [5, 7], you should return 4.
**/
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
       long long a=m, b=n, res=m;
       for(long long i=a+1;i<=b;i++)
       {
           if(res==0) return 0;
           res&=i;
       }
       return res;
    }
};
