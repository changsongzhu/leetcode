/**
564[H]. Find the Closest Palindrome
Given an integer n, find the closest integer (not including itself), which is a palindrome.
The 'closest' is defined as absolute difference minimized between two integers.
Example 1:
Input: "123"
Output: "121"
Note:
The input n is a positive integer represented by string, whose length will not exceed 18.
If there is a tie, return the smaller one as answer.
**/

class Solution {
public:
    string nearestPalindromic(string n) {
        long long num=stoll(n);
        long long big=findHigherPalindrome(num+1);
        long long small=findLowerPalindrome(num-1);
        return abs(num-small)>abs(num-big)?to_string(big):to_string(small);
    }
    long long findHigherPalindrome(long long limit)
    {
        string s=to_string(limit);
        int n=s.size();
        string t=s;
        for(int i=0;i<n/2;i++)
            t[n-1-i]=t[i];

        for(int i=0;i<n;i++)
        {
            if(s[i]<t[i]) return stoll(t);
            else if(s[i]>t[i])
            {
                for(int j=(n-1)/2;j>=0;j--)
                {
                    if(++t[j]>'9') t[j]='0';
                    else break;
                }
            }
            for(int k=0;k<n/2;k++)
                t[n-1-k]=t[k];
            return stoll(t);
        }
        return stoll(t);
    }
    long long findLowerPalindrome(long long limit)
    {
        string s=to_string(limit);
        int n=s.size();
        string t=s;
        for(int i=0;i<n/2;i++)
            t[n-1-i]=t[i];

        for(int i=0;i<n;i++)
        {
            if(s[i]>t[i]) return stoll(t);
            else if(s[i]<t[i])
            {
                for(int j=(n-1)/2;j>=0;j--)
                {
                    if(--t[j]<'0') t[j]='9';
                    else break;
                }
            }
            if(t[0]=='0')
            {
                string tmp(n-1,'9');
                return stoll(tmp);
            }
            for(int k=0;k<n/2;k++)
                t[n-1-k]=t[k];
            return stoll(t);
        }
        return stoll(t);
    }
};

