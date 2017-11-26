/**
392[M]. Is Subsequence
 
Given a string s and a string t, check if s is subsequence of t.
You may assume that there is only lower case English letters in both s and t. t is potentially a very long (length ~= 500,000) string, and s is a short string (<=100).
A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).
Example 1:
s = "abc", t = "ahbgdc"
Return true.
Example 2:
s = "axc", t = "ahbgdc"
Return false.
 
Notes:
·       Using two pointers to scan two strings, if the characters in two strings are the same, moving two pointers forward. Otherwise, just move the pointer of the string t
·       After the scan, check if the s’s pointer points to the end of the string s. If so, return true, otherwise, return false
**/

//Refind Solution
class Solution {
public:
    bool isSubsequence(string s, string t) {
       if(s.size()==0) return true;
       int m=s.size(), n=t.size();
       int index=0;
       for(int i=0;i<t.size();i++)
       {
           if(s[index]==t[i])index++;
           if(index==m) return true;
       }
       return index==m;
    }
};

 
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0,j=0;
        while(i<s.size()&&j<t.size())
        {
            if(s[i]==t[j]) i++;
            j++;       
        }
        return i==s.size();
    }
};

