/**
316[H]. Remove Duplicated Letters
Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.
Example:
Given "bcabc"
Return "abc"
Given "cbacdcbc"
Return "acdb"
**/
class Solution {
public:
    string removeDuplicateLetters(string s) {
       string res="";
       map<char, int> m;
       vector<bool> visited(26, false);
       for(auto c:s) m[c]++;
       for(int i=0;i<s.size();i++)
       {
          m[s[i]]--;
          if(visited[s[i]-'a']==true) continue;
          while(res.size()>0&&s[i]<res.back()&&m[res.back()])
          {   
             visited[res.back()-'a']=false;
             res.pop_back();
          }
          res.push_back(s[i]);
          visited[s[i]-'a']=true;

       }
       return res;
    }
};
