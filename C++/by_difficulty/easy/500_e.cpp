/**
500[E] Keyboard Row
Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below.

Example 1:
Input: ["Hello", "Alaska", "Dad", "Peace"]
Output: ["Alaska", "Dad"]
Note:
You may use one character in the keyboard more than once.
You may assume the input string will only contain letters of alphabet.

**/
 
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        map<char, int> mp;

        string s1="qwertyuiop";
        string s2="asdfghjkl";
        string s3="zxcvbnm";
        for(auto c:s1) mp[c]=1;
        for(auto c:s2) mp[c]=2;
        for(auto c:s3) mp[c]=3;

        vector<string> res;
        for(int i=0;i<words.size();i++)
        {
            int row=0;
            int valid=true;
            for(int j=0;j<words[i].size();j++)
            {
                row=(row==0)?mp[tolower(words[i][j])]:row;
                if(mp[tolower(words[i][j])]!=row)
                {
                    valid=false;
                }
            }
            if(valid==true) res.push_back(words[i]);
        }
        return res;
        
    }
};
