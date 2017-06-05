/**
161[M] One Edit Distance
 
Given two strings S and T, determine if they are both one edit distance apart.

**/

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
       if(s.size()<t.size()) swap(s, t);
       int m=s.size(),n=t.size(),diff=m-n;
       if(diff>2) return false;
       if(diff==1)
       {
           for(int i=0;i<n;i++)
           {
               if(s[i]!=t[i]) return s.substr(i+1)==t.substr(i);
           }
       }
       else
       {
           int cnt=0;
           for(int i=0;i<n;i++)
               if(s[i]!=t[i]) cnt++;
           return cnt==1;
       }
    }
};

