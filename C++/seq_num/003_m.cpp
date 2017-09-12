/**
3[M]. Longest Substring Without Repeating Characters
 
Given a string, find the length of the longest substring without repeating characters.
Examples:
Given "abcabcbb", the answer is "abc", which the length is 3.
Given "bbbbb", the answer is "b", with the length of 1.
Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
**/
//Refined Solution
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> m;
        int left=0;
        int res=0;
        for(int i=0;i<s.size();i++)
        {
            if(m.count(s[i]))
            {
                left=max(m[s[i]]+1, left);
            }
            res=max(res, i-left+1);
            m[s[i]]=i;
        }
        return res;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> map(256, -1);
        if(s.size()==0) return 0;
        int start=0;
        int res=INT_MIN;
        for(int i=0;i<s.size();i++)
        {
            if(map[s[i]]==-1)
            {
                res=max(res, i-start+1);
                map[s[i]]=i;
            }
            else
            {
                start=max(start, map[s[i]]+1);
                res=max(res, i-start+1);
                map[s[i]]=i;
            }
        }
        return res;
        
    }
};

