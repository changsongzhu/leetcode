/**
438[E]. Find all anagrams in a String
 
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.
Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.
The order of output does not matter.
Example 1:
Input: s: "cbaebabacd" p: "abc"  Output: [0, 6]  Explanation: The substring with start index = 0 is "cba", which is an anagram of "abc". The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:
Input: s: "abab" p: "ab"  Output: [0, 1, 2]  Explanation: The substring with start index = 0 is "ab", which is an anagram of "ab". The substring with start index = 1 is "ba", which is an anagram of "ab". The substring with start index = 2 is "ab", which is an anagram of "ab".
**/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>v1(256, 0);
        vector<int>v2(256, 0);
        vector<int> res;
        for(int i=0;i<p.size();i++)
        {
            v1[p[i]]++;
            v2[s[i]]++;
        }
        if(v1==v2)res.push_back(0);
        for(int i=p.size();i<s.size();i++)
        {
            v2[s[i]]++;
            v2[s[i-p.size()]]--;
            if(v1==v2)res.push_back(i-p.size()+1);
        }
        return res;
    }
};
