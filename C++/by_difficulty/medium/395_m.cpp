/**
395[M]. Longest Substring with At least K Repeating Characters
Find the length of the longest substring T of a given string (consists of lowercase letters only) such that every character in T appears no less than k times.
Example 1:
Input:
s = "aaabb", k = 3
 
Output:
3
 
The longest substring is "aaa", as 'a' is repeated 3 times.
Example 2:
Input:
s = "ababbc", k = 2
 
Output:
5
 
The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
**/
 
class Solution {
public:
    int longestSubstring(string s, int k) {
       int res=0;
       for(int i=0;i<s.size();i++)
       {
           int m[26]={0}, mask=0;
           for(int j=i;j<s.size();j++)
           {
              int t=s[j]-'a';
              m[t]++;
              if(m[t]<k) mask|=1<<t;
              else mask&=(~(1<<t));
              if(mask==0) res=max(res, j-i+1);
           }
       }
       return res;
    }
};

