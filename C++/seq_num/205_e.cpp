/**
205[E]. Isomorphic Strings
Given two strings s and t, determine if they are isomorphic.
Two strings are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.
For example,
Given "egg", "add", return true.
Given "foo", "bar", return false.
Given "paper", "title", return true.
Note:
You may assume both s and t have the same length.

**/

//Refined Solution
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()==0) return true;
        map<int, int> m1;
        map<int, int> m2;
        string s_key="";
        string t_key="";
        for(int i=0;i<s.size();i++)
        {
            if(m1.count(s[i])==0) 
            {
                m1[s[i]]=i;
                s_key.append(1, '*');
            }
            else
            {
                s_key+=to_string(m1[s[i]]);
            }
            if(m2.count(t[i])==0) 
            {
                m2[t[i]]=i;
                t_key.append(1, '*');
            }
            else
            {
                t_key+=to_string(m2[t[i]]);
            }
        }
        return s_key==t_key;
    }
};

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, int> mp1;
        map<char, int> mp2;
        for(int i=0;i<s.size();i++)
        {
            if(mp1.find(s[i])==mp1.end()&&mp2.find(t[i])==mp2.end())
            {
                mp1[s[i]]=mp2[t[i]]=i;
            }
            else if(mp1.find(s[i])!=mp1.end()&&mp2.find(t[i])!=mp2.end()&&mp1[s[i]]==mp2[t[i]])
                continue;
            else
                return false;
        }
        return true;
    }
};

