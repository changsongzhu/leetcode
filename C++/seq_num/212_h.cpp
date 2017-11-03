/**
212[H]. Word Search II
 
Given a 2D board and a list of words from the dictionary, find all words in the board.
Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.
For example,
Given words = ["oath","pea","eat","rain"] and board =
[  
['o','a','a','n'],  
['e','t','a','e'],  
['i','h','k','r'],  
['i','f','l','v']
]
Return ["eat","oath"].

Note:
You may assume that all inputs are consist of lowercase letters a-z.
**/
class TrieNode{
    public:
      TrieNode *child[26];
      string word;
      TrieNode():word(""){
          for(auto &c:child) c=NULL;
      }
    };
class Trie{
    public:
        TrieNode *root;
        Trie(){
            root=new TrieNode();
        }
        void add(string w)
        {
            TrieNode *p=root;
            for(auto c:w)
            {
                if(p->child[c-'a']==NULL) p->child[c-'a']=new TrieNode();
                p=p->child[c-'a'];
            }
            p->word=w;
        }
    };
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if(board.size()==0||board[0].size()==0||words.size()==0) return {};
        int m=board.size(), n=board[0].size();
        Trie *T= new Trie();
        for(auto w:words) T->add(w);
        vector<string> res;
        vector<vector<bool> > visited(m, vector<bool>(n, false));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int idx=board[i][j]-'a';
                if(T->root->child[idx])
                {
                    helper(board, i, j, visited, T->root->child[idx], res);
                }
                    
            }
        }
        return res;
    }
    void helper(vector<vector<char> >&board, 
                int x, 
                int y, 
                vector<vector<bool> >&visited,
                TrieNode* root, 
                vector<string> &res)
    {
        if(root->word.size()!=0)
        {
            res.push_back(root->word);
            root->word.clear();
        }
        vector<vector<int> > dirs={{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        visited[x][y]=true;
        for(int i=0;i<dirs.size();i++)
        {
            int a=x+dirs[i][0], b=y+dirs[i][1];
            if(a<0||a>=board.size()||b<0||b>=board[0].size()||visited[a][b]||root->child[board[a][b]-'a']==NULL) continue;
            helper(board, a, b, visited, root->child[board[a][b]-'a'], res);
        }
        visited[x][y]=false;
    }
};
