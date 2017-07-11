/**
126[H]. Word Ladder II
 
Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:
Only one letter can be changed at a time
Each intermediate word must exist in the word list
For example,
Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]
Return
  [ 	
    	["hit","hot","dot","dog","cog"], 	
    	["hit","hot","lot","log","cog"] 
   ]
Note:
All words have the same length.
All words contain only lowercase alphabetic characters.
**/
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string> > res;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        queue<string> q;
        unordered_map<string, int> m;
        unordered_map<string, vector<string> > father;
        q.push(beginWord);
        m[beginWord]=1;
        int min_level=INT_MAX;
        while(!q.empty()){
            string word=q.front();q.pop();
            for(int i=0;i<word.size();i++){
                string newword=word;
                for(char ch='a';ch<='z';ch++){
                   if(ch==word[i]) continue;
                   newword[i]=ch;
                   if(dict.count(newword)&&newword==endWord&&(m[word]+1)<=min_level){
                       vector<string> path;
                       path.push_back(newword);
                       if(m[word]+1==min_level){
                           helper(res, path, father, word, beginWord);
                       }
                       else{
                           res.clear();
                           min_level=m[word]+1;
                           helper(res, path, father, word, beginWord);
                       }
                   }
                   if(dict.count(newword)){
                       if(!m.count(newword)){
                           q.push(newword);
                           m[newword]=m[word]+1;
                           father[newword].push_back(word);
                       }
                       else if(m[newword]==m[word]+1){
                           father[newword].push_back(word);
                       }
                   }
                }
            }
        }
        return res;
    }
    void helper(vector<vector<string> >&res, vector<string> &path, unordered_map<string, vector<string> >&father, string word, string beginWord)
    {
       if(word==beginWord){
           path.push_back(word);
           reverse(path.begin(), path.end());
           res.push_back(path);
           reverse(path.begin(), path.end());
           path.pop_back();
           return;
       }
       path.push_back(word);
       for(int i=0;i<father[word].size();i++)
           helper(res, path, father, father[word][i], beginWord);
       }
       path.pop_back();
    }
};

