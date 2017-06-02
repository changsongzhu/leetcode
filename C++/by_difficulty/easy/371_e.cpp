/**
371[E]. Sum of Two Integers
Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.
Example:
Given a = 1 and b = 2, return 3.
**/

class Solution {
public:
    int getSum(int a, int b) {
        int carry=0;
        while(b)
        {
            carry=(a&b)<<1;
            a=a^b;
            b=carry;
        }
        return a;
    }
};
