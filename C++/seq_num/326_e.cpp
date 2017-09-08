/**
326[E]. Power of Three
 
Given an integer, write a function to determine if it is a power of three.
Follow up:
Could you do it without using any loop / recursion?
**/


class Solution{
public:
    bool isPowerofThree(int n)
    {
        while(n&&n%3==0)
        {
            n/=3;
        }
        return n==1;
    }
};

class Solution{
public:
    bool isPowerOfThree(int n)
    {
        return (n>0&&pow(3, 19)%n==0);
    }
};

class Solution {
public:
    bool isPowerOfThree(int n) {
    /*logb(x)=log10(x)/log10(3)*/
        return (n>0&&(int(log10(n)/log10(3)) - log10(n)/log10(3) ==0));
    }
};
