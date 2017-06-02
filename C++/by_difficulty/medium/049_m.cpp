/**
49[M]. Group Anagrams
Given an array of strings, group anagrams together.
For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
Return:
[  
["ate", "eat","tea"],  
["nat","tan"],  
["bat"]
]
Note: All inputs will be in lower-case.
**/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> > res;
        map<string, vector<string> > mp;
        for(int i=0;i<strs.size();i++)
        {
            string key=digest(strs[i]);
            mp[key].push_back(strs[i]);
        }
        for(auto i:mp)
            res.push_back(i.second);
        return res;
    }

    string digest(string s)
    {
        sort(s.begin(),s.end());
        return s;
    }
};

