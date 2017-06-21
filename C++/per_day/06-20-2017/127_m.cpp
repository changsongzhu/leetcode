/**
127[M]. Word Ladder
 
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:
Only one letter can be changed at a time
Each intermediate word must exist in the word list
For example,
Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
**/
 
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        queue<string> q;
        unordered_map<string ,int> m;
        q.push(beginWord);
        m[beginWord]=1;
        while(!q.empty())
        {
            string word=q.front();q.pop();
            for(int i=0;i<word.size();i++)
            {
                string newword=word;
                for(char ch='a';ch<='z';ch++)
                {
                    newword[i]=ch;
                    if(dict.count(newword)&&newword==endWord) return m[word]+1;
                    if(dict.count(newword)&&!m.count(newword))
                    {
                        q.push(newword);
                        m[newword]=m[word]+1;
                    }
                }
            }
        }
        return 0;
    }
};
