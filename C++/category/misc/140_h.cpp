/**
140[H]. Word Break 2
 
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.
Return all such possible sentences.
For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].
A solution is ["cats and dog", "cat sand dog"].
**/
 
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res;
        string path;
        vector<bool> possible(s.size()+1, true);
        map<string, int> m;
        for(auto w:wordDict)m[w]++; 
        helper(res, path, m, possible, s, 0);
        return res;
    }
    void helper(vector<string>& res, string path, map<string, int> &dict, vector<bool> &possible,string s, int start)
    {
        if(start == s.size())
        {
            res.push_back(path.substr(0, path.size()-1));
            return;
        }
        for(int i=start;i<s.size();i++)
        {
            string tmp=s.substr(start, i-start+1);
            if(dict.find(tmp)!=dict.end()&&possible[i+1]==true)
            {
                path.append(tmp).append(" ");
                int old_size=res.size();
                helper(res, path, dict, possible,s, i+1);
                if(old_size==res.size())
                   possible[i+1]=false;
                path.resize(path.size()-tmp.size()-1);
            }
        }
    }
};

