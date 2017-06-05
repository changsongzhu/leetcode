/**
186[M]. Reverse Words in a String II
Given an input string, reverse the string word by word. A word is defined as a sequence of non-space characters.
The input string does not contain leading or trailing spaces and the words are always separated by a single space.
For example,
Given s = "the sky is blue",
return "blue is sky the".

Could you do it in-place without allocating extra space?

**/

class Solution {
public:
    void reverseWords(string &s) {
       if(s.size()==0&&s.size()==1) return;
       reverse(s.begin(), s.end());
       int start=0;
       for(int i=0;i<=s.size();i++)
       {
          if(i==s.size()||s[i]==' ')
          {
              reverse(s, start, i-1);
              start=i+1;
          }
       }
   }
};

