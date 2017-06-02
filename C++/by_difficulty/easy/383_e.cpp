/**
383[E]. Ransom Notes
 
Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.
Each letter in the magazine string can only be used once in your ransom note.
Note:
You may assume that both strings contain only lowercase letters.
canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
**/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> v1(256, 0);
        vector<int> v2(256, 0);
        for(int i=0;i<ransomNote.size();i++)
            v1[ransomNote[i]]++;
        for(int i=0;i<magazine.size();i++)
            v2[magazine[i]]++;
        for(int i=0;i<256;i++)
        {
            if(v1[i]!=0&&v1[i]>v2[i]) return false;
        }
        return true;
    }
};
