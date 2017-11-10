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
class Solution {
public:
    struct TrieNode{
      TrieNode *child[26];
      string word;
      TrieNode():word("")
      {
          for(auto &c:child) c=NULL;
      }
    };
    struct Trie{
      TrieNode *root;
      Trie()
      {
          root= new TrieNode();
      }
      void add(string word)
      {
          TrieNode *p=root;
          for(auto c:word)
          {
              if(p->child[c-'a']==NULL) p->child[c-'a']=new TrieNode();
              p=p->child[c-'a'];
          }
          p->word=word;
      }
    };
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if(board.size()==0||board[0].size()==0||words.size()==0) return {};
        int m=board.size(), n=board[0].size();
        vector<string> res;
        Trie *T= new Trie();
        for(auto w:words) T->add(w);
        vector<vector<bool> > visited(m, vector<bool>(n, false));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int idx=board[i][j]-'a';
                if(T->root->child[idx])
                {
                    helper(board, i, j, T->root->child[idx], res, visited);
                }
            }
        }
        return res;
    }
    void helper(vector<vector<char>>&board,int i, int j, TrieNode *root, vector<string>&res, vector<vector<bool> >&visited)
    {
        if(root->word.size()!=0)
        {
            res.push_back(root->word);
            root->word.clear();
        }
        vector<vector<int> > dirs={{-1, 0},{1,0},{0, 1},{0,-1}};
        visited[i][j]=true;
        for(int k=0;k<dirs.size();k++)
        {
            int x=i+dirs[k][0], y=j+dirs[k][1];
            if(x<0||x>=board.size()||y<0||y>=board[0].size()||visited[x][y]==true||root->child[board[x][y]-'a']==NULL) continue;
            helper(board, x, y, root->child[board[x][y]-'a'], res, visited);
        }
        visited[i][j]=false;
    }
};
