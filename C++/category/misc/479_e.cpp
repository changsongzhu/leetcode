/**
479[E]. Largest Palindrome Product
Find the largest palindrome made from the product of two n-digit numbers.
Since the result could be very large, you should return the largest palindrome mod 1337.
Example:
Input: 2
Output: 987
Explanation: 99 x 91 = 9009, 9009 % 1337 = 987
Note:
The range of n is [1,8].
**/
class Solution {
public:
    int largestPalindrome(int n) {
        if(n==1) return 9;
        int mod=pow(10, n);
        int max=pow(10, n)-1;
        long long prod=(long long)max*(long long)max;
        int left=(int)(prod/mod);
        int right=(int)(prod%mod);
        if(left==reverse(right)) return (int)(prod%1337);
        if(left>right) left--;
        prod=(long long)left*(long long)mod+(long long)reverse(left);
        while(left!=mod/10)
        {
            for(int i=max;i>prod/i;i--)
                if(prod%i==0) return (int)(prod%1337);
            left--;
            prod=(long long)left*(long long)mod+(long long)reverse(left);
        }
        return (int)(prod%1337);
        
    }
    int reverse(int n)
    {
        string s=to_string(n);
        for(int i=0;i<s.size()/2;i++)
            swap(s[i], s[s.size()-1-i]);
        return stoi(s);
    }
};



//TLE Solution

class Solution {
public:
    int largestPalindrome(int n) {
        long long a=pow(10, n)-1;
        long long b=pow(10, n-1);
        long long res=0;
        for(long long i=a;i>=b;i--)
        {
            for(long long j=a;j>=b;j--)
            {
                if(palindrome(i*j))
                    res=max(res, i*j);
            }
        }
        return res%1337;
    }
    bool palindrome(long long num)
    {
        string s=to_string(num);
        for(int i=0;i<s.size()/2;i++)
        {
            if(s[i]!=s[s.size()-1-i]) return false;
        }
        return true;
    }
};

