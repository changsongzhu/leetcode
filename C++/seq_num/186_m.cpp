/**
186[M]. Reverse Words in a String II
Given an input string, reverse the string word by word. A word is defined as a sequence of non-space characters.
The input string does not contain leading or trailing spaces and the words are always separated by a single space.
For example,
Given s = "the sky is blue",
return "blue is sky the".

Could you do it in-place without allocating extra space?

**/

//Update for the input parameter
class Solution {
public:
    void reverseWords(vector<char>& str) {
        int i=0, j=str.size()-1;
        while(i<j)
        {
            swap(str[i++], str[j--]);
        }
        int start=0;
        for(int i=0;i<str.size();i++)
        {
            if(str[i]==' '||i==str.size()-1)
            {
                int j=start, k=(i==str.size()-1)?i:i-1;
                while(j<k) swap(str[j++], str[k--]);
                start=i+1;
            }
        }    
    }
};


class Solution {
public:
    void reverseWords(string &s) {
        istringstream is(s);
        is>>s;
        string tmp;
        while(is>>tmp) s=tmp+" "+s;
    }
};


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

