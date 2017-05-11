/**
7[E]. Reverse Integer
 
Reverse digits of an integer.
Example1: x = 123, return 321
Example2: x = -123, return -321
 
Notes:
·      Avoid the overflow/underflow, using the long long type and check the value before return
**/

class Solution {
public:
    int reverse(int x) {
        if(x==0) return x;
        int sign=(x>0)?1:-1;

        long long res=0;
        x=x*sign;
        while(x>0)
        {
            res=res*10+x%10;
            if(res>INT_MAX) return 0;
            x=x/10;
        }
        return sign*res;
    }
};
