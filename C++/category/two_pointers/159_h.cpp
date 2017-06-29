/**
159[H]. Longest Substring with At Most 2 distinct Characters
Given a string S, find the length of the longest substring T that contains at most two distinct characters.
For example,
Given S = “eceba”,
T is “ece” which its length is 3.

**/

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
       unordered_map<char, int> m;
       int left=0;
       int res=0;
       int k=2;
       for(int right=0;right<s.size();right++)
       {
           m[s[right]]++;
           while(m.size()>k)
           {
               m[s[left]]--;
               if(m[s[left]]==0) m.erase(s[left]);
               left++;
           }
           res=max(res, right-left+1);
       }
       return res;
   }
};

