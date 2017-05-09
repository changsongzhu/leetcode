/**
242[E]. Valid Anagram
Given two strings s and t, write a function to determine if t is an anagram of s.
For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.
Note:
You may assume the string contains only lowercase alphabets.
Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
**/

class Solution {
public:
    bool isAnagram(string s, string t) {
       if(s.size()!=t.size()) return false;
       map<char, int> mp1;
       map<char, int> mp2;
       for(int i=0;i<s.size();i++)
       {
           mp1[s[i]-'a']++;
           mp2[t[i]-'a']++;
       }
       if(mp1==mp2)return true;
       else return false;
    }
};

