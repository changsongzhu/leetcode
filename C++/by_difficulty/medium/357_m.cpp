/**
357[M]. Count Number with Unique digits
Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10n.
Example:
Given n = 2, return 91. (The answer should be the total numbers in the range of 0 ≤ x < 100, excluding [11,22,33,44,55,66,77,88,99])
**/
 
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int mx=pow(10, n), used=0;
        int res=1;
        for(int i=1;i<10;i++)
        {
           used|=1<<i;
           res+=search(i, mx, used);
           used&=~(1<<i);
        }
        return res;
    }
    int search(int pre, int mx, int used)
    {
        int res=0;
        if(pre>=mx) return 0;
        else res++;
        for(int i=0;i<10;i++)
        {
            if(!(used&(1<<i)))
            {
                used|=1<<i;
                res+=search(pre*10+i, mx, used);
                used&=~(1<<i);
            }
        }
        return res;
    }
};

