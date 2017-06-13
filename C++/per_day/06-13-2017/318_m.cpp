/**
318[M]. Maximum Product of Words Length
 
Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.
Example 1:
Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
Return 16
The two words can be "abcw", "xtfn".
Example 2:
Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
Return 4
The two words can be "ab", "cd".
Example 3:
Given ["a", "aa", "aaa", "aaaa"]
Return 0
No such pair of words.
**/

class Solution {
public:
    int maxProduct(vector<string>& words) {
        if(words.size()<2) return 0;
        vector<pair<int, int> > dict;
        for(int i=0;i<words.size();i++)
        {
            int val=0;
            for(int j=0;j<words[i].size();j++)
               val|=(1<<(words[i][j]-'a'));
            dict.push_back({val, words[i].size()});
        }
        int res=0;
        for(int i=0;i<dict.size()-1;i++)
        {
            for(int j=i+1;j<dict.size();j++)
            {
               if((dict[i].first&dict[j].first)==0)
                  res=max(res, dict[i].second*dict[j].second);
            }
        }
        return res;
    }
};

