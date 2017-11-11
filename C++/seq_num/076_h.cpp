/**
76[M]. Minimum Window Substring
 
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".
Note:
If there is no such window in S that covers all characters in T, return the empty string "".
If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
**/
//Another Solution
class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> m;
        for(auto c:t)m[c]++;
        int count=0;
        int left=0;
        int len=INT_MAX;
        int start=-1;
        for(int i=0;i<s.size();i++)
        {
            if(m.count(s[i]))
            {
                m[s[i]]--;
                if(m[s[i]]>=0) count++;
            }
            while(count==t.size())
            {
                if(i-left+1<len)
                {
                    len=i-left+1;
                    start=left;
                }
                if(m.count(s[left]))
                {
                    m[s[left]]++;
                    if(m[s[left]]>0)count--;
                }
                left++;
            }
        }
        return start!=-1?s.substr(start, len):"";
    }
};


class Solution {
public:
    string minWindow(string s, string t) {
       string res="";
       map<char, int> m;
       for(auto c:t)m[c]++;
       int min_len=s.size()+1;
       int left=0;
       int count=0;
       for(int i=0;i<s.size();i++)
       {
           if(m.find(s[i])!=m.end())
           {
               m[s[i]]--;
               if(m[s[i]]>=0) count++;
           }
           while(count==t.size())
           {
               if(min_len>i-left+1)
               {
                  min_len=i-left+1;
                  res=s.substr(left, i-left+1);
               }
               if(m.find(s[left])!=m.end())
               {
                   m[s[left]]++;
                   if(m[s[left]]>0) count--;
               }
               left++;
           }
       }
       return res;
    }
};

