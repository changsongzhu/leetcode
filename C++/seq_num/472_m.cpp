/**
472[M]. Concatenated Words
Given a list of words (without duplicates), please write a program that returns all concatenated words in the given list of words.
A concatenated word is defined as a string that is comprised entirely of at least two shorter words in the given array.
Example:
Input: ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
 
Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]
 
Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats";
 "dogcatsdog" can be concatenated by "dog", "cats" and "dog";
"ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".
Note:
The number of elements of the given array will not exceed 10,000
The length sum of elements in the given array will not exceed 600,000.
All the input string will only include lower case letters.
The returned elements order does not matter.
**/

//DP solution TLE
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>&words){
        set<string> dict;
        vector<string> res;
        sort(words.begin(), words.end(), [](string &a, string &b){return a.size()<b.size();});
        for(int i=0;i<words.size();i++)
        {
            if(canForm(words[i], dict))
                res.push_back(words[i]);
            dict.insert(words[i]);
        }
        return res;
    }
    bool canForm(string s, set<string> dict)
    {
        int n=s.size();
        vector<bool> dp(n+1, false);
        dp[0]=true;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(dp[j]==false) continue;
                if(dict.count(s.substr(j, i-j)))
                {
                    dp[i]=true;
                    break;
                }

            }
        }
        return dp[n];
    }
};


class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> res;
        if(words.size()==0) return res;
        map<string, int> dict;
        for(auto w:words)
        { 
            dict[w]++;
        }
        for(auto word:words)
        {
           if(dfs(dict, word, 0, 0))
               res.push_back(word);
        }
        return res;
    }
    bool dfs(map<string, int>&dict, string word, int cnt, int pos)
    {
       if(pos>=word.size()&&cnt>=2) return true;
       for(int i=pos;i<word.size();i++)
       {
          if(dict.find(word.substr(pos, i-pos+1))!=dict.end()&&dfs(dict, word, cnt+1, i+1))
          {
              return true;
          }
       }
       return false;
    }
};
