/**
30[H]. Substring with Concatenations of all Words
 
You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.
For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]
You should return the indices: [0,9].
(order does not matter).
**/

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n=words.size(),len=words[0].size();
        vector<int> res;
        if(s.size()<n*len) return res;
        map<string, int> m1;
        for(auto word:words)m1[word]++;
        for(int i=0;i<=s.size()-n*len;i++)
        {
            int cnt=0;
            map<string, int> m2;
            while(cnt<n)
            {
                string tmp=s.substr(i+cnt*len,len);
                if(m1.find(tmp)==m1.end()) break;
                cnt++;
                m2[tmp]++;
            }
            if(cnt==n&&m2==m1) res.push_back(i);
        }
        return res;
    }
};

