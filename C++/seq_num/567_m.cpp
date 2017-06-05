/**
567[M]. Permutation in String
 
Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.
Example 1:
Input:s1 = "ab" s2 = "eidbaooo"
Output:True
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:
Input:s1= "ab" s2 = "eidboaoo"
Output: False
Note:
The input strings only contain lower case letters.
The length of both given strings is in range [1, 10,000].
**/
 
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size()<s1.size()) return false;
        vector<int> m1(128, 0), m2(128, 0);
        for(int i=0;i<s1.size();i++)
        {
            m1[s1[i]]++;
            m2[s2[i]]++;
        }
        if(m1==m2) return true;
        for(int i=s1.size();i<s2.size();i++)
        {
            m2[s2[i-s1.size()]]--;
            m2[s2[i]]++;
            if(m1==m2) return true;
        }
        return false;
    }
};

