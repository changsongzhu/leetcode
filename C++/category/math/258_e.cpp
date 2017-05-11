/**
258[E]. Add Digits
 
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.
For example:
Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.
Follow up:
Could you do it without any loop/recursion in O(1) runtime?

**/

class Solution {
public:
    int addDigits(int num) {
        int res=num;
        while(res>=10)
        {
            res=0;
            while(num)
            {
                res+=num%10;
                num=num/10;
            }
            num=res;
        }
        return res;
    }
};
