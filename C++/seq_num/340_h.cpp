/**
159[H]. Longest Substring with At Most K distinct Characters
Given a string, find the length of the longest substring T that contains at most k distinct characters.
For example, Given s = “eceba” and k = 2,
T is "ece" which its length is 3.
**/

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
       unordered_map<char, int> m;
       int left=0;
       int res=0;
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

