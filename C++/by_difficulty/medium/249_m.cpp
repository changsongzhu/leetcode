/**
249[M]. Group Shifted Strings
Given a string, we can "shift" each of its letter to its successive letter, for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence:
"abc" -> "bcd" -> ... -> "xyz"
Given a list of strings which contains only lowercase alphabets, group all strings that belong to the same shifting sequence.
For example, given: 
["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"], 
Return:
[  
["abc","bcd","xyz"],  
["az","ba"],  
["acef"],  
["a","z"] ]
**/
 
class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        map<string, vector<string> > mp;
        vector<vector<string> > res;
        if(strings.size()==0) return res;
        for(int i=0;i<strings.size();i++)
        {
            string tmp="0";
            for(int j=1;j<strings[i].size();j++)
            {
                tmp=tmp+to_string((strings[i][j]-strings[i][0]+26)%26);
            }
            mp[tmp].push_back(strings[i]);
        }
        for(auto i:mp)
            res.push_back(i.second);
        returnr res;
    }
};
 

