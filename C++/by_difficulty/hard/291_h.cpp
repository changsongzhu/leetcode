/**
291[H]. Word Pattern II
Given a pattern and a string str, find if str follows the same pattern.
Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty substring in str.
Examples:
1.     pattern = "abab", str = "redblueredblue" should return true.
2.     pattern = "aaaa", str = "asdasdasdasd" should return true.
3.     pattern = "aabb", str = "xyzabcxzyabc" should return false.
 
Notes:
You may assume both pattern and str contains only lowercase letters.
**/

class Solution {
public:
    bool wordPatternMatch(string pattern, string str) {
        unordered_map<char, string> m;
        return dfs(pattern, 0, str, 0, m);
    }
    bool dfs(string pattern, int p, string str, int s, unordered_map<char, string>& m)
    {
       if(p==pattern.size()&&s==str.size()) return true;
       if(p==pattern.size()||s==str.size()) return false;
       char c= pattern[p];
       for(int i=s;i<str.size();i++)
       {
           string t=str.substr(s, i-s+1);
           if(m.count(c)&&m[c]==t)
           {
               if(dfs(pattern, p+1, str, i+1, m)) return true;
           }
           else if(m.count(c)==0)
           {
               bool b=false;
               for(auto it:m)
                   if(it->second==t) b=true;
               if(!b)
               {
                   m[c]=t;
                   if(helper(pattern, p+1, str, i+1, m)) return true;
                   m.erase(c);
               }
           }
       }
       return false;
    }
};

