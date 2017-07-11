/**
336[H]. Palindrome Pair
Given a list of unique words, find all pairs of distinct indices (i, j) in the given list, so that the concatenation of the two words, i.e. words[i] + words[j] is a palindrome.
Example 1:
Given words = ["bat", "tab", "cat"]
Return [[0, 1], [1, 0]]
The palindromes are ["battab", "tabbat"]
Example 2:
Given words = ["abcd", "dcba", "lls", "s", "sssll"]
Return [[0, 1], [1, 0], [3, 2], [2, 4]]
The palindromes are ["dcbaabcd", "abcddcba", "slls", "llssssll"]
**/

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
       vector<vector<int> > res;
       unordered_map<string, int> m;
       set<int> s;
       for(int i=0;i<words.size();i++)
       {
           m[words[i]]=i;
           s.insert(words[i].size());
       }
       for(int i=0;i<words.size();i++)
       {
           string t=words[i];
           int len=t.size();
           reverse(t.begin(),t.end());
           if(m.count(t)&&m[t]!=i)
           {
               res.push_back({i, m[t]});
           }
           auto a=s.find(len);
           for(auto it=s.begin();it!=a;it++)
           {
               int d=*it;
               if(isValid(t, 0, len-d-1)&&m.count(t.substr(len-d)))
                   res.push_back({m[t.substr(len-d)],i});
               if(isValid(t, d, len-1)&&m.count(t.substr(d)))
                   res.push_back({i,m[t.substr(d)]});
           }
       }
       return res;
    }
    bool isValid(string t, int left, int right)
    {
        while(left<right)
        {
            if(t[left++]!=t[right--]) return false;
        }
        return true;
    }
};

