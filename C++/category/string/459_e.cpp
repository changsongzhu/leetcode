/**
459[E].  Repeated Substring Pattern
 
Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.
Example 1:
Input: "abab"
 
Output: True
 
Explanation: It's the substring "ab" twice.
Example 2:
Input: "aba"
 
Output: False
Example 3:
Input: "abcabcabcabc"
 
Output: True
 
Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)
**/
 
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        vector<int> v(26,0);
        for(int i=0;i<s.size();i++)
            v[s[i]-'a']++;

        int least_repeat=INT_MAX;
        for(int i=0;i<26;i++)
        {
           if(v[i]!=0)
               least_repeat=min(least_repeat, v[i]);
        }

        for(int i=2;i<=least_repeat;i++)
        {
           string tmp="";
           if(s.size()%i==0)
           {
               for(int j=0;j<i;j++)
                  tmp+=s.substr(0, s.size()/i);
           }
           if(tmp==s) return true;
        }

        return false;
        
    }
};
