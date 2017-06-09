/**
29[M]. Divide Two Integers
Divide two integers without using multiplication, division and mod operator.
If it is overflow, return MAX_INT.
**/

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0 || (dividend == INT_MIN && divisor == -1)) return INT_MAX;
        long long res=0;
        int sign=1;
        if((dividend<0&&divisor>0)||(dividend>0&&divisor<0)) sign=-1;
        long long m=abs((long long) dividend);
        long long n=abs((long long) divisor);
 
        while(m>=n)
        {
            long long t=n,p=1;
            while(m>=(t<<1))
            {
                t=t<<1;
                p=p<<1;
             
            }
            res+=p;
            m-=t;
        }
        return res==0?0:sign*res;
    }
};

