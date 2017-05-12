/**
342[E]. Power of Four
 
Given an integer (signed 32 bits), write a function to check whether it is a power of 4.
Example:
Given num = 16, return true. Given num = 5, return false.
Follow up: Could you solve it without loops/recursion?
**/

class Solution {
public:
    bool isPowerOfFour(int num) {
       if(num<=0) return false;

       for(int i=0;i<16;i++)
       {
           if(num==1) return true;
           if((num&0x3)!=0) return false;
           num=num>>2;
       }
       return false;
    }
};
