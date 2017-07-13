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
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        int m=board.size(), n=board[0].size();
        Tire T;
        for(auto w:words) T.insert(w);
        vector<vector<boo> > visited(m vector<bool>(n, false));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(T.root->child[board[i][j]-'a']!=NULL)
                    dfs(board, res, i, j, T.root->child[board[i][j]-'a'], viisted);
            }
        }
        return res;
    }
    void dfs(vector<vector<char> >&board, vector<string>&res, int x, int y, TireNode *p, vector<vector<bool> > &visited)
    {
        if(!p->str.empty())
        {
            res.push_back(p->str);
            p->str.clear();
        }
        vector<vector<int> > dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        visited[x][y] = true;
        for(int i=0;i<dirs.size();i++)
        {
            int m = x + dirs[i][0];
            int n = y + dirs[i][1];
            if(m>=0&&m<board.size()&&n>=0&&n<board[0].size()&&!visited[m][n]&&p->child[board[m][n] - 'a'])
                dfs(board, res, m, n, p->child[board[m][n] - 'a'], visited);
        }
        visited[x][y] = false;
    }
    
private:
    struct TireNode
    {
        TireNode *child[26];
        string str;
        TireNode():str("")
        {
            for(auto &c:child)c=NULL;
        }
    };
    struct Tire
    {
        TireNode *root;
        Tire():root(NULL) {}
        void insert(string word)
        {
            TireNode *p=root;
            for(auto w:word)
            {
                int i=w-'a';
                if(p->child[i]==NULL) p->child[i]=new TireNode();
                p=p->child[i];
            }
            p->str=word;
        }
    };
    
};

