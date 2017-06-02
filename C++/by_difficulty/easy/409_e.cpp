/**
409[E]. Longest Palindrome
Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.
This is case sensitive, for example "Aa" is not considered a palindrome here.
Note:
Assume the length of given string will not exceed 1,010.
Example:
Input: "abccccdd"  Output: 7  Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7. 
**/

class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> mp;
        for(int i=0;i<s.size();i++) mp[s[i]]++;
        int odd_max=0;
        int res=0;
        for(map<char,int>::iterator it=mp.begin();it!=mp.end();it++)
        {
            if((it->second%2)==1)
            {
                odd_max=max(odd_max, it->second);
                res+=(it->second-1);
            }
            else
            {
                res+=it->second;
            }
        }
        return (odd_max!=0)?res+1:res;
    }
};
