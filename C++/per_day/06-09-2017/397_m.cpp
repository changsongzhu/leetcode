/**
397[M]. Integer Replacement
Given a positive integer n and you can do operations as follow:
If n is even, replace n with n/2.
If n is odd, you can replace n with either n + 1 or n - 1.
What is the minimum number of replacements needed for n to become 1?
Example 1:
Input:
8
 
Output:
3
 
Explanation:
8 -> 4 -> 2 -> 1
Example 2:
Input:
7
 
Output:
4
 
Explanation:
7 -> 8 -> 4 -> 2 -> 1
or
 
7 -> 6 -> 3 -> 2 -> 1
**/

class Solution {
public:
    int integerReplacement(int n) {
	int res=0;
        while(n>1)
        {
            res++;
            if(n%2==0) n=n/2;
            else
            {
                if(oneBits(n-1)==1)
                {
                    n=n-1;
                }
                else
                {
                    n=n+1;
                }
            }
        }    
        return res; 
    }
    int oneBits(int n)
    {
       int cnt=0;
       while(n>0)
       {
           cnt++;
           n=n&(n-1);
       }
       return cnt;
    }
};

class Solution{
public:
    int integerReplacement(int n) {
        return helper((long long)n);
    }

    int helper(long long n)
    {
       if(n==1) return 0;
       if(n%2==0) return 1+helper(n/2);
       return min(helper(n+1), helper(n-1))+1;
    }

};

