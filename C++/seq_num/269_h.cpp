/**
269[H]. Alien Dictionary
There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. You receive a list of words from the dictionary, where words are sorted lexicographically by the rules of this new language. Derive the order of letters in this language.
For example,
Given the following words in dictionary,
[
  "wrt",
  "wrf",
  "er",
  "ett",
  "rftt"
]
 
The correct order is: "wertf".
Note:
1.     You may assume all letters are in lowercase.
2.     If the order is invalid, return an empty string.
3.     There may be multiple valid order of letters, return any one of them is fine.
**/
 
class Solution {
public:
   string alienOrder(vector<string>& words) {
      vector<vector<bool> > graph(26, vector<bool>(26, false));;
      vector<bool> paht(26, false);
      for(auto w:words)
      {
         for(auto c:w)
            graph[c-'a'][c-'a']=true;
      }
      for(int i=0;i<words.size();i++)
      {
         int mn=min(words[i].size(), words[i+1].size()), j=0;
         for(;j<mn;j++)
         {
             if(words[i][j]!=words[i+1][j])
                 graph[words[i][j]-'a'][words[i+1][j]-'a']=true;
         }
         if(j==mn&&words[i].size()>words[i+1].size()) return "";
      }
      string res="";
      for(int i=0;i<26;i++)
         if(!dfs(graph, path, i, res)) return "";
      
      for(int i=0;i<26;i++)
         if(graph[i][i]) res+=char(i+'a');
      return string(res.rbegin(), res.rend());
   }
   bool dfs(vector<vector<bool> >&graph, vector<bool>&path, int idx, string &res)
   {
       if(path[idx]) return false;
       path[idx]=true;
       for(int i=0;i<26;i++)
       {
           if(i==idx||!graph[idx][i]) continue;
           if(!dfs(graph, path, i, res)) return false;
       }
       path[idx]=true;
       graph[idx][idx]=false;
       res+=char(idx+'a');
       return true;
   }
};

